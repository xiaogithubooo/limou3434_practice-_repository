#define _CRT_SECURE_NO_WARNINGS 1
//日志
//1、PTA：统计某类完全平方数，https://pintia.cn/problem-sets/14/exam/problems/739
//2、PTA：多项式求值，https://pintia.cn/problem-sets/14/exam/problems/734

//1、PTA：统计某类完全平方数：https://pintia.cn/problem-sets/14/exam/problems/739
#include <math.h>
#include <stdio.h>
int function(int i)//判断是否符合有重复的位数
{
    int arr[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int number = i;
    while (number)
    {
        if (arr[number % 10] == -1)
        {
            arr[number % 10] = number % 10;
        }
        else
        {
            arr[number % 10] = -2;
        }
        number /= 10;
    }
    for (int j = 0; j < 10; j++)
    {
        if (arr[j] == -2)
        {
            return 1;
        }
    }
    return 0;
}
int IsTheNumber(const int i)//判断是否符合完全平方数的函数
{
    int number = (int)sqrt(i);
    if (number * number == i)//判断是否为完全平方数
    {
        if (function(i))//function返回1,就返回1
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n1, n2, i, cnt;//存储最小数和最大数，一个循环数，统计符合条件的完全平方数个数
    scanf("%d %d", &n1, &n2);//输入最小值和最大值
    cnt = 0;
    for (i = n1; i <= n2; i++)
    {
        if (IsTheNumber(i))//判断是否符合条件
        {
            cnt++;//符号条件就++
            printf("%d ", i);//打印此时符合条件的i
        }
    }
    printf("\ncnt = %d\n", cnt);
    return 0;
}
//2、PTA：多项式求值，https://pintia.cn/problem-sets/14/exam/problems/734
#include <math.h>
#include <stdio.h>
#define MAXN 10
double f(int n, double a[], double x);
int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for (i = 0; i <= n; i++)
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}
double f(int n, double a[], double x)
{
    double add = 0;
    for (int i = 0; i <= n; i++)
    {
        add += a[i] * pow(x, i);
    }
    return add;
}

