#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、PTA题目一
#define MAXN 10
typedef float ElementType;

ElementType Average(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Average(ElementType S[], int N)
{
    float add = 0;
    for (int i = 0; i < N; i++)
    {
        add += S[i];
    }
    return add / N;
}
//2、PTA题目二
#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Max(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Max(ElementType S[], int N)
{
    float max_number = S[0];
    for (int i = 1; i < N; i++)
    {
        if (max_number < S[i])
        {
            max_number = S[i];
        }
    }
    return max_number;
}