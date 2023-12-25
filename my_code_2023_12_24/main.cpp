//尝试等待新线程（注意使用 g++ 编译的时候加上参数 -lpthread）
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* ThreadRun(void* args) //args 获取参数，也就是 pthread_create() 的最后一个参数
{
    int i = 0;

    while(true)
    {
        const string name = (char*)args;
        cout << "新线程的 name:" << name << '\n'; //显示线程名
        sleep(1);
        if(i++ == 5)
            break;
    }
    
    return (void*)10;
}

int main()
{
    //创建 1 个新线程
    pthread_t tid = 0; //线程名
    string name = "new thread ";
    pthread_create(
        &tid, //线程 id
        nullptr, //线程属性
        ThreadRun, //使用回调函数的方式让线程执行一部分的代码
        (void*)name.c_str() //传递给函数指针的参数
    );

    //线程等待，并且获取线程的结果
    void* ret = nullptr; //void* 大小就是 4/8，ret 作为变量为指针（我用的是 8 字节空间）
    pthread_join(tid, &ret); //阻塞等待新线程退出
    cout << "main thread wait done ... main quit, return value = " << (long long)ret << '\n'; //long long 是为了避免截断问题，因为这里的平台是 64 位，指针大小为 8
    
    return 0;
}
