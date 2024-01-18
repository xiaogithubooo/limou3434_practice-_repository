#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int ElemType;
typedef struct Sqlist
{
	ElemType* elem;
	int lstsize;//容量
	int length;//长度
}Sqlist;
//初始化函数
void InitSqlist(Sqlist* pSq)
{
	pSq->length = 0;//初始化长度为0，因为没有任何元素
	pSq->elem = (ElemType*)calloc(MAXSIZE, sizeof(ElemType));//申请内存，并且初始化
	if (!(pSq->elem)) exit(-1);//检查是否申请成功
	pSq->lstsize = MAXSIZE;//初始化好容量
}
//前插入函数
void InserElem(Sqlist* pSq, int i, ElemType x)
{
	assert(pSq);//检查空字符
	if (i < 1 || (i > pSq->lstsize)) exit(-1);//检查是否超出要插入的范围
	if (pSq->length == pSq->lstsize)//不够就多申请内存
	{
		ElemType* base = (ElemType*)realloc(pSq->elem, sizeof(ElemType) * (MAXSIZE + pSq->lstsize));
		if (!base)
			exit(-1);
		else
			pSq->elem = base;
	}
	//开始挪动数据
	//假设没有数据则i=1，length=0,lstsize=100
	for (ElemType* p = &(pSq->elem[pSq->lstsize - 1]); p >= &(pSq->elem[i - 1]); p--)
	{
		*p = *(p - 1);
	}
	pSq->elem[i - 1] = x;
	pSq->length++;
}
void DelElem(Sqlist* pSq, int i)
{
	assert(pSq);
	if (i < 1 || i > pSq->length) exit(-1);
	ElemType* p = NULL;
	for (p = &(pSq->elem[i - 1]); p < &(pSq->elem[pSq->length - 2]); p++)
	{
		*p = *(p + 1);
	}
	pSq->length--;
}
void PrintElem(Sqlist* pSq)
{
	for (int i = 0; i < pSq->length; i++)
	{
		printf("%d ", pSq->elem[i]);
	}
}
int main()
{
	Sqlist Sq;
	InitSqlist(&Sq);
	InserElem(&Sq, 1, 1);
	InserElem(&Sq, 2, 2);
	InserElem(&Sq, 3, 3);
	InserElem(&Sq, 4, 4);
	InserElem(&Sq, 2, 0);
	DelElem(&Sq, 5);
	PrintElem(&Sq);
	return 0;
}
