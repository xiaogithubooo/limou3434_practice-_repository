#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int a = 0;
    double i = 0;
    double j = 0;
    double number = 0;
    scanf("%d", &a);
    int b = a;
    while (a)
    {
        scanf("%f/%f", &i, &j);
        number += i / j;
        a--;
    }
    printf("%f", number / b);
    return 0;
}