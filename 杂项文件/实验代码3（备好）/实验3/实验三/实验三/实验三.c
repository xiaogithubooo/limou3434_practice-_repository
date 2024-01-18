#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>//实验目的
 //（1）能够熟练的使用C语言进行简单的算术运算、关系运算和逻辑运算。
 //（2）掌握不同的类型数据之间赋值的规律。
 //（3）进一步熟悉C语言程序的编辑、编译和运行的过程。
//任务一：算术运算
//int main()
//{
//	int a = 2, b = 3;
//	float x = 3.9, y = 2.3;
//	float result;
//	result = (float)(a + b) / 2 + (int)x % (int)y;
//	printf("%f", result);
//	return 0;
//}
//任务二：算术运算
//int main()
//{
//	int number;
//	int a1, a2, a3;
//	printf("请输入3位数字");
//	scanf("%d", &number);
//	a1 = number % 10;
//	a2 = number % 100, a2 = a2 / 10;
//	a3 = number / 100;
//	printf("三位数%d的个位数为%d，十位数为%d，百位数为%d\n", number, a1, a2, a3);
//	return 0;
//}
//任务三：关系运算与逻辑运算
//int main()
//{
//	int x;
//	printf("输入x的值：");
//	scanf("%d", &x);
//	printf("表达式（x>0）的值：%d\n", x > 0);	
//	printf("表达式（x>=-20&&x<=-10）的值：%d\n", x >= -20 && x <= -10);
//	printf("表达式（x>100||x<10）的值：%d\n", x > 100 || x < 10);
//	printf("表达式（x>20&&x%%3==0）的值：%d\n", x > 20 && x % 3 == 0);
//	printf("表达式（(x%%5==0)&&(x%%3!=0)）的值：%d\n", (x % 5 == 0) && (x % 3 != 0));
//	return 0;
//}
//任务四：综合任务
//int pd1(int x)
//{
//	if (x >= 0 && x <= 100)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int pd2(int x, int y)
//{
//	if (x > y)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int grad1, grad2, t1, t2,j;
//	printf("请输入学生1的成绩：");
//	scanf("%d", &grad1);
//	printf("请输入学生2的成绩：");
//	scanf("%d", &grad2);
//	t1 = pd1(grad1);
//	t2 = pd1(grad2);
//	printf("grad1在[0，100]范围内？ %d\n", t1);
//	printf("grad2在[0，100]范围内？ %d\n", t2);
//	j=pd2(grad1, grad2);
//	if (j == 1)
//	{
//		printf("grad1>grad2 ? %d\n",j);
//	}
//	else
//	{
//		printf("grad1<grad2 ? %d\n", j);
//	}
//	return 0;
//}
// 
// 
// 
// 
//额外题目：写一个求最大值函数
//int MAX(int x, int y)
//{
//	int t;
//	if (x > y)
//	{
//		t = x;
//	}
//	else
//	{
//		t = y;
//	}
//	return t;
//}

//int main()
//{
//	int x, y, j;
//	scanf("%d,%d", &x, &y);
//	j = MAX(x, y);
//	printf("%d", j);
//	return 0;
//}
int main()
{
    int grad1, grad2;
    printf("请输入学生1的成绩:");
    scanf("%d", &grad1);
    printf("请输入学生2的成绩:");
    scanf("%d", &grad2);
    if (grad1 >= 0 && grad1 <= 100)
    {
        printf("grad1在[0,100]范围内？1\n");
    }
    else
    {
        printf("grad2在[0,100]范围内？0\n");
    }
    if (grad2 >= 0 && grad2 <= 100)
    {
        printf("grad2在[0,100]范围内？1\n");
    }
    else
    {
        printf("grad2在[0,100]范围内？0\n");

    }
    printf("grad1>grad2 ? %d", grad1>grad2);
    return 0;
}