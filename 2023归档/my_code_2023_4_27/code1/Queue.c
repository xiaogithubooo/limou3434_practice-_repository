#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
//!> 队列的实现
//!> 1.链表结构（不带头）
//!typedef int QDataType;
//!typedef struct QListNode
//!{
//!    struct QListNode* _pNext;
//!    QDataType _data;
//!}QNode;
//!> 2.队列结构 
//!typedef struct Queue
//!{
//!    QNode* _front;  //标记队头
//!    QNode* _rear;   //标记队尾
//!}Queue;
//> 3.初始化队列 
void QueueInit(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.初始化队列（队尾队头都置为空）
	q->_front = q->_rear = NULL;
}
//> 4.队尾入队列（链表尾插）
void QueuePush(Queue* q, QDataType data)
{
	//1.检查指针的有效性
	assert(q);
	//2.先申请一个链表节点并且存储好数据
	QNode* cache = (QNode*)malloc(sizeof(QNode));
	if (!cache)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	cache->_data = data;
	cache->_pNext = NULL;
	//3.开始尾插
	if (q->_rear == NULL)//如果队列为空
	{
		q->_front = q->_rear = cache;
	}
	else
	{
		q->_rear->_pNext = cache;
		q->_rear = cache;//改变队列的队尾标记，形成新的队尾
	}
}
//> 5.队头出队列（链表头删）
void QueuePop(Queue* q)
{
	//1.检查指针有效性
	assert(q);
	assert(q->_front);
	//2.开始出数据
	//2.1.处理特殊情况（只剩一个节点）
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
		return;
	}
	//2.2.处理一般情况
	QNode* delNode = q->_front;
	q->_front = q->_front->_pNext;
	free(delNode);
}
//> 6.获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	assert(q->_front);
	//2.返回队头的值
	return q->_front->_data;
}
//> 7.获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	;
}
//> 8.获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.循环计数，返回有效元素个数
	int size = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
}
//> 9.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.检测队列是否为空
	return q->_front == NULL;
}
//> 10.销毁队列 
void QueueDestroy(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.开始销毁
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}