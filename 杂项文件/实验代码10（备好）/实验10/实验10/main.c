#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ʵ��Ŀ�ģ�
//��1����������ָ��ĸ���
//��2������ָ����Ϊ�����������ݵķ���
//��3����������ָ���������е�Ӧ�÷���

//����һ��
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
//	printf("������������������12��34��");
//	scanf("%d,%d", &x, &y);
//	printf("����ǰ��x��yֵ�ֱ�Ϊ��%d,%d\n", x, y);
//	swap(&x, &y);
//	printf("������x��yֵ�ֱ�Ϊ��%d,%d\n", x, y);
//	printf("So Easy!");
//	return 0;
//}
//�������
//int findElement(int* ptr, int arrLen, int n)//������������Ԫ�ض��٣���Ҫ������
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
//		printf("�������%d��Ԫ�أ�", i + 1);
//		scanf("%d", &arr[i]);
//	}
//	printf("������Ҫ���ҵ�n��ֵ��");
//	scanf("%d", &n);
//	i=findElement(arr, 10, n);
//	printf("�����д���������ҵ�n��%d����ȵ�����Ԫ�أ����±�Ϊ��%d",n, i);
//	return 0;
//}
//��������
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