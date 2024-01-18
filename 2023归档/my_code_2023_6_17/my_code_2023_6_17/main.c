#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void InsertSort(int* arr, int arrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		int end = i-1;
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
int main()
{
	int arr[10] = { 10, 29, 13, 4, 25, 60, 777, 87, 90, 0 };
	InsertSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}