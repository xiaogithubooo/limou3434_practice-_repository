#pragma once
#include "Triad.h"

//矩阵，主要管理矩阵资源（最大行、最大列、元素个数）
typedef struct Matrix
{
	int _maxRow;	//最大行数
	int _maxCol;	//最大列数
	int _effNum;	//有效个数
	Triad* _triad;	//头指针
}Matrix;

//矩阵初始化函数
void InitMatrix(Matrix* mat);

//矩阵插入函数
void InsertMatrix(Matrix* mat, Triad* data);

//矩阵打印函数
void PrintMatrix(Matrix* mat);

//矩阵加法函数
void Add(Matrix* mat);

//矩阵减法函数
void Sub(Matrix* mat);