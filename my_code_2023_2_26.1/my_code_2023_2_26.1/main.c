#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
////1����������
//void spin(char* arr, size_t size)//ʹһ���ַ��������
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (i < size - (i + 1))
//		{
//			char tmp = arr[i];
//			arr[i] = arr[size - (i + 1)];
//			arr[size - (i + 1)] = tmp;
//		}
//	}
//}
//void left_function(char* arr, int size, int left_number)//����ת�ַ���
//{
//	spin(arr, size);
//	spin(&arr[size - left_number], left_number);
//	spin(&arr[0], size - left_number);
//}
//int main()
//{
//	char arr[20] = { 0 };//�洢�ַ���
//	int left_number = 0;//�����ַ�����
//
//	scanf("%s %d", arr, &left_number);
//
//
//	left_function(arr, strlen(arr), left_number);//��������
//
//	printf("%s", arr);//��ӡ�ַ���
//	return 0;
//}
////2����������
//#define NUM 10
//int main()
//{
//	int A[NUM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int B[NUM] = { 10,20,30,40,50,60,70,80,90,100 };
//	printf("A:");
//	for (int i = 0; i < NUM; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	printf("B:");
//	for (int i = 0; i < NUM; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	printf("\n\n");
//
//	for (int i = 0; i < NUM; i++)
//	{
//		int tmp = A[i];
//		A[i] = B[i];
//		B[i] = tmp;
//	}
//
//	printf("A:");
//	for (int i = 0; i < NUM; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	printf("B:");
//	for (int i = 0; i < NUM; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	printf("\n");
//
//	return 0;
//}
////3���������
//#define NUM 10
//void my_print(int* arr, int x)
//{
//	for (int i = 0; i < x; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void my_init(int* arr, int x)
//{
//	for (int i = 0; i < x; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void my_reverse(int* arr, int x)//ʹһ���ַ���ת
//{
//	for (int i = 0; i < x; i++)
//	{
//		if (i < x - (i + 1))
//		{
//			char tmp = arr[i];
//			arr[i] = arr[x - (i + 1)];
//			arr[x - (i + 1)] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[NUM] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	my_print(arr, NUM);
//	my_reverse(arr, NUM);
//	my_print(arr, NUM);
//	my_init(arr, NUM);
//	my_print(arr, NUM);
//
//	return 0;
//}