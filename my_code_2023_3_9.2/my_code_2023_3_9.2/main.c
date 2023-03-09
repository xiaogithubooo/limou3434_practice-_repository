#define _CRT_SECURE_NO_WARNINGS 1
////PTA题目：https://pintia.cn/problem-sets/14/exam/problems/743，但是时间没有通过
#include <stdio.h>
#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}ElementType Median(ElementType A[], int N)
{
    for (int i = 0; i < N - 1; i++)//排序数组
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
            {
                double tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
    //for (int i = 0; i < N; i++)
    //{
    //    printf("%lf ", A[i]);
    //}
    if (N % 2 == 0)//偶数
    {
        return A[(N + 1) / 2];
    }
    else
    {
        return A[(N + 1) / 2 - 1];
    }
}




