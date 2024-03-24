//thread_pool.hpp
#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include <unistd.h>
#include "log.hpp"
#include "thread.hpp"
#include "lock_guard.hpp"

static const int gDefaultNum = 5;

class ThreadData
{
    
};

template<class T>
class ThreadPool
{
private:
    void ThreadWait()
    {
        pthread_cond_wait(&_cond, &_mutex);
    }
    void ThreadWaitUp()
    {
        pthread_cond_signal(&_cond);
    }

public:
    ThreadPool(int num_of_thread = gDefaultNum)
        : _num_of_thread(num_of_thread)
    {
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_cond, nullptr);
    
        //创建线程
        for (int i = 0; i < _num_of_thread; i++)
        {
            std::string tName = "thread";

            ThreadData td;

            Thread<ThreadData> t(tName + std::to_string(i), std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1), td); //bind() 可以把方法和参数绑定，调用的时候只需要传入占位符处的参数即可，对应的包装类类型也需要根据占位符改动
            _threads.push_back(t);
        }
    }

    bool Start()
    {
        for (auto& thread : _threads)
            thread.Start();
    }

    void ThreadRun(ThreadData &tid)
    {
        while(true)
        {
            //取得任务
            T t;
            {
                LockGuard lockguard(&_mutex);
                while(_q.empty()) //防止伪唤醒
                {
                    ThreadWait();
                }
                t = _q.front();
                _q.pop();
            }
            
            //执行任务
            t();
        }
    }

    void Push(const T& in)
    {
        LockGuard lockguard(&_mutex);
        _q.push_back(in);
        ThreadWaitUp();
    }

    void Wait()
    {
        for(auto& thread : _threads)
        {
            thread.Join();
        }
    }

    ~ThreadPool()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }

private:
    std::queue<T> _q; //任务队列
    std::vector<Thread<ThreadData>> _threads; //线程列表
    int _num_of_thread;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
};
