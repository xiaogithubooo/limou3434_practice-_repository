#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//typedef struct limou
//{
//	int n;
//	char c;
//	int arr[0];
//}limou;
//int main()
//{
//	limou* plimou = (limou*)malloc(sizeof(limou) + 5 * sizeof(int));
//	if (plimou == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		plimou->arr[i] = i;
//		printf("%d ", plimou->arr[i]);
//	}
//	printf("\n");
//
//	//������С
//	limou* plimou1 = realloc(plimou, sizeof(limou) + 10 * sizeof(int));
//	if (plimou1 == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	for (int i = 5; i < 10; i++)
//	{
//		plimou1->arr[i] = i;
//	}
//	for (int i = 0; i < 10; i++) 
//	{
//		printf("%d ", plimou1->arr[i]);
//	}
//
//	free(plimou1);
//	plimou1 = NULL;
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//typedef struct limou
//{
//	int n;
//	char c;
//	int* arr;
//}limou;
//int main()
//{
//	limou* plimou = (limou*)malloc(sizeof(limou));
//	if (plimou == NULL)
//	{
//		perror("malloc1");
//		return 1;
//	}
//	int* ptr = (limou*)malloc(sizeof(int) * 10);
//	if (ptr == NULL)
//	{
//		perror("malloc2");
//		return 1;
//	}
//	else
//	{
//		plimou->arr = ptr;
//	}
//
//	//ʹ�ö�̬�ڴ�
//	for (int i = 0; i < 10; i++)
//	{
//		plimou->arr[i] = i * i;
//		printf("%d ", plimou->arr[i]);
//	}
//
//	//�����ڴ��С
//	ptr = realloc(plimou->arr, 20 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("malloc3");
//		return 1;
//	}
//	else
//	{
//		plimou->arr = ptr;
//	}
//
//	printf("\n");
//	//ʹ�õ������ڴ�
//	for (int i = 0; i < 20; i++)
//	{
//		plimou->arr[i] = i * i;
//		printf("%d ", plimou->arr[i]);
//	}
//
//	//�ͷ��ڴ�
//	free(plimou->arr);
//	plimou->arr = NULL;
//	free(plimou);
//	plimou = NULL;
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	//�������������
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[10];
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//����Ҫɾ������
//	int del = 0;
//	int j = 0;
//	scanf("%d", &del);
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] != del)
//		{
//			arr[j++] = arr[i];
//		}
//		else
//		{
//			i++;
//		}
//	}
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}