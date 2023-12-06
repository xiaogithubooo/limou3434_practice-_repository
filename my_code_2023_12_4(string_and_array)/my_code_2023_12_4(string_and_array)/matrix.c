//����Ԫ�����ʽ��ʾϡ�����ʵ����������ļӷ�������
#include "matrix.h"

//��Ԫ��
//typedef struct Number
//{
//	int _num;		//Ԫ��
//	int _row;		//������
//	int _col;		//������
//	struct Number* _next;	//ָ����һ�� Number ���
//	struct Number* _prev;	//ָ����һ�� Number ���
//} Number;
//
////����
//typedef struct Matrix
//{
//	Number* _arr;	//�����������
//	int _maxRow;	//�����
//	int _maxCol;	//�����
//	int _size;		//Ԫ�ظ���
//} Matrix;

Number* Buy_Number_Node(int num, int row, int col)
{
	//����ռ�
	Number* newNode = (Number*)malloc(sizeof(Number));
	//����Ƿ�����ɹ�
	if (!newNode) assert(false);

	//��ʼ�����
	newNode->_num = num;
	newNode->_row = row;
	newNode->_col = col;
	newNode->_next = newNode;
	newNode->_prev = newNode;
	
	return newNode;
}

//��ʼ
void Matrix_Init(Matrix* m, int maxRow, int maxCol)
{
	//��ʼ��ͷ�ڵ�
	m->_arr = Buy_Number_Node(0, 0, 0);

	//��ʼ������к���
	m->_maxRow = maxRow;
	m->_maxCol = maxCol;

	//��ʼ���洢Ԫ�ظ���
	m->_size = 0;
}

//���
void Matrix_Push(Matrix* m, int num, int row, int col)
{
	//����Ƿ�Ϊ��ָ��
	assert(m);

	//�������Ƿ����
	if (row > m->_maxRow)
	{
		printf("���벻����������ֹ��\n");
		exit(-1);
	}
	if (col > m->_maxCol)
	{
		printf("���벻����������ֹ��\n");
		exit(-1);
	}

	//�Ż�����Ϊ��ʱ
	if (num == 0) return;

	//�����½�㣬�������ӵ�������
	Number* newNode = Buy_Number_Node(num, row, col);
	if (!newNode) assert(false);
	newNode->_prev = m->_arr->_prev;
	newNode->_next = m->_arr;
	m->_arr->_prev->_next = newNode;
	m->_arr->_prev = newNode;

	m->_size++;
}

//ǰ��
void Matrix_Front(Matrix* m, int num, int row, int col)
{
	//����Ƿ�Ϊ��ָ��
	assert(m);
	
	//�������Ƿ����
	if (row > m->_maxRow)
	{
		printf("���벻����������ֹ��\n");
		exit(-1);
	}
	if (col > m->_maxCol)
	{
		printf("���벻����������ֹ��\n");
		exit(-1);
	}

	//�Ż�����Ϊ��ʱ
	if (num == 0) return;

	//�����½�㣬�������ӵ�������
	Number* newNode = Buy_Number_Node(num, row, col);
	if (!newNode) assert(false);
	newNode->_next = m->_arr->_next;
	newNode->_prev = m->_arr;
	m->_arr->_next->_prev = newNode;
	m->_arr->_next = newNode;

	m->_size++;
}

//��ӡ
void Matrix_Print(Matrix* m)
{
	Number* cur = m->_arr->_next;
	for (int i = 1; i <= m->_maxRow; i++)
	{
		printf("|");
		for (int j = 1; j <= m->_maxCol; j++)
		{
			if (i == cur->_row && j == cur->_col)
			{
				printf("%+d ", cur->_num);
				cur = cur->_next;
			}
			else
			{
				printf(" 0 ");
			}
		}
		printf("|\n");
	}
	printf("\n");
}

