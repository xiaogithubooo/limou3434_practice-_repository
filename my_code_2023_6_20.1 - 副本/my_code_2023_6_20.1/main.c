#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#define SIZE 10
void InsertSort(int* arr, int arrSize)//插入排序的实现
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
void ShellSort(int* arr, int arrSize)//希尔排序的实现
{
	//0.gap的最大意义在于：让最大的数更快跳到后面，让更小的数更快跳到前面
	//0.1.gap越大越不接近有序，但是跳得快
	//0.2.gap越小越接近有序，特别当gap=1时，其效果等价于直接插入排序

	//1.写法一（单组单排）
	//for (int gap = arrSize/2; gap >= 1; gap /= 2)//1.3.控制gap的大小
	//{
	//	for (int j = 0; j < gap; j++)//1.2.分别使用“直接插入排序”排序gap组个数组
	//	{
	//		for (int i = j; i < arrSize; i += gap)
	//		{
	//			//1.1.某一次一组的“直接插入排序”
	//			int end = i - gap;
	//			int tmp = arr[i];
	//			while (end >= 0)
	//			{
	//				if (tmp < arr[end])
	//				{
	//					arr[end + gap] = arr[end];
	//					end -= gap;
	//				}
	//				else
	//				{
	//					break;
	//				}
	//			}
	//			arr[end + gap] = tmp;
	//		}
	//	}
	//}
	
	//2.写法二（多组同排，但是效率没有变化）
	int gap = arrSize;
	while(gap > 1)//2.3.控制gap的大小（注意这里得入口不能写等于，会因为条件“gap=gap/3+1”而死循环，这是代码设计导致的）
	{
		gap = gap / 3 + 1;//加1是为了保证最后一次是1，能用上gap=1的直接插入排序
		for (int i = 0; i < arrSize; i++)//2.2.每组只取一个元素排序
		{
			//2.1.“直接插入排序”代码 
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
void _Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
void SelectSort(int* arr, int arrSize)
{
	int begin = 0, end = arrSize - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = end;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxi])//选出最大数的下标
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])//选出最小数的下标
			{
				mini = i;
			}
		}
		_Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)//处理特殊情况
		{
			maxi = mini;
		}
		_Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}
void Test1()
{
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("InsertSort() :");
	InsertSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
void Test2()
{
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("ShellSort()  :");
	ShellSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
void Test3()
{
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("SelectSort() :");
	SelectSort(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}

//void ShellSort(int* arr, int arrSize)
//{
//	int gap = arrSize;
//	for (; gap >= 1; gap /= 2)
//	{
//		for (int j = 0; j < arrSize / gap; j++)//循环gap组
//		{
//			for (int i = j; i < arrSize; i += gap)//每组进行直接插入排序
//			{
//				int end = i - gap;
//				int tmp = arr[i];
//				while (end >= 0)
//				{
//					if (tmp < arr[end])
//					{
//						arr[end + gap] = arr[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				arr[end + gap] = tmp;
//			}
//		}
//	}
//}
//void test(void)
//{
//	int arr[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = SIZE - i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	ShellSort(arr, SIZE);
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	srand((unsigned)time(0));
//	test();
//	return 0;
//}