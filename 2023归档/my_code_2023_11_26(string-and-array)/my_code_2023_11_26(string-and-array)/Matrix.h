#pragma once
#include "Triad.h"

//������Ҫ���������Դ������С�����С�Ԫ�ظ�����
typedef struct Matrix
{
	int _maxRow;	//�������
	int _maxCol;	//�������
	int _effNum;	//��Ч����
	Triad* _triad;	//ͷָ��
}Matrix;

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