//�ӷ�
void Matrix_Add(Matrix* add, Matrix* m1, Matrix* m2)
{
	printf("�ӷ����Ϊ:\n");
	Number* cur1 = m1->_arr->_next;
	Number* cur2 = m2->_arr->_next;

	while (cur1 != m1->_arr && cur2!= m2->_arr)
	{
		if(cur1->_row == cur2->_row)
		{
			if (cur1->_col == cur2->_col)//�к��ж���ȣ�ֱ����ӣ�β��� add ����
			{
				int number = cur1->_num + cur2->_num;
				Matrix_Push(add, number, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
				cur2 = cur2->_next;
			}
			else if (cur1->_col < cur2->_col)//����ȣ��е� cur1 С��β�� cur1 ����
			{
				Matrix_Push(add, cur1->_num, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
			}
			else if (cur1->_col > cur2->_col)//����ȣ��е� cur1 ��β�� cur2 ����
			{
				Matrix_Push(add, cur2->_num, cur2->_row, cur2->_col);
				cur2 = cur2->_next;
			}
			else//������δȻ
			{
				printf("���ֲ���Ԥ֪�Ŀؼ�·��\n");
				assert(false);
			}
		}
		else if (cur1->_row < cur2->_row)
		{
			Matrix_Push(add, cur1->_num, cur1->_row, cur1->_col);
			cur1 = cur1->_next;
		}
		else if (cur1->_row > cur2->_row)
		{
			Matrix_Push(add, cur2->_num, cur2->_row, cur2->_col);
			cur2 = cur2->_next;
		}
		else//������δȻ
		{
			printf("���ֲ���Ԥ֪�Ŀؼ�·��\n");
			assert(false);
		}
	}

	while (cur1 != m1->_arr)
	{
		Matrix_Push(add, cur1->_num, cur1->_row, cur1->_col);
		cur1 = cur1->_next;
	}
	while (cur2 != m2->_arr)
	{
		Matrix_Push(add, cur2->_num, cur2->_row, cur2->_col);
		cur2 = cur2->_next;
	}

	//��ӡ����
	Matrix_Print(add);
}

//����
void Matrix_Sub(Matrix* sub, Matrix* m1, Matrix* m2)
{
	printf("�������Ϊ:\n");
	Number* cur1 = m1->_arr->_next;
	Number* cur2 = m2->_arr->_next;

	while (cur1 != m1->_arr && cur2 != m2->_arr)
	{
		if (cur1->_row == cur2->_row)
		{
			if (cur1->_col == cur2->_col)//�к��ж���ȣ�ֱ����ӣ�β��� sub ����
			{
				int number = cur1->_num - cur2->_num;
				Matrix_Push(sub, number, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
				cur2 = cur2->_next;
			}
			else if (cur1->_col < cur2->_col)//����ȣ��е� cur1 С��β�� cur1 ����
			{
				Matrix_Push(sub, cur1->_num, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
			}
			else if (cur1->_col > cur2->_col)//����ȣ��е� cur1 ��β�� cur2 ����
			{
				Matrix_Push(sub, -(cur2->_num), cur2->_row, cur2->_col);
				cur2 = cur2->_next;
			}
			else//������δȻ
			{
				printf("���ֲ���Ԥ֪�Ŀؼ�·��\n");
				assert(false);
			}
		}
		else if (cur1->_row < cur2->_row)
		{
			Matrix_Push(sub, cur1->_num, cur1->_row, cur1->_col);
			cur1 = cur1->_next;
		}
		else if (cur1->_row > cur2->_row)
		{
			Matrix_Push(sub, -(cur2->_num), cur2->_row, cur2->_col);
			cur2 = cur2->_next;
		}
		else//������δȻ
		{
			printf("���ֲ���Ԥ֪�Ŀؼ�·��\n");
			assert(false);
		}
	}

	while (cur1 != m1->_arr)
	{
		Matrix_Push(sub, cur1->_num, cur1->_row, cur1->_col);
		cur1 = cur1->_next;
	}
	while (cur2 != m2->_arr)
	{
		Matrix_Push(sub, -(cur2->_num), cur2->_row, cur2->_col);
		cur2 = cur2->_next;
	}

	//��ӡ����
	Matrix_Print(sub);
}

//����
void Matrix_Destroy(Matrix* m)
{
	Number* cur = m->_arr->_next;
	while (cur != m->_arr)
	{
		Number* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(cur);
}