#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int global_var = 10;

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        // 创建子进程失败
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // 子进程
        global_var += 5;
        printf("Child Process - Global Variable: %d\n", global_var);
    } else {
        // 父进程
        sleep(10);
        printf("Parent Process - Global Variable: %d\n", global_var);
    }
    
    return 0;
}

