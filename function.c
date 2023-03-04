#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "function.h"
//1、定义一个初始化行列式的函数
void function_table_initialize(number_table* table)//(传入行列式指针)
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
//2、定义一个可以输入输出的I/O函数
void function_table_n_IO(number_table* table, int n, int x)//(传入行列式指针, 选择“输入”或者“输出”)
{
	int bool_number = 0;
	int z = 0;
	if (x == 0)
	{
		printf("以下为行列式的输出:\n");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x == 1)//选择了输入函数
			{
				scanf("%d", &(table->arr[i][j]));
			}
			else if (x == 0)//选择了输出函数
			{
				z = 1;
				printf("%d ", table->arr[i][j]);
			}
			else
			{
				printf("请检查函数参数");
				bool_number = 1;
				break;
			}
		}
		if (x == 1)
		{
			getchar();//去除输入后的'\n'字符
		}
		else if (x == 0)//如果是输出函数就使用换行
		{
			printf("\n");
		}
		if (bool_number == 1)
			break;
	}
}
