//BlockingQueue.hpp
#pragma once
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include "LockGuard.hpp"

const int gDefaultCap = 10;

template<class T>
class BlockingQueue
{
private:
    bool IsQueueEmpty()
    {
        return _bq.size() == 0;
    }
    bool IsQueueFull()
    {
        return _bq.size() == _capacity;
    }

public:
    BlockingQueue(int capacity = gDefaultCap) //默认为 5
        : _capacity(capacity)
    {
        pthread_mutex_init(&_mtx, nullptr);
        pthread_cond_init(&_empty, nullptr);
        pthread_cond_init(&_full, nullptr);
    }

    //生产者产数据
    void Push(const T& in)
    {
        //使用 RAII 智能锁（自动加锁和解锁）
        LockGuard lockgrard(&_mtx);

        //检测临界资源是否满足访问条件（队列是否为满）
        while(IsQueueFull()) pthread_cond_wait(&_full, &_mtx);
        
        //访问临界资源，生产数据
        _bq.push(in);

        //只有在生产出足够的商品时才唤醒消费者（生产策略）
        if(_bq.size() >= _capacity/2) pthread_cond_signal(&_empty);
    }

    //消费者取数据
    void Pop(T* out)
    {
        //使用智能锁（自动加锁和解锁）
        LockGuard lockgrard(&_mtx);

        //检测临界资源是否满足访问条件（队列是否为空）
        while(IsQueueEmpty()) pthread_cond_wait(&_empty, &_mtx); //debug:这里也是一样的

        //访问临界资源，取得数据
        *out = _bq.front();
        _bq.pop();

        //唤醒生产者
        pthread_cond_signal(&_full);
    }

    ~BlockingQueue()
    {
        pthread_cond_destroy(&_empty);
        pthread_cond_destroy(&_full);
    }

private:
    std::queue<T> _bq; //阻塞队列
    int _capacity; //容量上限
    pthread_mutex_t _mtx; //通过互斥锁保护队列安全
    pthread_cond_t _empty; //通过条件变量阻塞队列（阻塞时表示 bq 为空）
    pthread_cond_t _full; //通过条件变量阻塞队列（阻塞时表示 bq 为满）
};