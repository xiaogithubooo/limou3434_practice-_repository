#include <stdio.h>
#include "Matrix.h"
#include "Triad.h"
int main()
{
	//1.��ʼ��������
	Matrix* m1;	//����1
	Matrix* m2;	//����2
	InitMatrix(m1);	//�����ʼ��
	InitMatrix(m2);	//�����ʼ��

	//2.�����������
	int m_size = 0;	//����Ԫ�ظ���
	scanf("%d", &m_size);

	printf("���������1��Ԫ��:\n");
	for (int i = 0; i < m_size; i++)
	{
		printf("�������%d��Ԫ�ص������С������С�����ֵ:", i);
		InsertMatrix(m1, );
	}

	printf("���������2��Ԫ��:\n");
	for (int i = 0; i < m_size; i++)
	{
		printf("�������%d��Ԫ�ص������С������С�����ֵ:", i);
		InsertMatrix(m2, data);
	}

	//��ӡ���󣬼������
	PrintMatrix(m1);
	PrintMatrix(m2);

	//����ӷ������Ҵ�ӡ
	PrintMatrix(Add(m1, m2));

	//������������Ҵ�ӡ
	PrintMatrix(Sub(m1, m2));

	return 0;
}