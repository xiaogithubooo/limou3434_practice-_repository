//����Ԫ�����ʽ��ʾϡ�����ʵ����������ļӷ�������

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//��Ԫ��
typedef struct Number
{
	int _num;		//Ԫ��
	int _row;		//������
	int _col;		//������
	struct Number* _next;	//ָ����һ�� Number ���
	struct Number* _prev;	//ָ����һ�� Number ���
} Number;

//����
typedef struct Matrix
{
	Number* _arr;	//�����������
	int _maxRow;	//�����
	int _maxCol;	//�����
	int _size;		//Ԫ�ظ���
} Matrix;

//��ʼ��
void Matrix_Init(Matrix* m, int maxRow, int maxCol);

//���
void Matrix_Push(Matrix* m, int num, int row, int col);

//ǰ��
void Matrix_Front(Matrix* m, int num, int row, int col);

//��ӡ
void Matrix_Print(Matrix* m);

//�ӷ�
void Matrix_Add(Matrix* add, Matrix* m1, Matrix* m2);

//����
void Matrix_Sub(Matrix* sub, Matrix* m1, Matrix* m2);

//����
void Matrix_Destroy(Matrix* m);