#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//��־���޸���ҵ
//1�������ַ���ʹ��scanf����ʱ��ʹ��&arr��arr������
//2������������n�������1��nλʮ���ƣ����ҷ���һ�������б�


//1�������ַ���ʹ��scanf����ʱ��ʹ��&arr��arr������
int main()
{
	char arr[10];
	scanf("%s", &arr);
	printf("%s", arr);
	return 0;
}
//2������������n�������1��nλʮ���ƣ����ҷ���һ�������б�
int* printNumbers(int n, int* returnSize) 
{
	*returnSize = pow(10, n) - 1; //ȷ����������
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));//�����㹻��С�Ŀռ�
	for (int i = 0; i < *returnSize; i++) 
	{
		arr[i] = i + 1;//�±��0��ʼ������ֵ��1��ʼ
	} 
	return arr;
}
int main()
{
	int n = 0;
	int number = 0;
	scanf("%d", &n);
	int* a = printNumbers(n, &number);
	for (int i = 0; i < number; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}