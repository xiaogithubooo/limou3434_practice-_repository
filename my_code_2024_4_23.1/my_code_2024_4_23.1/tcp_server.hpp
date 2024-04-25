//tcp_server.hpp(多线程服务端)

/* 使用方法
std::unique_ptr<TcpServer> svr(new TcpServer(port, ip));
svr->Start();
*/

#pragma once
#include <string>
#include <cerrno>
#include <cstring>
#include <cassert>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "log.hpp"
#include "thread.hpp"

const int buffSize = 1024;
const int g_backlog = 20; //这个数值一般不会太大, 也不会太小, 但是我们以后提及 TCP 报文的时候再来详细讲解

//线程数据类
struct ThreadData
{
    int _sock;
    std::string _ip;
    uint16_t _port;
};

static void Service(const int& serviceSock, const std::string& client_ip, const uint16_t& client_port)
{
    Log log;

    while (true)
    {
        //直接套用文件 IO 的接口 read() 和 write()

        //从服务端读取数据
        char readBuffer[1024] = { 0 };
        ssize_t s = read(serviceSock, readBuffer, sizeof(readBuffer) - 1);
        if (s > 0)
        {
            std::cout << "[" << client_ip << ":" << client_port << "] echo " << readBuffer << std::endl;
        }
        else if (s == 0) //代表对端关闭了
        {
            log.LogMessage(NORMAL, "write close, me too! %s %d", __FILE__, __LINE__);
            break;
        }
        else //代表读取出现异常
        {
            log.LogMessage(FATAL, "read() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //写入数据到服务端
        write(serviceSock, readBuffer, strlen(readBuffer)); //这里读到什么数据就直接传送回去
    }
}

class TcpServer
{
private:
    static void* ThreadRoutine(void* args) //static 去除 this 参数
    {
        pthread_detach(pthread_self()); //线程分离, 让子线程自己释放自己

        ThreadData* td = (ThreadData*)args;

        int serviceSock = td->_sock;
        std::string client_ip = td->_ip;
        int client_port = td->_port;

        Service(serviceSock, client_ip, client_port); //读写任务

        delete td; //这一步一定要记住
    }

public:
    //初始服务器
    TcpServer(uint16_t port, std::string ip)
        : _ip(ip), _port(port), _ListenSock(-1)
    {
        //1.创建套接字
        if ((_ListenSock = socket(AF_INET, SOCK_STREAM, 0)) < 0) //注意换成流式类型, 而不是数据报类型
        {
            _log.LogMessage(FATAL, "socket() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }
        _log.LogMessage(NORMAL, "sock: %d, %s %d", _ListenSock, __FILE__, __LINE__); //检验套接字是不是真的是一个文件描述符, 若是理应返回 3

        //2.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip(四字节), 内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port(两字节), 主机序列转为网络序列
        if (bind(_ListenSock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //3.设置套接字为监听状态
        /* 因为 TCP 是面向连接的, 因此正确通信时需要建立连接, 而这就注定一个服务端必须处于一个等待连接的状态 */
        if (listen(_ListenSock, g_backlog) < 0) //设置 _ListenSock 为监听状态
        {
            _log.LogMessage(FATAL, "%s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //4.提示初始化成功
        _log.LogMessage(NORMAL, "init tcp server done... %s %d", __FILE__, __LINE__);
    }

    //运行服务器
    void Start()
    {
        //signal(SIGCHLD, SIG_IGN); //父进程由程序员主动设置忽略, 因此子进程退出时会自动释放自己的僵尸状态

        while (true)
        {
            //1.获取和客户端的连接（如果没有任何一个客户端连接服务端, 服务端就会陷入阻塞状态）
            struct sockaddr_in src;
            socklen_t len = sizeof(src);
            int serviceSock = accept(_ListenSock, (struct sockaddr*)&src, &len); //获取 IO 用的套接字(这个套接字才是做 IO 服务的套接字, 而之前申请的 _ListenSock 应该叫做监听套接字)
            /* _ListenSock vs serviceSock ? 注意这里的 _ListenSock 其实就是之前代码中的 _sork, 不过我换了一个更加简介的名字 */
            /* 这两个套接字的区别就在于：_ListenSock 是提供揽客的揽客员, serviceSock 是提供服务的服务员 */
            /* _ListenSock 作用是获取新的连接, serviceSock 作用是提供 IO 服务, 这点和 UDP 编程很不一样 */

            if (serviceSock < 0) //若申请
            {
                _log.LogMessage(WARNING, "accept() error... , %s %d", __FILE__, __LINE__);
                continue; //即使获取不到新的连接也不影响, 重新循环尝试链接即可
            }

            std::string client_ip = inet_ntoa(src.sin_addr);
            uint16_t client_port = ntohs(src.sin_port);
            _log.LogMessage(NORMAL, "link success, the \"service sock\" is [%d], the \"client sock\" is [%s:%d], %s %d", serviceSock, client_ip.c_str(), client_port, __FILE__, __LINE__); //提示连接成功

            //2.开始进行通信服务
            //version 1 -- 单进程循环版本
            //Service(serviceSock, client_ip, client_port);

            //version 2 -- 多进程循环版本
            //pid_t id = fork(); //创建子进程
            //assert(id != -1);
            //if (id == 0) //子进程, 也能看到文件描述符, 因此也可以提供服务工作, 让连接工作交给父进程
            //{
            //    close(_ListenSock); //但是子进程无需知道监听套接字, 关闭即可, 避免文件描述符资源越来越少
            //    Service(serviceSock, client_ip, client_port); //执行服务任务
            //    close(serviceSock); //服务任务执行结束后最好关闭下服务套接字(虽然该进程自动释放后也会自动释放该套接字资源罢了, 不过我们严谨一点)
            //    exit(-1);
            //}
            //waitpid(); //这里我不设置非阻塞等待回收, 也不设置子进程退出时信号的处理机制, 我们使用信号忽略的方式, 对应代码就在 Start() 方法的开头处

            //version 3 -- 多进程循环版本（孙进程托管版本）
            //pid_t id = fork(); //创建子进程
            //if (id == 0) //(2)子进程部分
            //{
            //    close(_ListenSock); //提前关闭监听套接字, 这样孙进程就不用再次关闭了
            //    if (fork() > 0) //子进程创建完孙线程后, 自己立刻退出
            //        exit(-1);
            //    //(3)孙进程部分
            //    Service(serviceSock, client_ip, client_port); //孙进程被子进程抛弃, 成为孤儿进程被操作系统托养, 因此由操作系统决定释放(相当于由操作系统自动释放)
            //    close(serviceSock); //执行完服务任务后, 关闭服务套接字
            //    exit(-1); //注意这里孙进程执行完自己的任务后一定要退出, 不然会出现意想不到的错误(例如在客户端使用 "exit" 退出时会导致父进程陷入死循环, 这点您可以研究一下)
            //}
            //waitpid(id, nullptr, 0); //父进程阻塞等待回收子进程, 由于子进程立刻退出, 因此父进程可以立刻接收子进程再进行释放不会导致父进程进入阻塞, 而孙进程此时就在执行和服务端交互的任务
            ////(1)主进程部分
            
            //version 4 -- 多线程版本
            //pthread_t tid;
            //ThreadData* td = new ThreadData(); //这里最好用指针, 因为有可能在多线程的场景下 td 发生二义性, 而我又懒得加锁... 不过代价就是必须注意在线程方法内释放指针
            //td->_sock = serviceSock;
            //td->_ip = client_ip;
            //td->_port = client_port;
            //pthread_create(&tid, nullptr, ThreadRoutine, td);
            
            //version 5 -- 多线程版本(自己封装的线程对象)
            ThreadData* td = new ThreadData(); //这里最好用指针, 因为有可能在多线程的场景下 td 发生二义性, 而我又懒得加锁... 不过代价就是必须注意在线程方法内释放指针
            td->_sock = serviceSock;
            td->_ip = client_ip;
            td->_port = client_port;
            Thread<ThreadData*> t("aThread", ThreadRoutine, td);
            t.Start();

            //3.关闭服务套接字(多线程版本不能关闭, 否则会导致服务端被异常关闭, 这也很好理解, 这里不是多进程, 主线程关闭服务套接字会导致共享的子线程读写套接字时出现错误)
            //close(serviceSock);
        }
    }

    //销毁服务器
    ~TcpServer()
    {
        if (_ListenSock < 0)
            close(_ListenSock);
    }


private:
    std::string _ip;
    uint16_t _port;
    int _ListenSock; //int _sock; //我们更愿意叫这个套接字为监听套接字, 因此我们改一下名字
    Log _log;
};