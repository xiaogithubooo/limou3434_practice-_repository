#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1.定义一个初始化行列式的函数
void FunctionInitialize_table(number_table* table)//(传入行列式指针)
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
//2.定义一个输入行列式的函数
void FunctionInput_table(number_table* table) 
{
	printf("请输入本“行列式”的阶数n:");
	scanf("%d", &table->n);
	printf("请输入本“行列式”的各个元素\n");
	for (int i = 0; i < table->n; i++)
	{
		for (int j = 0; j < table->n; j++)
		{
			scanf("%d", &table->arr[i][j]);
		}
		getchar();//吃去一个'\n'
	}
}
//3.定义一个输出行列式的函数
void FunctionOutput_table(number_table* table)
{
	printf("以下是本行列式的各个元素\n");
	for (int i = 0; i < table->n; i++)
	{
		for (int j = 0; j < table->n; j++)
		{
			printf("%d ", table->arr[i][j]);
		}
		printf("\n");
	}
}
//4.1.定义一个计算二阶、三阶行列式的函数
void FunctionCalculate1_table(number_table* table)
{
	if (table->n == 1)
	{
		printf("一阶行列式的计算结果为：\n");
		printf("%d", table->arr[0][0]);
	}
	else if (table->n == 2)
	{
		printf("二阶行列式的计算结果为：\n");
		printf("%d", (table->arr[0][0] * table->arr[1][1]) - (table->arr[0][1] * table->arr[1][0]));
	}
	else if (table->n == 3)
	{
		printf("三阶行列式的计算结果为：\n");
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
		printf("请使用另外一个计算函数，本函数只能计算二阶、三阶行列式\n");
	}
}
//4.2.定义一个计算高阶行列式的函数
//void FunctionCalculate2_table(number_table* table)
//{
//
//}
//5.定义一个计算逆序数的函数
void FunctionInverseNumber_arrary(number_arrary* arrary)
{
	int t = 0;//存储总逆序数
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
	printf("该排列的逆序数是%d\n", t);
}
//6.定义一个输入排列的输入函数
void FunctionInput_arrary(number_arrary* arrary)
{
	printf("请输入本“排列”的元素个数n:");
	scanf("%d", &arrary->n);
	printf("请输入本“排列”的每个元素\n");
	for (int i = 0; i < arrary->n; i++)
	{
		scanf("%d", &arrary->arr[i]);
	}
	getchar();//吃去一个'\n'
}