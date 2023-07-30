#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
//PTA第一题
/*
一、二分法求函数根的原理为：如果连续函数f(x)在区间[a, b]的两个端点取值异号，即f(a)f(b) < 0，则它在这个区间内至少存在1个根r，即f(r) = 0。
二、二分法的步骤为：
1.检查区间长度，如果小于给定阈值，则停止，输出区间中点(a + b) / 2，否则
2.如果f(a)f(b) < 0，则计算中点的值f((a + b) / 2)；
3.如果f((a + b) / 2)正好为0，则(a + b) / 2就是要求的根，否则
	如果f((a + b) / 2)与f(a)同号，则说明根在区间[(a + b) / 2, b]，令a = (a + b) / 2，重复循环；
	如果f((a + b) / 2)与f(b)同号，则说明根在区间[a, (a + b) / 2]，令b = (a + b) / 2，重复循环。
三、本题目要求编写程序，计算给定3阶多项式f(x)，输出格式：在一行中输出该多项式在该区间内的根，精确到小数点后2位。
*/
/*
//1.定义各方面系数和数据
double a3 = 0, a2 = 0, a1 = 0, a0 = 0;//三阶函数的系数
double a = 0, b = 0;//区间系数

//2.f(x)三阶函数的定义
double Function(double x)
{
	return a3 * (x * x * x) + a2 * (x * x) + a1 * (x) + a0;
}

//3.二分法的主函数main()
int main()
{
	//4.获取各方面系数和数据
	int scanfReturn = scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	scanfReturn = scanf("%lf %lf", &a, &b);

	double begin = a;
	double end = b;
	double mind = 0;
	int i = 1;
	//5.进行不间断的二分法，变量i是为了方便调试设计的
	while (i)
	{
		mind = (begin + end) / 2;
		double beginValue = Function(begin);
		double endValue = Function(end);
		double mindValue = Function(mind);
		if (fabs(beginValue) < DBL_EPSILON)//说明等于0
		{
			printf("%.2lf", begin);
			return 0;
		}
		else if (fabs(endValue) < DBL_EPSILON)//说明等于0
		{
			printf("%.2lf", end);
			return 0;
		}
		else//说明均不等于0
		{
			if (fabs(mindValue) < 0)//说明等于0
			{
				printf("%.2lf", mind);
				return 0;
			}
			else if (mindValue > 0)
			{
				if (beginValue < 0)
				{
					end = mind;
				}
				else
				{
					begin = mind;
				}
			}
			else//mindValue < 0
			{
				if (beginValue < 0)
				{
					begin = mind;
				}
				else
				{
					end = mind;
				}
			}
		}
		i++;
	}
	return 0;
}
*/

//PTA第二题
/*
乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。
1.乌龟每分钟可以前进3米，兔子每分钟前进9米；
2.兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟：
	2.1.每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息30分钟
	2.2.否则继续跑10分钟
3.乌龟非常努力，一直跑，不休息。
4.假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？
5.在一行中输出比赛的结果：
	乌龟赢输出@_@，
	兔子赢输出^_^，
	平局则输出-_-；
	后跟1空格，再输出胜利者跑完的距离。
*/
//int main()
//{
//	int T = 0;//比赛举行的min数
//	int scanfReturn = scanf("%d", &T);
//	int	rabbitS = 0;//兔子的总路程
//	int tortoiseS = 0;//乌龟的总路程
//	int timer = 10;//计时器
//	while (T)
//	{
//		if (timer == 0)
//		{
//			timer = 10;
//			if (T > 10)
//			{
//				tortoiseS += (3 * 10);
//				T -= 10;
//			}
//			else
//			{
//				tortoiseS += (3 * T);
//				T = 0;
//			}
//		}
//		rabbitS += 9;
//		tortoiseS += 3;
//		timer--;
//		T--;
//	}
//	if (rabbitS > tortoiseS)
//	{
//		printf("^_^ %d", rabbitS);
//	}
//	else if (rabbitS < tortoiseS)
//	{
//		printf("@_@ %d", tortoiseS);
//	}
//	else
//	{
//		printf("-_- %d", rabbitS);
//	}
//	return 0;
//}

//PTA第三题
int GetNumber(int x, int y)
{
	if (y == 0)//最后没有剩余的
		return x;
	int r = x % y;//相当于x - n * y后剩余的部分r
	return GetNumber(y, r);//递归了就变成y - n * r
}
int main()
{
	int N = 0;
	scanf("%d", &N);
	int tmp = N;

	int fenz = 0;
	int fenm = 0;
	scanf("%d/%d", &fenz, &fenm);
	while (N - 1)
	{
		int a = 0;
		int b = 0;
		scanf("%d/%d", &a, &b);
		fenz = fenz * b + a * fenm;
		fenm = b * fenm;
		int number = GetNumber(fenz, fenm);
		fenz /= number;
		fenm /= number;

		N--;
	}
	fenm *= tmp;
	int number = GetNumber(fenz, fenm);
	fenz /= number;
	fenm /= number;
	if (fenm == 1)
	{
		printf("%d\n", fenz);
	}
	else
	{
		printf("%d/%d", fenz, fenm);
	}
	return 0;
}