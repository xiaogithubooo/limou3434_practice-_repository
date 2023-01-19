#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、测试能替换美式键盘的库
#include <iso646.h>//在这个库是可以有替换方案的
int main()
{
	int a = 1, b = 2;
	if (a == 1 and b == 2)
	{
		printf("你好！");
	}
	return 0;
}
//2、测试一道题目
int main()
{
	int x = -1;
	unsigned int y = 2;
	if (x > y)
	{
		printf("x is greater");
	} 
	else
	{
	printf("y is greater");
	} 
	return 0;
}
//3、测试一道题目
int main()
{
	int i = 1;
	sizeof(i++);
	printf("%d\n", i);
	return 0;
}