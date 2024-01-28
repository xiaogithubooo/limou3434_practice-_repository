//使用匿名管道（父进程读，子进程写）
#include <iostream>
#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

using namespace std;

int main()
{
    //1.创建管道
    int pipefd[2] = { 0 }; //这里的数组数据最后会被子进程拷贝了，所以子进程也看得到文件标识符
    int n = pipe(pipefd);
    assert(n != -1), (void)n; //检查管道是否创建成功，并且消除警告，由于这个返回值 n 只是检查是否成功，在 release 模式下 assert() 会失效，导致没人使用 n 从而引起报警，所以使用 void 强转一下
    
    //2.创建进程
    pid_t id = fork();
    assert(id != -1);
    
    //3.创建信道
    //3.1.子进程执行部分（子进程为写端）
    if (id == 0)
    {
        close(pipefd[0]); //关闭子进程读端
        char send_buffer[1024] = { 0 }; //自定义写缓冲区

        while (true)
        {
            //3.1.1.正常写入管道文件
            string message;
            cin >> message; //用户输入消息
            
            snprintf(send_buffer, sizeof(send_buffer), "%s", message.c_str()); //写到自定义的缓冲区中
            write(pipefd[1], send_buffer, strlen(send_buffer)); //写到管道文件中

            //3.1.2.关闭管道文件的写端
            if (message == "write_exit")
            {
                cout << "子进程关闭写端" << endl;
                close(pipefd[1]); //检测父进程提前关闭写端的现象
                break;
            }
        }
        
        exit(10);
    }

    //3.2.父进程执行部分（父进程为读段）
    close(pipefd[1]); //关闭父进程的写端
    char buffer[1024] = { 0 }; //自定义读缓冲区

    while (true)
    {
        //3.2.1.正常读取管道文件
        ssize_t s = read(pipefd[0], buffer, sizeof(buffer) - 1); //读取管道数据到自定义的缓冲区中
        if (s > 0)
        {
            sleep(3); //这个睡眠秒数在检验一些情况的时候可以稍微调整一下
            cout << "读取到的字符个数:" << s << endl;
            buffer[s] = 0; //添加 '\0' 因为系统调用不靠该字符结尾
            cout << "[" << getpid() << "]:Father get a message" << ", child sad:[" << buffer << "]" << endl;

            //3.1.2.关闭管道文件的读端
            if (strcmp(buffer, "read_exit") == 0)
            {
                cout << "父进程关闭读端" << endl;
                close(pipefd[0]);
                break;
            }
        }
        else if(s == 0)
        {
            cout << "子进程将写端关闭了，read() 直接返回:" << s << endl;
            break;
        }
        else
        {
            //todo...
        }
    }

    //4.等待和检测子进程信息
    int status = 0; //获取子进程信号
    pid_t ret = waitpid(id, &status, 0); //等待子进程
    assert(ret > 0), (void)ret; //检查和消除警告

    printf("I am father process, wait success, my pid: %d, sub pid: %d, exit code: %d, exit sig: %d\n"
        , getpid(), id, (status >> 8) & 0xFF, status & 0x7F);
    
    return 0;
}