#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void Worker(int cnt)
{
    printf("I am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
}

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //child
        int cnt = 10;
        while(cnt)
        {
            Worker(cnt);
            cnt--;
            sleep(1);
        }
        exit(0);
    }

    //father
    while(1)
    {
        int status = 0;
        pid_t rid = waitpid(id, &status, WNOHANG);
        if(rid > 0)
        {
            //等待成功，子进程当前是退出的
            printf("child quit sucess, exit code %d, exit signal %d\n", (status >> 8) & 0xFF, status & 0x7F);
            break;
        }
        else if(rid == 0)
        {
            //调用成功，但是子进程还没有返回
            printf("father do other thing...\n");
        }
        else
        {
            //调用失败（大部分情况是不会失败的）
            printf("wait failed\n");
            break;
        }
        sleep(1);
    }
    return 0;
}
