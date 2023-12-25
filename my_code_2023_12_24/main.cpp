//尝试线程分离
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int g_val = 0; //由于是全局变量并且进程地址空间共享，因此每个线程都可以访问

//新线程运行逻辑
void* ThreadRoutine(void* args) //args 获取参数，也就是 pthread_create() 的最后一个参数
{
    pthread_detach(pthread_self()); //线程分离
    cout
        << (char*)args
        << " g_val:" << g_val
        << " and &g_val:" << &g_val
        << '\n';
    
    g_val++, sleep(1);

    pthread_exit((void*)11);
}

int main()
{
    //创建新线程并且运行
    pthread_t tid = 0; //新线程 id
    string name = "new thred"; //新线程名
    pthread_create(
        &tid, //设置新线程 id
        nullptr, //设置新线程属性
        ThreadRoutine, //设置新线程的回调函数
        (void*)name.c_str() //设置传递给回调函数的参数
    );

    //主线程运行逻辑
    cout
        << "main thread"
        << " g_val:" << g_val
        << " and &g_val:" << &g_val
        << '\n';
    sleep(1);

    //强行等待
    int n = pthread_join(tid, nullptr);
    cout
        << "n:" << n << '\n'
        << "errstrong:" << strerror(n) << '\n'; //提示参数错误

    return 0;
}