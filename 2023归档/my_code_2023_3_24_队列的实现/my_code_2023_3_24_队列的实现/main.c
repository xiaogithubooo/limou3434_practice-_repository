#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
void test1()
{
	Queue q;
	Queue_Init(&q);
	Queue_Push(&q, 1);//入队
	Queue_Push(&q, 2);//入队
	Queue_Pop(&q);//出队
	Queue_Push(&q, 3);//入队
	Queue_Pop(&q);//出队
	Queue_Push(&q, 4);//入队
	Queue_Push(&q, 5);//入队
	while (!Queue_Empty(&q))
	{
		printf("%d ", Queue_Front(&q));
		Queue_Pop(&q);//出队
	}
	Queue_Destory(&q);
}
int main()
{
	test1();
	return 0;
}