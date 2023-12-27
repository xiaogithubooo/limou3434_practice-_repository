//多线程抢票（局部锁）
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <cassert>
using namespace std;

int ticket = 10000; //票数，模拟临界资源

class ThreadDatas
{
public:
    ThreadDatas(const string &n, pthread_mutex_t* pm)
        : _tname(n), _pmtx(pm)
    {}

    string _tname;
    pthread_mutex_t* _pmtx;
};

void* GetTickets(void* args) //模拟临界区代码
{
    //在临界区内，使用锁来保护临界资源
    ThreadDatas* td = (ThreadDatas*)args;

    while(true)
    {
        int n = pthread_mutex_lock(td->_pmtx); //上锁
        assert(n == 0); //检查是否加锁，没有则断死

        if(ticket > 0)
        {
            printf("%s sells ticket:%d\n", td->_tname.c_str(), ticket--);
            pthread_mutex_unlock(td->_pmtx);
        }
        else
        {
            n = pthread_mutex_unlock(td->_pmtx); //解锁
            assert(n == 0); //检查是否解锁，没有则断死

            break;
        }
        usleep(1000); //让线程停一下，保证可以让别的新线程也获得锁
    }
}

#define NUM 5
int main()
{
    //创建锁
    pthread_mutex_t mtx;
    pthread_mutex_init(&mtx, nullptr);

    //创建 5 个新线程
    pthread_t ts[NUM] = { 0 };
    for(int i = 0; i < NUM; i++)
    {
        string name = "thread ";
        name += to_string(i + 1);
        ThreadDatas* td = new ThreadDatas(name, &mtx);
        pthread_create(ts + i, nullptr, GetTickets, (void*)td); //这里的多个执行流同时调用 GetTickets() ，也就是对该函数进行重入，最后一个参数就是锁参数
    }

    //等待释放 5 个新线程
    for(int i = 0; i < NUM; i++)
    {
        pthread_join(ts[i], nullptr); //这里的多个执行流同时调用 GetTickets() ，也就是对该函数进行重入
    }
    
    //释放锁
    pthread_mutex_destroy(&mtx);

    return 0;
}
