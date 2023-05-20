#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct MyCircularQueue
{
	int* arr;
	int Front;//队头
	int rear;//队尾
	int k;
}MyCircularQueue;
//1.构造器，设置队列长度为k
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
//检查循环队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
	return (obj->Front) == (obj->rear + 1) % (obj->k + 1);
}
//检查循环队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->Front == obj->rear;
}
//向循环队列插入一个元素。如果成功插入则返回真
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
//从循环队列中删除一个元素。如果成功删除则返回真
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
//从队首获取元素。如果队列为空，返回-1
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return (obj->arr[obj->Front]);
}
//获取队尾元素。如果队列为空，返回-1 
int myCircularQueueRear(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	//(rear-1+k+1)%(k+1)这个就是从头向前，之前写的就是从尾向后
	return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
}
//销毁循环队列
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