#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、找出带9的数字
int main()
{
    int A = 0;
    int number = 0;
    int a = 0, b = 0;
    for (int i = 1; i <= 2019; i++)
    {
        a = i;
        while (a)
        {
            b = a % 10;
            if (b == 9)
            {
                number++;
                A = 1;
                break;
            }
            a /= 10;
        }
        if (A == 1)
            printf("%d ", i);
        A = 0;
    }
    printf("%d", number);
    return 0;
}
//2、KiKi判断上三角矩阵

int main()
{
    int WOL = 0;
    int i = 0;
    int j = 0;
    int ADD = 0;

    int number = 0;

    int arr[50][50] = { 0 };

    scanf("%d", &WOL);
    for (i = 0; i < WOL; i++)
    {
        for (j = 0; j < WOL; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < WOL; i++)
    {
        for (j = 0; j < WOL; j++)
        {
            if ((i > j) && (arr[i][j] == 0))
            {
                number++;
            }
        }
    }

    WOL = WOL - 1;
    while (WOL)
    {
        ADD += WOL;
        WOL--;
    }

    if (number == ADD)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}