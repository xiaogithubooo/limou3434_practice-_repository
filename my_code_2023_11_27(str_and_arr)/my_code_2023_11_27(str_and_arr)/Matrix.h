#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Element
{
	int _row;
	int _col;
	int _val;
}Element;

typedef struct Matrix
{
	int _maxRow;
	int _maxCol;
	int _size;
	Element* _datas;
}Matrix;

//1.æÿ’Û…Ë÷√
bool MatrixInput(Matrix* m, int size);

//2.æÿ’Ûº”∑®
Matrix* MatrixAdd(Matrix* m1, Matrix* m2);

//3.æÿ’Ûºı∑®
Matrix* MatrixSub(Matrix* m1, Matrix* m2);

//4.æÿ’Û¥Ú”°
void MatrixPrint(Matrix* m);
