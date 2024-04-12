//epoll.hpp

/* 文件描述
定义了关于 epoll 的初始化工作和操作接口的类, 默认 epoll 是 LT 模式, 需要使用 ET 模式则需要单独在每个事件中设置
limou::Epoll(timeout = g_timeout);      //可以为模型设置超时时间
limou::Epoll().AddSockToEpoll();        //添加需要关注对应事件的描述符
limou::Epoll().WaitEpoll();             //取得就绪关注对应事件的描述符的个数 n, 结合 revs 数组和 n 来获取对应的描述符和其事件情况
*/

#pragma once
#include <iostream>
#include <sys/epoll.h>

namespace limou
{
    /* Epoll 模型的相关操作 */
    class Epoll
    {
    private:
        static const int g_size; //256
        static const int g_timeout; //5000

    public:
        //创建 epoll 模型, 并且返回其 fd, 同时设置超时时间
        Epoll(int timeout = g_timeout)
            : _timeout(timeout)
        {
            _epfd = epoll_create(g_size);
            if (_epfd < 0)
                exit(-1);
        }

        //把套接字添加到 epoll 中, 关注其 events 事件
        bool AddSockToEpoll(int sock, uint32_t events)
        {
            struct epoll_event ev;
            ev.events = events;
            ev.data.fd = sock;
            int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev);
            return n == 0;
        }

        //从 epoll 模型中获取就绪的套接字的个数 n, 根据 revs[0-n] 来获取对应的
        //(1)套接字 revs[i].fd
        //(2)事件 revs[i].events
        int WaitEpoll(struct epoll_event revs[], int num) //revs 是输出型参数
        {
            int n = epoll_wait(_epfd, revs, num, _timeout);
            return n; //返回就绪套接字的个数
        }

        bool CtrlEpoll(int sock, uint32_t events)
        {
            events |= EPOLLET; //自动加上 ET 工作模式

            struct epoll_event ev;
            ev.events = events; //需要添加的事件
            ev.data.fd = sock;

            int n = epoll_ctl(_epfd, EPOLL_CTL_MOD, sock, &ev);

            return n == 0;
        }

        bool DelFromEpoll(int sock)
        {
            int n = epoll_ctl(_epfd, EPOLL_CTL_DEL, sock, nullptr);
            return n == 0;
        }

    private:
        int _epfd; //epoll 模型返回的 fd
        int _timeout; //超时事件
    };
    
    const int Epoll::g_size = 256;
    const int Epoll::g_timeout = 5000;
}