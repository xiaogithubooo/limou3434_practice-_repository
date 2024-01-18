#pragma once
#include "Matrix.h"

//typedef struct Element
//{
//	int _row;
//	int _col;
//	int _val;
//}Element;
//
//typedef struct Matrix
//{
//	int _maxRow;
//	int _maxCol;
//	int _size;
//	Element* _datas;
//}Matrix;

//1.矩阵设置
bool MatrixInput(Matrix* m, int size)
{
	//创建元素数组
	Element* datas = (Element*)malloc(sizeof(Element) * size);
	if (!datas) exit(-1);
	int i = 0;
	while (i < size)
	{
		printf("请输入元素%d数据:", i);
		int scbRet = scanf("%d %d %d", &datas[i]._row, &datas[i]._col, &datas[i]._val);
		i++;
	}
	m->_datas = datas;
}

//2.矩阵加法
Matrix* MatrixAdd(Matrix* m1, Matrix* m2)
{
	int maxSize = m1->_size < m2->_size ? m2->_size : m1->_size;
	Element* datas = (Element*)malloc(sizeof(Element) * maxSize);
	int minSize = m1->_size > m2->_size ? m2->_size : m1->_size;
	for(int i = 0; i < minSize; i++)
	{
		if (m1->_datas[i]._row == m2->_datas[i]._row
			&& m1->_datas[i]._col == m2->_datas[i]._col)
		{
		}
	}
	return;
}

//3.矩阵减法
Matrix* MatrixSub(Matrix* m1, Matrix* m2)
{
	return m1;
}

//4.矩阵打印
void MatrixPrint(Matrix* m)
{

}