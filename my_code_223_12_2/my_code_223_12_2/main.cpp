#include <iostream>
using namespace std;

int main()
{
    //交换
    int x = 10, y = 5;

    //lambda表达式没有捕获列表，可以直接赋值给函数指针
    auto func1 = []() { cout << "Hello, World!" << endl; };
    void(*ptr1)() = func1;
    ptr1(); //输出：Hello, World!

    //lambda表达式带有捕获列表，无法直接赋值给函数指针
    //int(*ptr2)() = [x, &y]() { return x + y; }; //编译错误

    return 0;
}
