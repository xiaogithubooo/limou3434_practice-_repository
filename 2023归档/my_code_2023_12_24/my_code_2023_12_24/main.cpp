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

    thread t(func); //�����߳�
    Sleep(2000);

    t.join(); //�����߳�

    return 0;
}