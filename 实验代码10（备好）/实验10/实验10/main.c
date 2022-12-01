#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//实验目的：
//（1）熟练掌握指针的概念
//（2）掌握指针作为函数参数传递的方法
//（3）熟练掌握指针在数组中的应用方法

//任务一：
//void swap(int* a, int* b)
//{
//	int t;
//	t = *a;
//	*a = *b;
//	*b = t;
//}
//int main(void)
//{
//	int x, y;
//	printf("请输入两个整数，如12，34：");
//	scanf("%d,%d", &x, &y);
//	printf("交换前：x和y值分别为：%d,%d\n", x, y);
//	swap(&x, &y);
//	printf("交换后：x和y值分别为：%d,%d\n", x, y);
//	printf("So Easy!");
//	return 0;
//}
//任务二：
//int findElement(int* ptr, int arrLen, int n)//数组名，数组元素多少，需要查找书
//{
//	int j;
//	for (j = 0; j < arrLen; j++)
//	{
//		if ((*(ptr + j)) == n)
//		{
//			return j;
//		}
//	}
//	for (j = 0; j < arrLen; j++)
//	{
//		if ((*(ptr + j)) != n)
//		{
//			return -1;
//		}
//	}
//}
//int main(void)
//{
//	int arr[10];
//	int n, i;
//	for (i=0;i<10;i++)
//	{
//		printf("请输入第%d个元素：", i + 1);
//		scanf("%d", &arr[i]);
//	}
//	printf("请输入要查找的n的值：");
//	scanf("%d", &n);
//	i=findElement(arr, 10, n);
//	printf("数组中存在与待查找的n（%d）相等的数组元素，其下标为：%d",n, i);
//	return 0;
//}
//任务三：
//int main(void)
//{
//	int i, j, k;
//	char space = ' ';
//	char a[5] = { '*','*','*','*','*' };
//	for (i=0;i<5;++i)
//	{
//		for (k = -1; k < i; ++k)
//		{
//			printf("%c", space);
//		}
//		for (j = 0; j < 5; ++j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}