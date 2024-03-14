//blocking_queue.cpp
#include "blocking_queue.hpp"

int productionSpeed = 1; //生产速率
int consumptionSpeed = 5; //消费/速率

//生产者方法：生产任务
void* Producer(void* args)
{
    //强制参数得到队列
    BlockingQueue<int>* bq = static_cast<BlockingQueue<int>*>(args);
    int a = 1; //起始数据
    while(true)
    {
        bq->Push(a); //生产者生产数据
        std::cout << "Produce data: " << a++ << '\n';
        sleep(productionSpeed);
    }
    return nullptr;
}

//消费者方法
void* Consumer(void* args)
{
    //强制参数得到队列
    BlockingQueue<int>* bq = static_cast<BlockingQueue<int>*>(args);
    int a = 0; //临时变量
    while(true)
    {
        bq->Pop(&a); //消费者消费数据
        std::cout << "Consumption data:" << a << '\n';
        sleep(consumptionSpeed);
    }
    return nullptr;
}

int main()
{
    //创建阻塞队列（也就是市场）
    BlockingQueue<int>* bq = new BlockingQueue<int>(); //不直接使用 STL 队列的原因是原生队列不是线程安全的

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