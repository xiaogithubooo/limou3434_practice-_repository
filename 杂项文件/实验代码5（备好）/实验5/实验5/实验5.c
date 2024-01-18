#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
//实验目的
//（1）了解C语言表示逻辑量的方法
//（2）学会了正确使用逻辑运算符和逻辑表达式
//（3）熟练掌握if语句和switch语句
//（4）结合程序掌握一些简单的算法
//（5）学习调试程序
//任务一：成绩分类问题（多分支if结构）
//int main()
//{
//	int grade = -1;
//	char gradeLeve1 = '0';
//
//	printf("请输入成绩（0~100）\n");
//	scanf("%d", &grade);
//
//	if ((grade >= 0) && (grade < 60))
//	{
//		gradeLeve1 = 'E';
//	}
//	else if ((grade >= 60) && (grade < 70))
//	{
//		gradeLeve1 = 'D';
//	}
//	else if ((grade >= 70) && (grade < 80))
//	{
//		gradeLeve1 = 'C';
//	}
//	else if ((grade >= 80) && (grade < 90))
//	{
//		gradeLeve1 = 'B';
//	}
//	else if ((grade >= 90) && (grade <= 100))
//	{
//		gradeLeve1 = 'A';
//	}
//	printf("成绩 %d的等级是%c：\n", grade, gradeLeve1);
//	printf("So Easy!!!!!");
//	return 0;
//}
//任务二：成绩分类问题（多分支switch结构）
//int main()
//{
//	int grade = -1;
//	int grande_d10 = -1;
//	char gradeLeve1 = '0';
//	printf("请输入成绩（0~100）\n");
//	scanf("%d", &grade);
//	grande_d10 = grade / 10;
//	switch (grande_d10)
//	{
//	case 10:
//	case 9:
//		gradeLeve1 = 'A';
//		break;
//	case 8:
//		gradeLeve1 = 'B';
//		break;
//	case 7:
//		gradeLeve1 = 'C';
//		break;
//	case 6:
//		gradeLeve1 = 'D';
//		break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:
//	case 0:
//		gradeLeve1 = 'E';
//		break;
//	}
//	printf("成绩%3d的等级是%c：\n", grade, gradeLeve1);
//
//	printf("So Easy!!!!!\n");
//	return 0;
//}
//任务三（综合任务）
//int main()
//{
//	int stuNum = 0;//存储学号
//	int remainder = -1;//存学号的最后一位
//	int weekNum = 0;//存储周数
//	int i;//自定义
//	//处理学号
//	printf("请输入学号（ 范围为[142011001，142015000) ）：");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &stuNum);
//		if ((stuNum >= 142011001) && (stuNum < 142015000))
//		{
//			break;
//		}
//		else
//		{
//			printf("学号输入错误，应该在[142011001，142015000)内：");
//			continue;
//		}
//	}
//	//处理周数
//	printf("\n");
//	printf("请输入周数（ [1,20] ）：");
//
//	for (i=0;i<10;i++)
//	{
//		scanf("%d", &weekNum);
//		if ((weekNum >= 1) && (weekNum <= 20))
//		{
//			break;
//		}
//		else
//		{
//			printf("周数输入错误，应该在[1，20]内：");
//			continue;
//		}
//	}
//	
//	remainder = stuNum % 10;
//	if (remainder % 3 == weekNum % 3)//最后一位%3和周数%3相等即可
//	{
//		printf("学生%d在第%d周应该交作业吗？是\n", stuNum, weekNum);
//	}
//	else
//	{
//		printf("学生%d在第%d周应该交作业吗？否\n", stuNum, weekNum);
//	}
//	return 0;
//}