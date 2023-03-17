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
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
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
	return phead;//返回指向这个初始化节点的地址
}

//3、尾插接口函数
void List_Push_Back(ListNode* phead, ListDataType x)
{
	assert(phead);//保证指针的有效性

	ListNode* tail = phead->prev;//直接找到尾节点

	ListNode* newnode = Buy_List_Node(x);//先创建一个新节点空间

	tail->next = newnode;//通过四个步骤连接好新的节点融入链表，从这里也可以看到newnode不是赋予给形参，而是赋予形参指向的节点的成员，因此不需要开头传入二级指针
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//4、头插接口函数
void List_Push_Front(ListNode* phead, ListDataType x)
{
	assert(phead);//保证指针的有效性
	
	ListNode* first = phead->next;//保存指向头节点的指针，如果没有这个，在交换节点指针的时候就要注意改变的顺序

	ListNode* newnode = Buy_List_Node(x);//创建一个新节点，准备插入成头节点

	//改变节点间的指针，使新节点变成头结点
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

//5、尾删接口函数
void List_Pop_Back(ListNode* phead)
{
	assert(phead);//保证指针的有效性
	assert(phead->next != phead);//确保不会释放掉哨兵节点

	//改变节点间的指针，使一个节点被隔离
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;

	//将被隔离的节点释放空间，并且置空
	free(tail);
	tail = NULL;
}

//6、头删接口函数
void List_Pop_Front(ListNode* phead)
{
	assert(phead);//保证指针的有效性
	assert(phead->next != phead);//确保不会释放掉哨兵节点

	//改变节点间的指针，使一个节点被隔离
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	//将被隔离的节点释放空间，并且置空
	free(first);
	first = NULL;
}

//7、查找接口函数（查早到pos），这个接口函数同时也可以做到修改某个节点的数据
ListNode* List_Find(ListNode* phead, ListDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;//也可以尝试倒着走
	}
	return NULL;
}

//8、任意插入接口函数（在pos前插入）
void List_Insert(ListNode* pos, ListDataType x)
{
	assert(pos);//保证指针有效性

	ListNode* prev = pos->prev;
	ListNode* newnode = Buy_List_Node(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//9、任意删除接口函数（在pos删除）
void List_Erase(ListNode* pos)
{
	assert(pos);//保证指针有效性
	assert(pos->next != pos);//确保不会释放掉哨兵节点

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

//10、判空接口函数（是否只有哨兵节点，比较简单，只需要判断是否指向自己就行，就是记得要加头文件stdbool.h才能使用bool值）
//bool ListEmpty(ListNode* phead)

//11、size接口函数（判断链表的大小，也比较简单）
//int ListSize(ListNode* phead)

//12、打印接口函数
void List_Print(ListNode* phead)
{
	assert(phead);//保证指针的有效性

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("|%+2d|<->", cur->data);
		cur = cur->next;
	}
	printf("循环到开头\n");
}

//13、销毁链表接口函数
void List_Destory(ListNode* phead)
{
	assert(phead);//保证指针的有效性

	//1、销毁节点
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	//2、销毁哨兵节点
	free(phead);
	phead = NULL;
}

//测试函数
void Test_List()
{
	//1、初始化头结点
	ListNode* plist = List_Init();

	//2、插入尾节点
	List_Push_Back(plist, 1);
	List_Push_Back(plist, 2);
	List_Push_Back(plist, 3);
	List_Push_Back(plist, 4);
	List_Print(plist);

	//3、插入头节点
	List_Push_Front(plist, 0);
	List_Push_Front(plist, -1);
	List_Push_Front(plist, -2);
	List_Push_Front(plist, -3);
	List_Print(plist);

	//4、尾删节点
	List_Pop_Back(plist);
	List_Print(plist);

	//5、头删节点
	List_Pop_Front(plist);
	List_Print(plist);

	//6、查找某个节点
	ListNode* pos = List_Find(plist, 1);
	if (pos != NULL)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	pos = List_Find(plist, 0);
	if (pos != NULL)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	pos = List_Find(plist, 100);
	if (pos != NULL)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}

	//7、任意插入接口函数
	List_Insert(List_Find(plist, 1), 100);
	List_Insert(List_Find(plist, 0), 200);
	List_Print(plist);

	//8、任意删除接口函数
	List_Erase(List_Find(plist, 1));
	List_Erase(List_Find(plist, 0));
	List_Print(plist);

	//9、销毁链表函数
	List_Destory(plist);
}

int main()
{
	Test_List();
	return 0;
}