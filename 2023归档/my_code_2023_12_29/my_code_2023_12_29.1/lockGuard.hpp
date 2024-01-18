//LockGuard.hpp
#pragma once
#include <iostream>
#include <pthread.h>

//封装锁
class Mutex
{
public:
    Mutex(pthread_mutex_t* mtx)
        : _pmtx(mtx)
    {}
    
    void Lock()
    {
        pthread_mutex_lock(_pmtx);
    }
    
    void UnLock()
    {
        pthread_mutex_unlock(_pmtx);
    }
    
    ~Mutex()
    {}

private:
    pthread_mutex_t* _pmtx;
};

//智能锁（有点类似智能指针）
class LockGuard
{
public:
    LockGuard(pthread_mutex_t* mtx)
        : _mtx(mtx)
    {
        _mtx.Lock();
    }

    ~LockGuard()
    {
        _mtx.UnLock();
    }

private:
    Mutex _mtx;
};