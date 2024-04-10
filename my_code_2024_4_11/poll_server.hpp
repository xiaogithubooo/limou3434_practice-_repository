//poll_server.hpp
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <poll.h>
#include <cstdio>
#include <cstring>
#include "sock.hpp"
#include "log.hpp"

#define FD_NONE -1

class PollServer
{
private:
    static const nfds_t g_num_of_fds = 100;

private:
    void __Accepter()
    {
        //现在就不用判断 _listensock 是否就绪了
        std::string client_ip;
        uint16_t client_port = 0;
        int sock = Sock::_Accept(_listensock, &client_ip, &client_port); //这里会不会被阻塞呢? 不会, 因为 IO事件/IO资源 已就绪

        if (sock < 0)
        {
            _log.LogMessage(WARNING, "accept error, %s %d", __FILE__, __LINE__);
            return;
        }

        _log.LogMessage(DEBUG, "get a new link success, %d->[%s:%d], %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);

        int pos = 1; //初始设置为 1, 因为我们约定第一个标识符是监听套接字
        for (; pos < _num_of_fds; pos++) //该循环的目的是一直走到可以被填充新描述符的 pos 索引
        {
            if (_fds[pos].fd == FD_NONE)
                break;
        }
        if (pos == _num_of_fds) //超出 _fds 数组的大小, 说明服务器的描述符资源已经不足
        {
            //TODO: 如果超出上限了, 这里可以进行自动扩容
            _log.LogMessage(WARNING, "poll server already full, close, %d, %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);
            close(sock);
        }
        else
        {
            _fds[pos].fd = sock; //把获取到的服务套接字添加进合法描述符集合 _fds 内, 等到本调用结束后进入主循环, 再次被 poll() 托管即可
            _fds[pos].events = POLLIN; //让操作系统也关注这个标识
        }
    }

    void __Recver(int pos)
    {
        //读事件就绪: INPUT 事件到来, 需要 recv() 或 read()
        _log.LogMessage(DEBUG, "message in, get I/O event: %d, %s %d", _fds[pos].fd, __FILE__, __LINE__);

        char buffer[1024] = { 0 };
        int n = recv(_fds[pos].fd, buffer, sizeof(buffer) - 1, 0); //这里一定不会被阻塞, select() 已经将事件检测完毕, 在合法的描述符种, 一定有资源可以被读取
        //当然这里的读取是有点问题的, 因为 TCP 是面向字节流的, 无法保证数据完整, 必须配合应用层协议, 但是这里我们暂时不考虑这些

        if (n > 0) //正常读取
        {
            _log.LogMessage(DEBUG, "client-[%d] message >:%s, %s %d", _fds[pos].fd, buffer, __FILE__, __LINE__);
        }
        else if (n == 0) //对端关闭
        {
            _log.LogMessage(DEBUG, "client-[%d] quit, %s %d", _fds[pos].fd, __FILE__, __LINE__);
            //(1)服务器也需要关闭该描述符资源
            close(_fds[pos].fd);
            //(2)从合法描述符种去除, 后续 select() 就不会关注该描述符
            _fds[pos].fd = FD_NONE;
            _fds[pos].events = 0;
        }
        else //读取出错
        {
            _log.LogMessage(WARNING, "recv client-[%d] error, error text is %s, %s %d", _fds[pos].fd, strerror(errno), __FILE__, __LINE__);
            //(1)服务器也需要关闭该描述符资源
            close(_fds[pos].fd);
            //(2)从合法描述符种去除, 后续 select() 就不会关注该描述符
            _fds[pos].fd = FD_NONE;
            _fds[pos].events = 0;
        }
    }

    void _HandlerEvent()
    {
        //这个函数被调用, 就说明至少有一个标识符资源可以被使用了
        //先提取出需要 link 和 read 的描述符
        for (int i = 0; i < _num_of_fds; i++)
        {
            //先排除不合法的描述符
            if (_fds[i].fd == FD_NONE)
            {
                continue;
            }

            //判定一个合法描述符是否就绪
            if (_fds[i].revents & POLLIN)
            {
                //走到这里的描述符合法且就绪, 但是不一定是需要 read 的描述符, 因此需要区分开做处理
                if (_fds[i].fd == _listensock)
                {
                    //读事件就绪: 链接时间到来
                    __Accepter(); //让其链接即可, 让新的合法标识符加入
                }
                else
                {
                    __Recver(i);
                }
            }
        }
    }

public:
    PollServer(const uint16_t& port = 8080)
        : _port(port), _num_of_fds(g_num_of_fds), _timeout(1000)
    {
        _listensock = Sock::_Socket();
        Sock::_Bind(_listensock, _port);
        Sock::_Listen(_listensock);
        _log.LogMessage(DEBUG, "create base socket success, %s %d", __FILE__, __LINE__);

        _fds = new struct pollfd[_num_of_fds];
        for (int i = 0; i < _num_of_fds; i++)
        {
            _fds[i].fd = FD_NONE;
            _fds[i].events = 0;
            _fds[i].revents = 0;
        }
        _fds[0].fd = _listensock;
        _fds[0].events = POLLIN; //关心读取事件
    }

    ~PollServer()
    {
        if (_listensock >= 0)
            close(_listensock);
        if (_fds)
            delete[] _fds;
    }

    void Start()
    {
        while (true)
        {
            DebugPrint();

            //将当前集合内的描述符都添加到 poll() 的管理范畴中
            int n = poll(_fds, _num_of_fds, _timeout);

            //根据 poll() 的返回值做不同的反应
            switch (n)
            {
            case 0: //超时(不过我暂时没有设定超时机制, 只要没有标识符资源可用我就阻塞)
                _log.LogMessage(DEBUG, "time out ..., %s %d", __FILE__, __LINE__);
                break;
            case -1: //等待失败
                _log.LogMessage(WARNING, "poll error, %s %d", __FILE__, __LINE__);
                break;
            default: //poll 等待成功, 有描述符资源可以使用了!
                _log.LogMessage(DEBUG, "get a new link, %s %d", __FILE__, __LINE__);
                //必须把准备好的链接取走, 不让就会陷入死循环
                _HandlerEvent(); //把就绪的描述符传递过去
                break;
            }
        }
    }

    void DebugPrint()
    {
        std::cout << "_fds[]: " << std::endl;
        for (int i = 0; i < _num_of_fds; i++)
        {
            if (_fds[i].fd != FD_NONE)
                std::cout << _fds[i].fd << " ";
        }
        std::cout << std::endl;
    }

private:
    uint16_t _port;
    int _listensock;
    struct pollfd* _fds; //合法描述符的信息集合
    nfds_t _num_of_fds; //nfds_t 实际上就是一个整型
    int _timeout;
    Log _log;
};