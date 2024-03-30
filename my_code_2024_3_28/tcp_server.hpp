//tcp_server.hpp
/* 文件描述
主要是对 sock.hpp 的使用，构建一个可用的 TCP 服务端
*/

#pragma once
#include <functional>
#include <vector>
#include <pthread.h>
#include "sock.hpp"
#include "log.hpp"

class TcpServer
{
private:
    class ThreadData
    {
    public:
        ThreadData(int serviceSock, TcpServer* server) : _serviceSock(serviceSock), _server(server) {}
        ~ThreadData() {}

    public:
        int _serviceSock;
        TcpServer* _server;
    };

    using func_t = std::function<void(int)>;

private:
    void __Excute(int serviceSock)
    {
        for (auto& func : _funcs)
        {
            func(serviceSock); //执行任务列表中的所有任务
        }
    }

    static void* _ThreadRoutine(void* args)
    {
        pthread_detach(pthread_self()); //线程分离
        ThreadData* td = static_cast<ThreadData*>(args); //解包参数
        td->_server->__Excute(td->_serviceSock); //执行所有绑定的方法
        close(td->_serviceSock);
        delete td;
        return nullptr;
    }

public:
    //利用套接字工具包初始化套接字
    TcpServer(const uint16_t& port, const std::string& ip = "0.0.0.0")
    {
        _listensock = _sock._Socket();
        _sock._Bind(_listensock, port, ip);
        _sock._Listen(_listensock);
    }

    //给服务器绑定的一些 void(int) 类型的服务（PS：请在服务器启动之前绑定，该方法没有保证线程安全）
    void BindService(func_t func)
    {
        _funcs.push_back(func);
    }

    //启动 tcp 服务器
    void Start()
    {
        while(true) //不断获取新的服务套接字
        {
            std::string client_ip;
            uint16_t client_port;
            int serviceSock = _sock._Accept(_listensock, &client_ip, &client_port);
            if (serviceSock == -1)
            {
                continue;
            }
            else
            {
                _log.LogMessage(NORMAL, "creat new link success, sock %d, %s %d", serviceSock, __FILE__, __LINE__);

                //创建子线程，让子线程完成任务，一个线程分配一个服务套接字做服务
                pthread_t tid;
                ThreadData* td = new ThreadData(serviceSock, this);
                pthread_create(&tid, nullptr, _ThreadRoutine, td); //注意子线程内部做了线程分离，也自己做了 td 制作的释放
            }
        }
    }

    ~TcpServer()
    {
        if (_listensock >= 0)
            close(_listensock);
    }

private:
    Sock _sock; //套接字工具包
    int _listensock; //监听套接字
    std::vector<func_t> _funcs; //任务列表
    Log _log; //日志对象
};