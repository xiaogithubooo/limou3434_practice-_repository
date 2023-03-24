#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//1����ʼ�����нӿں���
void Queue_Init(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//2���������ٽӿں���
void Queue_Destory(Queue* pq)
{
	assert(pq);
	//assert(pq->head);��������ǲ��õģ�����
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
//3����β�루������ڵ㣩
void Queue_Push(Queue* pq, QueueDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	//��ʼ��һ�����������Ľڵ�
	newnode->data = x;
	newnode->next = NULL;

	//�����½ڵ�
	if (pq->tail == NULL)//�������û�нڵ�
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;//����tail
	}
}
//3����ͷ����ɾ����ڵ㣩
void Queue_Pop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	//Ҫע�ⱻɾ��һ���ڵ���������ֹtail��ΪҰָ��
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;//�����µ�head
	}
}
//4��ȡ����ͷ�ӿں���
QueueDataType Queue_Front(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}
//5��ȡ����β�ӿں���
void Queue_Back(Queue* pq)
{
	//������Բ�д����
	;
}
//6��������д�С�ӿں���
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
//7���ж϶����Ƿ�Ϊ��
Queue* Queue_Empty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}