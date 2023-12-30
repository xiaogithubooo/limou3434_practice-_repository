//ConProd.cc
#include "BlockingQueue.hpp"
#include "Task.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//操作方法
int MyAdd(int x, int y)
{
    return x + y;
}

//生产者方法
void* producer(void* args)
{
    BlockingQueue<Task>* bqueue = (BlockingQueue<Task>*)args;
    while(true)
    {
        //生产数据
        int x = rand() % 10 + 1;
        int y = rand() % 5 + 1;

        //构建任务（内含操作数和操作方法）
        Task t(x, y, MyAdd);
        bqueue->Push(t);

        std::cout << pthread_self() << "生产任务:"
        << "\'" << t._x << "\'"
        << " and "
        << "\'" << t._y << "\'"
        << " and func()"
        << '\n';

    }
    return nullptr;
}

//消费者方法
void* consumer(void* args)
{
    BlockingQueue<Task>* bqueue = (BlockingQueue<Task>*) args;
    while(true)
    {
        //获取任务
        Task t;
        bqueue->Pop(&t);
        //输出结果
        std::cout << pthread_self() << "消费任务:" << t._x << " and " << t._y << " --> " << t() << '\n';
    
        usleep(100);
    }
    return nullptr;
}

const int size = 5;
int main()
{
    //种下随机数种子
    srand((uint64_t)time(nullptr) ^ getpid() ^ 0x114514);

    //使用 生产者-消费者模型 运作线程
    BlockingQueue<Task>* bqueue = new BlockingQueue<Task>();

    //创建生产者和消费者进程
    pthread_t ps[size]; //生产者
    pthread_t cs[size]; //消费者
    for(int i = 0; i < size; i++)
    {
        pthread_create(ps + i, nullptr, consumer, bqueue); //最后一个参数可以让生产者和消费者看到同一个队列
        pthread_create(cs + i, nullptr, producer, bqueue);
    }
    
    //等待释放两种线程
    for(int i = 0; i < size; i++)
    {
        pthread_join(ps[i], nullptr);
        pthread_join(cs[i] + i, nullptr);
    }
    return 0;
}