#include <stdio.h>
#include "Matrix.h"
#include "Triad.h"
int main()
{
	//1.初始化两矩阵
	Matrix* m1;	//矩阵1
	Matrix* m2;	//矩阵2
	InitMatrix(m1);	//矩阵初始化
	InitMatrix(m2);	//矩阵初始化

	//2.输入矩阵数据
	int m_size = 0;	//矩阵元素个数
	scanf("%d", &m_size);

	printf("请输入矩阵1的元素:\n");
	for (int i = 0; i < m_size; i++)
	{
		printf("请输入第%d个元素的所处行、所处列、所带值:", i);
		InsertMatrix(m1, );
	}

	printf("请输入矩阵2的元素:\n");
	for (int i = 0; i < m_size; i++)
	{
		printf("请输入第%d个元素的所处行、所处列、所带值:", i);
		InsertMatrix(m2, data);
	}

	//打印矩阵，检查输入
	PrintMatrix(m1);
	PrintMatrix(m2);

	//矩阵加法，并且打印
	PrintMatrix(Add(m1, m2));

	//矩阵减法，并且打印
	PrintMatrix(Sub(m1, m2));

	return 0;
}