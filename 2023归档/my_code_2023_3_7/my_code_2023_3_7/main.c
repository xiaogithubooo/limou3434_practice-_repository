#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��־������ҵ
//1��ʹ�õݹ����쳲���������
//2��ʹ�õݹ齫�ַ����������

//1��ʹ�õݹ����쳲���������
long fun(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fun(n - 1) + fun(n - 2);
}
int main()
{
	int number = 0;
	scanf("%d", &number);
	printf("%ld\n", fun(number));
	return 0;
}
//2��ʹ�õݹ齫�ַ����������
void function(char* arr1, char* arr2)
{
	if (arr1 < arr2)
	{
		char a = *arr1;
		*arr1 = *arr2;
		*arr2 = a;
		function(arr1 + 1, arr2 - 1);
	}
}
int main()
{
	char arr[] = "abcdef";
	printf("%s\n", arr);
	function(arr, arr + (sizeof(arr)/sizeof(arr[0])) - 2);
	printf("%s\n", arr);
	return 0;
}