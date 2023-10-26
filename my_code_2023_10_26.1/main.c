#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

void Worker()
{
    int cnt = 10;
    while(cnt--)
    {
        printf("I am child process, [pid:%d], [ppid:%d], [cnt:%d]\n", getpid(), getppid(), cnt);
        sleep(1);
    }
}

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
        sleep(1);
        pid_t id = fork();
        if(id == 0)
        {
            //child进程只会执行一次循环
            printf("[creat child %d]\n", i);
            Worker();
            exit(0);//子进程退出，暂时变成僵尸状态
        }
        //father进程执行循环，但是不会进入if语句
    }
    //这里只有父进程走到这里
    sleep(100);//由于我们还没有讲解僵尸进程的解决方法，因此这里就让父进程多等一会，直到全部子进程结束再来回收

    return 0;
}