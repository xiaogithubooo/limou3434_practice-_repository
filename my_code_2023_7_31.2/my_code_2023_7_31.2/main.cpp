//PTA第一题
/*
通讯录中的一条记录包含下述基本信息：
朋友的姓名、出生日期、性别、固定电话号码、移动电话号码。
本题要求编写程序，录入N条记录，并且根据要求显示任意某条记录。

输入格式：
输入在第一行给出正整数N（≤10）；
随后N行，每行按照格式“姓名 生日 性别 固话 手机”给出一条记录。
其中姓名是不超过10个字符、不包含空格的非空字符串；
生日按yyyy / mm / dd的格式给出年月日；
性别用M表示“男”、F表示“女”；
固话和手机均为不超过15位的连续数字，前面有可能出现 + 。
在通讯录记录输入完成后，最后一行给出正整数K，
并且随后给出K个整数，表示要查询的记录编号（从0到N−1顺序编号）。
数字间以空格分隔。

输出格式：
对每一条要查询的记录编号，
在一行中按照“姓名 固话 手机 性别 生日”的格式输出该记录。
若要查询的记录不存在，则输出“Not Found”。
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct MyStruct
{
	//姓名
	char _name[11];
	//出生年月日
	char _yearMonthDay[20];
	//性别
	char _sex;
	//固定电话
	char _number1[17];
	//移动电话
	char _number2[17];
}MyStruct;
void test_1()
{
	//1.需要输入的N个记录（N属于[0,10]）
	int N = 0;
	int scanfReturn = scanf("%d", &N);
	MyStruct* arr = (MyStruct*)malloc(sizeof(MyStruct) * N);
	if (!arr) exit(-1);

	//2.输入数据
	for (int i = 0; i < N; i++)//循环K次
	{
		scanfReturn = scanf("%s %s %c %s %s",
			arr[i]._name,
			arr[i]._yearMonthDay,
			&(arr[i]._sex),
			arr[i]._number1,
			arr[i]._number2);
	}
		
	//3.需要输出的K个记录以及编号nums（K属于[0,N]）
	int K = 0;
	scanfReturn = scanf("%d", &K);
	int* nums = (int*)malloc(sizeof(int) * K);
	for (int i = 0; i < K; i++)//循环K次，存储编号，编号从0开始
	{
		scanfReturn = scanf("%d", &nums[i]);
	}
	if (N == 0)
	{
		while (K)
		{
			printf("Not Found\n");
			K--;
		}
	}
	for (int j = 0; j < K; j++)
	{
		if (nums[j] >= N || nums[j] < 0)
		{
			printf("Not Found\n");
			continue;
		}
		printf("%s %s %s %c %s",
			arr[nums[j]]._name,
			arr[nums[j]]._number1,
			arr[nums[j]]._number2,
			arr[nums[j]]._sex,
			arr[nums[j]]._yearMonthDay);
		if (j < (K - 1))
		{
			printf("\n");
		}
	}
	//4.销毁资源
	free(arr);
	free(nums);
}
//PTA第二题目
/*
将一个正整数N分解成几个正整数相加，
可以有多种分解方法，例如7=6+1，7=5+2，7=5+1+1，…。
编程求出正整数N的所有整数分解式子。
*/
void test_2()
{
	int N = 0;
	int scanfReturn = scanf("%d", &N);
}
int main()
{
	//test_1();
	test_2();
	return 0;
}
