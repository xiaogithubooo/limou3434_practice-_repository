#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct MyCircularQueue
{
	int* arr;
	int Front;//��ͷ
	int rear;//��β
	int k;
}MyCircularQueue;
//1.�����������ö��г���Ϊk
MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (!obj) exit(-1);

	obj->arr = (int*)malloc(sizeof(int) * (k + 1));
	if (!(obj->arr)) exit(-1);

	obj->Front = obj->rear = 0;

	obj->k = k;

	return obj;
}
//���ѭ�������Ƿ�����
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
	return (obj->Front) == (obj->rear + 1) % (obj->k + 1);
}
//���ѭ�������Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->Front == obj->rear;
}
//��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻���
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->arr[obj->rear] = value;
		obj->rear++;
		obj->rear %= (obj->k + 1);
		return true;
	}
}
//��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻���
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->Front++;
	obj->Front %= (obj->k + 1);
	return true;
}
//�Ӷ��׻�ȡԪ�ء��������Ϊ�գ�����-1
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return (obj->arr[obj->Front]);
}
//��ȡ��βԪ�ء��������Ϊ�գ�����-1 
int myCircularQueueRear(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	//(rear-1+k+1)%(k+1)������Ǵ�ͷ��ǰ��֮ǰд�ľ��Ǵ�β���
	return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
}
//����ѭ������
void myCircularQueueFree(MyCircularQueue* obj) 
{
	free(obj->arr);
	free(obj);
}
int main()
{
	MyCircularQueue* obj = myCircularQueueCreate(8);
	return 0;
}