#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//��ȷ����
class Person
{
public:
    void PrintPersonInfo();
public:
    char* _name;
    char* _sex;
    int _age;
};
void Person::PrintPersonInfo()
{
    cout << _name << " " << _sex << " " << _age << endl;
}
 //���м��г�Ա���������г�Ա����
class A1
{
public:
    void f1() {}
private:
    int _a;
};

 //���н��г�Ա����
class A2
{
public:
    void f2() {}
};

 //����ʲô��û��---����
class A3
{};

int main()
{
    Person man;
    man._name = (char*)"limou3434";//����C++���ͼ��Ƚ��ϸ񣬹ʼ���ǿ��ת��
    man._age = 10;
    man._sex = (char*)"��";//����C++���ͼ��Ƚ��ϸ񣬹ʼ���ǿ��ת��
    man.PrintPersonInfo();
    cout << sizeof(A1) << " " << sizeof(A2) << " " << sizeof(A3) << endl;
    return 0;
}