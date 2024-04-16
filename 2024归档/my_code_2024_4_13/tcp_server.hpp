//tcp_server.hpp

/* 文件描述
使用多个模块构建的基于 ET-Epoll-Tcp 的高并发服务器
TcpServer svr(port);
svr.Dispather();
svr.EnableReadWrite();
*/

#pragma once
#include <string>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cerrno>
#include <cassert>
#include <ctime>
#include "log.hpp"
#include "sock.hpp"
#include "connection.hpp"
#include "epoll.hpp"
#include "protocol.hpp"

namespace limou
{
    /* 描述 TcpServer 服务器的类 */
    //TODO: 可以把这个服务器对象设计为单例模式
    class TcpServer
    {
    private:
        using func_t = std::function<void(Connection*)>;
        using callback_t = std::function<void(Connection*, std::string& request)>;
        static const int g_port; //8080
        static const int g_num_of_revs; //128

    private:
        //再次封装 epoll 的 AddSockToEpoll() 方法, 专门针对任意的 sock 进行事件关注
        //(1)保证每一个套接字处于 ET 工作模式, 并且保证描述符处于非阻塞模式
        //(2)定制化该套接字的读写异常回调
        //(3)把描述符通过 AddSockToEpoll() 添加到 epoll 模型中
        //(4)封装的标识符通过 kv 树的方式交付给调用者, 调用者得到就绪描述符可根据 kv 关系调用对应的读写异常回调
        void _AddConnection(int sock, func_t recv_cb = nullptr, func_t send_cb = nullptr, func_t except_cb = nullptr)
        {
            //先直接设置套接字为非阻塞
            Sock::_SetNonBlock(sock);

            //封装套接字对象, 并且设置其对应的读写回调方法
            Connection* conn = new Connection(sock, this);
            conn->SetCallBack(recv_cb, send_cb, except_cb);
            //conn->_lastTimeStamp = time();

            //针对关注事件将描述符添加到 epoll 中, 然后通过 kv 树交付封装后的描述符给调用者
            //(1)添加 sock 到 epoll 中
            _poll.AddSockToEpoll(sock, EPOLLIN | EPOLLET); //任何多路转接的服务器一般默认打开对读事件的关系, 写入事件按需进行设置, 因为写事件通常很容易就绪(注意这里还设置成 ET 模式)
            //(2)添加封装的 sock 对象指针到 conns 集合中
            _conns[sock] = conn;
        }

        //检查描述符是否已经被添加进 epoll 并且添加进 kv 树中
        bool _IsConnectionExists(int sock)
        {
            auto iter = _conns.find(sock);
            if (iter == _conns.end())
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        //读写异常回调设置
        //(1)正常服务标识符的读回调
        void __Recver(Connection* conn)
        {
            //conn->_lastTimeStamp = time(); //读一次就更新时间

            _log.LogMessage(DEBUG, "Recver exists, been called __Recver(), %s %d", __FILE__, __LINE__);

            bool err = false; //一个标志位, 防止最后调用报文分割的函数

            //由于是 ET 模式, 因此必须一次性读取完毕
            //TODO: 直接面向字节流读取, 暂时不用考虑协议的问题
            while (true)
            {
                char buffer[1024] = { 0 };
                ssize_t n = recv(conn->_sock, buffer, sizeof(buffer) - 1, 0); //此处的 flag=0 已经无效了, 不用管了

                if (n < 0)
                {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) //代表不是出错, 只是没有新链接了
                    {
                        break;
                    }
                    else if (errno == EINTR) //被信号打断
                    {
                        continue; //继续读取
                    }
                    else
                    {
                        _log.LogMessage(ERROR, "recv error %s %d", __FILE__, __LINE__);
                        conn->_except_cb(conn); //交给异常回调即可, 所有的异常都可以统一被 __Excepter() 处理
                        err = true;//设置标志位
                        break;
                    }
                }
                else if (n == 0) //对端关闭
                {
                    _log.LogMessage(DEBUG, "client[%d] quit, server close, %s %d", conn->_sock, __FILE__, __LINE__);
                    conn->_except_cb(conn); //跳转异常来统一处理
                    err = true;
                    break;
                }
                else //不断读取
                {
                    buffer[n] = 0;
                    conn->_inbuffer += buffer; //由于不能保证一次读取就读取完整, 因此加入到描述符自己的缓冲区保存起来
                }
            } //end while

            _log.LogMessage(DEBUG, "conn->_inbuffer: %s, %s %d", conn->_inbuffer.c_str(), __FILE__, __LINE__);

            if (!err) //只要没出错
            {
                std::vector<std::string> messages;
                SpliteMessage(conn->_inbuffer, &messages); //注意这里 _inbuffer 会因为分割取走数据
                for (auto& msg : messages) //如果缺失报文那这里列表 messages 就为空
                {
                    //处理每一个完整的报文, 注意这里不要和服务端业务强耦合, 因此这里直接根据用户需求, 把完整报文按照服务端上层用户的要求进行回调即可
                    _cb(conn, msg); //TODO: 实际上也可以把许多的任务做任务队列, 进行多线程处理
                }
            }
        }

