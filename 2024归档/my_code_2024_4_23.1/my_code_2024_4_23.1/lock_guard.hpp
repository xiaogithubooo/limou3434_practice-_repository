//lock_guard.hpp(线程池版本的服务端)

/* 使用方法
{
    LockGuard l = LockGuard(mutex);
}
*/

#pragma once
#include <iostream>
#include <pthread.h>

//锁类
class Mutex
{
public:
    //构造
    Mutex(pthread_mutex_t* mtx) : _pmtx(mtx) {}

    //加锁
    void Lock() { pthread_mutex_lock(_pmtx); }

    //解锁
    void UnLock() { pthread_mutex_unlock(_pmtx); }


private:
    pthread_mutex_t* _pmtx;
};

//智能锁类（有点类似智能指针）
class LockGuard
{
public:
    LockGuard(pthread_mutex_t* mtx) : _mtx(mtx) { _mtx.Lock(); }

    ~LockGuard() { _mtx.UnLock(); }


private:
    Mutex _mtx;
};