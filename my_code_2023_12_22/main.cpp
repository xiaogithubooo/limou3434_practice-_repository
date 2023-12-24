//基于信号版本的子进程回收机制（父进程无需等待子进程，自己清理自己）
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
    signal(SIGCHLD, SIG_IGN); //手动设置忽略

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