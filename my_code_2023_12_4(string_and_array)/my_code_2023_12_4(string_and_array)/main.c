#define _CRT_SECURE_NO_WARNINGS 1
#include "matrix.h"

int scaRet = 0;
void Matrix_Set(Matrix* m, int maxRow, int maxCol)
{
	int number = 0, row = 0, col = 0;
	printf("����������ЧԪ�ظ���:");
	int size = 0;
	scaRet = scanf("%d", &size);
	if (size > maxRow * maxCol)
	{
		printf("��Ч���ֱȾ�����Ԫ�ظ�����Ҫ�࣬��ǰ�����ѽ���������������\n");
		exit(-1);
	}
	int i = 1;
	while (size--)
	{
		printf("������ЧԪ��%d��ֵ������:", i++);
		scaRet = scanf("%d %d %d", &number, &row, &col);
		Matrix_Push(m, number, row, col);
	}
	Matrix_Print(m);
}
int main()
{
	//��ʼ����
	Matrix m1;
	Matrix m2;
	int maxRow = 0;
	int maxCol = 0;
	printf("��������Ҫ����ľ��������к������:");
	scaRet = scanf("%d %d", &maxRow, &maxCol);
	if (maxRow <= 0 || maxCol <= 0)
	{
		printf("����������룬�������\n");
		exit(-1);
	}

	Matrix_Init(&m1, maxRow, maxCol);
	Matrix_Init(&m2, maxRow, maxCol);

	Matrix* add = (Matrix*)malloc(sizeof(Matrix));
	Matrix* sub = (Matrix*)malloc(sizeof(Matrix));
	Matrix_Init(add, maxRow, maxCol);
	Matrix_Init(sub, maxRow, maxCol);

	//���þ��� 1
	//1  2  3  0  0
	//0  0  2  0  1
	//0  5  6  0  3
	//8  0  0 -1  7
	Matrix_Set(&m1, maxRow, maxCol);

	//���þ��� 2 
	//1  3  0  0  0
	//0  0  0  0  0
	//1  0  0 -3  0
	//3  0  0  9  8
	Matrix_Set(&m2, maxRow, maxCol);

	//����ӷ�
	Matrix_Add(add ,&m1, &m2);
	//�������
	Matrix_Sub(sub ,&m1, &m2);

	//������Դ
	free(add);
	free(sub);
	Matrix_Destroy(&m1);
	Matrix_Destroy(&m2);
	return 0;
}