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

////1.ѭ��������Ҫ�Ľṹ��
//typedef struct MyCircularQueue
//{
//	int* arr;//��̬����
//	int front;//��ͷ
//	int rear;//��β
//	int k;//���������ݵĴ�С
//}MyCircularQueue;
////1.�����������ö��г���Ϊk
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	//1.1.�ȴ���һ��ռ��ѭ�����нṹ��ʹ��
//	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	if (!obj) exit(-1);
//	//1.2.�����ṹ���ڵĶ�̬����
//	obj->arr = (int*)malloc(sizeof(int) * (k + 1));
//	if (!(obj->arr)) exit(-1);
//	//1.3.���ô�ʱ�ṹ���ڵĳ�Ա����ͷ�������͡���β��������Ϊ0
//	obj->front = obj->rear = 0;
//	//1.4.�����е����洢����k�洢���ṹ��
//	obj->k = k;
//	//1.5.����ָ��ṹ���ָ��
//	return obj;
//}
////2.���ѭ�������Ƿ�����
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	//2.1.ֻҪ
//	return (obj->front) == (obj->rear + 1) % (obj->k + 1);
//}
////3.���ѭ�������Ƿ�Ϊ��
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	return obj->front == obj->rear;
//}
////��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻���
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
////��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻���
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
////�Ӷ��׻�ȡԪ�ء��������Ϊ�գ�����-1
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	return (obj->arr[obj->front]);
//}
////��ȡ��βԪ�ء��������Ϊ�գ�����-1 
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//	{
//		return -1;
//	}
//	//(rear-1+k+1)%(k+1)������Ǵ�ͷ��ǰ��֮ǰд�ľ��Ǵ�β���
//	return obj->arr[(obj->rear + obj->k) % (obj->k + 1)];
//}
////����ѭ������
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->arr);
//	free(obj);
//}