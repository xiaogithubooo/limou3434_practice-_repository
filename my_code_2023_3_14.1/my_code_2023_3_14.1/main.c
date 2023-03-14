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
    return (int)(*(float*)p1 - *(float*)p2);//ע�ⲻ��ֱ�ӽ�����voidָ�룬��������������������������
}

ElementType Median(ElementType A[], int N)
{
    //1��ʹ��ѡ������
    for (int i = 0; i < N - 1; i++)//��������
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
    //2��ʹ�ÿ�������
    //qsort(A, N, sizeof(float), float_cmp);

    //for (int i = 0; i < N; i++)
    //{
    //    printf("%f ", A[i]);
    //}
    //printf("\n");

    if (N % 2 == 0)//ż��
    {
        return A[(N + 1) / 2];
    }
    else
    {
        return A[(N + 1) / 2 - 1];
    }
}
