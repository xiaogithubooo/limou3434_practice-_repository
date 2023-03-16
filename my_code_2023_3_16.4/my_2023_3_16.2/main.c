#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//日志：希尔排序
//1、希尔排序的逻辑
//2、希尔排序解决：求自定义类型元素序列的中位数，https://pintia.cn/problem-sets/14/exam/problems/743

//1、希尔排序的逻辑
void shellsortl(int a[], int n)
{
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2)//希尔排序的次数，每次会对内部小数组进行排序
	{
		for (i = 0; i < gap; i++)//得到每个小数组的首元素
		{
			for (j = i + gap; j < n; j += gap)//得到每个小组元素的后续元素
			{
				//开始进行所有的小数组进行各自的排序

				int temp = a[j];//记下“某一个元素”
				int k = j - gap;//“某一个元素”的“前一个元素”的下标
				while (k >= 0 && a[k] > temp)//判断小数组内，是否存在前一个元素大于后一个元素的情况
				{
					a[k + gap] = a[k];//将“某一个元素”替换成“后一个元素”
					k -= gap;//向前检查排序是否合理
				}
				a[k + gap] = temp;//当前最大的
			}
		}
	}
}
int main()
{
	int arr[20] = { 10,86,3,23,12,53,9,4,55,234,43,3,2,34,4,32,43,23,0,-3 };
	shellsortl(arr, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr[i]);
	}
}
//2、希尔排序解决：求自定义类型元素序列的中位数，https://pintia.cn/problem-sets/14/exam/problems/743
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
}

ElementType Median(ElementType A[], int N)
{
    //1、使用选择排序
//     for (int i = 0; i < N - 1; i++)//排序数组
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             if (A[i] > A[j])
//             {
//                 double tmp = A[i];
//                 A[i] = A[j];
//                 A[j] = tmp;
//             }
//         }
//     }
//     2、使用快排排序
//     qsort(A, N, sizeof(float), float_cmp);

//     for (int i = 0; i < N; i++)
//     {
//        printf("%f ", A[i]);
//     }
//     printf("\n");

//     3、使用希尔排序
    //void shellsortl(int a[], int n)A、N
    //{
    int i, j, gap;
    for (gap = N / 2; gap > 0; gap /= 2)//希尔排序的次数，每次会对内部小数组进行排序
    {
        for (i = 0; i < gap; i++)//得到每个小数组的首元素
        {
            for (j = i + gap; j < N; j += gap)//得到每个小组元素的后续元素
            {
                //开始进行所有的小数组进行各自的排序
                float temp = A[j];//记下“某一个元素”
                int k = j - gap;//“某一个元素”的“前一个元素”的下标
                while (k >= 0 && A[k] > temp)//判断小数组内，是否存在前一个元素大于后一个元素的情况
                {
                    A[k + gap] = A[k];//将“某一个元素”替换成“后一个元素”
                    k -= gap;//向前检查排序是否合理
                }
                A[k + gap] = temp;//当前最大的
            }
        }
    }
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