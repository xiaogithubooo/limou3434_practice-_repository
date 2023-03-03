#define _CRT_SECURE_NO_WARNINGS 1
//日志
//主要针对递归和非递归解决问题
#include <stdio.h>
//1、使用递归的方式
void function(int number)
{
	int num = number;
	if (num > 10)
	{
		function(num /= 10);
	}
	printf("%d ", number % 10);
}
int main()
{
	int number = 0;
	scanf("%d", &number);
	function(number);
	return 0;
}
//2、递归实现n的阶乘
int fun(int number)
{
	if (number == 0 || number == 1)
	{
		return 1;
	}
	return number * fun(number - 1);
}
int main()
{
	int number = 0;
	scanf("%d", &number);
	printf("%d", fun(number));
	return 0;
}
//3、非递归实现阶乘
int main()
{
	int number = 0;
	int add = 1;
	scanf("%d", &number);
	if (number == 1 && number == 0)
	{
		printf("1\n");
	}
	else if (number >= 2)
	{
		while (number)
		{
			add *= number;
			number--;
		}
		printf("%d", add);
	}
	else
	{
		printf("输入错误");
	}
	return 0;
}