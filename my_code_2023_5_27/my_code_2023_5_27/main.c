#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//typedef int ListNodeDataType;
//typedef struct ListNode
//{
//	ListNodeDataType data;//������
//	struct ListNode* next;//ָ����
//}ListNode;
//ListNode* BuyNode(int x)
//{
//	ListNode* cache = (ListNode*)malloc(sizeof(ListNode));
//	if (!cache) exit(-1);
//	cache->data = x;
//	cache->next = NULL;
//	return cache;
//}
////1.������ĳ�ʼ��
//void InitList(ListNode** head)
//{
//	assert(head);
//	*head = BuyNode(0);
//	(*head)->next = *head;
//}
////2.��������������
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
////3.��������������
//void PushList(ListNode* pNode, ListNodeDataType x)
//{
//	assert(pNode);
//	ListNode* cache = BuyNode(x);
//	ListNode* next = pNode->next;
//	pNode->next = cache;
//	cache->next = next;
//}
////4.�����������ɾ��
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
////5.�����������
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
//	ListNode* A;//Aָ��ָ��ĳ�������ͷ�ڵ�
//	InitList(&A);//��ʼ������
//	PushList(MindList(A, 0), 1);
//	PushList(MindList(A, 0), 2);
//	PushList(MindList(A, 0), 3);
//	PushList(MindList(A, 0), 4);
//	PushList(MindList(A, 0), 5);
//	return 0;
//}