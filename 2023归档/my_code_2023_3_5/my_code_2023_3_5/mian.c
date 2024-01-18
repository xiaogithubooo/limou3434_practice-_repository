#define _CRT_SECURE_NO_WARNINGS 1
//日志：修改作业
//1、计算一个补码的1的个数
//2、sizeof的隐蔽错误

//1、计算一个补码的1的个数
#include<stdio.h>
int count_one_bit(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
 //int main()
{
	printf("%d", count_one_bit(999));
	return 0;
}
//2、sizeof的隐蔽错误
#include <stdio.h>
int i;
int main()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}