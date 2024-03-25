//main.cpp(线程池)
#include <iostream>
#include <memory>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "thread_pool.hpp"
#include "task.hpp"

std::string opers = "+-*/%";

const int gProductionSpeed = 1; //生产速度

int main()
{
    //std::unique_ptr<ThreadPool<Task>> tp(new ThreadPool<Task>());    
    ThreadPool<Task>* tp = ThreadPool<Task>::GetInstance();
    tp->Start();

    while(true)
    {
        //制作任务
        int data_1 = rand() % 10;
        usleep(rand() % 100); //避免两个随机值一样
        int data_2 = rand() % 10;
        char oper = opers[rand() % opers.size()];
        Task t(data_1, data_2, oper);
        std::cout << t.Show() << std::endl;

        //插入任务
        tp->Push(t);
        sleep(gProductionSpeed);
    }

    tp->Wait();
    return 0;
}

