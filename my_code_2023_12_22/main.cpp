#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
using namespace std;

void ShowPending(sigset_t& pending)
{
    cout << "进程 " << getpid() << " 打印一次 pending 集合" << '\n';
    for(int sig = 1; sig <= 31; sig++)
    {
        if(sigismember(&pending, sig))
            cout << "1";
        else
            cout << "0";
    }
    cout << '\n';
}

int main()
{
    //屏蔽所有信号
    sigset_t best;

    for(int sig = 0; sig <= 31; sig++)
    {
        sigemptyset(&best);
        sigaddset(&best, sig);
        int n = sigprocmask(SIG_BLOCK, &best, nullptr);
        assert(n == 0), (void) n;
    }

    //不断获取 pending 信号集并且打印
    sigset_t pending;
    while(true)
    {
        sigpending(&pending);
        ShowPending(pending);
        sleep(1);
    }
    return 0;
}