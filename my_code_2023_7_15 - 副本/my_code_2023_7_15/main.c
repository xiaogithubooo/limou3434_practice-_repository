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
//	int gap = 1;//gap����һ������Ԫ�ظ���
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
//				break;//��ӦԽ���ǰ�������
//			}
//			if (newRighti_2 >= n)
//			{
//				newRighti_2 = n - 1;//��Ӧ�����������������
//			}
//
//			//����Ĳ����������鲢�Ķ�����ʵ���Ͼ��Ƕ����������������Ĺ��̣��ȽϿ����ȽϿ�������
//			//������һ������++���˾Ͷ�ͣ�£���ʣ��������ڲ�Ԫ��һ�������һ�����������Ԫ�ض���
//			//Ȼ�����ȫ����tmp�ڲ�Ԫ�ؿ�������
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
//			//�����޷�Ԥ��˭�����ֱ꣬��������ѭ����������������ѭ��ֻ������һ��
//			while (newLefti_1 <= newRighti_1)
//			{
//				tmp[j++] = arr[newLefti_1++];
//			}
//			while (newLefti_2 <= newRighti_2)
//			{
//				tmp[j++] = arr[newLefti_2++];
//			}
//			//�鲢һ�飬����һ��
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
//	MergeSortNonR1(arr, SIZE);//������
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//���������breakʹ�������Ļ��Ϳ��Բ�������ķ���
//void MergeSortNonR2(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (!tmp) exit(-1);
//	int gap = 1;//gap����һ������Ԫ�ظ���
//	//gap = 1 2 4 8 16 32 ...
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			int newLefti_1 = i, newRighti_1 = i + gap - 1;
//			int newLefti_2 = i + gap, newRighti_2 = i + 2 * gap - 1;
//
//			//ע�������if���˳������������ܳ�������
//			if (newRighti_1 >= n)
//			{
//				//����Խ��ĵڶ������
//				//�޳ɲ����ܴ��ڵ����䣬�������whileѭ���Ͳ����ȥ�ȽϿ�����
//				newRighti_1 = n - 1;
//				newLefti_2 = n;
//				newRighti_2 = n - 1;
//			}
//			else if (newLefti_2 >= n)
//			{
//				//����Խ��ĵ�һ�����
//				//�޳ɲ����ܴ��ڵ����䣬�������whileѭ���Ͳ����ȥ�ȽϿ�����
//				newLefti_2 = n;
//				newRighti_2 = n - 1;
//			}
//			else if (newRighti_2 >= n)
//			{
//				//��ӦԽ��ĵ��������
//				newRighti_2 = n - 1;//����
//			}
//
//			//����Ĳ����������鲢�Ķ�����ʵ���Ͼ��Ƕ����������������Ĺ��̣��ȽϿ����ȽϿ�������
//			//������һ������++���˾Ͷ�ͣ�£���ʣ��������ڲ�Ԫ��һ�������һ�����������Ԫ�ض���
//			//Ȼ�����ȫ����tmp�ڲ�Ԫ�ؿ�������
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
//			//�����޷�Ԥ��˭�����ֱ꣬��������ѭ����������������ѭ��ֻ������һ��
//			while (newLefti_1 <= newRighti_1)
//			{
//				tmp[j++] = arr[newLefti_1++];
//			}
//			while (newLefti_2 <= newRighti_2)
//			{
//				tmp[j++] = arr[newLefti_2++];
//			}
//			//�鲢һ�飬����һ�飨�����������ԱȲο���
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
//	MergeSortNonR2(arr, SIZE);//������
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
//	if (lefti >= righti)//��ʵֱ��д��==��Ҳ�ǿ��Եģ�������Ǳ�������
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
//	//����Ĳ����������鲢�Ķ�����ʵ���Ͼ��Ƕ����������������Ĺ��̣��ȽϿ����ȽϿ�������
//	//������һ������++���˾Ͷ�ͣ�£���ʣ��������ڲ�Ԫ��һ�������һ�����������Ԫ�ض���
//	//Ȼ�����ȫ����tmp�ڲ�Ԫ�ؿ�������
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
//	//�����޷�Ԥ��˭�����ֱ꣬��������ѭ����������������ѭ��ֻ������һ��
//	while (newLefti_1 <= newRighti_1)
//	{
//		tmp[i++] = arr[newLefti_1++];
//	}
//	while (newLefti_2 <= newRighti_2)
//	{
//		tmp[i++] = arr[newLefti_2++];
//	}
//	//���ȫ������������ע������֮ǰarr�������û�б����ֻ�Ǳ�tmp����
//	memcpy(arr + lefti, tmp + lefti, sizeof(int) * (righti - lefti + 1));//ע���������һ����������ʹ��i����Ϊiֻ���±겻��Ԫ�ظ�������һ����0��ʼ
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
//	MergeSortMix(arr, SIZE);//������
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
//	int mid = (lefti + righti) >> 1;//ȡƽ��ֵ
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
//	//1.���䲻���ڻ���������ֻ��һ��ֵ
//	if (lefti >= righti)
//	{
//		return;
//	}
//
//	//2.����ȡ�з�����ֹ������������
//	int indexi = _GetMidIndex(arr, lefti, righti);
//	_Swap(&arr[indexi], &arr[lefti]);
//
//	//3.ʹ����·���ַ�����ֹԪ�ؾ��ȵ�����
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
//	ThreeWay_QuickSort(arr, 0, SIZE - 1);//������
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

void CountSort(int* arr, int n)
{
	//1.ѡ��������С��
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
	//2.����ӳ���õ���ʱ����
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	if (!countArr) exit(-1);
	memset(countArr, 0, sizeof(int) * range);
	//3.��ʼ����
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}
	//4.��ʼ����
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
	CountSort(arr, SIZE);//������
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