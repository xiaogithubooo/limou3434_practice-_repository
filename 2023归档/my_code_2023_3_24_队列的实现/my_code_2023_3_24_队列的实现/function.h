#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//�ṩһ��ר��Ϊ���з��������
typedef int QueueDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataType data;
}QueueNode;
//���нṹ�壬ע��ͷ�ڵ�Ϊ��ͷ��ִ��ɾ������
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//1����ʼ�����нӿں���
void Queue_Init(Queue *pq);
//2���������ٽӿں���
void Queue_Destory(Queue *pq);
//3����β�루������ڵ㣩
void Queue_Push(Queue *pq , QueueDataType x);
//3����ͷ����ɾ����ڵ㣩
void Queue_Pop(Queue *pq);
//4��ȡ����ͷ�ӿں���
QueueDataType Queue_Front(Queue *pq);
//5��ȡ����β�ӿں���
void Queue_Back(Queue *pq);
//6��������д�С�ӿں���
int Queue_Size(Queue *pq);
//7���ж϶����Ƿ�Ϊ��
Queue* Queue_Empty(Queue *pq);
