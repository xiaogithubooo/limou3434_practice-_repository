#include "queue.h"

//> 队列的实现
//> 1.链式结构：表示队列的一个元素
//typedef int QDataType;
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}QNode;

//> 2.队列的结构 
//typedef struct Queue
//{
//	QNode* _front;	//队头
//	QNode* _rear;	//队尾
//}Queue;

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
	//由于我的队列结构体没有写size成员，所以这里没有进行size++，正常来说要队列最好有这个成员，效率能提高

}

//> 5.队头出队列（链表头删）
void QueuePop(Queue* q)
{
	//1.检查指针有效性
	assert(q);
	assert(q->_front);//这个建议写成判空，在断言的时候更好
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
	//由于我的队列结构体没有写size成员，所以这里没有进行size--，正常来说要队列最好有这个成员，效率能提高
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
	;//这里我没有写，因为对于存粹的队列来说还用不到这个函数，但是有的时候又确实需要这个函数，以后再说
}

//> 8.获取队列中有效元素个数（这里也可以让队列结构体多加一个size成员） 
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
	//由于我的队列结构体没有写size成员，所以这里需要遍历，正常来说要队列最好有这个成员，效率能提高
}

//> 9.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	//1.检查指针的有效性
	assert(q);
	//2.检测队列是否为空
	return q->_front == NULL;//也可以采用size处理
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

//> 11.打印队列
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