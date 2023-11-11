#include "queue.h"

//> ���е�ʵ��
//> 1.��ʽ�ṹ����ʾ���е�һ��Ԫ��
//typedef int QDataType;
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}QNode;

//> 2.���еĽṹ 
//typedef struct Queue
//{
//	QNode* _front;	//��ͷ
//	QNode* _rear;	//��β
//}Queue;

//> 3.��ʼ������ 
void QueueInit(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.��ʼ�����У���β��ͷ����Ϊ�գ�
	q->_front = q->_rear = NULL;
}

//> 4.��β����У�����β�壩
void QueuePush(Queue* q, QDataType data)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.������һ������ڵ㲢�Ҵ洢������
	QNode* cache = (QNode*)malloc(sizeof(QNode));
	if (!cache)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	cache->_data = data;
	cache->_pNext = NULL;
	//3.��ʼβ��
	if (q->_rear == NULL)//�������Ϊ��
	{
		q->_front = q->_rear = cache;
	}
	else
	{
		q->_rear->_pNext = cache;
		q->_rear = cache;//�ı���еĶ�β��ǣ��γ��µĶ�β
	}
	//�����ҵĶ��нṹ��û��дsize��Ա����������û�н���size++��������˵Ҫ��������������Ա��Ч�������

}

//> 5.��ͷ�����У�����ͷɾ��
void QueuePop(Queue* q)
{
	//1.���ָ����Ч��
	assert(q);
	assert(q->_front);//�������д���пգ��ڶ��Ե�ʱ�����
	//2.��ʼ������
	//2.1.�������������ֻʣһ���ڵ㣩
	if (q->_front == q->_rear)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
		return;
	}
	//2.2.����һ�����
	QNode* delNode = q->_front;
	q->_front = q->_front->_pNext;
	free(delNode);
	//�����ҵĶ��нṹ��û��дsize��Ա����������û�н���size--��������˵Ҫ��������������Ա��Ч�������
}

//> 6.��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	assert(q->_front);
	//2.���ض�ͷ��ֵ
	return q->_front->_data;
}

//> 7.��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	;//������û��д����Ϊ���ڴ��Ķ�����˵���ò�����������������е�ʱ����ȷʵ��Ҫ����������Ժ���˵
}

//> 8.��ȡ��������ЧԪ�ظ���������Ҳ�����ö��нṹ����һ��size��Ա�� 
int QueueSize(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.ѭ��������������ЧԪ�ظ���
	int size = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		size++;
		cur = cur->_pNext;
	}
	return size;
	//�����ҵĶ��нṹ��û��дsize��Ա������������Ҫ������������˵Ҫ��������������Ա��Ч�������
}

//> 9.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.�������Ƿ�Ϊ��
	return q->_front == NULL;//Ҳ���Բ���size����
}

//> 10.���ٶ��� 
void QueueDestroy(Queue* q)
{
	//1.���ָ�����Ч��
	assert(q);
	//2.��ʼ����
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

//> 11.��ӡ����
void QueuePrint(Queue* q)
{
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		printf("%d ", cur->_data);
		cur = cur->_pNext;
	}
	printf("\n");
}