//main.cpp(基于循环队列 和 信号量 的多生产者-消费者模型)
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctime>
#include <cstdlib>
#include "ring_queue.hpp"
#include "task.hpp"

std::string opers = "+-*/%";

//生产者方法
void* Producer(void* args)
{
    RingQueue<Task>* rq = (RingQueue<Task>*)args;
    while(true)
    {
        //1.生产任务
        //生成两个随机数
        int data_1 = rand() % 10;
        usleep(rand() % 100); //避免两个随机值一样
        int data_2 = rand() % 10;
        char oper = opers[rand() % opers.size()];
        Task t(data_1, data_2, oper);

        //2.推送任务
        rq->Push(t); //生产者生产数据
        std::cout << pthread_self() << "--Produce data: " << t.Show() << std::endl;

        //3.控制循环速度，便于观察数据生产和消费
        sleep(1);
    }
    return nullptr;
}

//消费者方法
void* Consumer(void* args)
{
    RingQueue<Task>* rq = (RingQueue<Task>*)args;
    while(true)
    {
        //1.获取数据
        Task t; //临时变量
        rq->Pop(&t); 
        
        //2.消费数据
        std::cout << pthread_self() << "--Consumption data: " << t.Show() << "=" << t() << std::endl;
        
        //3.控制循环速度，便于观察数据生产和消费
        sleep(6);
    }
    return nullptr;
}

const int size = 3; //生产者和消费者的数量

int main()
{
    //设置随机数种子
    srand((uint64_t)time(nullptr) ^ getpid());

    //构建循环队列
    RingQueue<Task>* rq = new RingQueue<Task>(10);
    rq->Debug();


    //创建和初始化生产者和消费者线程
    pthread_t ps[size];
    for(int i = 0; i < size; i++)
        pthread_create(ps + i, nullptr, Producer, (void*)rq);
    
    pthread_t cs[size];
    for(int i = 0; i < size; i++)
        pthread_create(cs + i, nullptr, Consumer, (void*)rq);

    //释放线程
    for(int i = 0; i < size; i++)
        pthread_join(ps[i], nullptr);
    
    for(int i = 0; i < size; i++)
        pthread_join(cs[i], nullptr);

    return 0;
}
