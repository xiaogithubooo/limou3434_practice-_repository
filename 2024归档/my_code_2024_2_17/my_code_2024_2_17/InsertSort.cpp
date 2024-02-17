#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void Show(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int* arr, int size)
{
	int end = -1;
	for (int i = 0; i < size; i++)
	{
		int tmp = arr[i];

		while (end != -1 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		
		arr[end + 1] = tmp;
		end = i;

		//ÏÔÊ¾ÅÅÐò
		Show(arr, size);
	}
}

int main()
{
	int arr[SIZE] = { 3, 3, 3 };
	InsertSort(arr, 3);
	Show(arr, SIZE);
	return 0;
}