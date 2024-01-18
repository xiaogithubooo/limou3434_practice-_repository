#define _CRT_SECURE_NO_WARNINGS 1
//PTAÌâÄ¿;BCDÊý£¬https://pintia.cn/problem-sets/14/exam/problems/784
#include <stdio.h>
int main()
{
	long number = 0;
	scanf("%ld", &number);
	int num1 = number & 15;
	int num2 = number & 240;
	num2 >>= 4;
	if (num1 > 10 || num2 > 10)
	{
		return 0;
	}
	printf("%d", num2 * 10 + num1);
	return 0;
}