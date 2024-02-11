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

class TcpServer
{
private:
    const static int gBackLog = 20; //这个全局静态变量用就行，以后解释

public:
    TcpServer(uint16_t port, std::string ip = "")
        : _port(port), _ip(ip)
    {
        //1.创建套接字
        _sock = socket(
            AF_INET, //套接字类型
            SOCK_STREAM, //通信类型（TCP），流式套接字和文件描述符的理解几乎一样
            0 //协议类别
        );
        if (_sock < 0) //套接字创建失败
        {
            LogMessage(FATAL, "socket() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
            exit(-1);
        }
        LogMessage(NORMAL, "create sock value:%d", _sock, __FILE__, __LINE__); //这里输出 _sock 原因是检验其和文件描述符的相似性
            
        //2.绑定套接字
        struct sockaddr_in local; memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str());
        if (bind(
            _sock, //获取到的套接字标识符
            (struct sockaddr*)&local, //套接字结构体
            sizeof(local) //传入的对象结构体的字节长度
        ) < 0)
        {
            LogMessage(FATAL, "bind() error, %d:%s|[%s][%d]", errno, strerror(errno), __FILE__, __LINE__);
            exit(-1);
        }

        //3.建立链接（TCP 是面向链接的，在建立链接之前，服务端需要进入一个等待状态，或者说设置为监听状态）
        if (listen(_sock, //套接字标识符
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
            std::cout << "server~~" << std::endl;
            sleep(1);
        }
    }
    
    ~TcpServer()
    {
        
    }

private:
    uint16_t _port;
    std::string _ip;
    int _sock;
};