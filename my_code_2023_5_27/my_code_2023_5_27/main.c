#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//typedef int ListNodeDataType;
//typedef struct ListNode
//{
//	ListNodeDataType data;//数据域
//	struct ListNode* next;//指针域
//}ListNode;
//ListNode* BuyNode(int x)
//{
//	ListNode* cache = (ListNode*)malloc(sizeof(ListNode));
//	if (!cache) exit(-1);
//	cache->data = x;
//	cache->next = NULL;
//	return cache;
//}
////1.单链表的初始化
//void InitList(ListNode** head)
//{
//	assert(head);
//	*head = BuyNode(0);
//	(*head)->next = *head;
//}
////2.单链表的任意查找
//ListNode* MindList(ListNode* head, int n)
//{
//	assert(head);
//	assert(n >= 0);
//	ListNode* cache = head->next;
//	while (n && cache != head)
//	{
//		cache = cache->next;
//		n--;
//	}
//	return cache;
//}
////3.单链表的任意插入
//void PushList(ListNode* pNode, ListNodeDataType x)
//{
//	assert(pNode);
//	ListNode* cache = BuyNode(x);
//	ListNode* next = pNode->next;
//	pNode->next = cache;
//	cache->next = next;
//}
////4.单链表的任意删除
//void DeleList(ListNode* pNode)
//{
//	assert(pNode);
//	assert(pNode->next != pNode);
//	ListNode* cur = pNode;
//	ListNode* next = pNode;
//	ListNode* dele = pNode;
//	ListNode* prev = cur;
//	while (cur->next != pNode)
//	{
//		cur = cur->next;
//		prev = cur;
//	}
//	free(pNode);
//	prev->next = next;
//}
////5.单链表的销毁
//void DestList(ListNode* head)
//{
//	ListNode* next = head->next->next;
//	ListNode* dele = head->next;
//	while (next != head)
//	{
//		free(dele);
//		dele = next;
//		next = next->next;
//	}
//	free(head);
//}
//int main()
//{
//	ListNode* A;//A指针指向某个链表的头节点
//	InitList(&A);//初始化链表
//	PushList(MindList(A, 0), 1);
//	PushList(MindList(A, 0), 2);
//	PushList(MindList(A, 0), 3);
//	PushList(MindList(A, 0), 4);
//	PushList(MindList(A, 0), 5);
//	return 0;
//}