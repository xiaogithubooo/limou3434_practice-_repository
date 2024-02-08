//基于信号的智能子进程回收机制（父进程无需等待子进程，自己清理自己）
#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>
using namespace std;

void handler(int signum)
{
    cout << "子进程已退出，父进程接受到信号为: " << signum << '\n';
}

int main()
{
    //手动设置忽略，父进程就不需要自己回收子进程了，子进程会自动释放，也不会通知父进程回收信息
    //(1)如果我们只是单纯希望不出现僵尸进程，就可以用下述设置忽略的做法
    //(2)如果我们还希望得到子进程的信息，就一定需要父进程进行等待，就不能设置忽略
    signal(SIGCHLD, SIG_IGN);

    if(fork() == 0)
    {
        cout << "子进程: " << getpid() << " 启动" << '\n';
        sleep(5);
        exit(10);
    }

    while(true) 
    {
        cout << "父进程: " << getpid() << " 执行自己的代码" << '\n';
        sleep(5);
    }

    return 0;
}