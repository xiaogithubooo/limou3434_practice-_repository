#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double fun(double n)
{
	if (n < 0)//如果传过来负数，令该函数返回 -1 表示出错
		return -1;
	double number = 1;
	for (double i = n; i > 0; i--)
	{
		number *= i;
	}
	return number;
}
int main()
{
	for(int e = 0; e < 100; e++)//循环打印 10 次
	{
		printf("%f\n", fun(e));
	}
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//double fun(double n)
//{
//	if (n < 0)//如果传过来负数，令该函数返回 -1 表示出错
//		return -1;
//
//	if (n == 1 || n == 0)
//		return 1;
//	return n * fun(n - 1);
//}
//int main()
//{
//	for (int e = 0; e < 100; e++)//循环打印 10 次
//	{
//		printf("%f\n", fun(e));
//	}
//	return 0;
//}