#include "Matrix.h"

void DataInput(Matrix* m1, Matrix* m2);
int main()
{
	Matrix m1;
	Matrix m2;

	//1.�����������
	DataInput(&m1, &m2);

	//2.�������ӷ�
	MatrixPrint(MatrixAdd(&m1, &m2));
	
	//3.����������
	MatrixPrint(MatrixSub(&m1, &m2));
	return 0;
}

void DataInput(Matrix* m1, Matrix* m2)
{
	int size = 0;
	int scRet = 0;
	int maxRow = 0;
	int maxCol = 0;

	printf("�����������������к������:");
	scanf("%d %d", &maxRow, &maxCol);
	m1->_maxRow = m2->_maxRow = maxRow;
	m1->_maxCol = m2->_maxCol = maxCol;

	printf("���������1�ķ���Ԫ����:");
	scRet = scanf("%d", &size);
	MatrixInput(m1, size);

	printf("���������2�ķ���Ԫ����:");
	scRet = scanf("%d", &size);
	MatrixInput(m2, size);
}