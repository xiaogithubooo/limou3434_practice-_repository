//sock.hpp

/* 文件描述
主要是对套接字编程的常见接口做封装，是一个关于套接字的静态方法工具包
Sock::_Socket()
Sock::_Bind()
Sock::_Listen()
Sock::_Accept()
Sock::_Connect()
Sock::_SetNonBlock()
*/

#pragma once
#include <memory>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "log.hpp"

namespace limou
{
    class Sock
    {
    private:
        const static int g_backlog; //10, 一般不会太大也不会太小

    public:
        //空的构造函数
        Sock() {}

        //创建监听套接字
        static int _Socket()
        {
            int listenSock = socket(AF_INET, SOCK_STREAM, 0);
            if (listenSock < 0)
            {
                _log.LogMessage(FATAL, "socket() error %s %d", __FILE__, __LINE__);
                exit(1);
            }
            _log.LogMessage(NORMAL, "socket() success %s %d", __FILE__, __LINE__);
            return listenSock;
        }

        //绑定监听套接字
        static void _Bind(int listenSock, uint16_t port, std::string ip = "127.0.0.1")
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
            _log.LogMessage(NORMAL, "bind() success %s %d", __FILE__, __LINE__);
        }

        //置套接字监听状态
        static void _Listen(int listenSock)
        {
            if (listen(listenSock, g_backlog) < 0)
            {
                _log.LogMessage(FATAL, "listen() error %s %d", __FILE__, __LINE__);
                exit(3);
            }
            _log.LogMessage(NORMAL, "listen() success %s %d", __FILE__, __LINE__);
        }

        //服务端等待连接后, 返回服务套接字（参数还带有服务端的信息）
        static int _Accept(int listenSock, std::string* ip, uint16_t* port, int* accept_errno)
        {
            struct sockaddr_in src;
            socklen_t len = sizeof(src);
            *accept_errno = 0;
            int serviceSock = accept(listenSock, (struct sockaddr*)&src, &len);
            if (serviceSock < 0)
            {
                _log.LogMessage(FATAL, "accept() error %s %d", __FILE__, __LINE__);
                *accept_errno = errno; //把错误码设置为输出型参数
                return -1;
            }
            _log.LogMessage(NORMAL, "accept() success %s %d", __FILE__, __LINE__);

            *port = ntohs(src.sin_port);
            *ip = inet_ntoa(src.sin_addr);

            return serviceSock;
        }

        //客户端主动连接服务端
        static bool _Connect(int sock, const std::string& server_ip, const uint16_t& server_port)
        {
            struct sockaddr_in server;
            memset(&server, 0, sizeof(server));
            server.sin_family = AF_INET;
            server.sin_port = htons(server_port);
            server.sin_addr.s_addr = inet_addr(server_ip.c_str());

            if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0)
            {
                _log.LogMessage(NORMAL, "accept() success %s %d", __FILE__, __LINE__);
                return true;
            }

            _log.LogMessage(FATAL, "connect() error %s %d", __FILE__, __LINE__);
            return false;
        }

        //设置套接字为非阻塞
        static bool _SetNonBlock(int sock)
        {
            int fl = fcntl(sock, F_GETFL);
            if (fl < 0)
                return false;
            fcntl(sock, F_SETFL, fl | O_NONBLOCK);
            return true;
        }

    private:
        static Log _log;
    };

    const int Sock::g_backlog = 10;
    Log Sock::_log = Log();
}