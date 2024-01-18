//testMain.hpp
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctime>
#include <cstdlib>
#include "ringQueue.hpp"

//生产者方法
void* Producer(void* args)
{
    RingQueue<int>* rq = (RingQueue<int>*)args;
    while(true)
    {
        //1.生产数据
        int x = rand() % 100 + 1;
        std::cout << pthread_self() << ":生产数据" << x << '\n';

        //2.推送数据
        rq->Push(x);
        
        //3.控制循环速度，便于观察数据生产和消费
        sleep(1);
    }
    return nullptr;
}

//消费者方法
void* Consumer(void* args)
{
    RingQueue<int>* rq = (RingQueue<int>*)args;
    while(true)
    {
        //1.获取数据
        int x = 0;
        rq->Pop(&x);

        //2.数据处理
        std::cout << pthread_self() << ":消费数据" << x << '\n';
        
        //3.控制循环速度，便于观察数据生产和消费
        sleep(6);
    }
    return nullptr;
}

const int size = 3;

int main()
{
    //设置随机数 种子
    srand((uint64_t)time(nullptr) ^ getpid());

    //构建循环队列
    RingQueue<int>* rq = new RingQueue<int>(10);
    rq->Debug();


    //创建和初始化生产者和消费者线程
    pthread_t ps[size], cs[size];

    for(int i = 0; i < size; i++)
        pthread_create(ps + i, nullptr, Producer, (void*)rq);
    for(int i = 0; i < size; i++)
        pthread_create(cs + i, nullptr, Consumer, (void*)rq);

    //释放线程
    for(int i = 0; i < size; i++)
        pthread_join(ps[i], nullptr);
    for(int i = 0; i < size; i++)
        pthread_join(cs[i], nullptr);

    return 0;
}