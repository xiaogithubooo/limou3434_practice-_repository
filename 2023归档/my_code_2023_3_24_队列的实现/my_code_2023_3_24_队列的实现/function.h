#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//提供一个专门为队列服务的链表
typedef int QueueDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;
//队列结构体，注意头节点为队头，执行删除操作
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//1、初始化队列接口函数
void Queue_Init(Queue *pq);
//2、队列销毁接口函数
void Queue_Destory(Queue *pq);
//3、队尾入（加链表节点）
void Queue_Push(Queue *pq , QueueDataType x);
//3、队头出（删链表节点）
void Queue_Pop(Queue *pq);
//4、取出队头接口函数
QueueDataType Queue_Front(Queue *pq);
//5、取出队尾接口函数
void Queue_Back(Queue *pq);
//6、计算队列大小接口函数
int Queue_Size(Queue *pq);
//7、判断队列是否为空
Queue* Queue_Empty(Queue *pq);
