#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//正确做法
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
 //类中既有成员变量，又有成员函数
class A1
{
public:
    void f1() {}
private:
    int _a;
};

 //类中仅有成员函数
class A2
{
public:
    void f2() {}
};

 //类中什么都没有---空类
class A3
{};

int main()
{
    Person man;
    man._name = (char*)"limou3434";//由于C++类型检查比较严格，故加上强制转化
    man._age = 10;
    man._sex = (char*)"男";//由于C++类型检查比较严格，故加上强制转化
    man.PrintPersonInfo();
    cout << sizeof(A1) << " " << sizeof(A2) << " " << sizeof(A3) << endl;
    return 0;
}