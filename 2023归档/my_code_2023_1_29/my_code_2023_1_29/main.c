#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Factorial(const int N);

int main()
{
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int Factorial(const int N)
{
    int n = N;
    int add = 1;
    if (n == 1 || n == 0)
    {
        return add;
    }
    else if (n > 1)
    {
        while (n)
        {
            add *= n;
            n--;
        }
        return add;
    }
    else
    {
        return 0;
    }
}