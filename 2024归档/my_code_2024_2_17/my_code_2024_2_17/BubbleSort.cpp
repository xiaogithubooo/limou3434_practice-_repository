#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void _Show(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void _Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int* arr, int size)
{
	for (int j = 0; j < size - 1; j++) //冒泡次数
	{
		for (int i = 0; i < size - j - 1; i++) //交换次数
		{
			if (arr[i] > arr[i + 1])
				_Swap(&arr[i], &arr[i + 1]);
		}
		_Show(arr, size);
	}
}

int main()
{
	int arr[SIZE] = { 5, 5, 5, 0 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	printf("最终结果：");
	_Show(arr, sizeof(arr) / sizeof(int));
	return 0;
}