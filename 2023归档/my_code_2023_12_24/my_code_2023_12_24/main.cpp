#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

void func()
{
    cout << "I am a new thread!" << '\n';
    Sleep(1000);
}

int main()
{
    cout << "I am a main thread!" << '\n';

    thread t(func); //创建线程
    Sleep(2000);

    t.join(); //销毁线程

    return 0;
}