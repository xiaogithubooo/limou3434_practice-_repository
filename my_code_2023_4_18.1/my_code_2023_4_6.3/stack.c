#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
void Stack_Init(Stack* ps)
{
	assert(ps);

	ps->a = (StackDataType*)malloc(sizeof(StackDataType) * 4);//初始化就给予4个空间大小
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;//标识栈有4个元素
	ps->top = 0;//可以选择初始化-1
}
void Stack_Destory(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;

	ps->top = 0;
	ps->capacity = 0;
}
void Stack_Push(Stack* ps, StackDataType x)
{
	assert(ps);

	if (ps->capacity == ps->top)//如果栈空间不够用了
	{
		StackDataType* tmp = realloc(ps->a, ps->capacity * 2 * sizeof(StackDataType));//申请空间节点
		if (tmp == NULL)//申请失败
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else//申请成功
		{
			ps->a = tmp;//赋予新生成的空间地址，因为realloc有可能改变原来的地址
			ps->capacity *= 2;//更新栈的容量
		}
	}
	//存入数据
	ps->a[ps->top] = x;
	ps->top++;
}
void Stack_Pop(Stack* ps)
{
	assert(ps);

	assert(ps->top > 0);//栈空了就终止程序
	ps->top--;//直接减一，反正后面Top函数也要靠再次减一得到下标取到元素
}
StackDataType Stack_Top(Stack* ps)
{
	assert(ps);

	assert(ps->top > 0);//栈空了就终止程序
	return ps->a[ps->top - 1];

}
int Stack_Size(Stack* ps)
{
	assert(ps);

	return ps->top;
}
bool Stack_Empty(Stack* ps)
{
	assert(ps);

	return (ps->top == 0);
}