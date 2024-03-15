//blocking_queue.cpp
#include <stdlib.h>
#include <unistd.h>
#include "blocking_queue.hpp"
#include "task.hpp"

int productionSpeed = 1; //生产速率
int consumptionSpeed = 5; //消费/速率

std::string opers = "+-*/%";

//生产者方法：生产任务
void* Producer(void* args)
{
    //强制参数得到队列
    BlockingQueue<Task>* bq = static_cast<BlockingQueue<Task>*>(args);
    while (true)
    {
        //生成两个随机数
        int data_1 = rand() % 10;
        usleep(rand() % 100); //避免两个随机值一样
        int data_2 = rand() % 10;
        char oper = opers[rand() % opers.size()];

        Task t(data_1, data_2, oper);
        bq->Push(t); //生产者生产数据
        std::cout << "Produce data: " << t.Show() << std::endl;
        sleep(productionSpeed);
    }
    return nullptr;
}

//消费者方法：消费任务
void* Consumer(void* args)
{
    //强制参数得到队列
    BlockingQueue<Task>* bq = static_cast<BlockingQueue<Task>*>(args);
    while(true)
    { 
        Task t; //临时变量
        bq->Pop(&t); //消费者消费数据
        std::cout << "Consumption data: " << t.Show() << "=" << t() << std::endl;
        sleep(consumptionSpeed);
    }
    return nullptr;
}

int main()
{
    //初始随机种子
    srand((uint16_t)time(nullptr) ^ getpid() ^ pthread_self());

    //创建阻塞队列（也就是市场）
    BlockingQueue<Task>* bq = new BlockingQueue<Task>(); //不直接使用 STL 队列的原因是原生队列不是线程安全的

    //创建生产者和消费者进程
    pthread_t p; //单个生产者线程
    pthread_t c; //单个消费者线程
    pthread_create(&p, nullptr, Consumer, bq);
    pthread_create(&c, nullptr, Producer, bq);

    //等待释放两种线程
    pthread_join(p, nullptr);
    pthread_join(c, nullptr);
    return 0;
}