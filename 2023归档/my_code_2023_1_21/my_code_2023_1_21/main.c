#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、图像相似判断
int main()
{
	int m = 0, n = 0;//行和列
	int number = 0;
	int A = 0;
	scanf("%d %d", &m, &n);
	int arr_1[100 * 100] = { 0 };//这里数组太大会引发一些错误
	int i = 0;
	for (i = 0; i < m * n; i++)
	{
		scanf("%d", &arr_1[i]);
	}
	for (i = 0; i < m * n; i++)
	{
		A = arr_1[i];
		scanf("%d", &arr_1[i]);
		if (arr_1[i] == A)
		{
			number++;
		}
	}
	float result = (float)number / (float)(m * n);
	printf("%.2f", result * 100);
	return 0;
}
//2、筛选法求素数
int main()
{
	int num = 0;
	int A = 0;
	int number = 1;
	while (scanf("%d", &num) == 1)
	{
		for (int i = 2; i < num; i++)
		{
			A = 0;
			if (i % 2 == 0 && i != 2)
			{
				A = 1;
			}
			else if (i % 5 == 0 && i != 5)
			{
				A = 1;
			}
			else if (i % 3 == 0 && i != 3)
			{
				A = 1;
			}
			else if (i % 7 == 0 && i != 7)
			{
				A = 1;
			}

			if (A == 0)
			{
				printf("%d ", i);
			}
			else if (A == 1)
			{
				number++;
			}
		}
		printf("\n%d", number);
	}
	return 0;
}
//3、矩阵运算
int main()
{
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	int number = 0;
	int Add = 0;
	for (int i = 0; i < (m * n); i++)
	{
		scanf("%d", &number);
		if (number > 0)
		{
			Add += number;
		}
	}
	printf("%d", Add);
	return 0;
}
//4、KiKi学结构体和指针
int main() {
	int num = 0;
	int number = 0;
	int number_1 = 0;
	int arr[50] = { 0 };
	scanf("%d", &num);
	for (int i = 0; i < num; i++) 
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &number);
	for (int i = 0; i < num; i++) 
	{
		if (arr[i] == number) 
		{
			arr[i] = -1;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (arr[i] != -1)
		{
			number_1++;
		}
	}
	printf("%d", number_1);
	for (int i = 0; i < num; i++)
	{
		if (arr[i] != -1)
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}
//5、数组去重
int main()
{
    int a = 0;
    int A[1000] = { 0 };
    int T = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < a; i++)
    {
        T = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[j] == A[i])
            {
                T = 1;
            }
        }
        if (T == 0)
        {
            printf("%d ", A[i]);
        }
    }
    return 0;
}
//6、有序数组的插入
int main()
{
    int N;
    scanf("%d", &N);
    int arr[100] = { 0 };
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    //输入完毕，现在进行一次插入排序
    int end = N - 1;
    while (end >= 0) 
    {
        if (arr[end] > m) 
        {
            arr[end + 1] = arr[end];
            end--;
        }
        else 
        {
            break; 
        }
    }
    arr[end + 1] = m;
    for (int i = 0; i <= N; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}