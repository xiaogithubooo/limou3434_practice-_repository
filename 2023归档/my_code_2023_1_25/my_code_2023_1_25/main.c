#define _CRT_SECURE_NO_WARNINGS 1
////1°¢≤‚ ‘PTAÃ‚ƒø
void PrintN(int N)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }
}
#include<stdio.h>
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
    int add = 0;
    int X = 1;
    int I = 0;
    for (int i = 0; i <= n; i++)
    {
        I = i;
        while (I)
        {
            X *= x;
            I--;
        }
        add += (a[i] * X);
    }
    return add;
}//s ß∞‹¡À°≠°≠