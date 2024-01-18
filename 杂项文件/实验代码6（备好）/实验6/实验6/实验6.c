#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
//实验目的
//（1）了解循环的概念和方法
//（2）熟练掌握for语句和while语句
//（3）能够应用循环解决实际问题
//任务一、求阶乘问题（for语句）
//int main()
//{
//	int a = 1, i, n;
//	printf("请输入阶乘中的n（1~100）：");
//	scanf("%d", &n);
//	for (i = 1; i <= n; ++i)
//	{
//		a *= i;
//	}
//	printf("%d的阶乘是%d\n", n, a);
//	return 0;
//}
//任务二、字符统计问题
//int main()
//{
//	char ch;//存储字符
//	int upperNum = 0;//存储大写字母个数
//	int lowerNum = 0;//存储小写字母个数
//	int digitNum = 0;//存储数字字符的个数
//	printf("请输入一串字符，按回车结束：");
//	ch = getchar();
//	while (ch != '\n')
//	{
//		
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			++upperNum;
//		}
//		else if (ch >= 'a' && ch <= 'z')
//		{
//			++lowerNum;
//		}
//		else if (ch >= '0' && ch <= '9')
//		{
//			++digitNum;
//		}
//		else
//		{
//			printf("输入不合法！");
//		}
//		ch = getchar();
//	}
//	printf("大写字母个数为%d\n", upperNum);
//	printf("小写字母个数为%d\n", lowerNum);
//	printf("数字字符个数为%d\n", digitNum);
//	printf("So Easy!!!");
//	return 0;
//}
//任务三（综合任务）：无限循环计算阶乘的问题
//int main()
//{
//	double result = 1.0;
//	int n = 1;
//	while (1)
//	{
//		printf("请输入求阶乘中的n（1~100），输入负整数退出程序：");
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			break;
//		}
//		else if (n == 0)
//		{
//			continue;
//		}
//		else if (n >= 1 && n <= 100)
//		{
//			int a = 1, i;
//			for (i = 1; i <= n; ++i)
//			{
//				a *= i;
//			}
//			printf("%d的阶乘是%d\n", n, a);
//		}
//		else
//		{
//			break;
//		}
//	}
//	return 0;
//}