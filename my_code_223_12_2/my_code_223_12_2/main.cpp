#include <iostream>
using namespace std;

int main()
{
    //����
    int x = 10, y = 5;

    //lambda���ʽû�в����б�����ֱ�Ӹ�ֵ������ָ��
    auto func1 = []() { cout << "Hello, World!" << endl; };
    void(*ptr1)() = func1;
    ptr1(); //�����Hello, World!

    //lambda���ʽ���в����б��޷�ֱ�Ӹ�ֵ������ָ��
    //int(*ptr2)() = [x, &y]() { return x + y; }; //�������

    return 0;
}
