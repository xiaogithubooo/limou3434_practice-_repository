#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//1.����ʽ�ṹ��
typedef struct Data
{
	int _coefficient;	//ÿһ���ϵ��
	int _power;			//ÿһ�������
}Data;

//2.����ͷ+��ѭ��+˫��+�����ṹ�� 
typedef Data LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//3.����ڵ�ռ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* cache = (ListNode*)malloc(sizeof(ListNode));//����һ���ڵ�Ŀռ�
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

//4.��ʼ������ͷ+��ѭ��+˫��+����������һ���������ͷ�ڵ㡱��
ListNode* ListInit(void)
{
	Data data = { 0, 0 };
	ListNode* cache = BuyListNode(data);
	if (!cache) exit(-1);

	cache->next = cache;
	cache->prev = cache;
	return cache;
}

//5.β�塰��ͷ+��ѭ��+˫��+����
void ListPushBack(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* cache = BuyListNode(x);//����ڵ�ռ�
	if (!cache) exit(-1);

	plist->prev->next = cache;//�ҵ�ָ��β�ڵ��ָ��
	cache->prev = plist->prev;
	cache->next = plist;
	plist->prev = cache;
}

//6.ͷ�塰��ͷ+��ѭ��+˫��+����
void ListPushFront(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode* cache = BuyListNode(x);//����ڵ�ռ�
	if (!cache) exit(-1);

	ListNode* p = plist->next;
	plist->next = cache;
	cache->next = p;
	cache->prev = plist;
	p->prev = cache;
}

//7.���١���ͷ+��ѭ��+˫��+����
void ListDestory(ListNode* plist)
{
	//1.��ֹ��ָ�������
	assert(plist);
	ListNode* cur = plist->next;//ѭ������
	//2.���ͷŵ�ѭ��������
	while (cur != plist)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//3.���ͷŵ�ͷ�ڵ�
	free(plist);
	//plist = NULL;//û��Ҫ�ã�Ҫ�ÿվ�Ҫʹ�ö���ָ�룬��ʹ�õĻ���Ҫ��ʹ�����ÿ�
}

//8.��������Ĵ�С
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

//9.����ͷ+��ѭ��+˫��+������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);//��������ÿ�ָ��
	ListNode* cache = BuyListNode(x);//�����½ڵ�

	ListNode* p = pos->prev;
	pos->prev = cache;
	cache->next = pos;
	cache->prev = p;
	p->next = cache;
}

//10.����ͷ+��ѭ��+˫��+����ɾ��posλ�õĽ��
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

//11.�������
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

//12.����ת������ʽ
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