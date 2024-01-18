#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include "头文件.h"
//实验目的
//（1）掌握的类型
//（2）熟练掌握函数的传参
//（3）熟练掌握return语句
//（4）熟练掌握函数的调用

//任务一：使用函数求阶乘
//方法1
//int main(void)
//{
//	double result = 1.0;//存储阶乘结果
//	int n = 1;//存储整数n
//	int fun(int n);//声明fun函数
//	printf("请输入求阶乘中得n（1~100）：");
//	scanf("%d", &n);
//	result = fun(n);
//	printf("%.0f", result);
//	return 0;
//}
//方法2
int main()
{
	while (1)
	{
		double result = 1;//存储阶乘结果
		int n = 1;//存储整数n
		int jieCheng(int n);//声明阶乘函数
		printf("请输入一个整数：");
		scanf("%d", &n);
		result = jieCheng(n);                                //植入实验8的内容
		if (n < 0)
		{
			printf("输入不合法");
			break;
		}
		printf("%d的阶乘为：%f\n\n", n, result);
	}
	return 0;
}


////任务二：面积和体积计算问题
int main(void)
{
	float length = 0, width = 0, height = 0, area = 0, volume = 0;
	float getRectArea(float length, float width);//声明面积函数
	float getCuboidVolume(float length, float width, float height);//声明体积函数
	while (1)
	{                                                                                                          //实验8的循环输入也植入了
		printf("请依次输入长度、宽度和高度（如1.0，2.0，3.0）：");
		scanf("%f，%f，%f", &length, &width, &height);
		area = getRectArea(length, width);
		volume = getCuboidVolume(length, width, height);
	
		printf("矩形（长：%f，宽：%f）的面积为：%f\n", length, width, area);
		printf("长方体（长：%f，宽：%f，高：%f）的体积为：%f\n\n", length, width, height, volume);
		if (area < 0)
		{
			break;
		}
	}
	return 0;
}


//任务三：成绩分类问题
int main()
{		
	int grade = -1;
	char gradeLeve1 = 'A';
	char getGradeLevel(int grade);//声明等级函数
	while (1)
	{
		printf("请输入成绩（0~100）\n");
		scanf("%d", &grade);

		gradeLeve1 = getGradeLevel(grade);
		printf("成绩 %d的等级是：%c\n", grade, gradeLeve1);
		
		if (gradeLeve1=='0')                                                    //植入了实验8
		{
			printf("So Easy!!!!!");
			break;
		}
	}
	return 0;
}
