//thread.hpp
#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <pthread.h>

typedef void*(func_t)(void*);

class Thread
{
    /*线程封装*/
public:
    Thread(int num)
    {
        /*传递名称*/
        std::string name = "Thread-";
        name += std::to_string(num);
    }

    void Start(func_t callback, void* args)
    {
        /*线程启动*/
        pthread_create(&_tid, nullptr, callback, args);
    }

    void Join()
    {
        /*线程等待*/
        pthread_join(_tid, nullptr);
    }

    std::string Name()
    {
        /*线程名字*/
        return _name;
    }

    ~Thread()
    {}
private:
    std::string _name;
    pthread_t _tid;
    func_t _func;
};