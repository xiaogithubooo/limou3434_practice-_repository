#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode//单向链表结构体
{
	SLTDataType data;
	struct SListNode* next;//这里不是结构体套结构体，而单纯是一个指针，指向下一个结构体。（就是一个地址）
 }SLTNode;

//链表尾插接口函数
void SListPushBack(SLTNode* phead, SLTDataType x)
{
	//1、首先形成一个单独的节点（赋予值和空指针）
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	// 2、下面是将上面单独的节点设置为链表的新尾节点
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		//①找到当前链表尾节点的空指针
		SLTNode* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//②将这个旧尾节点空指针，设置为指向新尾节点的指针
		tail->next = newnode;
	}
}

//链表头插接口函数
void SListPushFront(SLTNode* phead, SLTDataType x)
{
	;
}

//链表打印插口函数
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
}

//链表首元素置空接口函数
void TestSList1()
{
	SLTNode* plist = NULL;//此时链表是空的
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPrint(plist);
}

//测试驱动函数
int main()
{
	TestSList1();
}