#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        printf("I am child process\n");
        sleep(5);
        int n = 10;
        n /= 0;
        exit(10);
    }

    //等待多个子进程
    int status = 0;
    pid_t rid = waitpid(-1, &status, 0);
    if(rid == id)
    {
        if(WIFEXITED(status))//如果进程正常终止，返回真
        {
            printf("child process normal quit, exit code: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("child process quit except: %d\n", status & 0x7F);
        }
    }

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// void Worker()
// {
//     int cnt = 5;
//     while(cnt)
//     {
//         printf("I am child process, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt--);
//         sleep(1);
//     }
// }

// int main()
// {
//     pid_t id = fork();
//     if(id == 0)
//     {
//         //child
//         Worker();

//         //下面这两句可以测试进程因为异常退出的情况
//         //int a = 10;
//         //a /= 0;

//         exit(10);
//     }
//     else
//     {
//         //father
//         int status = 0;
//         pid_t rid = waitpid(id, &status, 0);//和使用 wait() 是一样的
//         if(rid == id)
//         {
//             if(WIFEXITED(status))//如果进程正常终止，返回真
//             {
//                 printf("child process normal quit, exit code: %d\n", WEXITSTATUS(status));
//             }
//             else
//             {
//                 printf("child process quit except\n");
//             }
//         }
//     }

//     return 0;
// }