//task.hpp(线程池版本的服务端)

/* 使用方法
Task t = Task(操作数1, 操作数2, 操作符);
t.Run(); 或 仿函数 t(); 来调用执行任务, 并且返回结果
t.Show(); 查看任务的具体内容
*/

#pragma once
#include <iostream>
#include <string>
#include <functional>

//任务类
class Task
{
public:
    using task_func_t = std::function<void(int sock, const std::string ip, uint16_t port)>;


public:
    //构造空对象
    Task() {}

    //传入套接字相关信息和一个任务回调
    Task(int sock, const std::string ip, uint16_t port, task_func_t func)
        : _sock(sock)
        , _ip(ip)
        , _port(port)
        , _func(func) //在多线程的服务端这里, 这里的任务内应该至少打包一个服务端的套接字
    {}

    //仿函数, 让对象可以调用任务回调
    void operator()()
    {
        _func(_sock, _ip, _port);
    }


private:
    int _sock;
    std::string _ip;
    uint16_t _port;
    task_func_t _func;
};