#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
//void InsertSort(int* arr, int arrSize)
//{
//	for (int i = 0; i < arrSize; i++)
//	{
//		int end = i - 1;
//		int tmp = arr[i];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				end--;
//			}
//			else 
//			{
//				break;
//			}
//		}
//		arr[end + 1] = tmp;
//	}
//}
void ShellSort(int* arr, int arrSize)
{
	int gap = arrSize;
	for (; gap >= 1; gap /= 2)
	{
		for (int j = 0; j < arrSize / gap; j++)//循环gap组
		{
			for (int i = j; i < arrSize; i += gap)//每组进行直接插入排序
			{
				int end = i - gap;
				int tmp = arr[i];
				while (end >= 0)
				{
					if (tmp < arr[end])
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				arr[end + gap] = tmp;
			}
		}
	}
}
void test(void)
{
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = 100 - i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	ShellSort(arr, 100);
	for (int i = 0; i < 100; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	srand((unsigned)time(0));
	test();
	return 0;
}