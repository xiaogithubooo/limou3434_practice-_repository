#include <unistd.h>
#include <wait.h>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>

int main()
{
    int fd[2] = { 0 };
    pipe(fd);

    pid_t id = fork();
    assert(id != -1);

    if (id == 0) //子进程读
    {
        close(fd[1]);
        char buffer[1024] = { 0 };
        ssize_t s = read(fd[0], buffer, sizeof(buffer) - 1);
        std::cout << "father # " << buffer << std::endl;
        exit(1);
    }

    //父进程写
    close(fd[0]);
    char buffer[1024] = "i am father";
    ssize_t s = write(fd[1], buffer, sizeof(buffer) - 1);

    //等待子进程
    int status = 0; //获取子进程信号
    pid_t ret = waitpid(id, &status, 0); //等待子进程
    assert(ret > 0), (void)ret; //检查和消除警告

    printf("I am father process, wait success, my pid: %d, sub pid: %d, exit code: %d, exit sig: %d\n",
        getpid(), id, (status >> 8) & 0xFF, status & 0x7F);

    return 0;
}
