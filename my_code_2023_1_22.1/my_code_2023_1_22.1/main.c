#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、判断是否为有序数组
int main()
{
	int n = 0;
	scanf("%d", &n);
	int number = 0;
	int max = 0;
	int BOOL = 0;
	int arr[50] = { 0 };

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (arr[0] > arr[n - 1])
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i] < arr[n - 1])
			{
				BOOL = 1;
				break;
			}
		}
	}
	else if (arr[0] < arr[n - 1])
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i] > arr[n - 1])
			{
				BOOL = 1;
				break;
			}
		}
	}
	else if (arr[0] == arr[n - 1])
	{
		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i] != arr[n - 1])
			{
				BOOL = 1;
				break;
			}
		}
	}

	if (BOOL == 1)
	{
		printf("unsorted");
	}
	else
	{
		printf("sorted");
	}
	return 0;
}
//2、序列删除
int main()
{
    int n = 0;
    int arr[50] = { 0 };
    int number = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &number);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == number)
        {
            arr[i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}