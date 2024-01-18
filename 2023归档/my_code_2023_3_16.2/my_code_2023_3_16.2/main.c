#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int ListDataType;
typedef struct ListNode
{
	struct ListNode* next;//后继指针
	struct ListNode* prev;//前驱指针
	ListDataType data;
}ListNode;
//1、申请节点空间接口函数
ListNode* Buy_List_Node(ListDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListDataType));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//2、初始化节点接口函数
ListNode* List_Init(void)
{
	 ListNode* phead = Buy_List_Node(0);
	 phead->next = phead;
	 phead->prev = phead;
	 return phead;
}
//3、销毁接口函数
void List_Destory(ListNode* phead)
{
	;
}
//3、尾部插入接口函数
void List_Push_Back(ListNode* phead, ListDataType x)
{
	ListNode* tail = phead->prev;//直接找到尾节点
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