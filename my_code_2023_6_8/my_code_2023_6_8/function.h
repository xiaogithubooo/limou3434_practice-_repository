#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;
extern int _age;
class Person
{
public:
	const char* _name;//������ע����ֻ�����������Ƕ���
	const char* _sex;//�Ա�ע����ֻ�����������Ƕ���
	int _age;//���䣬ע����ֻ�����������Ƕ���
public:
	void Print(void);
};