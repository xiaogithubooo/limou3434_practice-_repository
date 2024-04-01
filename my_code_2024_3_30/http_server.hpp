//http_server.hpp

/* 文件描述
使用 sock.hpp 工具包进一步封装的 HTTP 服务端
*/

#pragma once
#include <signal.h>
#include <functional>
#include "sock.hpp"
#include "log.hpp"

class HttpServer
{
private:
    using func_t = std::function<void(int)>;

public:
    HttpServer(const uint16_t& port, func_t func)
        : _port(port), _func(func)
    {
        _listenSock = _sock._Socket();
        _sock._Bind(_listenSock, _port);
        _sock._Listen(_listenSock);
    }

    void Start()
    {
        signal(SIGCHLD, SIG_IGN);
        while (true)
        {
            std::string client_ip;
            uint16_t client_port = 0;
            int serviceSock = _sock._Accept(_listenSock, &client_ip, &client_port);
            if (fork() == 0)
            {
                close(_listenSock);
                _func(serviceSock);
                exit(0);
            }
            close(serviceSock);
        }
    }

    ~HttpServer()
    {
        if (_listenSock >= 0)
            close(_listenSock);
    }

private:
    int _listenSock;
    uint16_t _port;
    Sock _sock;
    func_t _func;
};