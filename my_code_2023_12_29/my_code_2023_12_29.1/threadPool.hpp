//threadPool.hpp
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "thread.hpp"

//线程池（这里的运行逻辑实际上就是生产者-消费者模型）
class ThreadPool
{
public:
    ThreadPool()
    {

    }

    void Run()
    {
        /*启动线程池*/
    }

    void PushTask()
    {
        /*放置任务*/
    }

    ~ThreadPool()
    {}
private:
    std::vector<Thread*> _threads;
    int _num;
    std::queue<T> _task_queue;
};