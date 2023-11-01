#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void Worker()
{
    int cnt = 5;
    while(cnt)
    {
        printf("I am child process, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt--);
        sleep(1);
    }
}

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //child
        Worker();
        exit(0);
    }
    else
    {
        //father
        sleep(10);//在后10秒子进程处于僵尸状态
        pid_t rid = wait(NULL);
        if(rid == id)
        {
            printf("I am father process, wait success, pid: %d\n", getpid());
        }
    }

    return 0;
}