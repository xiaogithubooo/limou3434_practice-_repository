#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

#define MAXN 10
typedef float ElementType;

int float_cmp(const void* p1, const void* p2);
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
}

int float_cmp(const void* p1, const void* p2)
{
    return (int)(*(float*)p1 - *(float*)p2);//注意不能直接解引用void指针，另外如果倒过来就是逆序输出了
}

ElementType Median(ElementType A[], int N)
{
    //1、使用选择排序
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
    //2、使用快排排序
    //qsort(A, N, sizeof(float), float_cmp);

    //for (int i = 0; i < N; i++)
    //{
    //    printf("%f ", A[i]);
    //}
    //printf("\n");

    if (N % 2 == 0)//偶数
    {
        return A[(N + 1) / 2];
    }
    else
    {
        return A[(N + 1) / 2 - 1];
    }
}
