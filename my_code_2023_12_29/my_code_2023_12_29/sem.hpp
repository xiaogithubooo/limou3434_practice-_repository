//sem.hpp
#pragma once
#include <semaphore.h>

class Sem
{
public:
    Sem(int value)
    {
        sem_init(&_sem, 0, value);
    }

    void P()
    {
        sem_wait(&_sem); //申请信号量资源
    }

    void V()
    {
        sem_post(&_sem); //释放信号量资源
    }

    ~Sem()
    {
        sem_destroy(&_sem);
    }
private:
    sem_t _sem;
};