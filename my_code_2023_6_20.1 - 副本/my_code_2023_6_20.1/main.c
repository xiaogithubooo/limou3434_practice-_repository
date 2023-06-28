#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#define SIZE 10
void InsertSort(int* arr, int arrSize)//���������ʵ��
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
void ShellSort(int* arr, int arrSize)//ϣ�������ʵ��
{
	//0.gap������������ڣ��������������������棬�ø�С������������ǰ��
	//0.1.gapԽ��Խ���ӽ����򣬵������ÿ�
	//0.2.gapԽСԽ�ӽ������ر�gap=1ʱ����Ч���ȼ���ֱ�Ӳ�������

	//1.д��һ�����鵥�ţ�
	//for (int gap = arrSize/2; gap >= 1; gap /= 2)//1.3.����gap�Ĵ�С
	//{
	//	for (int j = 0; j < gap; j++)//1.2.�ֱ�ʹ�á�ֱ�Ӳ�����������gap�������
	//	{
	//		for (int i = j; i < arrSize; i += gap)
	//		{
	//			//1.1.ĳһ��һ��ġ�ֱ�Ӳ�������
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
	
	//2.д����������ͬ�ţ�����Ч��û�б仯��
	int gap = arrSize;
	while(gap > 1)//2.3.����gap�Ĵ�С��ע���������ڲ���д���ڣ�����Ϊ������gap=gap/3+1������ѭ�������Ǵ�����Ƶ��µģ�
	{
		gap = gap / 3 + 1;//��1��Ϊ�˱�֤���һ����1��������gap=1��ֱ�Ӳ�������
		for (int i = 0; i < arrSize; i++)//2.2.ÿ��ֻȡһ��Ԫ������
		{
			//2.1.��ֱ�Ӳ������򡱴��� 
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
			if (arr[i] > arr[maxi])//ѡ����������±�
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])//ѡ����С�����±�
			{
				mini = i;
			}
		}
		_Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)//�����������
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
//		for (int j = 0; j < arrSize / gap; j++)//ѭ��gap��
//		{
//			for (int i = j; i < arrSize; i += gap)//ÿ�����ֱ�Ӳ�������
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