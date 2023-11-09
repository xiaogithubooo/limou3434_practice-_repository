#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//1.多项式结构体
typedef struct Data
{
	int _coefficient;	//每一项的系数
	int _power;			//每一项的幂数
}Data;

//2.“有头+有循环+双向+链表”结构体 
typedef Data LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//3.申请节点空间
ListNode* BuyListNode(LTDataType x)
{
	ListNode* cache = (ListNode*)malloc(sizeof(ListNode));//申请一个节点的空间
	if (!cache)
	{
		perror("malloc fail!");
		return NULL;
	}
	cache->data = x;
	cache->next = NULL;
	cache->prev = NULL;
	return cache;
}

//4.初始化“有头+有循环+双向+链表”（创建一个“链表的头节点”）
ListNode* ListInit(void)
{
	Data data = { 0, 0 };
	ListNode* cache = BuyListNode(data);
	if (!cache) exit(-1);

	cache->next = cache;
	cache->prev = cache;
	return cache;
}

//5.尾插“有头+有循环+双向+链表”
void ListPushBack(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* cache = BuyListNode(x);//申请节点空间
	if (!cache) exit(-1);

	plist->prev->next = cache;//找到指向尾节点的指针
	cache->prev = plist->prev;
	cache->next = plist;
	plist->prev = cache;
}

//6.头插“有头+有循环+双向+链表”
void ListPushFront(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* cache = BuyListNode(x);//申请节点空间
	if (!cache) exit(-1);

	ListNode* p = plist->next;
	plist->next = cache;
	cache->next = p;
	cache->prev = plist;
	p->prev = cache;
}

//7.销毁“有头+有循环+双向+链表”
void ListDestory(ListNode* plist)
{
	//1.防止空指针解引用
	assert(plist);
	ListNode* cur = plist->next;//循环变量
	//2.先释放掉循环的链表
	while (cur != plist)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//3.再释放掉头节点
	free(plist);
	//plist = NULL;//没必要置，要置空就要使用二级指针，不使用的话就要让使用者置空
}

//8.返回链表的大小
int ListSize(ListNode* plist)
{
	assert(plist != NULL);
	ListNode* cur = plist->next;
	int size = 0;
	while (cur != plist)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//9.“有头+有循环+双向+链表”在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);//避免解引用空指针
	ListNode* cache = BuyListNode(x);//购买新节点

	ListNode* p = pos->prev;
	pos->prev = cache;
	cache->next = pos;
	cache->prev = p;
	p->next = cache;
}

//10.“有头+有循环+双向+链表”删除pos位置的结点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

//11.链表相加
ListNode* AddTwoLink(ListNode* pl1, ListNode* pl2)
{
	assert(pl1);
	assert(pl2);
	ListNode* cur1 = pl1->next;
	ListNode* cur2 = pl2->next;
	ListNode* ret = ListInit();

	while (cur1 != pl1 && cur2 != pl2)
	{
		if (cur1->data._power == cur2->data._power)
		{
			int add = cur1->data._coefficient + cur2->data._coefficient;
			if (add != 0)
			{
				Data data = { add, cur1->data._power };
				ListPushBack(ret, data);
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else if (cur1->data._power > cur2->data._power)
		{
			ListPushBack(ret, cur1->data);
			cur1 = cur1->next;
		}
		else //cur1->data._power < cur2->data._power
		{
			ListPushBack(ret, cur2->data);
			cur2 = cur2->next;
		}
	}
	while (cur1 != pl1)
	{
		ListPushBack(ret, cur1->data);
		cur1 = cur1->next;
	}
	while (cur2 != pl2)
	{
		ListPushBack(ret, cur2->data);
		cur2 = cur2->next;
	}

	return ret;
}

//12.链表转化多项式
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d*x^%d", cur->data._coefficient, cur->data._power);
		cur = cur->next;
		if (cur != plist)
		{
			printf(" + ");
		}
	}
	printf("\n");
}