//task.hpp(线程池版本的服务端)

/* 使用方法
Task t = Task(操作数1, 操作数2, 操作符);
t.Run(); 或 仿函数 t(); 来调用执行任务，并且返回结果
t.Show(); 查看任务的具体内容
*/

#pragma once
#include <iostream>
#include <string>
#include <functional>

static const int gDefaultResult = 0;

class Task
{
private:
    using func_t = std::function<void(int, const std::string, uint16_t)>;
    
public:
    Task() {}

    Task(int sock, const std::string ip, uint16_t port, func_t func)
        : _sock(sock), _ip(ip), _port(port), _func(func) //在多线程的服务端这里，这里的任务内应该至少打包一个服务端的套接字
    {}

    void operator()()
    {
        _func(_sock, _ip, _port);
    }

private:
    int _sock;
    std::string _ip;
    uint16_t _port;
    func_t _func; //为 0 则为结果可信任，非 0 表示结果不可信
};
