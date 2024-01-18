#include "Matrix.h"

void DataInput(Matrix* m1, Matrix* m2);
int main()
{
	Matrix m1;
	Matrix m2;

	//1.输入矩阵数据
	DataInput(&m1, &m2);

	//2.计算矩阵加法
	MatrixPrint(MatrixAdd(&m1, &m2));
	
	//3.计算矩阵减法
	MatrixPrint(MatrixSub(&m1, &m2));
	return 0;
}

void DataInput(Matrix* m1, Matrix* m2)
{
	int size = 0;
	int scRet = 0;
	int maxRow = 0;
	int maxCol = 0;

	printf("请输入两矩阵的最大行和最大列:");
	scanf("%d %d", &maxRow, &maxCol);
	m1->_maxRow = m2->_maxRow = maxRow;
	m1->_maxCol = m2->_maxCol = maxCol;

	printf("请输入矩阵1的非零元个数:");
	scRet = scanf("%d", &size);
	MatrixInput(m1, size);

	printf("请输入矩阵2的非零元个数:");
	scRet = scanf("%d", &size);
	MatrixInput(m2, size);
}