//tcp_server.hpp
#pragma once
#include <iostream>
#include <string>
#include <memory>

#include <cerrno>
#include <cstring>
#include <cstdio>
#include <cassert>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

#include "log.hpp"
#include "threadPool.hpp"
#include "Task.hpp"

static void Service(int serviceSock, const std::string& client_ip, const uint16_t& client_port)
{
    //返回内容
    while (true)
    {
        //和文件一样读取
        char readBuff[1024] = { 0 };
        ssize_t s = read(serviceSock, readBuff, sizeof(readBuff) - 1);
        if (s > 0)
        {
            std::cout << "[client_ip:" << client_ip << "-client_port:" << client_port << "]#"
                << readBuff << std::endl;
        }
        else if (s == 0) //代表对端关闭链接
        {
            LogMessage(NORMAL, "%s-%d shutdown, me too!|[%s][%d]", client_ip.c_str(), client_port, __FILE__, __LINE__);
            break;
        }
        else //s < 0 读取失败
        {
            LogMessage(ERROR, "read() error|[%s][%d]", __FILE__, __LINE__);
            exit(-1);
        }

        //和文件一样写入
        write(serviceSock, readBuff, strlen(readBuff));
    }
    close(serviceSock);
}

struct SocketData
{
   int _sock;
   std::string _ip;
   uint16_t _port;
};

class TcpServer
{
private:
    const static int gBackLog = 20; //这个全局静态变量用就行，以后解释
    static void* ThreadRoutine(void* args)
    {
        pthread_detach(pthread_self()); //线程分离可以让新线程自己释放自己，不必让主线程使用 pthread_join() 等待
        SocketData* td = static_cast<SocketData*>(args);
        Service(td->_sock, td->_ip, td->_port);
        delete td;
        return nullptr;
    }

public:
    TcpServer(uint16_t port, std::string ip = "")
        : _port(port), _ip(ip), _threadpool_ptr(new ThreadPool<Task>(3))
    {
        //1.创建套接字
        _listenSock = socket(
            AF_INET, //套接字类型
            SOCK_STREAM, //通信类型（TCP），流式套接字和文件描述符的理解几乎一样
            0 //协议类别
        );
        if (_listenSock < 0) //套接字创建失败
        {
            LogMessage(FATAL, "socket() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
            exit(-1);
        }
        LogMessage(NORMAL, "create sock value:%d", _listenSock); //这里输出 _listenSock 原因是检验其和文件描述符的相似性
            
        //2.绑定套接字
        struct sockaddr_in local; memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str());
        if (bind(
            _listenSock, //获取到的套接字标识符
            (struct sockaddr*)&local, //套接字结构体
            sizeof(local) //传入的对象结构体的字节长度
        ) < 0)
        {
            LogMessage(FATAL, "bind() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
            exit(-1);
        }

        //3.建立链接（TCP 是面向链接的，在建立链接之前，服务端需要进入一个等待状态，或者说设置为监听状态）
        if (listen(_listenSock, //套接字标识符
            gBackLog //一个全局变量，以后解释（不过一般不会太大或太小）
        ) < 0)
        {
            LogMessage(FATAL, "listen() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
            exit(-1);
        }
        LogMessage(NORMAL, "init server success.");
    }

    void Start()
    {
        //signal(SIGCHLD, SIG_IGN); //主动忽略 SIGCHLD 信号，子进程退出不会产生僵尸进程

        _threadpool_ptr->Run(); //运行线程池

        while (true)
        {
            //4.获取链接（UDP 则是直接发送和接收，无需链接）
            struct sockaddr_in src;
            socklen_t len = sizeof(src);
            int serviceSock = accept( //返回值也是一个套接字
                _listenSock, //已绑定的套接字
                (sockaddr*)&src, //输出型参数，返回客户端的相关套接字消息
                &len //输出型参数
            );
            //sock 获取到的套 接字和 _listenSock 有什么区别呢？
            //区别在于，参数里的 sock 是用来监听新连接的套接字（招客员）
            //而 accept() 返回的 sock 是用来与客户端进行通信的新套接字（服务员）
            //常见的做法是在 accept() 返回的新套接字上进行 IO 数据收发，而监听套接字仍然保持用于接受新连接
            //不过两者都可以作为文件标识符来理解
            if (serviceSock < 0) //获取底层链接失败（招客失败）
            {
                LogMessage(ERROR, "serviceSock() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
                continue; //继续尝试获取底层链接
            }

            //5.获取链接
            uint16_t client_port = ntohs(src.sin_port);
            std::string client_ip = inet_ntoa(src.sin_addr);
            LogMessage(NORMAL, "link succer, serviceSock:%d, client ip:%s, client port:%d", serviceSock, client_ip.c_str(), client_port);

            //6.通信服务
            //6.1.单进程死循环版本
            //Service(serviceSock, client_ip, client_port);

            //6.2.多进程死循环版本
            //pid_t id = fork();
            //assert(id != -1);
            //if (id == 0)
            //{
            //    //子进程
            //    close(_listenSock); //子进程只需要充当招客员即可，无需进行监听
            //    Service(serviceSock, client_ip, client_port); 
            //    exit(0); //退出，进入僵尸状态
            //}
            //close(serviceSock);

            //6.3.多进程非阻塞版本
            //pid_t id = fork();
            //if (id == 0) //子进程
            //{
            //    close(_listenSock);
            //    if (fork() > 0) //如果 fork() 的返回值大于 0，则为子进程本身，立马退出，但是如果是 0，则多创建了一个孙进程
            //        exit(-1);
            //    Service(serviceSock, client_ip, client_port); //真正给用户提供服务的是孙进程（并且是孤儿进程，被操作系统领养，会被操作系统自动回收）

            //    exit(0); //孙进程执行完后退出，等待操作系统自动回收
            //}
            //waitpid(id, nullptr, 0); //由于子进程立即退出，这里就不会立刻陷入阻塞状态（而是先回收子进程）

            //6.4.多线程版本
            //struct SocketData* td = new SocketData(); //这里不直接使用一个对象而是使用指针的原因是：由于线程安全
            //td->_sock = serviceSock;
            //td->_ip = client_ip;
            //td->_port = client_port;
            //pthread_t tid;
            //pthread_create(&tid, nullptr, ThreadRoutine, td);
            //不进行线程等待，而是线程分离 

            //6.5.线程池版本
            Task t(serviceSock, client_ip, client_port, Service);
            _threadpool_ptr->PushTask(t);

            //7.关闭链接
            close(serviceSock);
        }
    }
    
    ~TcpServer()
    {

    }

private:
    uint16_t _port;
    std::string _ip;
    int _listenSock;
    std::unique_ptr<ThreadPool<Task>> _threadpool_ptr;//线程池
};