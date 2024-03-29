//tcp_server.hpp
/* 文件描述
主要是对 sock.hpp 的使用，构建一个可用的服务端类
*/

#pragma once
#include <functional>
#include <vector>
#include <pthread.h>
#include "sock.hpp"
#include "log.hpp"

class TcpServer
{
private: //定义一些类型
    class ThreadData
    {
    public:
        ThreadData(int serviceSock, TcpServer* server)
            : _serviceSock(serviceSock), _server(server)
        {}
        ~ThreadData()
        {}
    public:
        int _serviceSock;
        TcpServer* _server;
    };

    using func_t = std::function<void(int)>;

private: //定义一些私有函数
    void __Excute(int serviceSock)
    {
        for (auto& func : _funcs)
        {
            func(serviceSock);
        }
    }

    static void* _ThreadRoutine(void* args)
    {
        pthread_detach(pthread_self());
        ThreadData* td = static_cast<ThreadData*>(args);
        td->_server->__Excute(td->_serviceSock); //执行所有绑定的方法
        close(td->_serviceSock);
        delete td;
        return nullptr;
    }

public: //定义一些公有函数
    TcpServer(const uint16_t& port, const std::string& ip = "0.0.0.0")
    {
        _listensock = _sock._Socket();
        _sock._Bind(_listensock, port, ip);
        _sock._Listen(_listensock);
    }

    void BindService(func_t func)
    {
        _funcs.push_back(func); //给服务器绑定的服务
    }

    void Start()
    {
        while(true) //不断获取新的服务套接字
        {
            std::string client_ip;
            uint16_t client_port;
            int serviceSock = _sock._Accept(_listensock, &client_ip, &client_port);
            if (serviceSock == -1)
                continue;
            _log.LogMessage(NORMAL, "creat new link success, sock %d, %s %d", serviceSock, __FILE__, __LINE__);

            pthread_t tid;
            ThreadData* td = new ThreadData(serviceSock, this);
            pthread_create(&tid, nullptr, _ThreadRoutine, td); //内部做了线程分离，内部自己做了 td 的释放
        }
    }

    ~TcpServer()
    {
        if (_listensock >= 0)
            close(_listensock);
    }

private:
    int _listensock;
    Sock _sock;
    std::vector<func_t> _funcs;
    Log _log;
};