        //(2)正常服务标识符的写回调
        void __Sender(Connection* conn)
        {
            _log.LogMessage(DEBUG, "Sender exists, been called __Sender(), %s %d", __FILE__, __LINE__);
            while (true)
            {
                ssize_t n = send(conn->_sock, conn->_outbuffer.c_str(), conn->_outbuffer.size(), 0);
                if (n > 0)
                {
                    conn->_outbuffer.erase(0, n); //已经发送的就移除

                    if (conn->_outbuffer.empty()) //如果读取完了就退出
                        break;
                }
                else
                {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) //发送缓冲区可能还有数据, 但是对面缓冲区满了, 过会再发
                    {
                        break;
                    }
                    else if (errno == EINTR) //信号中断的情况
                    {
                        continue;
                    }
                    else
                    {
                        _log.LogMessage(ERROR, "Sender error, %s %d", __FILE__, __LINE__);
                        conn->_except_cb(conn); //异常就另外处理就绪
                        break;
                    }
                }
            } //end while

            //发不发完是不确定的, 但是可以保证没有出错的话, 要么发完, 要么条件不满足, 下次发就行
            if (conn->_outbuffer.empty()) //如果发送完了
            {
                EnableReadWrite(conn, true, false); //把写关注关闭
            }
            else //如果还没发送完, 需要等待对端有空间被写, 就需要关注写事件
            {
                EnableReadWrite(conn, true, true); //把写关注打开
            }
        }

        //(3)正常服务标识符的异常回调
        void __Excepter(Connection* conn)
        {
            _log.LogMessage(DEBUG, "Excepter exists, been called __Excepter(), %s %d", __FILE__, __LINE__);
            if (!_IsConnectionExists(conn->_sock)) //不存在就不处理了
                return;
            
            //1.从 epoll 中移除
            bool res = _poll.DelFromEpoll(conn->_sock);
            assert(res);

            //2.从 unorder_map 中移除
            _conns.erase(conn->_sock);

            //3.关闭文件描述符
            close(conn->_sock);

            //4.delete conn
            delete conn;

            _log.LogMessage(DEBUG, "Recovery completed!!! %s %d", __FILE__, __LINE__);
        }

        //针对监听套接字读事件就绪的连接方法
        void _Accepter(Connection* conn)
        {
            while (true) //循环的目的是为了一次处理多个连接(不能保证只有一个), 直到读取出错, 而且就算出错也不会被阻塞
            {
                _log.LogMessage(DEBUG, "_Accepter()...", __FILE__, __LINE__);
                //监听套接字走到这里一定不会被阻塞
                std::string client_ip;
                uint16_t client_port;
                int accept_errno = 0;
                int sock = Sock::_Accept(conn->_sock, &client_ip, &client_port, &accept_errno);
                if (sock < 0)
                {
                    //获取服务套接字失败, 或者有可能是读取完所有连接
                    if (accept_errno == EAGAIN || accept_errno == EWOULDBLOCK) //代表不是出错, 只是没有新链接了
                    {
                        break;
                    }
                    else if (accept_errno == EINTR) //被信号中断, 重新链接
                    {
                        continue;
                    }
                    else
                    {
                        _log.LogMessage(WARNING, "accept error %s %d", __FILE__, __LINE__);
                        break;
                    }
                }
                else //sock >= 0
                {
                    //连接就绪了, 但是对应的读写不一定就绪, 应该继续托管给 epoll
                    _AddConnection(
                        sock,
                        std::bind(&TcpServer::__Recver, this, std::placeholders::_1),
                        std::bind(&TcpServer::__Sender, this, std::placeholders::_1),
                        std::bind(&TcpServer::__Excepter, this, std::placeholders::_1)
                    );
                    _log.LogMessage(DEBUG, "accept success %s %d, sock->[%d]", __FILE__, __LINE__, sock);
                }
            } //end while
        }

