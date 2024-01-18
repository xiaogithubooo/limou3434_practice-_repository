#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
int main() 
{
    //fork之前是父进程     
    printf("1.进程PID：%d 父进程PPID：%d\n", getpid(), getppid());
    printf("father-you can see me!\n");
    printf("father-you can see me!\n");
    printf("father-you can see me!\n");
    //fork之后就会创建一个子进程，具有和父进程同样的代码     
    fork();
    
    printf("father-child-you can see me!\n");
    printf("2.进程PID：%d 父进程PPID：%d\n", getpid(), getppid());
    printf("%d\n", );
    sleep(1); 
    return 0;
}
