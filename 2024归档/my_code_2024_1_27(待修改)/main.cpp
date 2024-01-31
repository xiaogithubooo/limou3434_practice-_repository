//编写一个简单的进程池
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Task.hpp"

using namespace std;

//信道类
const int PROCESS_NUM = 5; //信道数量（子进程数量）
struct Channel
{
    Channel(const int& fd, const pid_t& id, const string& channelName)
        : _fd(fd), _id(id), _channelName(channelName)
    {}

    int _fd; //对应的管道文件
    pid_t _id; //对应的子进程 id
    string _channelName; //对应的信道名字（方便调试）
};

//子进程的工作
void work()
{
    while (true)
    {
        //读取任务
        int code = 0;
        ssize_t n = read(0, &code, sizeof(code)); assert(n != sizeof(code)); (void)n; //返回读取到的字节个数，断死不匹配字节的情况
        tasks.RunTask(code); //执行任务
        if (n == 0) //父进程关闭了写端
            break;
    }
}

//创建多个信道
void CreatChannels(vector<Channel>* pchannels)
{
    for (int i = 0; i < PROCESS_NUM; i++)
    {
        //创建管道和创建子进程
        int pipefd[2] = {0};
        int n = pipe(pipefd); assert(n >= 0), (void)n;
        pid_t id = fork(); assert(id != -1);

        string name = "channelName_"; name += to_string(i);
        pchannels->push_back(Channel(pipefd[1], id, name));
        
        //子进程部分
        if (id == 0)
        {
            close(pipefd[1]); //关闭子进程的管道文件写端，子进程读取父进程的命令
            dup2(pipefd[0], 0); //重定向到子进程，可以避免给 work() 传参和更多复杂的场景
            work(); //执行对应的工作
            exit(10); //设置子进程退出码
        }

        //父进程部分
        close(pipefd[0]); //关闭父进程的读端，由父进程进行写入管道，通知其他进程
    }
}

//打印多个信道的结果
void PrintChannels(const vector<Channel>& channels)
{
    for (auto it : channels)
    {
        cout << it._channelName << ":" << "fd[" << it._fd << "]read-->id[" << it._id << "]" << endl;
    }
}

//随机选择信道
int SelectChannel()
{
    return rand() % PROCESS_NUM;
}

int main()
{
    //创建多个信道，并且显示创建结果
    vector<Channel> channels;
    CreatChannels(&channels);
    PrintChannels(channels);

    //父进程部分
    srand(((unsigned long)time(nullptr)) ^ getpid() ^ 114514L); //获取随机数（这里做了一些数据操作，让数据源更加随机）
    while (true)
    {
        //用户进行命令输入
        int code = 0;
        tasks.ShowTaskList();
        cout << "<Please>:";
        cin >> code;

        if (tasks.CheckSafe(code))
        {
            int choice = SelectChannel();
            write(channels[choice]._fd, &code, sizeof(code)); //向某条信道输入指定的任务

            cout << "call process:" << channels[choice]._id //指定某子进程
                << ", execute:" << tasks.TaskShow(code) //执行某任务
                << ", through:" << channels[choice]._fd //直通某管道
                << endl;
        }
        else
        {
            goto BREAK;
        }
    }

BREAK:
    for (const auto it : channels)
    {
        close(it._fd); //父进程关闭掉所有的写端
    }
    for (const auto& it : channels)
    {
        int status = 0;
        waitpid(it._id, &status, WUNTRACED); //父进程阻塞回收所有子进程信息
        cout << "sub exit code:" << WEXITSTATUS(status) << ", sub signal:" << WTERMSIG(status) << endl;
    }
    return 0;
}