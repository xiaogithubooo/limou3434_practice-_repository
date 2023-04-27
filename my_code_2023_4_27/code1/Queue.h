#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//> 队列的实现
//> 1.链式结构：表示队列的一个元素
typedef int QDataType;
typedef struct QListNode
{
    struct QListNode* _pNext;
    QDataType _data;
}QNode;
//> 2.队列的结构 
typedef struct Queue
{
    QNode* _front;  //队头
    QNode* _rear;   //队尾
}Queue;
//> 3.初始化队列 
void QueueInit(Queue* q);
//> 4.队尾入队列 
void QueuePush(Queue* q, QDataType data);
//> 5.队头出队列 
void QueuePop(Queue* q);
//> 6.获取队列头部元素 
QDataType QueueFront(Queue* q);
//> 7.获取队列队尾元素 
QDataType QueueBack(Queue* q);
//> 8.获取队列中有效元素个数 
int QueueSize(Queue* q);
//> 9.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
//> 10.销毁队列 
void QueueDestroy(Queue* q);