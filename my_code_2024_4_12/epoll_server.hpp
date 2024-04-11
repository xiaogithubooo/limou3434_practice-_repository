//epoll_server.hpp
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "sock.hpp"
#include "epoll.hpp"
#include "log.hpp"

#define FD_NONE -1

class EpollServer
{
private:
    const int g_num_of_revs = 64;
    using func_t = std::function<void(std::string)>;
    
private:
    void ___Accepter(int listensock)
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

        //将新的套接字 insert 到红黑树种
        if (!Epoll::CtrlEpoll(_epfd, EPOLL_CTL_ADD, sock, EPOLLIN))
        {
            _log.LogMessage(DEBUG, "add new sock, %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);
        }
    }

    void ___Recver(const int& sock)
    {
        _log.LogMessage(DEBUG, "message in, get I/O event: %d, %s %d", sock, __FILE__, __LINE__);

        char buffer[1024] = { 0 };
        int n = recv(sock, buffer, sizeof(buffer) - 1, 0); //这里一定不会被阻塞, select() 已经将事件检测完毕, 在合法的描述符种, 一定有资源可以被读取
        //当然这里的读取是有点问题的, 因为 TCP 是面向字节流的, 无法保证数据完整, 必须配合应用层协议, 但是这里我们暂时不考虑这些

        if (n > 0) //正常读取
        {
            _log.LogMessage(DEBUG, "client-[%d] message >:%s, %s %d", sock, buffer, __FILE__, __LINE__);
            _HandlerRequest(buffer); //进一步处理客户端要求的业务逻辑
        }
        else if (n == 0) //对端关闭
        {
            _log.LogMessage(NORMAL, "client-[%d] quit, me too... %s %d", sock, __FILE__, __LINE__);
            //(1)把描述符从红黑树种去除(因为 epoll 有“只能去除‘合法’的描述符”)
            bool res = Epoll::CtrlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0);
            assert(res);
            //(2)服务器也需要关闭该描述符资源
            close(sock);
        }
        else //读取出错
        {
            _log.LogMessage(WARNING, "recv client-[%d] error, error text is %s, %s %d", sock, strerror(errno), __FILE__, __LINE__);
            //(1)把描述符从红黑树种去除(因为 epoll 有“只能去除‘合法’的描述符”)
            bool res = Epoll::CtrlEpoll(_epfd, EPOLL_CTL_DEL, sock, 0);
            assert(res);
            //(2)服务器也需要关闭该描述符资源
            close(sock);
        }
    }

    void __HanderEvents(int n)
    {
        assert(n > 0);
        for (int i = 0; i < n; i++) //TODO: ???
        {
            uint32_t revents = _revs[i].events;
            int sock = _revs[i].data.fd;

            //读事件就绪
            if (revents & EPOLLIN)
            {
                if (sock == _listensock)
                {
                    ___Accepter(_listensock);
                }
                else
                {
                    ___Recver(sock);
                }
            }
        }
    }

    void _LoopOnce()
    {
        int n = Epoll::WaitEpoll(_epfd, _revs, _num_of_revs, _timeout); //注意 _revs 是输出型参数
        switch (n)
        {
        case 0:
            _log.LogMessage(DEBUG, "timeout..., %s %d", __FILE__, __LINE__);
            break;
        case -1:
            _log.LogMessage(WARNING, "epoll wait error, %s %d", __FILE__, __LINE__);
            break;
        default:
            _log.LogMessage(DEBUG, "get a event, %s %d", __FILE__, __LINE__);
            __HanderEvents(n); //注意 _revs 是输出型参数, 也是类内成员, 因此只需要传递 n 即可
            break;
        }
    }

public:
    EpollServer(func_t handlerRequest, const uint16_t& port = 8080)
        : _port(port), _timeout(1000), _num_of_revs(g_num_of_revs), _HandlerRequest(handlerRequest)
    {
        _revs = new struct epoll_event[_num_of_revs]; //TODO: 可以设置为扩容机制

        _listensock = Sock::_Socket();
        Sock::_Bind(_listensock, _port);
        Sock::_Listen(_listensock);

        _epfd = Epoll::CreateEpoll();
        if (_epfd < 0)
        {
            _log.LogMessage(WARNING, "create epfd error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }

        //可以预测到文件描述符打印出来的应该是 3 和 4
        _log.LogMessage(DEBUG, "create socket success, listensock=%d, epfd=%d, %s %d", _listensock, _epfd, __FILE__, __LINE__);

        //把 _listensock 添加进 epoll, 等待连接成功再调用 IO
        if (Epoll::CtrlEpoll(_epfd, EPOLL_CTL_ADD, _listensock, EPOLLIN))
        {
            //思考: 可不可以把 _epfd 自己也加入呢?
            _log.LogMessage(DEBUG, "CtrlEpoll() success, %s %d", __FILE__, __LINE__);
        }
        else
        {
            _log.LogMessage(WARNING, "CtrlEpoll() error, %s %d", __FILE__, __LINE__);
            exit(-1);
        }
    }

    ~EpollServer()
    {
        if (_listensock >= 0)
            close(_listensock);
        if (_epfd >= 0)
            close(_epfd);
        if (_revs)
            delete[] _revs;
    }

    void Start()
    {
        //多路转接编码原则: 在不清楚资源就绪时, 不要使用 IO 接口
        while (true)
        {
            _LoopOnce();
        }
    }

    void DebugPrint()
    {

    }

private:
    uint16_t _port;
    int _listensock;

    int _epfd;
    int _timeout;

    struct epoll_event* _revs; //就绪描述符资源
    int _num_of_revs; //其容量决定一次返回的描述符资源, 可以尝试扩容

    func_t _HandlerRequest;
    
    Log _log;
};