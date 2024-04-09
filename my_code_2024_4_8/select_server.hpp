//select_server.hpp
#pragma once
#include <iostream>
#include <string>
#include <sys/select.h>
#include <cstdio>
#include "sock.hpp"
#include "log.hpp"

//select 只讲解读取，写入和异常之后提到 epoll 时再说
class SelectServer
{
private:
    void HandlerEvent(const fd_set& rfds) //rfds 是一个集合, 内部可能有多个标识符, 但是这里我们确保只有一个, 所以先这么写
    {
        if (FD_ISSET(_listensock, &rfds))
        {
            //成功走到这里就说明可以读取了, 已经获取了新连接
            std::string client_ip;
            uint16_t client_port;
            int sock = Sock::_Accept(_listensock, &client_ip, &client_port); //这里会不会被阻塞呢? 不会, 因为 IO事件/IO资源 已就绪

            if (sock < 0)
            {
                _log.LogMessage(WARNING, "accept error, %s %d", __FILE__, __LINE__);
                return;
            }

            _log.LogMessage(DEBUG, "get a new link success, %d->[%s:%d], %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);

            //TODO: read() and write()
        }
    }

public:
    SelectServer(const uint16_t &port = 8080)
    	: _port(port) 
    {
        _listensock = Sock::_Socket();
        Sock::_Bind(_listensock, _port);
        Sock::_Listen(_listensock);
        _log.LogMessage(DEBUG, "create base socket success, %s %d", __FILE__, __LINE__);
    }

    ~SelectServer()
    {
        if (_listensock >= 0)
            close(_listensock);
    }

    void Start()
    {
        fd_set rfds;
        FD_ZERO(&rfds);

        while (true)
        {
            //把 _listensock 的获取也看做 IO, 而如果没有获取到新链接, 也会导致阻塞
            //int sock = Sock::_Accept(_listensock, ...); //因此不能直接调用 _Accept(), 否则默认没有获取到新链接就进入阻塞
            FD_SET(_listensock, &rfds);
            //struct timeval timeout = { 5, 0 }; //每次都有需要设置, 因为是输入输出型参数
            //int n = select(_listensock + 1, &rfds, nullptr, nullptr, &timeout);
            int n = select(_listensock + 1, &rfds, nullptr, nullptr, nullptr);
            switch (n)
            {
                case 0: //超时
                    _log.LogMessage(DEBUG, "time out ..., %s %d", __FILE__, __LINE__);
                    break;
                case -1: //等待失败
                    _log.LogMessage(WARNING, "select error, %s %d", __FILE__, __LINE__);
                    break;
                default: //select 等待成功
                    _log.LogMessage(DEBUG, "get a new link, %s %d", __FILE__, __LINE__);
                    //必须把准备好的链接取走, 不让就会陷入死循环
                    HandlerEvent(rfds); //把就绪的描述符传递过去
                    break;
            }
        }
    }

private:
    uint16_t _port;
    int _listensock;
    Log _log;
};