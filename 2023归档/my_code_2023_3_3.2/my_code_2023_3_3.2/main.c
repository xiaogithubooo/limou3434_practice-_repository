#define _CRT_SECURE_NO_WARNINGS 1
//��־
//��Ҫ��Եݹ�ͷǵݹ�������
#include <stdio.h>
//1��ʹ�õݹ�ķ�ʽ
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
//2���ݹ�ʵ��n�Ľ׳�
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
//3���ǵݹ�ʵ�ֽ׳�
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
		printf("�������");
	}
	return 0;
}