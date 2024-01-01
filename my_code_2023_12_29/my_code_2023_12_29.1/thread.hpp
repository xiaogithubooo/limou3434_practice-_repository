//thread.hpp
#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <pthread.h>

struct ThreadData
{
    void* _args;
    std::string _name;
};

typedef void*(*func_t)(void*);

class Thread
{
    /*线程封装*/
public:
    Thread(int num, func_t callback, void* args)
        : _func(callback)
    {
        /*传递名称*/
        std::string name = "Thread-";
        name += std::to_string(num);
        _tdata._args = args;
        _tdata._name = name;
    }

    void Start()
    {
        /*线程启动*/
        pthread_create(&_tid, nullptr, _func, (void*)(&_tdata));
    }

    void Join()
    {
        /*线程等待*/
        pthread_join(_tid, nullptr);
    }

    std::string Name()
    {
        /*线程名字*/
        return _tdata._name;
    }

    ~Thread()
    {}
private:
    pthread_t _tid;
    ThreadData _tdata;
    func_t _func;
};