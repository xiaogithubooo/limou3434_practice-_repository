#define _CRT_SECURE_NO_WARNINGS 1
//��־
//1��strlen����ʹ�õݹ�ʵ��
//2��strlenʹ�÷ǵݹ�ʵ��
//3��ʹ�õݹ�ʵ��n��k�η�
//4������һ������ÿλ֮�ͣ����õݹ飩

#include<stdio.h>
//1��strlen����ʹ�õݹ�ʵ��
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
//2��strlenʹ�÷ǵݹ�ʵ��
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
//3��ʹ�õݹ�ʵ��n��k�η�
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
//4������һ������ÿλ֮�ͣ����õݹ飩
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