//Task.hpp
#pragma once
#include <functional>
#include <string>

class Task
{
//typedef std::function<void(int, const std::string&, const uint16_t&)> func_t; //函数包装
using func_t = std::function<void(int, const std::string&, const uint16_t&)>; //函数包装

public:
    Task() {}

    Task(int sock, const std::string& ip, uint16_t& port ,func_t func)
        : _sock(sock), _ip(ip), _port(port), _func(func)
    {}

    void operator()(const std::string& name) //仿函数
    {
        _func(_sock, _ip, _port);
    }

public:
    int _sock;
    std::string _ip;
    uint16_t _port;
    func_t _func;
};