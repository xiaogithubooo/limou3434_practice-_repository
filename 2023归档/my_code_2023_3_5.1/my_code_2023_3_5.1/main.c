#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//日志：修改作业
//1、测试字符串使用scanf输入时，使用&arr和arr的区别
//2、输入正整数n，输出从1到n位十进制，并且返回一个整数列表


//1、测试字符串使用scanf输入时，使用&arr和arr的区别
int main()
{
	char arr[10];
	scanf("%s", &arr);
	printf("%s", arr);
	return 0;
}
//2、输入正整数n，输出从1到n位十进制，并且返回一个整数列表
int* printNumbers(int n, int* returnSize) 
{
	*returnSize = pow(10, n) - 1; //确定最大的数字
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));//申请足够大小的空间
	for (int i = 0; i < *returnSize; i++) 
	{
		arr[i] = i + 1;//下标从0开始，而数值从1开始
	} 
	return arr;
}
int main()
{
	int n = 0;
	int number = 0;
	scanf("%d", &n);
	int* a = printNumbers(n, &number);
	for (int i = 0; i < number; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}