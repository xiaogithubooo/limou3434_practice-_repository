//以三元组表形式表示稀疏矩阵，实现两个矩阵的加法、减法
#include "matrix.h"

//三元组
//typedef struct Number
//{
//	int _num;		//元素
//	int _row;		//坐在行
//	int _col;		//所在列
//	struct Number* _next;	//指向下一个 Number 结点
//	struct Number* _prev;	//指向上一个 Number 结点
//} Number;
//
////矩阵
//typedef struct Matrix
//{
//	Number* _arr;	//管理矩阵链表
//	int _maxRow;	//最大行
//	int _maxCol;	//最大列
//	int _size;		//元素个数
//} Matrix;

Number* Buy_Number_Node(int num, int row, int col)
{
	//申请空间
	Number* newNode = (Number*)malloc(sizeof(Number));
	//检查是否申请成功
	if (!newNode) assert(false);

	//初始化结点
	newNode->_num = num;
	newNode->_row = row;
	newNode->_col = col;
	newNode->_next = newNode;
	newNode->_prev = newNode;
	
	return newNode;
}

//初始
void Matrix_Init(Matrix* m, int maxRow, int maxCol)
{
	//初始化头节点
	m->_arr = Buy_Number_Node(0, 0, 0);

	//初始化最大行和列
	m->_maxRow = maxRow;
	m->_maxCol = maxCol;

	//初始化存储元素个数
	m->_size = 0;
}

//后插
void Matrix_Push(Matrix* m, int num, int row, int col)
{
	//检查是否为空指针
	assert(m);

	//检查插入是否合理
	if (row > m->_maxRow)
	{
		printf("输入不合理，程序终止！\n");
		exit(-1);
	}
	if (col > m->_maxCol)
	{
		printf("输入不合理，程序终止！\n");
		exit(-1);
	}

	//优化插入为零时
	if (num == 0) return;

	//购买新结点，并且链接到链表中
	Number* newNode = Buy_Number_Node(num, row, col);
	if (!newNode) assert(false);
	newNode->_prev = m->_arr->_prev;
	newNode->_next = m->_arr;
	m->_arr->_prev->_next = newNode;
	m->_arr->_prev = newNode;

	m->_size++;
}

//前插
void Matrix_Front(Matrix* m, int num, int row, int col)
{
	//检查是否为空指针
	assert(m);
	
	//检查插入是否合理
	if (row > m->_maxRow)
	{
		printf("输入不合理，程序终止！\n");
		exit(-1);
	}
	if (col > m->_maxCol)
	{
		printf("输入不合理，程序终止！\n");
		exit(-1);
	}

	//优化插入为零时
	if (num == 0) return;

	//购买新结点，并且链接到链表中
	Number* newNode = Buy_Number_Node(num, row, col);
	if (!newNode) assert(false);
	newNode->_next = m->_arr->_next;
	newNode->_prev = m->_arr;
	m->_arr->_next->_prev = newNode;
	m->_arr->_next = newNode;

	m->_size++;
}

//打印
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

//加法
void Matrix_Add(Matrix* add, Matrix* m1, Matrix* m2)
{
	printf("加法结果为:\n");
	Number* cur1 = m1->_arr->_next;
	Number* cur2 = m2->_arr->_next;

	while (cur1 != m1->_arr && cur2!= m2->_arr)
	{
		if(cur1->_row == cur2->_row)
		{
			if (cur1->_col == cur2->_col)//行和列都相等，直接相加，尾插给 add 即可
			{
				int number = cur1->_num + cur2->_num;
				Matrix_Push(add, number, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
				cur2 = cur2->_next;
			}
			else if (cur1->_col < cur2->_col)//行相等，列的 cur1 小，尾插 cur1 即可
			{
				Matrix_Push(add, cur1->_num, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
			}
			else if (cur1->_col > cur2->_col)//行相等，列的 cur1 大，尾插 cur2 即可
			{
				Matrix_Push(add, cur2->_num, cur2->_row, cur2->_col);
				cur2 = cur2->_next;
			}
			else//防范于未然
			{
				printf("出现不可预知的控件路径\n");
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
		else//防范于未然
		{
			printf("出现不可预知的控件路径\n");
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

	//打印矩阵
	Matrix_Print(add);
}

//减法
void Matrix_Sub(Matrix* sub, Matrix* m1, Matrix* m2)
{
	printf("减法结果为:\n");
	Number* cur1 = m1->_arr->_next;
	Number* cur2 = m2->_arr->_next;

	while (cur1 != m1->_arr && cur2 != m2->_arr)
	{
		if (cur1->_row == cur2->_row)
		{
			if (cur1->_col == cur2->_col)//行和列都相等，直接相加，尾插给 sub 即可
			{
				int number = cur1->_num - cur2->_num;
				Matrix_Push(sub, number, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
				cur2 = cur2->_next;
			}
			else if (cur1->_col < cur2->_col)//行相等，列的 cur1 小，尾插 cur1 即可
			{
				Matrix_Push(sub, cur1->_num, cur1->_row, cur1->_col);
				cur1 = cur1->_next;
			}
			else if (cur1->_col > cur2->_col)//行相等，列的 cur1 大，尾插 cur2 即可
			{
				Matrix_Push(sub, -(cur2->_num), cur2->_row, cur2->_col);
				cur2 = cur2->_next;
			}
			else//防范于未然
			{
				printf("出现不可预知的控件路径\n");
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
		else//防范于未然
		{
			printf("出现不可预知的控件路径\n");
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

	//打印矩阵
	Matrix_Print(sub);
}

//销毁
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