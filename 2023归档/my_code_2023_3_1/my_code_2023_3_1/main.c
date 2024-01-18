#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <stdio.h>
/*1、PTA题目https://pintia.cn/problem-sets/14/exam/problems/741
* 2、PTA题目https://pintia.cn/problem-sets/14/exam/problems/742
*/
//1、第一题
int Count_Digit(const int N, const int D)
{
    int number = abs(N);
    int add = 0;
    if (N == 0)
    {
        return 1;
    }
    while (number)
    {
        if (number % 10 == D)
        {
            add++;
        }
        number /= 10;
    }
    return add;
}
int Count_Digit(const int N, const int D);

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
//第二题
int fun(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return (n) * fun(n - 1);
    }
}
void Print_Factorial(const int N)
{
    if (N > 1000)
    {
        printf("Invalid input");
    }
    else
    {
        printf("%d", fun(N));
    }
}

int main()
{
    int N;

    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}