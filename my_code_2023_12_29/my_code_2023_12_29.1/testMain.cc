//testMain
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "threadPool.hpp"
#include "task.hpp"
#include "log.hpp"

int main()
{
    //种下随机种子
    srand((unsigned long)time(nullptr) ^ getpid());

    //创建线程池
    std::cout << "--thread Pool--" << '\n';
    ThreadPool<Task>* tp = new ThreadPool<Task>();
    tp->Run();

    //生产-消费过程
    while (true) 
    {
        //主线程承担生产的过程（可能需要一定的时间）
        int x = rand() % 100 + 1;
        usleep(1000);
        int y = rand() % 30 + 1;

        //制作任务
        Task t(x, y, [](int x, int y)->int {
            return x + y;
        });
        LogMessage(NORMAL, "%s:%d+%d=?", "completion of the production:", x, y);

        //推送任务
        tp->PushTask(t);
        sleep(1);
    }
    return 0;
}