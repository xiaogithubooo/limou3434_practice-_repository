//connection.hpp

/* 文件描述
内含对套接字封装的类, 可以做到:
(1)让描述符具有单独的输入输出缓冲区
(2)并且实例化对象可以通过调用 SetCallBack() 设置以及对应的读写异常回调
(3)让该对象通过 TcpServer* _tsvr 跳转回使用套接字的服务器对象上, 方便一些编码操作
*/

#pragma once
#include <functional>

namespace limou
{
    //TODO: 可以修改为现有的 HTTP 协议和 JSON 序列化, 而不必自定义

    //类声明
    class TcpServer;

    /* 为了能够正常工作, 常规的 sock 必须是有自己的发送/接受缓冲区的, 本类专门用来封装描述符 */
    class Connection
    {
    private:
        using func_t = std::function<void(Connection*)>;

    public:
        //封装套接字, 并且保存使用该对象的服务器对象指针信息
        Connection(const int& sock = -1, TcpServer* tsvr = nullptr) : _sock(sock), _tsvr(tsvr) {}

        //设置套接字的读写异常回调方法
        void SetCallBack(func_t recv_cb, func_t send_cb, func_t except_cb)
        {
            _recv_cb = recv_cb; //设置读回调
            _send_cb = send_cb; //设置写回调
            _except_cb = except_cb; //设置异常回调
        }

    public:
        //负责 IO 服务的文件描述符
        int _sock;

        //以下三个回调方法就是对 _sock 进行特定读写对应的方法
        func_t _recv_cb; //读回调
        func_t _send_cb; //写回调
        func_t _except_cb; //异常回调

        //发送/接受缓冲区(暂时无法处理二进制流, 先放着), 一般为了保证每一个套接字都完整读取，应对每一个套接字设置单独的缓冲区
        std::string _inbuffer;
        std::string _outbuffer;

        //设置对 TcpServer 的回指指针
        TcpServer* _tsvr;

        //拓展定制链接管理功能(获取时间戳)
        uint64_t _lastTimeStamp;
    };
}