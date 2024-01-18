#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//> ���е�ʵ��
//> 1.��ʽ�ṹ����ʾ���е�һ��Ԫ��
typedef int QDataType;
typedef struct QListNode
{
    struct QListNode* _pNext;
    QDataType _data;
}QNode;
//> 2.���еĽṹ 
typedef struct Queue
{
    QNode* _front;  //��ͷ
    QNode* _rear;   //��β
}Queue;
//> 3.��ʼ������ 
void QueueInit(Queue* q);
//> 4.��β����� 
void QueuePush(Queue* q, QDataType data);
//> 5.��ͷ������ 
void QueuePop(Queue* q);
//> 6.��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
//> 7.��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
//> 8.��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
//> 9.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
//> 10.���ٶ��� 
void QueueDestroy(Queue* q);