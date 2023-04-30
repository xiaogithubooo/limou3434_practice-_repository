#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void function1(double Close, double Open)
{
    if (Close < Open)
    {
        printf("BW-Solid");
    }
    else if (Close > Open)
    {
        printf("R-Hollow");
    }
    else
    {
        printf("R-Cross");
    }
}
void function2(double Open, double Close, double Low, double High)
{
    int i = Low < Open&& Low < Close;
    int j = High > Open && High > Close;
    if (i && j)
    {
        printf(" with Lower Shadow and Upper Shadow");
    }
    else if (i)
    {
        printf(" with Lower Shadow");
    }
    else if (j)
    {
        printf(" with Upper Shadow");
    }
}
int main()
{
    //1.输入数据
    double Open, High, Low, Close;
    scanf("%lf %lf %lf %lf", &Open, &High, &Low, &Close);
    //2.检查数据
    function1(Close, Open);
    function2(Open, Close, Low, High);
    return 0;
}