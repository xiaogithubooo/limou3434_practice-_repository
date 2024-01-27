//使用匿名管道（父进程写，子进程读）
#include <iostream>
#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    //1.创建管道
    int pipefd[2] = { 0 }; //这里的数组数据最后会被子进程拷贝了，所以也看得到
    int n = pipe(pipefd);
    assert(n != -1), (void)n; //检查是否创建成功，并且消除警告，因为这个返回值n只是检查是否成功，在release模式下assert()会失效，导致没人使用 n 从而引起报警
    
    //2.创建进程
    pid_t id = fork();
    assert(id != -1);
    
    //3.创建信道
    if(id == 0) //子进程入口
    {
        close(pipefd[1]); //关闭子进程的写端，保留子进程读端
        fcntl(pipefd[0], F_SETFL, O_NONBLOCK); //设置读端非阻塞

        char buffer[1024];
        sleep(8); //向让子进程别那么快读取，等父进程写入一些数据先

        while (true)
        {
            ssize_t s = read(pipefd[0], buffer, sizeof(buffer) - 1); //读取管道数据
            if(s > 0) //读成功
            {
                sleep(5); //这里加上这一句的目的是想查看，父进程写完字符串 "exit" 后，比子进程读取先关闭了写端，则子进程是否会进行正常读取
                cout << "读取到的字符个数:" << s << endl;
                buffer[s] = 0; //添加 '\0' 因为系统调用不靠该字符结尾
                cout << "[" << getpid() << ":child get a message]" << ", Father sad:[" << buffer << "]" << endl;
            }
            else //一旦管道文件不存在数据，read() 返回 -1
            {
                cout << "s=" << s << ", 父进程关闭写端" << endl;
                break;
            }
        }
        exit(0);
    }
    
    close(pipefd[0]); //保留写端
    fcntl(pipefd[1], F_SETFL, O_NONBLOCK); //设置写端非阻塞

    string message;
    int count = 0; //统计消息条数
    char send_buffer[1024];
    while (true)
    {
        cin >> message;
        
        snprintf(send_buffer, sizeof(send_buffer), "%s:%d", message.c_str(), ++count); //写到缓冲区
        write(pipefd[1], send_buffer, strlen(send_buffer));

        if (message == "exit")
        {
            close(pipefd[0]); //检测父进程提前关闭写端的现象
            break;
        }
    }
    cout << "父进程跳出循环，准备接受子进程中..." << endl;
    pid_t ret = waitpid(id, nullptr, 0); //等待子进程
    assert(ret < 0), (void)ret; //消除警告

    return 0;
}