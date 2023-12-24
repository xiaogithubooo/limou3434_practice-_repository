#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* ThreadRun(void* args) //args 获取参数，也就是 pthread_create() 的最后一个参数
{
    const string name = (char*)args;
    cout
    << "新线程的 name:" << name << '\n' //显示线程名
    << "新线程所处进程的 pid:" << getpid() << '\n'; //检验线程是否真的在进程内（若是则获得和进程一样的 pid）
    sleep(10);
    cout << "新进程任务结束" << '\n';

    return nullptr;
}

int main()
{
    //打印本进程的 pid
    cout << "本进程的 pid:" << getpid() << '\n';

    //创建 5 个新线程
    pthread_t tids[5] = { 0 };
    for(int i = 0; i < 5; ++i)
    {
        string name = "thread ";
        name += to_string(i + 1);
        pthread_create(
            tids + i, //线程 id
            nullptr, //线程属性
            ThreadRun, //使用回调函数的方式让线程执行一部分的代码
            (void*)name.c_str() //传递给函数指针的参数
        );
        sleep(1);
    }

    //主线程持续运行
    cout << "-------" << '\n';
    while(true)
    {
        cout << "主线程所处进程的 pid:" << getpid() << '\n';
        sleep(1);
    }

    return 0;
}
