#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��־��ϣ������
//1��ϣ��������߼�
//2��ϣ�������������Զ�������Ԫ�����е���λ����https://pintia.cn/problem-sets/14/exam/problems/743

//1��ϣ��������߼�
void shellsortl(int a[], int n)
{
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2)//ϣ������Ĵ�����ÿ�λ���ڲ�С�����������
	{
		for (i = 0; i < gap; i++)//�õ�ÿ��С�������Ԫ��
		{
			for (j = i + gap; j < n; j += gap)//�õ�ÿ��С��Ԫ�صĺ���Ԫ��
			{
				//��ʼ�������е�С������и��Ե�����

				int temp = a[j];//���¡�ĳһ��Ԫ�ء�
				int k = j - gap;//��ĳһ��Ԫ�ء��ġ�ǰһ��Ԫ�ء����±�
				while (k >= 0 && a[k] > temp)//�ж�С�����ڣ��Ƿ����ǰһ��Ԫ�ش��ں�һ��Ԫ�ص����
				{
					a[k + gap] = a[k];//����ĳһ��Ԫ�ء��滻�ɡ���һ��Ԫ�ء�
					k -= gap;//��ǰ��������Ƿ����
				}
				a[k + gap] = temp;//��ǰ����
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
//2��ϣ�������������Զ�������Ԫ�����е���λ����https://pintia.cn/problem-sets/14/exam/problems/743
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
    //1��ʹ��ѡ������
//     for (int i = 0; i < N - 1; i++)//��������
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
//     2��ʹ�ÿ�������
//     qsort(A, N, sizeof(float), float_cmp);

//     for (int i = 0; i < N; i++)
//     {
//        printf("%f ", A[i]);
//     }
//     printf("\n");

//     3��ʹ��ϣ������
    //void shellsortl(int a[], int n)A��N
    //{
    int i, j, gap;
    for (gap = N / 2; gap > 0; gap /= 2)//ϣ������Ĵ�����ÿ�λ���ڲ�С�����������
    {
        for (i = 0; i < gap; i++)//�õ�ÿ��С�������Ԫ��
        {
            for (j = i + gap; j < N; j += gap)//�õ�ÿ��С��Ԫ�صĺ���Ԫ��
            {
                //��ʼ�������е�С������и��Ե�����
                float temp = A[j];//���¡�ĳһ��Ԫ�ء�
                int k = j - gap;//��ĳһ��Ԫ�ء��ġ�ǰһ��Ԫ�ء����±�
                while (k >= 0 && A[k] > temp)//�ж�С�����ڣ��Ƿ����ǰһ��Ԫ�ش��ں�һ��Ԫ�ص����
                {
                    A[k + gap] = A[k];//����ĳһ��Ԫ�ء��滻�ɡ���һ��Ԫ�ء�
                    k -= gap;//��ǰ��������Ƿ����
                }
                A[k + gap] = temp;//��ǰ����
            }
        }
    }
    //}
    if (N % 2 == 0)//ż��
    {
        return A[(N + 1) / 2];
    }
    else
    {
        return A[(N + 1) / 2 - 1];
    }
}