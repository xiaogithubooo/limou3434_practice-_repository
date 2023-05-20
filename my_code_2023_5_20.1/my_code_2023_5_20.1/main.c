#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = Add(a, b);
	printf("%d\n", c);
	return 0; 
}

////1.循环链表需要的结构体
//typedef struct MyCircularQueue
//{
//	int* arr;//动态数组
//	int front;//队头
//	int rear;//队尾
//	int k;//最大存入数据的大小
//}MyCircularQueue;
////1.构造器，设置队列长度为k
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	//1.1.先创建一块空间给循环队列结构体使用
//	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	if (!obj) exit(-1);
//	//1.2.创建结构体内的动态数组
//	obj->arr = (int*)malloc(sizeof(int) * (k + 1));
//	if (!(obj->arr)) exit(-1);
//	//1.3.设置此时结构体内的成员“队头索引”和“队尾索引”均为0
//	obj->front = obj->rear = 0;
//	//1.4.将队列的最大存储数量k存储进结构体
//	obj->k = k;
//	//1.5.返回指向结构体的指针
//	return obj;
//}
////2.检查循环队列是否已满
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	//2.1.只要
//	return (obj->front) == (obj->rear + 1) % (obj->k + 1);
//}
////3.检查循环队列是否为空
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	return obj->front == obj->rear;
//}
////向循环队列插入一个元素。如果成功插入则返回真
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	if (myCircularQueueIsFull(obj))
//	{
//		return false;
//	}
//	else
//	{
//		obj->arr[obj->rear] = value;
//		obj->rear++;
//		obj->rear %= (obj->k + 1);
//		return true;
//	}
//}
////从循环队列中删除一个元素。如果成功删除则返回真
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return false;
//	}
//	obj->front++;
//	obj->front %= (obj->k + 1);
//	return true;
//}
////从队首获取元素。如果队列为空，返回-1
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	return (obj->arr[obj->front]);
//}
////获取队尾元素。如果队列为空，返回-1 
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	//(rear-1+k+1)%(k+1)这个就是从头向前，之前写的就是从尾向后
//	return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
//}
////销毁循环队列
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->arr);
//	free(obj);
//}