#define _CRT_SECURE_NO_WARNINGS 1
//日志
//1、strlen函数使用递归实现
//2、strlen使用非递归实现
//3、使用递归实现n的k次方
//4、计算一个数的每位之和（采用递归）

#include<stdio.h>
//1、strlen函数使用递归实现
int function(char* arr)
{
	static number = 0;
	if (*arr != '\0')
	{
		arr++;
		number++;
		function(arr);
	}
	else
	{
		return number;
	}
}
int main()
{
	char arr[20] = "abcdefghijkl";
	printf("%d", function(arr));
	return 0;
}
//2、strlen使用非递归实现
int function(const char* arr)
{
	int number = 0;
	while (*arr)
	{
		number++;
		arr++;
	}
	return number;
}
int main()
{
	char arr[20] = "abcdefghijklm";
	printf("%d", function(arr));
	return 0;
}
//3、使用递归实现n的k次方
int function(int number, int k)
{
	static int add = 1;
	add = 1 * number;
	if (k > 1)
	{
		k--;
		add = function(number, k)* number;
	}
	else
	{
		return add;
	}
}
int main()
{
	int number = 0;
	int k = 0;
	scanf("%d %d", &number, &k);
	printf("%d", function(number, k));
	return 0;
}
//4、计算一个数的每位之和（采用递归）
int function(int number)
{
	static int add = 0;
	if (number >= 10)
	{
		add = function(number / 10) + (number % 10);
	}
	else
	{
		add += number;
	}
	return add;
}
int main()
{
	int number = 45239994;
	printf("%d", function(number));
	return 0;
}