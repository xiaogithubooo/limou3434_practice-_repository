#include <stdlib.h>
#include <unistd.h>
#include "blocking_queue.hpp"
#include "task.hpp"

int productionSpeed = 1; //生产速率
int consumptionSpeed = 5; //消费/速率

const int num_of_producer = 3; //生产者个数
const int num_of_consumer = 2; //消费者个数

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
    pthread_t ps[num_of_producer]; //多个生产者线程
    pthread_t cs[num_of_consumer]; //多个消费者线程
    
    for (int i = 0; i < num_of_producer; i++)
        pthread_create(&ps[i], nullptr, Consumer, bq);
    
    for (int j = 0; j < num_of_consumer; j++)
        pthread_create(&cs[j], nullptr, Producer, bq);

    //等待释放两种线程
    for (int i = 0; i < num_of_producer; i++)
        pthread_join(ps[i], nullptr);
    
    for (int j = 0; j < num_of_consumer; j++)
        pthread_join(cs[j], nullptr);
    return 0;
}
