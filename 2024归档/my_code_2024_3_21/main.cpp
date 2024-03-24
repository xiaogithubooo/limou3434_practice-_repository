//main.cpp
#include <iostream>
#include <memory>
#include "thread_pool.hpp"

int main()
{
    std::unique_ptr<ThreadPool<int>> tp(new ThreadPool<int>());    
    tp->Start();
    tp->Wait();
    return 0;
}
