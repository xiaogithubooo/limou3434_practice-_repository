#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#define SIZE 1000
//void MergeSortNonR1(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//
//	int gap = 1;//gap代表一个数组元素个数
//	//gap = 1 2 4 8 16 32 ...
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int newLefti_1 = i, newRighti_1 = i + gap - 1;
//			int newLefti_2 = i + gap, newRighti_2 = i + 2 * gap - 1;
//
//			if (newRighti_1 >= n || newLefti_2 >= n)
//			{
//				break;//对应越界的前两种情况
//			}
//			if (newRighti_2 >= n)
//			{
//				newRighti_2 = n - 1;//对应第三种情况进行修正
//			}
//
//			//下面的步骤是在做归并的动作，实际上就是对两个数组进行排序的过程，比较拷贝比较拷贝……
//			//若是有一个数组++完了就都停下，有剩余的数组内部元素一点比另外一个数组的所有元素都大
//			//然后最后全部把tmp内部元素拷贝回来
//			int j = i;
//			while (newLefti_1 <= newRighti_1 && newLefti_2 <= newRighti_2)
//			{
//				if (arr[newLefti_1] < arr[newLefti_2])
//				{
//					tmp[j++] = arr[newLefti_1++];
//				}
//				else
//				{
//					tmp[j++] = arr[newLefti_2++];
//				}
//			}
//			//我们无法预测谁先走完，直接上两个循环，因此下面的两个循环只会满足一个
//			while (newLefti_1 <= newRighti_1)
//			{
//				tmp[j++] = arr[newLefti_1++];
//			}
//			while (newLefti_2 <= newRighti_2)
//			{
//				tmp[j++] = arr[newLefti_2++];
//			}
//			//归并一组，拷贝一组
//			memcpy(arr + i, tmp + i, sizeof(int) * (newRighti_2 - i + 1));
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}
//void test_1()
//{
//	srand((unsigned)time(0));
//	int arr[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = SIZE - i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	MergeSortNonR1(arr, SIZE);//堆排序
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//如果不采用break使用修正的话就可以采用下面的方法
//void MergeSortNonR2(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (!tmp) exit(-1);
//	int gap = 1;//gap代表一个数组元素个数
//	//gap = 1 2 4 8 16 32 ...
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int newLefti_1 = i, newRighti_1 = i + gap - 1;
//			int newLefti_2 = i + gap, newRighti_2 = i + 2 * gap - 1;
//
//			//注意下面的if语句顺序如果调换可能出现问题
//			if (newRighti_1 >= n)
//			{
//				//对于越界的第二种情况
//				//修成不可能存在的区间，则下面的while循环就不会就去比较拷贝了
//				newRighti_1 = n - 1;
//				newLefti_2 = n;
//				newRighti_2 = n - 1;
//			}
//			else if (newLefti_2 >= n)
//			{
//				//对于越界的第一种情况
//				//修成不可能存在的区间，则下面的while循环就不会就去比较拷贝了
//				newLefti_2 = n;
//				newRighti_2 = n - 1;
//			}
//			else if (newRighti_2 >= n)
//			{
//				//对应越界的第三种情况
//				newRighti_2 = n - 1;//修正
//			}
//
//			//下面的步骤是在做归并的动作，实际上就是对两个数组进行排序的过程，比较拷贝比较拷贝……
//			//若是有一个数组++完了就都停下，有剩余的数组内部元素一点比另外一个数组的所有元素都大
//			//然后最后全部把tmp内部元素拷贝回来
//			int j = i;
//			while (newLefti_1 <= newRighti_1 && newLefti_2 <= newRighti_2)
//			{
//				if (arr[newLefti_1] < arr[newLefti_2])
//				{
//					tmp[j++] = arr[newLefti_1++];
//				}
//				else
//				{
//					tmp[j++] = arr[newLefti_2++];
//				}
//			}
//			//我们无法预测谁先走完，直接上两个循环，因此下面的两个循环只会满足一个
//			while (newLefti_1 <= newRighti_1)
//			{
//				tmp[j++] = arr[newLefti_1++];
//			}
//			while (newLefti_2 <= newRighti_2)
//			{
//				tmp[j++] = arr[newLefti_2++];
//			}
//			//归并一组，拷贝一组（废弃，仅作对比参考）
//			//memcpy(arr + i, tmp + i, sizeof(int) * (newRighti_2 - i + 1));
//		}
//		memcpy(arr, tmp, sizeof(int) * n);
//		gap *= 2;
//	}
//	free(tmp);
//}
//void test_2()
//{
//	int arr[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = SIZE - i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	MergeSortNonR2(arr, SIZE);//堆排序
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//void _InsertSort(int* arr, int arrSize)
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
//void _MergeSort(int* arr, int lefti, int righti, int* tmp)
//{
//	if (lefti >= righti)//其实直接写“==”也是可以的，左边这是保险做法
//	{
//		return;
//	}
//	if (righti - lefti + 1 < 10)
//	{
//		_InsertSort(arr + lefti, righti - lefti + 1);
//		return;
//	}
//	int mid = (lefti + righti) / 2;
//	//[lefti, mid][mid+1, righti]
//	_MergeSort(arr, lefti, mid, tmp);
//	_MergeSort(arr, mid + 1, righti, tmp);
//
//	int newLefti_1 = lefti, newRighti_1 = mid;
//	int newLefti_2 = mid + 1, newRighti_2 = righti;
//
//	//下面的步骤是在做归并的动作，实际上就是对两个数组进行排序的过程，比较拷贝比较拷贝……
//	//若是有一个数组++完了就都停下，有剩余的数组内部元素一点比另外一个数组的所有元素都大
//	//然后最后全部把tmp内部元素拷贝回来
//	int i = lefti;
//	while (newLefti_1 <= newRighti_1 && newLefti_2 <= newRighti_2)
//	{
//		if (arr[newLefti_1] < arr[newLefti_2])
//		{
//			tmp[i++] = arr[newLefti_1++];
//		}
//		else
//		{
//			tmp[i++] = arr[newLefti_2++];
//		}
//	}
//	//我们无法预测谁先走完，直接上两个循环，因此下面的两个循环只会满足一个
//	while (newLefti_1 <= newRighti_1)
//	{
//		tmp[i++] = arr[newLefti_1++];
//	}
//	while (newLefti_2 <= newRighti_2)
//	{
//		tmp[i++] = arr[newLefti_2++];
//	}
//	//最后全部拷贝回来，注意在这之前arr数组从来没有变过，只是被tmp拷贝
//	memcpy(arr + lefti, tmp + lefti, sizeof(int) * (righti - lefti + 1));//注意这里最后一个参数不能使用i，因为i只是下标不是元素个数，不一定从0开始
//}
//void MergeSortMix(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	_MergeSort(arr, 0, n - 1, tmp);
//	free(tmp);
//}
//void test_3()
//{
//	int arr[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = SIZE - i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	MergeSortMix(arr, SIZE);//堆排序
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//void _Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int _GetMidIndex(int* arr, int lefti, int righti)
//{
//	int mid = (lefti + righti) >> 1;//取平均值
//	if (arr[lefti] < arr[mid])
//	{
//		if (arr[mid] < arr[righti])
//		{
//			return mid;
//		}
//		else if (arr[lefti] > arr[righti])
//		{
//			return lefti;
//		}
//		else
//		{
//			return righti;
//		}
//	}
//	else//arr[lefti] > arr[mid]
//	{
//		if (arr[mid] > arr[righti])
//		{
//			return mid;
//		}
//		else if (arr[lefti] < arr[righti])
//		{
//			return lefti;
//		}
//		else
//		{
//			return righti;
//		}
//	}
//}
//void ThreeWay_QuickSort(int* arr, int lefti, int righti)
//{
//	//1.区间不存在或是区间内只有一个值
//	if (lefti >= righti)
//	{
//		return;
//	}
//
//	//2.三数取中法，防止数组有序的情况
//	int indexi = _GetMidIndex(arr, lefti, righti);
//	_Swap(&arr[indexi], &arr[lefti]);
//
//	//3.使用三路划分法，防止元素均等的数组
//	int li = lefti;
//	int ri = righti;
//	int curi = li + 1;
//	int key = arr[li];
//	while (curi <= ri)
//	{
//		if (arr[curi] < key)
//		{
//			_Swap(&arr[curi], &arr[li]);
//			curi++;
//			li++;
//		}
//		else if(arr[curi] > key)
//		{
//			_Swap(&arr[curi], &arr[ri]);
//			ri--;
//		}
//		else//arr[curi] == key
//		{
//			curi++;
//		}
//	}
//
//	//[lefti, li-1] [li, ri] [ri+1, righti]
//	ThreeWay_QuickSort(arr, lefti, li - 1);
//	ThreeWay_QuickSort(arr, ri + 1, righti);
//}
//void test_4()
//{
//	int arr[SIZE];
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = SIZE - i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	ThreeWay_QuickSort(arr, 0, SIZE - 1);//堆排序
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

void CountSort(int* arr, int n)
{
	//1.选出最大和最小数
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//2.创建映射用的临时数组
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	if (!countArr) exit(-1);
	memset(countArr, 0, sizeof(int) * range);
	//3.开始计数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}
	//4.开始排序
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[k++] = i + min;
		}
	}
}
void test_5()
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = SIZE - i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	CountSort(arr, SIZE);//堆排序
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	test_5();
	return 0;
}