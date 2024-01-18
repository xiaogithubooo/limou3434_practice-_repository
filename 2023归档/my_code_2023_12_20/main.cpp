//计算 CPU 的性能
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

unsigned long long count = 0;

void CatchSig(int sigNum) //该回调函数被调用的时候，会将编号传递给该函数的 sig
{
    cout << " 捕捉到信号为: " << sigNum
    << " 本进程pid为:" << getpid()
    << " 结果为:" << count
    << '\n';
    alarm(1);
}

int main(int argc, char* argv[])
{
    alarm(1);

    signal(SIGALRM, CatchSig);
    while(true) ++count;
    return 0;
}