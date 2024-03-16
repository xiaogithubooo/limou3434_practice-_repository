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

class TcpServer
{
    //2.初始服务器自己的 ip 和 port
    public:TcpServer(std::string ip, uint16_t port)
        : _ip(ip), _port(port), _sock(-1)
    {
        //3.创建套接字
        if ( (_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) //注意换成流式类型，而不是数据报类型
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(10);
        }
        LogMessage(NORMAL, "sock: %d, %d %s %s %d", _sock, errno, strerror(errno), __FILE__, __LINE__); //检验套接字是不是真的是一个文件描述符，若是理应返回 3

        //4.绑定套接字
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); //比特位置零
        local.sin_family = AF_INET; //设置协议家族/域
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); //设置 ip（四字节），内部做了两个步骤：(1)转化为四字节 (2)再转化为网络序列
        local.sin_port = htons(_port); //设置 port（两字节），主机序列转为网络序列
        if ( bind(_sock, (struct sockaddr*)&local, sizeof(local)) < 0 )
        {
            LogMessage(FATAL, "%d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(20);
        }

        /* 因为 TCP 是面向连接的，因此正确通信时需要建立连接，而这就注定一个服务端必须处于一个等待连接的状态 */
        //5.设置套接字为监听状态
        if (listen(_sock, g_backlog) < 0)
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
            int fd = accept(_sock, (struct sockaddr*)&src, &len); //获取监听套接字
            /* _sock vs sock ? */
            /* 这两个套接字的区别就在于： */
        }
    }

    public:~TcpServer()
    {
        
    }

private:
    //1.设置成员变量
    std::string _ip; //ip
    uint16_t _port; //port
    int _sock;
};
