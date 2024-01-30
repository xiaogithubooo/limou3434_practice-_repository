//尝试编写一个简单的进程池
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

//信道类
struct Channel
{
    Channel(const int& fd, const pid_t& id, const string& channelName)
        : _fd(fd), _id(id), _channelName(channelName) {}
    
    int _fd; //对应的管道文件
    pid_t _id; //对应的子进程 id
    string _channelName; //对应的信道名字（方便日志打印）
};

//子进程的工作
void work()
{
    int code = 0;
    ssize_t n = read(0, &code, sizeof(code)); assert(n != sizeof(code)); (void)n; //返回读取到的字节个数，断死不匹配字节的情况
    
}

//创建多个信道
/*
编码规范：
1.输入型参数(const &)
2.输出型参数(*)
3.输入输出型参数(&)
*/
const int PROCESS_NUM = 5; //进程池中子进程的数量
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
            dup2(pipefd[0], 0); //重定向到子进程的标准输入，可以避免给 work() 传参
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
        cout << it._channelName << ":" << it._id << "-->read[" << it._fd << "]" << endl;
    }
}

//打印选择界面
void PrintChoice()
{
    cout << "------------------------------------" << endl;
    cout << "| 1.show functions  2.send command |" << endl;
    cout << "| 3.quit the program               |" << endl;
    cout << "------------------------------------" << endl;
    cout << "<Please Select>:";
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
        //3.1.打印 UI 界面
        PrintChoice();

        //3.2.用户进行命令输入
        int n = 0;
        cin >> n;
        if (n == 1)
        {
            PrintChoice();
        }
        else if (n == 2)
        {
            //TODO
        }
        else if(n == 3)
        {
            goto BREAK;
        }
        else
        {
            assert(false); //断死其他的意外情况，供开发者调试使用
        }
    }

BREAK:
    return 0;
}





// //等待读取函数
// int waitCommand(int waitFd, bool& quit);

// //使用包装类定义一个调用类型（可以使用函数指针），指向的调用对象是各个任务
// //查询数据
// void readSQL();
// //解析地址
// void execuleUrl();
// //加密任务
// void cal();
// //数学计算
// void mathCalculate();

// //包装类对象


// void load();              //填充若干调用
// void show();              //查看任务名称
// int handlerSize();        //查看任务数量
// void sendAndWakeup(       //布置一个任务（父进程通过管道布置任务）
//     pid_t who, //子进程 pid
//     int fd, //管道文件标识符
//     int command //命令字符串
// ); 

// //处理主逻辑
// unordered_map<int, string> desc; //创建哈希表
// int main()
// {
//     //1.装载任务
//     load();

//     //2.构造进程池，让管道文件和子进程一一对应
//     vector<pair<pid_t, int>> slots;
    
//     for (int i = 0; i < PROCESS_NUM; i++)
//     {
//         //1.1.创建管道
//         int pipefd[2] = {0};
//         int n = pipe(pipefd); assert(n >= 0), (void)n;

//         //1.2.创建进程
//         pid_t id = fork(); assert(id != -1);

//         //1.2.1.子进程部分
//         if (id == 0)
//         {
//             close(pipefd[1]); //关闭子进程的管道文件写端，子进程读取父进程的命令
//             while (true)
//             {
//                 bool quit = false;
//                 int command = waitCommand(pipefd[0], quit); //如果父进程不写就进入阻塞，如果父进程关闭了写段就会设置 quit=false
//                 if (quit)
//                 {
//                     break;
//                 }
                
//                 if (command >= 0 && command < handlerSize())
//                 {
//                     callbacks[command](); //调用对应的方法
//                 }
//                 else
//                 {
//                     cout << "error command:" << command << endl; //报错
//                 }
//             }

//             exit(10); //设置子进程退出码
//         }

//         //1.2.2.父进程部分
//         close(pipefd[0]); //关闭父进程的读端，由父进程进行写入管道，通知其他进程
//         slots.push_back(pair<pid_t, int>(id, pipefd[1])); //子进程 id 和各管道写标识符建立键值对，调用哪一个进程就可以找到其对应的管道文件
//     }

