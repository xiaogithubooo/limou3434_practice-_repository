#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;
extern int _age;
class Person
{
public:
	const char* _name;//姓名，注意这只是声明，不是定义
	const char* _sex;//性别，注意这只是声明，不是定义
	int _age;//年龄，注意这只是声明，不是定义
public:
	void Print(void);
};