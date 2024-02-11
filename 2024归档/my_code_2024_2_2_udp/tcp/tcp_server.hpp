#pragma once
#include <iostream>
#include <string>

#include <cerrno>
#include <cstring>
#include <cstdio>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include "log.hpp"

static void Service_1(int serviceSock, const std::string& client_ip, const uint16_t& client_port)
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
        }
        else //s < 0 读取失败
        {
            LogMessage(ERROR, "read() error|[%s][%d]", __FILE__, __LINE__);
            exit(-1);
        }

        //和文件一样写入
        write(serviceSock, readBuff, strlen(readBuff));
    }
}

class TcpServer
{
private:
    const static int gBackLog = 20; //这个全局静态变量用就行，以后解释

public:
    TcpServer(uint16_t port, std::string ip = "")
        : _port(port), _ip(ip)
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
            Service_1(serviceSock, client_ip, client_port); //单进程循环版本

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
};