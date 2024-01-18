#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        //子进程
        while(1)
        {
            printf("I am child, pid = %d, ppid = %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        //父进程
        while(1)
        {
            printf("I am father, pid = %d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}
