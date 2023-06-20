#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
//1.≤Â»Î≈≈–Úµƒ∏¥œ∞
void InsertSort(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
//3.√∞≈›≈≈–Úµƒ∏¥œ∞
void BubbleSort(int* arr, int arrSize)
{
	int flag = 0;
	for (int j = 0; j < arrSize - 1; j++)
	{
		for (int i = 0; i + 1 < arrSize - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//≤‚ ‘”√¿˝
void test_1(void)
{
	int arr[10];
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}
	printf("\n≈≈–Ú∫Û£∫");
	InsertSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test_2(void)
{
	int arr[10];
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}
	printf("\n≈≈–Ú∫Û£∫");
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//main∫Ø ˝
int main()
{
	srand((unsigned)time(0));
	test_1();
	test_2();
	return 0;
}