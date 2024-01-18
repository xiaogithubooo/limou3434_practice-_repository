#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int c = 100;
static void test(void)
{
	printf("limou:%d\n", c);
}

void (*ptest)(void) = &test;

void fun(void)//间接使用方法2
{
	test();
}