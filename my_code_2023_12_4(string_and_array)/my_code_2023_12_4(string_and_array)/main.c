#define _CRT_SECURE_NO_WARNINGS 1
#include "matrix.h"

int scaRet = 0;
void Matrix_Set(Matrix* m, int maxRow, int maxCol)
{
	int number = 0, row = 0, col = 0;
	printf("输入矩阵的有效元素个数:");
	int size = 0;
	scaRet = scanf("%d", &size);
	if (size > maxRow * maxCol)
	{
		printf("有效数字比矩阵总元素个数还要多，当前程序已结束，请重新输入\n");
		exit(-1);
	}
	int i = 1;
	while (size--)
	{
		printf("输入有效元素%d的值和坐标:", i++);
		scaRet = scanf("%d %d %d", &number, &row, &col);
		Matrix_Push(m, number, row, col);
	}
	Matrix_Print(m);
}
int main()
{
	//初始变量
	Matrix m1;
	Matrix m2;
	int maxRow = 0;
	int maxCol = 0;
	printf("请输入需要计算的矩阵的最大行和最大列:");
	scaRet = scanf("%d %d", &maxRow, &maxCol);
	if (maxRow <= 0 || maxCol <= 0)
	{
		printf("不合理的输入，程序结束\n");
		exit(-1);
	}

	Matrix_Init(&m1, maxRow, maxCol);
	Matrix_Init(&m2, maxRow, maxCol);

	Matrix* add = (Matrix*)malloc(sizeof(Matrix));
	Matrix* sub = (Matrix*)malloc(sizeof(Matrix));
	Matrix_Init(add, maxRow, maxCol);
	Matrix_Init(sub, maxRow, maxCol);

	//设置矩阵 1
	//1  2  3  0  0
	//0  0  2  0  1
	//0  5  6  0  3
	//8  0  0 -1  7
	Matrix_Set(&m1, maxRow, maxCol);

	//设置矩阵 2 
	//1  3  0  0  0
	//0  0  0  0  0
	//1  0  0 -3  0
	//3  0  0  9  8
	Matrix_Set(&m2, maxRow, maxCol);

	//矩阵加法
	Matrix_Add(add ,&m1, &m2);
	//矩阵减法
	Matrix_Sub(sub ,&m1, &m2);

	//析构资源
	free(add);
	free(sub);
	Matrix_Destroy(&m1);
	Matrix_Destroy(&m2);
	return 0;
}