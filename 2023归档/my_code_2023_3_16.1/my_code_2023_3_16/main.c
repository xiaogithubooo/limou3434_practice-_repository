#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////BCD数，但是失败了，明白了原因，C语言没有比一个字节再小的数据类型了
int main()
{
	long number = 0;
	scanf("%ld", &number);
	char num1 = *((char*)(&number));
	char num2 = *(((char*)(&number)) + 1);
	if (num1 > 10 || num2 > 10)
	{
		char num = num1 + num2 * 10;
		printf("%d %d\n", num1, num2);
		printf("%d", num);
	}
	return 0;
}