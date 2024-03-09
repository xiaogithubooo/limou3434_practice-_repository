#include <iostream>
#include <unistd.h>
#include "thread.hpp"

void Print(int num)
{
    sleep(1);
    while (num)
    {
        std::cout << "hello world: " << num-- << std::endl;
        sleep(1);
    }
}

int main()
{
    Thread<int> t("My new thread", Print, 10);
    t.Start();
    std::cout << t.IsRunning() << std::endl;
    std::cout << t.ThreadName() << std::endl;
    t.Join();
    return 0;
}