//sock.hpp（可以把本类看作一个关于 Sock 编程的工具包，只不过是让接口不会显得那么难用）
#pragma once

#include <string>

#include <cerrno>
#include <cstring>

#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>

#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>

#include <unistd.h> //主要是文件 IO 接口的头文件
#include <signal.h>

#include "log.hpp"

#define DEBUG_SHOW

class Sock
{
private:
    const int g_backlog = 20;

public:
    Sock() {}

    //套接字创建
    int Socket()
    {
        int listenSock = socket(AF_INET, SOCK_STREAM, 0);
        if (listenSock < 0)
        {
            LogMessage(FATAL, "socket() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(1);
        }
        LogMessage(NORMAL, "socket() sucess, listen sock: %d, %d %s %s %d", listenSock, errno, strerror(errno), __FILE__, __LINE__);
        return listenSock;
    }

    //套接字绑定
    void Bind(const int& listenSock, const uint16_t& server_port, const std::string& server_ip = "0.0.0.0")
    {
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local)); 
        local.sin_family = AF_INET; 
        local.sin_addr.s_addr = server_ip.empty() ? INADDR_ANY : inet_addr(server_ip.c_str());
        local.sin_port = htons(server_port);
        if (bind(listenSock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            LogMessage(FATAL, "bind() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(2);
        }
        LogMessage(NORMAL, "bind() sucess, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    }

    //套接字监听
    void Listen(const int& listenSock)
    {
        if (listen(listenSock, g_backlog) < 0)
        {
            LogMessage(FATAL, "listen() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            exit(3);
        }
        LogMessage(NORMAL, "listen() sucess, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
    }

    //接收客户端
    int Accept(const int& listenSock, std::string* client_ip, uint16_t* client_port)
    {
        struct sockaddr_in src;
        socklen_t len = sizeof(src);
        int serviceSock = accept(listenSock, (struct sockaddr*)&src, &len);
        if (serviceSock < 0)
        {
            LogMessage(ERROR, "accept() error, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
            return -1;
        }
        if (client_ip)
            *client_ip = inet_ntoa(src.sin_addr);
        if (client_port)
            *client_port = ntohs(src.sin_port);
        LogMessage(NORMAL, "accept() sucess, %d %s %s %d", errno, strerror(errno), __FILE__, __LINE__);
        return serviceSock;
    }

    //连接服务端
    bool Connect(const int& clientSock, const std::string &server_ip, const uint16_t &server_port)
    {
        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(server_port);
        server.sin_addr.s_addr = inet_addr(server_ip.c_str());

        if (connect(clientSock, (struct sockaddr*)&server, sizeof(server)) == 0)
            return true;
        else return
            false;
    }
};
