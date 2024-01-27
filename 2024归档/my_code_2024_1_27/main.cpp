//使用匿名管道（让）
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
int main()
{
    //1.创建管道
    int pipefd[2] = { 0 };
    int n = pipe(pipefd);
    
    //2.创建进程
    pid_t id = fork();
    assert(id != -1);
    
    //3.创建信道
    if(id == 0)//子进程入口
    {
        close(pipefd[1]);//保留子进程读端
        char buffer[1024];
        while (true)
        {
            ssize_t s = read(pipefd[0], buffer, sizeof(buffer) - 1);//读取管道数据
            if(s > 0)//读成功
            {
                buffer[s] = 0;//添加'\0'因为系统调用不靠该字符结尾
                cout << "child get a message[" << getpid() << "]" << "Father sad:" << buffer << endl;
            }
        }
        exit(0);
    }
    
    close(pipefd[0]);//保留父进程的写端
    string message = "I am Fater";
    int count = 0;//统计消息条数
    char send_buffer[1024];
    while (true)
    {
        snprintf(send_buffer, sizeof(send_buffer), "%s:%d", message.c_str(), ++count);//写到缓冲区
        write(pipefd[1], send_buffer, strlen(send_buffer));
        sleep(1);
    }
    
    pid_t ret = waitpid(id, nullptr, 0);//等待子进程

    return 0;
}