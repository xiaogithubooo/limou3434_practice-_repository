#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//实验目的：
//（1）掌握数组的定义方法
//（2）熟练掌握数组赋值的方法
//（3）熟练掌握数组输入、输出的方法
//（4）熟练掌握数组作为函数参数的调用方法
//
//任务一：
//int main(void)
//{
//	double results[10];
//	int i = 0;
//	printf("成绩登记：\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("请输入第%d个学生的成绩：",i+1);
//		scanf("%Lf", &(results[i]));
//	}
//	printf("成绩如下：\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("第%d个学生的成绩：%.0Lf\n", i + 1, *(results+i));
//	}
//	return 0;
//}
//任务二：
//int main(void)
//{
//	double results[10];
//	int i = 0;
//	double max = 0, min = 100, sum = 0, average;
//	printf("成绩登记：\n");
//	for (; i < 10; i++)
//	{
//		printf("请输入第%d个学生的成绩：", i + 1);
//		scanf("%Lf", &results[i]);
//		if (max < results[i])
//		{
//			max = results[i];
//		}
//		if (min > results[i])
//		{
//			min = results[i];
//		}
//		sum += results[i];
//	}
//	average = sum / (sizeof(results) / sizeof(results[0]));//很奇怪？
//	printf("统计如下：\n");
//	printf("所有学生中最高分为：%Lf\n", max);
//	printf("所有学生中最低分为：%Lf\n", min);
//	printf("所有学生的平均值为：%Lf\n", average);
//	return 0;
//}
//任务三：
//int main(void)
//{
//	char a[20] = { 'H','e','l','l','o',' ','W','o','r','l','d' };
//	int i;
//	printf("加密前：");//加密前
//	for (i = 0; i < 20; i++)
//	{
//		printf("%c", a[i]);
//	}
///////////////////////////////////////////////////////////////////
//	printf("\n");//加密开始
//	for (i = 0; i < 20; i++)
//	{
//		if (a[i] >= 'a' && a[i] <= 'z')
//		{
//			a[i] += 5;
//			if (a[i] >= 'z')
//			{
//				a[i] = 'a' + (a[i] - 'z' - 1);
//			}
//		}
//		else if (a[i] >= 'A' && a[i] <= 'Z')
//		{
//			a[i] += 5;
//			if (a[i] >= 'Z')
//			{
//				a[i] = 'A' + (a[i] - 'Z' - 1);
//			}
//		}
//	}
///////////////////////////////////////////////////////////////////
//	printf("加密后：");
//	for (i = 0; i < 20; i++)//加密后
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}