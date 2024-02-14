//Task.hpp
#pragma once
#include <functional>

class Task
{
    typedef std::function<int(int, int)> func_t; //函数包装
public:
    Task(){}

    Task(int x, int y, func_t func)
        : _x(x), _y(y), _func(func)
    {}

    int operator()() //仿函数
    {
        return _func(_x, _y);
    }

public:
    int _x; //操作数 x
    int _y; //操作数 y
    func_t _func;
};