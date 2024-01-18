#include <stdio.h>
#include <unistd.h>
int g_val = 100;
int main()
{
    pid_t id = fork();//创建子进程

    if(id == 0)//子进程代码
    {
        int cnt = 0;
        while(1)
        {
            printf("I am a child. pid = %d, ppid = %d, g_val = %d, &g_val = %p.\n", \
            getpid(), getppid(), g_val, &g_val);
            sleep(1);
            cnt++;
            if(cnt == 3)
            {
                g_val = 200;
                printf("child chage g_val = 100 --> g_val = 200\n");
            }
        }
    }
    else//父进程代码
    {
        while(1)
        {
            printf("I am a father. pid = %d, ppid = %d, g_val = %d, &g_val = %p.\n", \
            getpid(), getppid(), g_val, &g_val);
            sleep(1);
        }
    }
    return 0;
}