#include "Matrix.h"

/*
typedef struct Matrix
{
	int _maxRow;	//�������
	int _maxCol;	//�������
	int _effNum;	//��Ч����
}Matrix;
*/

//�����ʼ������
void InitMatrix(Matrix* mat);

//������뺯��
void InsertMatrix(Matrix* mat, Triad* data);

//�����ӡ����
void PrintMatrix(Matrix* mat);

//����ӷ�����
void Add(Matrix* mat);

//�����������
void Sub(Matrix* mat);