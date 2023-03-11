#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, c, n;
	printf("请输入一个数字\n");
	scanf("%d", &n);
	if (n <= 99 || n > 999)//非三位数
	{
		printf("该数字不是水仙花数");
	}
	else//是三位数
	{
		a = n % 10;//得到最后一位数
		b = (n / 10) % 10;//得到第二位数
		c = (n / 100);//得到第一位数

		if (n = a * a * a + b * b * b + c * c * c)
		{
			printf("该数是水仙花数\n");
		}
		else
		{
			printf("不是水仙花数\n");
		}
	}
	return 0;
}