//tcp_server.hpp
#pragma once

#include <cerrno>
#include <cstring>

#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>

#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>

#include <unistd.h> //主要是文件 IO 接口的头文件

#include "log.hpp"

#define DEBUG_SHOW

const int buffSize = 1024;

const int g_backlog = 20; //一般不会太大，也不会太小

static void Service(const int& serviceSock, const std::string& client_ip, const uint16_t& client_port)
{
    while(true)
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
            LogMessage(NORMAL, "write close, me too! %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            break;
        }
        else 
        {
            LogMessage(FATAL, "read() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(40);
        }
        
        //写入数据到服务端
        write(serviceSock, readBuffer, strlen(readBuffer));
    }
}

class TcpServer
{
    //2.初始服务器自己的 ip 和 port
    public:TcpServer(std::string ip, uint16_t port)
        : _ip(ip), _port(port), _ListenSock(-1)
    {
        //3.创建套接字
        if ( (_ListenSock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) //注意换成流式类型，而不是数据报类型
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(10);
        }
        LogMessage(NORMAL, "sock: %d, %d %s %s %d", _ListenSock, errno, strerror(errno), __FILE__, __LINE__); //检验套接字是不是真的是一个文件描述符，若是理应返回 3

        //4.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip（四字节），内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port（两字节），主机序列转为网络序列
        if ( bind(_ListenSock, (struct sockaddr*)&local, sizeof(local)) < 0 )
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(20);
        }

        /* 因为 TCP 是面向连接的，因此正确通信时需要建立连接，而这就注定一个服务端必须处于一个等待连接的状态 */
        //5.设置套接字为监听状态
        if (listen(_ListenSock, g_backlog) < 0)
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(30);
        }

        //6.提示初始化成功
        LogMessage(NORMAL, "init tcp server done ... %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    }

    public:void Start()
    {
        while (true)
        {
            //7.获取和客户端的连接（如果没有任何一个客户端连接服务端，服务端就会陷入阻塞状态）
            struct sockaddr_in src;
            socklen_t len = sizeof(src);
            int serviceSock = accept(_ListenSock, (struct sockaddr*)&src, &len); //获取 IO 用的套接字
            /* _ListenSock vs serviceSock ? 注意这里的 _ListenSock 其实就是之前代码中的 _sork，不过我换了一个更加简介的名字 */
            /* 这两个套接字的区别就在于：_ListenSock 是提供揽客的揽客员，serviceSock 是提供服务的服务员 */
            /* _ListenSock 作用是获取新的连接，serviceSock 作用是提供 IO 服务，这点和 UDP 编程很不一样 */
            if (serviceSock < 0)
            {
                LogMessage(WARNING, "accept() fail... , %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
                continue; //即使获取不到新的连接也不影响，重新循环即可
            }
            std::string client_ip = inet_ntoa(src.sin_addr);
            uint16_t client_port = ntohs(src.sin_port);
            LogMessage(NORMAL, "link success, the \"service sock\" is [%d], the \"client sock\" is [%s:%d], %d %s %s %d", serviceSock, client_ip.c_str(), client_port, errno, strerror(errno), __FILE__, __LINE__); //提示连接成功

            //8.开始进行通信服务
            //version 1 -- 单进程循环版本
            Service(serviceSock, client_ip, client_port);

            //9.关闭服务套接字
            close(serviceSock);
        }
    }

    public:~TcpServer()
    {
        if(_ListenSock < 0)
            close(_ListenSock);
    }

private:
    //1.设置成员变量
    std::string _ip; //ip
    uint16_t _port; //port
    int _ListenSock; //int _sock; //我们更愿意叫这个套接字为监听套接字，因此我们改一下名字
};
