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
    int pipefd[2] = {0};//这里的数据被子进程拷贝了，所以也看得到
    int n = pipe(pipefd);
    assert(n != -1);//检查是否创建成功
    (void)n;//消除警告，因为这个返回值n只是检查是否成功，在release模式下assert()会失效，导致没人使用n从而报警
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
            sleep(10);
            ssize_t s = read(pipefd[0], buffer, sizeof(buffer) - 1);//读取管道数据
            if(s > 0)//读成功
            {
                buffer[s] = 0;//添加'\0'因为系统调用不靠该字符结尾
                cout << "child get a message[" << getpid() << "]" << "Father sad:" << buffer << endl;
            }
        }
        exit(0);
    }
    close(pipefd[0]);//保留父进程写端
    string message = "I am Fater";
    int count = 0;//统计消息条数
    char send_buffer[1024];
    while (true)
    {
        snprintf(send_buffer, sizeof(send_buffer), "%s:%d", message.c_str(), ++count);//写到缓冲区
        write(pipefd[1], send_buffer, strlen(send_buffer));
        cout << count << endl;
    }
    pid_t ret = waitpid(id, nullptr, 0);//等待子进程
    assert(ret < 0);
    (void)ret;//消除警告
    return 0;
}