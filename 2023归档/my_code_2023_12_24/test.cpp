//多线程抢票（全局锁）
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cassert>
using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; //定义锁（如果是全局的、静态的，就可以直接使用 PTHREAD_MUTEX_INITIALIZER 宏来初始化，也可以使用函数）

int ticket = 10000; //票数，模拟临界资源，没有被保护的情况下被并发访问

void* GetTickets(void* args) //模拟临界区代码
{
    //在临界区内，使用锁来保护临界资源
    (void)args;
    while(true)
    {
        int n = pthread_mutex_lock(&mtx); //每一个线程都会执行获得锁的动作，但是任何一个时刻只允许一个线程获得，其他线程此时处于阻塞状态，直到锁被解开（并且不一定所有每一个线程都可以平均获得锁）
        assert(n == 0); //检查是否加锁，没有则断死

        if(ticket > 0)
        {
            printf("%p sells ticket:%d\n", pthread_self(), ticket--);
            pthread_mutex_lock(&mtx); //解锁，不要放太后，减少加锁的颗粒度，否则打印的效率更低，导致代码整体效率低
        }
        else
        {
            n = pthread_mutex_lock(&mtx); //解锁
            assert(n == 0); //检查是否解锁，没有则断死

            break;
        }
        usleep(1000); //让线程停一下，保证可以让别的新线程也获得锁
    }
}

int main()
{
    //创建 5 个新线程
    pthread_t t1, t2, t3, t4, t5;
    pthread_create(&t1, nullptr, GetTickets, nullptr); //这里的多个执行流同时调用 GetTickets() ，也就是对该函数进行重入
    pthread_create(&t2, nullptr, GetTickets, nullptr);
    pthread_create(&t3, nullptr, GetTickets, nullptr);
    pthread_create(&t4, nullptr, GetTickets, nullptr);
    pthread_create(&t5, nullptr, GetTickets, nullptr);

    //等待释放 5 个新线程
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);
    pthread_join(t4, nullptr);
    pthread_join(t5, nullptr);
    
    return 0;
}
