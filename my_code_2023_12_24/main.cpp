//多线程抢票
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int ticket = 10000; //票数，模拟临界资源，没有被保护的情况下被并发访问

void* GetTickets(void* args) //模拟临界区代码
{
    (void)args;
    while(true)
    {
        if(ticket > 0)
        {
            usleep(1000);
            printf("%p sells ticket:%d\n", pthread_self(), ticket--);
            //(1)实际上 -- 操作有三个执行步骤，先从内存中读取数据到 CPU 的上下文寄存器中
            //(2)CPU 进行自减操作
            //(3)自减操作做完后，写回进程中
            //在线程频繁切换中，有可能会触发上下文保护
            //被切出的线程记录了没有被 -- 操作的上下文
            //但是下一个线程切入的时候就把 -- 操作做完了
            //而原先的进程再次切入时，会把上一个线程的结果覆盖，数据就出现了错乱
        }
    }
}

int main()
{
    //创建 5 个新线程
    pthread_t t1, t2, t3;
    pthread_create(&t1, nullptr, GetTickets, nullptr); //这里的多个执行流同时调用 GetTickets() ，也就是对该函数进行重入
    pthread_create(&t2, nullptr, GetTickets, nullptr);
    pthread_create(&t3, nullptr, GetTickets, nullptr);

    //等待释放 5 个新线程
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);

    return 0;
}