        //对就绪的描述符资源分类来执行其对应的读写回调(处理一次循环)
        void _LoopOnce()
        {
            //获取就绪的描述符资源个数
            int n = _poll.WaitEpoll(_revs, _num_of_revs);

            //遍历就绪的每一个描述符资源
            for (int i = 0; i < n; i++)
            {
                int sock = _revs[i].data.fd; //获取描述符
                uint32_t revents = _revs[i].events; //获取其返回的事件

                //补充: 处理的时候出现异常都交给读写事件来解决(内部会跳转到异常事件)
                if (revents & EPOLLERR)
                    revents |= (EPOLLIN | EPOLLOUT);
                if (revents & EPOLLHUP)
                    revents |= (EPOLLIN | EPOLLOUT);

                //校验出读事件的描述符准备就绪后
                if (revents & EPOLLIN)
                {
                    //_IsConnectionExists() 主要是为了避免因为一些读写异常出现的描述符提前从 kv 树中移除的情况, 或者 EPOLLERR 或 EPOLLHUP 的情况出现
                    if (_IsConnectionExists(sock) && _conns[sock]->_recv_cb != nullptr)
                    {
                        _conns[sock]->_recv_cb(_conns[sock]); //通过 kv 树调用描述符的读回调(例如在这里出现读异常, 提前关闭了该描述符, 并且从 kv 树中移除, 而如果该描述符之前判定还有写事件就绪, 就会导致后续的 if() {...} 错误执行)
                    }
                }

                //校验出写事件的描述符准备就绪后
                if (revents & EPOLLOUT)
                {
                    if (_IsConnectionExists(sock) && _conns[sock]->_send_cb != nullptr) //这里添加 _IsConnectionExists() 同样是为了健壮性考虑
                    {
                        _conns[sock]->_send_cb(_conns[sock]); //通过 kv 树调用描述符的写回调
                    }
                }
            }
        }

        //遍历所有的 _conns, 如果长时间没有活动, 就建立连接超时的逻辑
        void _ConnectAliveCheck()
        {
            //for (auto& iter : _conns)
            //{
            //    uint64_t currtime = time();
            //    uint64_t deadtime = currtime - iter->_lastTimeStamp;
            //    if(deadtime > ...) //超时管理
            //}
        }

    public:
        //创建监听套接字, 设置好服务器的 ip:port, 初始化 epoll 模型, 准备好就绪缓冲区
        TcpServer(const int& port = g_port)
            : _listensock(Sock::_Socket())
            , _port(port)
            , _poll(Epoll())
            , _num_of_revs(g_num_of_revs)
        {
            //准备好监听套接字
            Sock::_Bind(_listensock, _port);
            Sock::_Listen(_listensock);

            //封装监听描述符, 规定其读写异步事件(尤其是特殊的读事件), 并且添加到 epoll 中
            //注意这里的绑定会导致函数类型从 void ()(const TcpServer*, Connection*) 变为 void ()(Connection*) 
            _AddConnection(_listensock, std::bind(&TcpServer::_Accepter, this, std::placeholders::_1), nullptr, nullptr);

            //准备就绪缓冲区
            _revs = new struct epoll_event[_num_of_revs]; //TODO: 可进行扩容

        }

        //释放监听套接字资源和 epoll 模型资源
        ~TcpServer()
        {
            if (_listensock >= 0)
                close(_listensock);
            if (_revs)
                delete[] _revs;
        }

        //根据特定的事件进行派发, cb是对上层用户报文的回调方法
        void Dispather(callback_t cb)
        {
            _cb = cb;
            while (true)
            {
                //TODO: _ConnectAliveCheck(); //连接超时管理, 但是这种做法有点不太精确, 最好把 epoll 当作定时器来使用
                _LoopOnce();
            }
        }

        //读写使能接口
        void EnableReadWrite(Connection* conn, bool readable, bool writeable)
        {
            uint32_t events = (readable ? EPOLLIN : 0) | (writeable ? EPOLLOUT : 0);
            bool res = _poll.CtrlEpoll(conn->_sock, events);
            assert(res);
        }

    private:
        int _listensock;
        int _port;

        Epoll _poll;
        std::unordered_map<int, Connection*> _conns; //多个封装的连接就可以被一起在这里被管理(但是不一定是就绪的)
        struct epoll_event* _revs; //存储就绪描述符资源
        int _num_of_revs; //一次存储就绪描述符资源的大小

        callback_t _cb; //上层用户需要对报文的处理回调

        Log _log;
    };

    const int TcpServer::g_port = 8080; //定义静态成员变量 g_port
    const int TcpServer::g_num_of_revs = 128; //定义静态成员变量 g_num_of_revs
}