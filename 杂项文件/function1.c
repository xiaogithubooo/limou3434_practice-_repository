#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1.����һ����ʼ������ʽ�ĺ���
void FunctionInitialize_table(number_table* table)//(��������ʽָ��)
{
	table->n = 10;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			table->arr[i][j] = 0;
		}
	}
}
//2.����һ����������ʽ�ĺ���
void FunctionInput_table(number_table* table) 
{
	printf("�����뱾������ʽ���Ľ���n:");
	scanf("%d", &table->n);
	printf("�����뱾������ʽ���ĸ���Ԫ��\n");
	for (int i = 0; i < table->n; i++)
	{
		for (int j = 0; j < table->n; j++)
		{
			scanf("%d", &table->arr[i][j]);
		}
		getchar();//��ȥһ��'\n'
	}
}
//3.����һ���������ʽ�ĺ���
void FunctionOutput_table(number_table* table)
{
	printf("�����Ǳ�����ʽ�ĸ���Ԫ��\n");
	for (int i = 0; i < table->n; i++)
	{
		for (int j = 0; j < table->n; j++)
		{
			printf("%d ", table->arr[i][j]);
		}
		printf("\n");
	}
}
//4.1.����һ��������ס���������ʽ�ĺ���
void FunctionCalculate1_table(number_table* table)
{
	if (table->n == 1)
	{
		printf("һ������ʽ�ļ�����Ϊ��\n");
		printf("%d", table->arr[0][0]);
	}
	else if (table->n == 2)
	{
		printf("��������ʽ�ļ�����Ϊ��\n");
		printf("%d", (table->arr[0][0] * table->arr[1][1]) - (table->arr[0][1] * table->arr[1][0]));
	}
	else if (table->n == 3)
	{
		printf("��������ʽ�ļ�����Ϊ��\n");
		printf("%d",
			(table->arr[0][0] * table->arr[1][1] * table->arr[2][2]) +
			(table->arr[0][1] * table->arr[1][2] * table->arr[2][0]) +
			(table->arr[0][2] * table->arr[1][0] * table->arr[2][1]) -
			(table->arr[0][2] * table->arr[1][1] * table->arr[2][0]) -
			(table->arr[0][0] * table->arr[1][2] * table->arr[2][1])
		);
	}
	else
	{
		printf("��ʹ������һ�����㺯����������ֻ�ܼ�����ס���������ʽ\n");
	}
}
//4.2.����һ������߽�����ʽ�ĺ���
//void FunctionCalculate2_table(number_table* table)
//{
//
//}
//5.����һ�������������ĺ���
void FunctionInverseNumber_arrary(number_arrary* arrary)
{
	int t = 0;//�洢��������
	for (int i = 1; i < arrary->n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrary->arr[j] > arrary->arr[i])
			{
				t++;
			}
		}
	}
	printf("�����е���������%d\n", t);
}
//6.����һ���������е����뺯��
void FunctionInput_arrary(number_arrary* arrary)
{
	printf("�����뱾�����С���Ԫ�ظ���n:");
	scanf("%d", &arrary->n);
	printf("�����뱾�����С���ÿ��Ԫ��\n");
	for (int i = 0; i < arrary->n; i++)
	{
		scanf("%d", &arrary->arr[i]);
	}
	getchar();//��ȥһ��'\n'
}