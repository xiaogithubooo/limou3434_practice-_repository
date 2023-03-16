#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int ListDataType;
typedef struct ListNode
{
	struct ListNode* next;//���ָ��
	struct ListNode* prev;//ǰ��ָ��
	ListDataType data;
}ListNode;
//1������ڵ�ռ�ӿں���
ListNode* Buy_List_Node(ListDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListDataType));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//2����ʼ���ڵ�ӿں���
ListNode* List_Init(void)
{
	 ListNode* phead = Buy_List_Node(0);
	 phead->next = phead;
	 phead->prev = phead;
	 return phead;
}
//3�����ٽӿں���
void List_Destory(ListNode* phead)
{
	;
}
//3��β������ӿں���
void List_Push_Back(ListNode* phead, ListDataType x)
{
	ListNode* tail = phead->prev;//ֱ���ҵ�β�ڵ�
	ListNode* newnode = Buy_List_Node(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void Test_List()
{
	ListNode* plist = List_Init();
	List_Push_Back(plist, 1);
	List_Destory(plist);
}
int main()
{
	return 0;
}