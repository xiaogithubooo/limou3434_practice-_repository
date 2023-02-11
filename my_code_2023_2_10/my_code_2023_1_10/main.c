#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////1、使用指针打印数组
//int main()
//{
//	int arr[3] = { 1, 2, 3 };
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	return 0;
//}
////2、打印棱形
//int main()
//{
//	for (int i = 0; i <= 6; i++)
//	{
//		for (int j = 6; j > i; j--)
//		{
//			printf("  ");
//		}
//		for (int j = 0; j <  2 * i + 1; j++)
//		{
//			printf("* ");
//		}
//		printf("\n\n");
//	}
//	for (int i = 5; i >= 0; i--)
//	{
//		for (int j = i; j <= 5; j++)
//		{
//			printf("  ");
//		}
//		for (int j = 2 * i + 1; j > 0; j--)
//		{
//			printf("* ");
//		}
//		printf("\n\n");
//	}
//	return 0;
//}
////3、水仙花数
#include<math.h>
//int main()
//{
//	int number = 0;
//	int i = 0;
//	int arr[100000] = { 0 };
//	long add = 0;
//	for(int j = 0; j <= 100000; j++)
//	{
//		i = 0;
//		number = j;
//		while (number)
//		{
//			arr[i] = number % 10;
//			number /= 10;
//			i++;
//		}
//		for (int z = 0; z < i; z++)
//		{
//			add += pow(arr[z], i);
//		}
//		if (add == j)
//		{
//			printf("%ld",j);
//		}
//	}
//	return 0;
//}
////4、求得数列和
//int main()
//{
//	int number = 0;
//	int i = 0;
//	int add = 0;
//	scanf("%d", &number);
//	
//	for (int z = 5; z > 0; z--)
//	{
//		i = 0;
//		while (i < z)
//		{
//			add += number * pow(10, i);
//			i++;
//		}
//	}
//	printf("%d", add);
//	return 0;
//}
////5、水仙花数的修改
//int main()
//{
//	int j = 0;
//	int number = 0;
//	int add = 0;
//	for (int i = 0; i < 100000; i++)
//	{
//		j = 0;
//		number = i;
//		while (number)
//		{
//			number /= 10;
//			j++;
//		}
//		number = i;
//		add = 0;
//		while (number)
//		{
//			add += pow((number % 10), j);
//			number /= 10;
//		}
//		if (add == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
