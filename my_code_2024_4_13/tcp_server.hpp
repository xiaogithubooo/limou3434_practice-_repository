#pragma once
#include <string>
#include <functional>
#include <unordered_map>
#include <iostream>
#include "sock.hpp"
#include "epoll.hpp"

namespace limou
{
    class Connection; //类声明
    class TcpServer; //类声明

    using func_t = std::function<void(Connection*)>;

    
    /* 为了能够正常工作, 常规的 sock 必须是有自己的发送/接受缓冲区的, 本类专门用来封装描述符 */
    class Connection
    {
    public: 
        Connection(const int& sock, TcpServer* tsvr)
            : _sock(sock), _tsvr(nullptr)
        {}

        ~Connection() {}

        void SetCallBack(func_t recv_cb, func_t send_cb, func_t except_cb)
        {
            _recv_cb = recv_cb; //设置读回调
            _send_cb = send_cb; //设置写回调
            _except_cb = except_cb; //设置异常回调
        }

    private:
        //负责 IO 服务的文件描述符
        int _sock;

        //以下三个回调方法就是对 _sock 进行特定读写对应的方法
        func_t _recv_cb; //读回调
        func_t _send_cb; //写回调
        func_t _except_cb; //异常回调

        //发送/接受缓冲区(暂时无法处理二进制流, 先放着)
        std::string _inbuffer;
        std::string _outbuffer;

        //设置对 TcpServer 的回指指针
        TcpServer* _tsvr;
    };

    
    /* TcpServer 服务器的类 */
    class TcpServer
    {
    private:
        static const int g_port; //8080

    private:
        //专门针对任意的 sock 进行添加
        void _AddConnection(int sock, func_t recv_cb = nullptr, func_t send_cb = nullptr, func_t except_cb = nullptr)
        {
            Connection* conn = new Connection(sock, this);
            conn->SetCallBack(recv_cb, send_cb, except_cb);

            //将封装的 sock 添加到 epoll
            //(1)添加 sock 到 epoll 中
            _poll.AddSockToEpoll(sock, EPOLLIN | EPOLLET); //任何多路转接的服务器一般默认打开对读事件的关系, 写入事件按需进行设置(注意这里还设置成 ET 模式)
            //(2)添加封装的 sock 对象指针到 conns 集合中
            _conns[sock] = conn;
        }

    public:
        TcpServer(const int& port = g_port)
            : _listensock(Sock::_Socket())
            , _port(port)
            , _poll(Epoll())
        {
            Sock::_Bind(_listensock, _port);
            Sock::_Listen(_listensock);

            _AddConnection(_listensock/*...*/); //把描述符进行封装后添加管理
        }

        ~TcpServer()
        {

        }

    private:
        int _listensock;
        int _port;
        Epoll _poll;
        std::unordered_map<int, Connection*> _conns; //多个封装的连接就可以被一起在这里被管理
    };
    const int TcpServer::g_port = 8080; // 定义静态成员变量 g_port
}