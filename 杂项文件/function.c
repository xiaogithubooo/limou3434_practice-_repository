#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "function.h"
//1������һ����ʼ������ʽ�ĺ���
void function_table_initialize(number_table* table)//(��������ʽָ��)
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
//2������һ���������������I/O����
void function_table_n_IO(number_table* table, int n, int x)//(��������ʽָ��, ѡ�����롱���ߡ������)
{
	int bool_number = 0;
	int z = 0;
	if (x == 0)
	{
		printf("����Ϊ����ʽ�����:\n");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x == 1)//ѡ�������뺯��
			{
				scanf("%d", &(table->arr[i][j]));
			}
			else if (x == 0)//ѡ�����������
			{
				z = 1;
				printf("%d ", table->arr[i][j]);
			}
			else
			{
				printf("���麯������");
				bool_number = 1;
				break;
			}
		}
		if (x == 1)
		{
			getchar();//ȥ��������'\n'�ַ�
		}
		else if (x == 0)//��������������ʹ�û���
		{
			printf("\n");
		}
		if (bool_number == 1)
			break;
	}
}
