#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXSIZE 10
#define NUMBER 10
typedef int ElemType;
typedef struct Sqlist
{
	ElemType* elem;
	int listsize;//长度
	int length;//容量
}Sqlist;
void InitSqlist(Sqlist* pSq)
{
	assert(pSq);
	ElemType* base = (ElemType*)calloc(MAXSIZE, sizeof(ElemType));
	if (!base) exit(-1);
	pSq->elem = base;
	pSq->listsize = MAXSIZE;
	pSq->length = 0;
}
void InserElem(Sqlist* pSq, int i, ElemType x)
{
	assert(pSq);
	if (i < 1 || i > pSq->length + 1) exit(-1);
	if (pSq->length == pSq->listsize)
	{
		ElemType* base = (ElemType*)realloc(pSq->elem, (pSq->listsize + MAXSIZE) * sizeof(ElemType));
		if (!base) exit(-1);
		pSq->elem = base;
		//memset(pSq->elem, 0, sizeof(ElemType) * pSq->listsize);//填充动态内存，这个语句就不应该存在……
		pSq->listsize = pSq->listsize + MAXSIZE;
	}
	ElemType* p = &(pSq->elem[i - 1]);
	ElemType* pend = &(pSq->elem[pSq->listsize - 2]);
	for (pend; pend >= p; pend--)
	{
		*(pend + 1) = *(pend);
	}
	pSq->elem[i - 1] = x;
	pSq->length++;
}
void DelElem(Sqlist* pSq, int i)
{
	assert(pSq);
	if (i < 1 || i > pSq->length + 1) exit(-1);
	if (pSq->length == 0) exit(-1);
	ElemType* p = &(pSq->elem[i - 1]);
	ElemType* pend = &(pSq->elem[pSq->length - 1]);
	for (p; p <= pend; p++)
	{
		*(p) = *(p + 1);
	}
	pSq->length--;
}
void PrintElem(Sqlist* pSq)
{
	for (int i = 0; i < pSq->length - 1; i++)
	{
		printf("%d ", pSq->elem[i]);
	}
	printf("\n");
}
void test_1(void)
{
	Sqlist S;
	InitSqlist(&S);
	InserElem(&S, 1, 1);
	InserElem(&S, 2, 2);
	InserElem(&S, 3, 3);
	InserElem(&S, 3, 3);
	InserElem(&S, 4, 4);
	InserElem(&S, 5, 5);
	InserElem(&S, 6, 6);
	InserElem(&S, 7, 7);
	InserElem(&S, 8, 8);
	InserElem(&S, 9, 9);
	InserElem(&S, 10, 10);
	InserElem(&S, 11, 11);
	InserElem(&S, 12, 12);
	PrintElem(&S);

	DelElem(&S, 1);
	DelElem(&S, 1);
	DelElem(&S, 1);
	DelElem(&S, 1);
	PrintElem(&S);
}
int main()
{
	test_1();
	return 0;
}