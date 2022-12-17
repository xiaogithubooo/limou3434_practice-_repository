#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//1、有关于字符串被改写成单个字符的问题
//int main()
//{
//	char arr[5] = { 'a','b','c'};
//	printf("%d\n", strlen(arr));//输出3则就说明,arr确实后面被自动赋值为\0了
//	
//	char a[] = { 'a','b','c' };
//	printf("%d\n", strlen(arr));//尽管输出了3，但是这对于不同的编译器之间是不一样的，其结果是随机的
//	return 0;
//}

//2、有关负数的取模运算（%）
/*int main()
{
	int i = 5 % -3;
	printf("%d\n", i);
	int j = -5 % -3;
	printf("%d\n", j);

	i = 100 % 7;
	j = -100 % 7;
	printf("%d\n", i);
	printf("%d\n", j);
	return 0;
}*///貌似还是有区别的！！！之后研究

//3、验证前置与后置在三种循环中的书写是否有区别？
/*int main()
{
	int i = 0;
	for(i = 5; i > 0; i--)
	{
		printf("%d\n", i);
	}
	printf("\n");
	for(i = 5; i > 0; --i)
	{
		printf("%d\n", i);
	}
	printf("*****************\n");
	i = 5;
	while (i > 0)
	{
		printf("%d\n", i);
		i--;
	}
	printf("\n");
	i = 5;
	while (i > 0)
	{
		printf("%d\n", i);
		--i;
	}
	printf("*****************\n");
	i = 5;
	do
	{
		printf("%d\n", i);
		i--;
	} while (i > 0);
	printf("\n");
	i = 5;
	do
	{
		printf("%d\n", i);
		--i;
	} while (i > 0);
	return 0;
}*///貌似在三种循环的内部都是没有区别的，这里以后还可以研究一下……

//4、今天先写博客


