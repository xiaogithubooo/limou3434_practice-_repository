//多次发送 2 号信号和其他信号，观察 pending 表的变化
#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

volatile int flag = 0;

void ChangFlag(int signum)
{
    cout << "捕捉到信号:" << signum << '\n';
    cout << "修改 flag=1" << '\n';
    flag = 1;
}

int main()
{
    signal(2, ChangFlag);
    while(!flag)
    {
        //cout << "flag..." << '\n';
        //sleep(1);
    }
    return 0;
}