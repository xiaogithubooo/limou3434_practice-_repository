#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//# 1.静态链表的实现

//>	1.1.静态链表结构体
#define MAXSIZE 10
typedef int ElemType;
typedef struct SLListNode
{
	ElemType data;
	int cur;
}SLListNode;
//> 1.2.静态链表初始化
void InitList(SLListNode* list)
{
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		list[i].cur = i + 1;
	}
	list[MAXSIZE - 1].cur = 0;
}
//> 1.3.静态链表插入
//辅助函数：查找空置的节点，成功则返回非负值，失败就返回-1
int MallocSLL(SLListNode* list)
{
	assert(list);
	//1.取出首链表存储的空闲链表索引
	int index = list[0].cur;
	//2.修改首链表的此时存储的空闲链表索引
	if (index != MAXSIZE - 1)//如果这个索引不是末链表的索引就进入
	{
		list[0].cur = list[index].cur;//修改
		return index;
	}
	return -1;
}
void InsertList(SLListNode* list, ElemType x)
{
	assert(list);
	//1.申请空闲链表
	int index = MallocSLL(list);//找空闲链表
	assert(index != -1);//检查是否找到
	//2.插入
	list[index].data = x;
	//3.注意末节点
	if (list[MAXSIZE - 1].cur == 0)
		list[MAXSIZE - 1].cur = index;
}
//> 1.4.静态链表长度
int LengthList(SLListNode* list)
{
	assert(list);
	int i = list[MAXSIZE - 1].cur;
	int number = 0;
	while (i)
	{
		i = list[i].cur;
		number++;
	}
	return number;
}
//> 1.5.静态链表删除
void Free(SLListNode* list, int behind)
{
	assert(list);
	list[behind].cur = list[0].cur;
	list[behind].cur = behind;
}
void DeleList(SLListNode* list, int k)
{
	assert(list);
	//1.检查k的有效性
	assert(k < 1 || k > LengthList(list));
	//2.开始删除
	int front = MAXSIZE - 1, behind = 0;//front保存“指向要删除节点的前一个节点的”cur，behind保存“指向要删除节点的”cur
	for (int i = 0; i < k; i++)
	{
		front = list[front].cur;
	}//最后front存储的是“指向要删除节点的前一个节点的”cur
	behind = list[front].cur;//最后behind存储的是“指向要删除节点的”cur
	list[front].cur = list[behind].cur;
	//3.销毁这个被删除的节点，并且返回这个空闲的索引给首链表
	Free(list, behind);
}
void test_1(void)
{
	SLListNode list[MAXSIZE] = { 0 };//创建一个静态链表
	InitList(list);//初始化
	InsertList(list, 1);//插入数据
	InsertList(list, 2);//插入数据
	InsertList(list, 3);//插入数据
	InsertList(list, 4);//插入数据
	DeleList(list, 3);//删除数据
}
int main()
{
	test_1();
	return 0;
}