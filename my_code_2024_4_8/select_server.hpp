//select_server.hpp
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sys/select.h>
#include <cstdio>
#include "sock.hpp"
#include "log.hpp"

#define BIT_NUM_OF_BYT 8
#define NUM_OF_FDS BIT_NUM_OF_BYT * sizeof(fd_set)
#define FD_NONE -1
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

            //注意这里不能直接 read() and write(), 万一对方一直不发送数据过来就一直读取不了, 陷入阻塞
            //因此将新的 sock 托管给 select(), 让其检查其上是否有新的数据就绪, 在进行阻塞
            //由于文件描述符有可能会越来越大, 因此这里就必须动态调用 select()
            //并且 select() 的使用会导致曾经被操作系统关注的描述符, 因此就注定每一次调用时, 都有可能需要重新添加曾经关注的描述符
            //最终导致可能需要:
            //(1)需要单独保存一个第三方数组, 保存历史上所有的合法 fd, 根据需求动态添加到位图中
            //(2)遍历描述符数组, 动态找出最大的 max_fd

            int pos = 0;
            for (pos = 0; pos < NUM_OF_FDS; pos++)
            {
                if (_fds[pos] == FD_NONE)
                    break;
            }
            if (pos == NUM_OF_FDS) //服务器的描述符资源不足
            {
                _log.LogMessage(WARNING, "select server already full, close, %d, %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);
                close(sock);
            }
            else
            {
                _fds[pos] = sock; //添加后, 等到本调用结束后进入主循环, 再次使用 seletc() 即可
            }
        }
    }

public:
    SelectServer(const uint16_t &port = 8080)
        :  _port(port) 
    {
        _listensock = Sock::_Socket();
        Sock::_Bind(_listensock, _port);
        Sock::_Listen(_listensock);
        _log.LogMessage(DEBUG, "create base socket success, %s %d", __FILE__, __LINE__);
        for (auto& fd : _fds)
            fd = FD_NONE;

        //我约定: _fds[0] = _listensock, 因为改套接字一般不变动
        _fds[0] = _listensock;
    }

    ~SelectServer()
    {
        if (_listensock >= 0)
            close(_listensock);
    }

    void Start()
    {
        while (true)
        {
            //把 _listensock 的获取也看做 IO, 而如果没有获取到新链接, 也会导致阻塞
            //int sock = Sock::_Accept(_listensock, ...); //因此不能直接调用 _Accept(), 否则默认没有获取到新链接就进入阻塞
            //FD_SET(_listensock, &rfds);
            //struct timeval timeout = { 5, 0 }; //每次都有需要设置, 因为是输入输出型参数
            //int n = select(_listensock + 1, &rfds, nullptr, nullptr, &timeout);
            //int n = select(_listensock + 1, &rfds, nullptr, nullptr, nullptr);
            DebugPrint();
            
            fd_set rfds;
            FD_ZERO(&rfds);
            int maxFd = _listensock;
            for (auto& fd : _fds)
            {
                if (fd == FD_NONE)
                    continue;
                
                FD_SET(fd, &rfds);

                if (maxFd < fd)
                    maxFd = fd;
            }

            int n = select(maxFd + 1, &rfds, nullptr, nullptr, nullptr);

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

    void DebugPrint()
    {
        std::cout << "_fds: " << std::endl;
        for (const auto& fd : _fds)
        {
            if (fd != FD_NONE)
                std::cout << fd << " ";
        }
        std::cout << std::endl;
    }

private:
    uint16_t _port;
    int _listensock;
    Log _log;
    int _fds[NUM_OF_FDS];
};