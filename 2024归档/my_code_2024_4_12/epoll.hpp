#pragma once

#include <iostream>
#include <sys/epoll.h>

class Epoll
{
private:
    static const int g_size = 256;

public:
    static int CreateEpoll()
    {
        int epfd = epoll_create(g_size);
        if (epfd > 0)
            return epfd;
        return -1;
    }

    static bool CtrlEpoll(int epfd, int oper, int sock, uint32_t events)
    {
        struct epoll_event ev;
        ev.events = events;
        ev.data.fd = sock;
        int n = epoll_ctl(epfd, oper, sock, &ev);
        if (n == 0)
            return true;
        else
            return false;
    }

    static int WaitEpoll(int epfd, struct epoll_event revs[], int num, int timeout)
    {
        return epoll_wait(epfd, revs, num, timeout); //一次拿不完, 就会下一次再拿取
        //若有 n 个就绪, 会按照顺序将 n 个就绪描述符放入 revs 数组里, 因此遍历成本变低
    }
};