//     //3.父进程派发任务（这就相当于单机版的负载均衡）
//     srand(((unsigned long)time(nullptr)) ^ getpid() ^ 114514L); //获取随机数（这里做了一些数据操作，让数据源更加随机）
//     while (true)
//     {
//         //3.1.打印 UI 界面
//         int n = 0;
//         int command = 0;
//         cout << "--------------------------------" << endl;
//         cout << "1.show functions  2.send command" << endl;
//         cout << "3.quit the program              " << endl;
//         cout << "--------------------------------" << endl;
//         cout << "<Please Select>:";

//         //3.2.用户进行命令输入
//         cin >> n;
//         if (n == 1)
//         {
//             show();
//         }
//         else if (n == 2)
//         {
//             show();
//             cout << "<Enter Your Command>:";
//             //选择任务
//             cin >> command;
//             //随机选择进程
//             int choice = rand() % slots.size();
//             //布置任务
//             sendAndWakeup(slots[choice].first, slots[choice].second, command); //传递子进程 id 和对应的管道文件 fd，还有参数 command 用来决定该进程执行哪一些任务
//         }
//         else if(n == 3)
//         {
//             cout << "This code has exited!" << endl;
//             goto BREAK;
//         }            
//         else
//         {
//             assert(false); //断死其他的意外情况，供开发者调试使用
//         }
//     }

// BREAK:
//     //4.关闭管道 fd（其实可以不关），等待回收所有子进程，并且获取子进程的退出码和信号
//     for (const auto slot : slots)
//     {
//         close(slot.second); //父进程关闭掉所有的写端
//     }
//     for (const auto& solt : slots)
//     {
//         int status = 0;
//         waitpid(solt.first, &status, WUNTRACED); //父进程阻塞回收所有子进程信息
//         cout << "sub exit code:" << WEXITSTATUS(status) << ", sub signal:" << WTERMSIG(status) << endl;
//     }

//     return 0;
// }

// void load()
// {
//     //注意 callbacks 会随着插入为变大
//     desc.insert({ callbacks.size(), "readSQL-读取数据库" });
//     callbacks.push_back(readSQL);

//     desc.insert({callbacks.size(), "execuleUrl-解析URL"});
//     callbacks.push_back(execuleUrl);

//     desc.insert({callbacks.size(), "cal-加密"});
//     callbacks.push_back(cal);

//     desc.insert({callbacks.size(), "mathCalculate-数学计算"});
//     callbacks.push_back(mathCalculate);
// }

// int handlerSize()
// {
//     /* 返回任务数量 */
//     return callbacks.size();
// }

// void sendAndWakeup(pid_t who, int fd, int command)
// {
//     write(fd, &command, sizeof(command)); //向管道输入指定的任务

//     cout << "call process:" << who //指定某子进程
//         << ", execute:" << desc[command] //执行某任务
//         << ", through:" << fd //直通某管道
//         << endl;
// }

// void show()
// {
//     /* 查看可执行的任务列表 */
//     for(const auto &iter : desc)
//     {
//         cout << iter.first << "\t" << iter.second << endl;
//     }
// }

// int waitCommand(int waitFd, bool& quit) //注意 quit 是引用参数
// {
//     int command = 0; //四字节缓冲区
//     ssize_t s = read(waitFd, &command, sizeof(command)); //从读端读给 command
//     if(s == 0) //如果 s 为 0，则说明父进程已经关闭了写段，此时就应该停止后续的代码
//     {
//         quit = true;
//         return -1;
//     }
//     return command;
// }

// void readSQL()
// {
//     sleep(3);
//     cout << "process[" << getgid() << "] 执行了访问数据库的任务" << endl;
// }
// void execuleUrl()
// {
//     sleep(3);
//     cout << "process[" << getgid() << "] 执行了解析URL地址的任务" << endl;
// }
// void cal()
// {
//     sleep(3);
//     cout << "process[" << getgid() << "] 执行了加密的任务" << endl;
// }
// void mathCalculate()
// {
//     sleep(3);
//     cout << "process[" << getgid() << "] 执行了数学计算的任务" << endl;
// }