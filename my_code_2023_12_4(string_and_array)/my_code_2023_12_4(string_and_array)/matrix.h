//以三元组表形式表示稀疏矩阵，实现两个矩阵的加法、减法

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//三元组
typedef struct Number
{
	int _num;		//元素
	int _row;		//坐在行
	int _col;		//所在列
	struct Number* _next;	//指向下一个 Number 结点
	struct Number* _prev;	//指向上一个 Number 结点
} Number;

//矩阵
typedef struct Matrix
{
	Number* _arr;	//管理矩阵链表
	int _maxRow;	//最大行
	int _maxCol;	//最大列
	int _size;		//元素个数
} Matrix;

//初始化
void Matrix_Init(Matrix* m, int maxRow, int maxCol);

//后插
void Matrix_Push(Matrix* m, int num, int row, int col);

//前插
void Matrix_Front(Matrix* m, int num, int row, int col);

//打印
void Matrix_Print(Matrix* m);

//加法
void Matrix_Add(Matrix* add, Matrix* m1, Matrix* m2);

//减法
void Matrix_Sub(Matrix* sub, Matrix* m1, Matrix* m2);

//销毁
void Matrix_Destroy(Matrix* m);