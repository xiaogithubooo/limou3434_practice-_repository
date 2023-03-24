#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1、初始化队列接口函数
void Queue_Init(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//2、队列销毁接口函数
void Queue_Destory(Queue* pq)
{
	assert(pq);
	//assert(pq->head);这条语句是不用的！！！
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
//3、队尾入（加链表节点）
void Queue_Push(Queue* pq, QueueDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//初始化一下这个新申请的节点
	newnode->data = x;
	newnode->next = NULL;

	//连接新节点
	if (pq->tail == NULL)//如果链表没有节点
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;//更新tail
	}
}
//3、队头出（删链表节点）
void Queue_Pop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	//要注意被删到一个节点的情况，防止tail成为野指针
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;//更新新的head
	}
}
//4、取出队头接口函数
QueueDataType Queue_Front(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}
//5、取出队尾接口函数
void Queue_Back(Queue* pq)
{
	//这个可以不写……
	;
}
//6、计算队列大小接口函数
int Queue_Size(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	int size = 0;

	QueueNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
//7、判断队列是否为空
Queue* Queue_Empty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}