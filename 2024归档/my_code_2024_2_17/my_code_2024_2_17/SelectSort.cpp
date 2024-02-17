#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void Show(int* arr, int size)
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

void Selectsort(int* arr, int size)
{
	int begin_i = 0, end_i = size - 1;

	while (begin_i < end_i)
	{
		//ѡ����ֵ
		int max_i = begin_i, min_i = end_i;
		for (int i = begin_i; i < end_i + 1; i++)
		{
			if (arr[i] > arr[max_i]) //Ѱ�����ֵ
				max_i = i;
			if (arr[i] < arr[min_i]) //Ѱ����Сֵ
				min_i = i;
		}

		printf("%d %d\n", arr[max_i], arr[min_i]);

		//��������
		_Swap(&arr[min_i], &arr[begin_i]);
		if (max_i == begin_i) //�����������
		{
			max_i = min_i;
		}
		_Swap(&arr[max_i], &arr[end_i]);

		begin_i++;
		end_i--;

		//��ʾ����
		Show(arr, size);
	}
}

int main()
{
	int arr[SIZE] = { 5, 4, 3, 2, 1 };
	Selectsort(arr, SIZE);
	printf("���ս����");
	Show(arr, SIZE);
	return 0;
}