//lock_guard.hpp(线程池)

/* 使用方法
LockGuard l = LockGuard(mutex);
*/

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
       //std::cout << "智能加锁" << '\n';
       pthread_mutex_lock(_pmtx);
   }
   void UnLock()
   {
       //std::cout << "智能解锁" << '\n';
       pthread_mutex_unlock(_pmtx);
   }

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
