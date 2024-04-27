//lock_guard.hpp(�̳߳ذ汾�ķ����)

/* ʹ�÷���
{
    LockGuard l = LockGuard(mutex);
}
*/

#pragma once
#include <iostream>
#include <pthread.h>

//����
class Mutex
{
public:
    //����
    Mutex(pthread_mutex_t* mtx) : _pmtx(mtx) {}

    //����
    void Lock() { pthread_mutex_lock(_pmtx); }

    //����
    void UnLock() { pthread_mutex_unlock(_pmtx); }


private:
    pthread_mutex_t* _pmtx;
};

//�������ࣨ�е���������ָ�룩
class LockGuard
{
public:
    LockGuard(pthread_mutex_t* mtx) : _mtx(mtx) { _mtx.Lock(); }

    ~LockGuard() { _mtx.UnLock(); }


private:
    Mutex _mtx;
};