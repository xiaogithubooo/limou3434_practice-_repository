#pragma once
#include <iostream>
#include <sys/epoll.h>

namespace limou
{
    class Epoll
    {
    private:
        static const int g_size; //256

    public:
        Epoll()
        {
            _epfd = epoll_create(g_size);
            if (_epfd < 0)
                exit(-1);
        }

        //把套接字添加到 epoll 中
        bool AddSockToEpoll(int sock, uint32_t events)
        {
            struct epoll_event ev;
            ev.events = events;
            ev.data.fd = sock;
            int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev);
            return n == 0;
        }

    private:
        int _epfd;
    };
    const int Epoll::g_size = 256;
}