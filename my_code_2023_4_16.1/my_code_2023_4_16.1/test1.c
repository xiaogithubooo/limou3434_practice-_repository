#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//extern void test(void); //�����ⲿ����
extern void (*ptest)(void);
extern void fun(void);
int main()
{
	//test();//ʹ���ⲿ����
	(*ptest)();
	fun();
	return 0;
}
