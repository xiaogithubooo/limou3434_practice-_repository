//尝试获取线程 tid
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

//新线程运行逻辑
void* ThreadRun(void* args) //args 获取参数，也就是 pthread_create() 的最后一个参数
{
    // for(int i = 0; i < 10; i++)
    while(true)
    {
        cout << (char*)args 
        << " tid:"
        << pthread_self() //获取新线程 id
        << '\n';

        sleep(1);
    }
    return nullptr;
}

int main()
{
    //创建新线程并且运行
    pthread_t tid =  0; //新线程 id
    string name = "new thred"; //新线程名
    pthread_create(
        &tid, //设置新线程 id
        nullptr, //设置新线程属性
        ThreadRun, //设置新线程的回调函数
        (void*)name.c_str() //设置传递给回调函数的参数
    );

    //主线程运行逻辑
    cout << "main thred"
    << " tid:"
    << pthread_self() //获取主线程 id
    << '\n';

    sleep(5);

    //没有线程等待

    return 0;
}

