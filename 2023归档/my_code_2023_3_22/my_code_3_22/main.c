#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//1、联合体的研究
union Un
{
	char c;
	int i;
};
struct St
{
	short a;
	float arr[7];
	int b;
	double c;
};
int main()
{
	union Un a;
	printf("%zd\n", sizeof(a));
	printf("%p\n", &(a.c));
	printf("%p\n", &(a.i));

	struct St b;
	printf("%zd\n", sizeof(b));
	return 0;
}
//2、冒泡排序的书写
#define SIZE 10
void my_sort_function(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[SIZE] = { 2,3,4,1,5,3,7,5,10,3 };
	my_sort_function(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//3、测试联合体代码
#include <stdio.h>
union Un
{
    int i;
    char c;
};
int main()
{
    union Un u;
    u.i = 1;
    if (u.c == 1)
    {
        printf("小端\n");
    }
    return 0;
}