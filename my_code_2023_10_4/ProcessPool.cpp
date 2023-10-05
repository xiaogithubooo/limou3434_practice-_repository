#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define PROCESS_NUM 5
int main(int argc, char const *argv[])
{
    for(int i = 0; i < PROCESS_NUM; i++)
    {
        //1.创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n > 0);(void)n;
        //2.创建进程
        pid_t id = fork();
        assert(id != -1);
        if(id == 0)//子进程
        {
            close(pipefd[1]);
            while(true)
            {
                
            }
            exit(1);
        }
        //父进程
        close(pipefd[0]);
    }
    return 0;
}