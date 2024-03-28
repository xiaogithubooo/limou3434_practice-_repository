//socket.hpp
#pragma once
#include <memory>
#include <sys/types.h> //套接字编程的头文件
#include <sys/socket.h>
#include <netinet/in.h> //转化字节序的头文件
#include <arpa/inet.h>
#include <cstring>
#include "log.hpp"

#define DEBUG_SHOW

class ThreadData
{
public:
    int _sock;
    std::string _ip;
    uint16_t _port;
};

class Sock
{
private:
    const static int g_backlog = 20; //一般不会太大，也不会太小

public:
    int _Socket()
    {
        int listenSock = socket(AF_INET, SOCK_STREAM, 0);
        if (listenSock < 0)
        {
            _log.LogMessage(FATAL, "socket() error %s %d", __FILE__, __LINE__);
            exit(1);
        }
        return listenSock;
    }

    void _Bind(int listenSock, uint16_t port, std::string ip = "0.0.0.0")
    {
        struct sockaddr_in local;
        memset(&local, 0, sizeof local);
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &local.sin_addr);

        if (bind(listenSock, (struct sockaddr*)&local, sizeof(local)) < 0)
        {
            _log.LogMessage(FATAL, "bind() error %s %d", __FILE__, __LINE__);
            exit(2);
        }
    }

    void _Listen(int listenSock)
    {
        if (listen(listenSock, g_backlog) < 0)
        {
            _log.LogMessage(FATAL, "listen() error %s %d", __FILE__, __LINE__);
            exit(3);
        }
        _log.LogMessage(NORMAL, "listen() success %s %d", __FILE__, __LINE__);
    }

    int _Accept(int listenSock, std::string* ip, uint16_t* port) //注意是输出型参数
    {
        struct sockaddr_in src;
        socklen_t len = sizeof(src);
        int serviceSock = accept(listenSock, (struct sockaddr*)&src, &len);
        if (serviceSock < 0)
        {
            _log.LogMessage(FATAL, "listen() error %s %d", __FILE__, __LINE__);
            return -1;
        }
        *port = ntohs(src.sin_port);
        *ip = inet_ntoa(src.sin_addr);
        return serviceSock;
    }

    Sock() {}

private:
    Log _log;
};