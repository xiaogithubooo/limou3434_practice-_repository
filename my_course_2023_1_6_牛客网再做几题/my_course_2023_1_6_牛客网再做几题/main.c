#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1��N�����ĺ�
int main()
{
    int n = 0;
    scanf("%d", &n);
    int t = 0;
    int add = 0;
    while (n)
    {
        scanf("%d", &t);
        add += t;
        n--;
    }
    printf("%d\n", add);
    return 0;
}
//2���ҿ�Σ��
int main()
{
    int n = 0;
    if (scanf("%d", &n) == 1)
    {
        if (n >= 10)
        {
            printf("Danger++");
        }
        else if (n >= 4 && n <= 9)
        {
            printf("Danger");
        }
        else if (n >= 0 && n <= 3)
        {
            printf("Good");
        }
    }
    return 0;
}
//3����߷�����ͷ�֮��
int main()
{
    int n = 0;
    scanf("%d", &n);
    int number = 0;
    int max = 0;
    int min = 10000;
    while (n)
    {
        scanf("%d", &number);
        if (max < number)
        {
            max = number;
        }
        if (min > number)
        {
            min = number;
        }
        n--;
    }
    printf("%d", max - min);
    return 0;
}