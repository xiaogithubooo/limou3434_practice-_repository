#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

void func()
{
    sigset_t pending;
    sigpending(&pending);
    for (int i = 1; i <= 45; i++)
    {
        if (sigismember(&pending, i))
            std::cout << "1";
        else
            std::cout << "0";
    }
    std::cout << '\n';
}

int main()
{
    sigset_t sigset, osigset;
    sigemptyset(&sigset); //清空信号集
    sigaddset(&sigset, 2); //添加 2 号信号
    sigaddset(&sigset, 40); //添加 40 号信号

    sigprocmask(SIG_BLOCK, &sigset, &osigset); //阻塞信号
    
    while (true)
        std::cout << "echo:", func(), sleep(1);

    return 0;
}
