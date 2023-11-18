#include <iostream>
int main()
{
    const int x = 1;
    double y = 2.3;

    //decltype 可以根据表达式的类型来创建变量
    decltype(x * y) ret;//ret的类型变成了 double
    decltype(&x) p;//p的类型变成了 const int*

    std::cout << typeid(ret).name() << '\n';
    std::cout << typeid(p).name() << '\n';

    return 0;
}