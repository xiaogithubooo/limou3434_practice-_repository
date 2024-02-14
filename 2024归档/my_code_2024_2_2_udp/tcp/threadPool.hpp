//threadPool.hpp
#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "thread.hpp"
#include "lockGuard.hpp"
#include "log.hpp"

//线程池（这里的运行逻辑实际上就是生产者-消费者模型）
const int gThreadNum = 3;

template <typename T>
class ThreadPool
{
private:
    //线程默认调用方法（相当于消费）
    static void* routine(void* tdata) //this 指针有一个坑，这个函数实际具有两个参数类型，最好不要写成成员函数
    {
        ThreadData* td = (ThreadData*)tdata;
        ThreadPool<T>* tp = (ThreadPool<T>*)td->_args;
        while(true)
        {
            T task;
            {
                LockGuard lockGuard(tp->GetMutex()); //智能锁
                while(tp->IsEmpty()) tp->WaitCond(); //内部自动释放锁（在被重新唤醒时会自动持有锁，不影响后续析构）
                
                task = tp->GetTask(); //获取任务（从共享空间拿到私有空间）
            }

            sleep(10);
        }
    }

public:
    ThreadPool(int threadNum = gThreadNum)
        : _num(threadNum)
    {
        for(int i = 0; i < _num; i++)
            _threads.push_back(new Thread(i, routine, this));
    
        pthread_mutex_init(&_lock, nullptr);
        pthread_cond_init(&_cond, nullptr);
    }

    void Run()
    {
        /*线程创建*/
        for(auto& iter : _threads)
        {
            iter->Start();
            LogMessage(NORMAL, "%s %s", iter->Name().c_str(), "run...");
        }
    }

    void PushTask(const T& task)
    {
        /*给线程放置任务*/
        LockGuard lockGuard(&_lock); //添加智能锁
        _task_queue.push(task);
        pthread_cond_signal(&_cond);
    }

    pthread_mutex_t* GetMutex()
    {
        return &_lock;
    }

    bool IsEmpty()
    {
        return _task_queue.empty();
    }

    void WaitCond()
    {
        pthread_cond_wait(&_cond, &_lock);
    }

    T GetTask()
    {
        T t = _task_queue.front();
        _task_queue.pop();
        return t;
    }

    ~ThreadPool()
    {
        std::cout << "析构线程池" << '\n';
        for(auto& iter : _threads) iter->Join(), delete iter;
        pthread_mutex_destroy(&_lock);
        pthread_cond_destroy(&_cond);
    }

private:
    std::vector<Thread*> _threads; //线程池
    int _num; //线程池大小
    std::queue<T> _task_queue; //任务列表
    pthread_mutex_t _lock; //任务列表锁
    pthread_cond_t _cond; //任务列表条件变量
};