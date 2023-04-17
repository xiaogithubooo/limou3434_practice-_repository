#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//extern void test(void); //声明外部函数
extern void (*ptest)(void);
extern void fun(void);
int main()
{
	//test();//使用外部函数
	(*ptest)();
	fun();
	return 0;
}
