//使用 sigaction() 做类似 signal() 的行为
#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void handler(int signum)
{
    cout << "获取信号:" << signum << '\n';
    sleep(10); //尝试在 10s 内不断发送 2 号信号
}
int main()
{
    signal(2, SIG_IGN); //捕捉到 2 号信号，对于的信号行为是 SIG_IGN，即忽略

    struct sigaction act, oact; //设置新旧信号捕捉结构体
    
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask); //清空信号集
    act.sa_handler = handler;

    sigaction(2, &act, &oact);

    while (true)
    {
        cout << "pid:" << getpid() << endl
        << " 新捕捉方法:" << (void*)(oact.sa_handler) << endl
        << " 旧捕捉方法:" << (void*)(act.sa_handler) << endl;
        sleep(1);
    }

    return 0;
}