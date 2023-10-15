#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define PROCESS_NUM 5

int waitCommand(int waitFd, bool& quit);//等待读取函数

typedef std::function<void()> func;//这就定义了一个函数类型
//或者使用using func = std::function<void()>
void readSQL();
void execuleUrl();
void cal();
void mathCalculate();
vector<func> callbacks;//若干回调函数
void load();//填充若干函数/任务
unordered_map<int, string> desc;//创建哈希表
void show();//查看任务
int handlerSize();//查看任务数量
void sendAndWakeup(pid_t who, int fd, uint32_t command);//布置任务

int main()
{
    //0.装载任务
    load();
    vector<pair<pid_t, int>>slots;
    //1.构造进程池
    for(int i = 0; i < PROCESS_NUM; i++)
    {
        //1.1.创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n <= 0);(void)n;
        //1.2.创建进程
        pid_t id = fork();
        assert(id != -1);
        if(id == 0)//子进程
        {
            close(pipefd[1]);
            while(true)
            {
                bool quit = false;
                int command = waitCommand(pipefd[0], quit);//如果父进程不写就进入阻塞
                if(quit) break;
                if(command >= 0 && command < handlerSize())
                {
                    callbacks[command]();//调用对应的方法
                }
                else
                {
                    cout << "非法command:" << command << endl;
                }
            }
            exit(1);
        }
        //父进程
        close(pipefd[0]);
        slots.push_back(pair<pid_t, int>(id, pipefd[1]));
    }
    //2.父进程派发任务（这就相当于单机版的负载均衡）
    srand(((unsigned long)time(nullptr)) ^ getpid() ^ 114514L);//让数据源更加随机
    while(true)
    {
        int n = 0;
        int command = 0;
        cout << "--------------------------------" << endl;
        cout << "1.show functions  2.send command" << endl;
        cout << "--------------------------------" << endl;
        cout << "<Please Select>:";
        cin >> n;
        if(n == 1) show();
        else if(n == 2)
        {
            cout << "<Enter Your Command>:";
            //选择任务
            cin >> command;
            //选择进程
            int choice = rand() % slots.size();
            //布置任务（给指定的进程）
            sendAndWakeup(slots[choice].first, slots[choice].second, command);
        }
        else
        {
            ;
        }
    }
    //3.关闭fd，结束所有进程
    for(const auto slot : slots)
    {
        close(slot.second);//父进程关闭掉所有的写端
    }
    for(const auto& solt : slots)//回收所有子进程信息
    {
        waitpid(solt.first, nullptr, 0);
    }
    return 0;
}

int waitCommand(int waitFd, bool& quit)
{
    uint32_t command = 0;//四字节缓冲区
    ssize_t s = read(waitFd, &command, sizeof(command));//从读端读给command
    if(s == 0)//已经关闭了文件描述符
    {
        quit = true;
        return -1;
    }
    assert(s == sizeof(uint32_t));//保证读取正确
    return command;
}

//任务表
void readSQL()
{
    sleep(1);
    cout << "process[" << getgid() << "] 执行了访问数据库的任务" << endl;
}
void execuleUrl()
{
    sleep(1);
    cout << "process[" << getgid() << "] 执行了解析URL地址的任务" << endl;
}
void cal()
{
    sleep(1);
    cout << "process[" << getgid() << "] 执行了加密的任务" << endl;
}
void mathCalculate()
{
    sleep(1);
    cout << "process[" << getgid() << "] 执行了数学计算的任务" << endl;
}
void load()
{
    desc.insert({callbacks.size(), "readSQL:读取数据库"});//插入键值对
    callbacks.push_back(readSQL);

    desc.insert({callbacks.size(), "execuleUrl:解析URL"});
    callbacks.push_back(execuleUrl);

    desc.insert({callbacks.size(), "cal:加密"});
    callbacks.push_back(cal);

    desc.insert({callbacks.size(), "mathCalculate:数学计算"});
    callbacks.push_back(mathCalculate);
}
void show()
{
    for(const auto &iter : desc)
    {
        cout << iter.first << "\t" << iter.second << endl;
    }
}
int handlerSize()
{
    return callbacks.size();
}

//布置任务
void sendAndWakeup(pid_t who, int fd, uint32_t command)
{
    write(fd, &command, sizeof(command));//向管道输入数据
    cout << "call process" << who << "execute" << desc[command] << "through" << fd << endl;
}