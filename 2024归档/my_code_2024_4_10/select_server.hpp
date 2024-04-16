//select_server.hpp
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sys/select.h>
#include <cstdio>
#include <cstring>
#include "sock.hpp"
#include "log.hpp"

#define BIT_NUM_OF_BYT 8
#define NUM_OF_FDS BIT_NUM_OF_BYT * sizeof(fd_set)
#define FD_NONE -1

//select 暂时只讲解读取事件，写入和异常之后提到 epoll 时再说
class SelectServer
{
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

        //注意这里不能直接 read() and write(), 万一对方一直不发送数据过来就一直读取不了, 陷入阻塞
        //因此将新的 sock 托管给 select(), 让其检查其上是否有新的数据就绪, 再进行阻塞

        int pos = 1; //初始设置为 1, 因为我们约定第一个标识符是监听套接字
        for (; pos < NUM_OF_FDS; pos++) //该循环的目的是一直走到可以被填充新描述符的 pos 索引
        {
            if (_fds[pos] == FD_NONE)
                break;
        }
        if (pos == NUM_OF_FDS) //超出 _fds 数组的大小, 说明服务器的描述符资源已经不足
        {
            _log.LogMessage(WARNING, "select server already full, close, %d, %s %d", sock, client_ip.c_str(), client_port, __FILE__, __LINE__);
            close(sock);
        }
        else
        {
            _fds[pos] = sock; //把获取到的服务套接字添加进合法数组 _fds 内, 等到本调用结束后进入主循环, 再次被 seletc() 托管即可
        }
    }

    void __Recver(int& a_fd)
    {
        //读事件就绪: INPUT 事件到来, 需要 recv() 或 read()
        _log.LogMessage(DEBUG, "message in, get I/O event: %d, %s %d", a_fd, __FILE__, __LINE__);
        char buffer[1024] = { 0 };
        int n = recv(a_fd, buffer, sizeof(buffer) - 1, 0); //这里一定不会被阻塞, select() 已经将事件检测完毕, 在合法的描述符种, 一定有资源可以被读取
        //当然这里的读取是有点问题的, 因为 TCP 是面向字节流的, 无法保证数据完整, 必须配合应用层协议, 但是这里我们暂时不考虑这些

        if (n > 0) //正常读取
        {
            _log.LogMessage(DEBUG, "client-[%d] message >:%s, %s %d", a_fd, buffer, __FILE__, __LINE__);
        }
        else if (n == 0) //对端关闭
        {
            _log.LogMessage(DEBUG, "client-[%d] quit, %s %d", a_fd, __FILE__, __LINE__);
            //(1)服务器也需要关闭该描述符资源
            close(a_fd);
            //(2)从合法描述符种去除, 后续 select() 就不会关注该描述符
            a_fd = FD_NONE;
        }
        else //读取出错
        {
            _log.LogMessage(WARNING, "recv client-[%d] error, error text is %s, %s %d", a_fd, strerror(errno), __FILE__, __LINE__);
            //(1)服务器也需要关闭该描述符资源
            close(a_fd);
            //(2)从合法描述符种去除, 后续 select() 就不会关注该描述符
            a_fd = FD_NONE;
        }
    }

    void _HandlerEvent(const fd_set& rfds) //rfds 是一个集合, 内部可能有多个、多种标识符
    {
        //这个函数被调用, 就说明至少有一个标识符资源可以被使用了
        //先提取出需要 link 和 read 的描述符
        for (int i = 0; i < NUM_OF_FDS; i++)
        {
            //先排除不合法的描述符
            if (_fds[i] == FD_NONE)
            {
                continue;
            }

            //判定一个合法描述符是否就绪
            if (FD_ISSET(_fds[i], &rfds))
            {
                //走到这里的描述符合法且就绪, 但是不一定是需要 read 的描述符, 因此需要区分开做处理
                if (_fds[i] == _listensock)
                {
                    //读事件就绪: 链接时间到来
                    __Accepter(); //让其链接即可, 让新的合法标识符加入
                }
                else
                {
                    __Recver(_fds[i]);
                }
            }
        }
    }

public:
    SelectServer(const uint16_t& port = 8080)
        : _port(port)
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
            DebugPrint(); //打印所有合法的描述符(注意这些描述符不一定是就绪的)

            //初始化需要被 select() 管理的描述符集合
            fd_set rfds;
            FD_ZERO(&rfds);
            int maxFd = _listensock;

            //将当前所有的合法描述符添加到需要被 seletc() 管理的集合中
            for (int i = 0; i < NUM_OF_FDS; i++)
            {
                if (_fds[i] == FD_NONE)
                    continue;

                FD_SET(_fds[i], &rfds);

                if (maxFd < _fds[i])
                    maxFd = _fds[i];
            }

            //将当前集合内的描述符都添加到 select() 的管理范畴中
            int n = select(maxFd + 1, &rfds, nullptr, nullptr, nullptr);

            //根据 select() 的返回值做不同的反应
            switch (n)
            {
            case 0: //超时(不过我暂时没有设定超时机制, 只要没有标识符资源可用我就阻塞)
                _log.LogMessage(DEBUG, "time out ..., %s %d", __FILE__, __LINE__);
                break;
            case -1: //等待失败
                _log.LogMessage(WARNING, "select error, %s %d", __FILE__, __LINE__);
                break;
            default: //select 等待成功, 有描述符资源可以使用了!
                _log.LogMessage(DEBUG, "get a new link, %s %d", __FILE__, __LINE__);
                //必须把准备好的链接取走, 不让就会陷入死循环
                _HandlerEvent(rfds); //把就绪的描述符传递过去
                break;
            }
        }
    }

    void DebugPrint()
    {
        std::cout << "_fds[]: " << std::endl;
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
    int _fds[NUM_OF_FDS]; //合法数组, 内部存储所有被申请到的套接字
};