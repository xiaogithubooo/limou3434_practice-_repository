//tcp_server.hpp
#pragma once

#include <functional>
#include <vector>

#include <pthread.h>

#include "sock.hpp"
#include "log.hpp"

namespace ns_tcpserver
{
    using func_t = std::function<void(int)>;

    //线程任务参数包
    class TcpServer;
    class ThreadData
    {
    public:
        ThreadData(int sock, TcpServer* server) :
            _sock(sock), _server(server)
        {}
        ~ThreadData() {}

    public:
        int _sock;
        TcpServer* _server; //加上这个参数的原因在于，线程任务内部可以直接调用对应的方法
    };

    class TcpServer
    {
    private:
        //线程任务
        static void* ThreadRoutine(void* args)
        {
            pthread_detach(pthread_self());
            ThreadData* td = static_cast<ThreadData*>(args);
            td->_server->Excute(td->_sock);
            close(td->_sock);
            delete td;
            return nullptr;
        }

    public:
        //构造函数
        TcpServer(const uint16_t& port, const std::string& ip = "0.0.0.0")
        {
            _listenSock = _sock.Socket();
            _sock.Bind(_listenSock, port, ip);
            _sock.Listen(_listenSock);
        }

        //装载线程任务
        void BindServer(func_t func)
        {
            _funcs.push_back(func);
        }

        //执行线程任务
        void Excute(int sock)
        {
            for (auto& f : _funcs)
            {
                f(sock);
            }
        }

        //启动服务端
        void Start()
        {
            while (true)
            {
                std::string client_ip;
                uint16_t client_port;
                int sock = _sock.Accept(_listenSock, &client_ip, &client_port);
                if (sock < -1)
                    continue;
                LogMessage(NORMAL, "creat new link success, sock", sock);

                pthread_t tid = 0;
                ThreadData* td = new ThreadData(sock, this);
                pthread_create(&tid, nullptr, ThreadRoutine, td);
            }
        }

        //析构函数
        ~TcpServer()
        {
            if (_listenSock >= 0)
                close(_listenSock);
        }

    private:
        int _listenSock;
        Sock _sock;
        std::vector<func_t> _funcs;
    };
}
