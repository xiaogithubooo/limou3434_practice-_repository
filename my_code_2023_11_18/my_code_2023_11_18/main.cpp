#include <iostream>
int main()
{
    const int x = 1;
    double y = 2.3;

    //decltype ���Ը��ݱ��ʽ����������������
    decltype(x * y) ret;//ret�����ͱ���� double
    decltype(&x) p;//p�����ͱ���� const int*

    std::cout << typeid(ret).name() << '\n';
    std::cout << typeid(p).name() << '\n';

    return 0;
}