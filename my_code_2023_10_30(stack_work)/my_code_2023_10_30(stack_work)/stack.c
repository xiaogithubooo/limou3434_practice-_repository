#include "stack.h"

//> 1.支持动态增长的栈
/*
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		//栈顶
//	int _capacity;	//容量 
//}Stack;
*/

//> 2.初始化栈
void StackInit(Stack* ps)
{
	//1.检查指针有效性
	assert(ps);

	//2.初始化栈的信息
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);//先给上4个空间，并且检查是否申请成功
	if (!ps->_a)
	{
		perror("malloc fail!\n");
		return;
	}
	ps->_top = 0;//这个赋值也可以是-1
	ps->_capacity = 4;
}

//> 3.入栈 
void StackPush(Stack* ps, STDataType data)
{
	//1.检查指针有效性
	assert(ps);
	//2.检查栈容量是否满了
	if (ps->_capacity == ps->_top)
	{
		STDataType* cache = (STDataType*)realloc(ps->_a, sizeof(STDataType) * ((ps->_capacity) * 2));
		if (!cache)
		{
			printf("realloc fail!\n");
			exit(-1);
		}
		ps->_a = cache;
		ps->_capacity = ps->_capacity * 2;
	}
	//3.入栈并且更新栈的数据
	ps->_a[ps->_top] = data;
	ps->_top++;
}

//> 4.出栈 
void StackPop(Stack* ps)
{
	//1.检查指针有效性
	assert(ps);
	//2.检查栈是否有元素
	assert(ps->_top > 0);
	//3.直接利用下标“删除”元素，注意栈内存储元素的“实际下标”比“_top”的数值小1
	ps->_top--;
}

//> 5.获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	//1.检查指针的有效性
	assert(ps);
	//2.检查栈是否还有元素
	assert(ps->_top > 0);
	//3.取出栈顶元素
	return ps->_a[ps->_top - 1];
}

//> 6.获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	//1.检查指针的有效性
	assert(ps);
	//2.获取元素个数
	return ps->_top;
}

//> 7.检测栈是否为空，如果为空返回非零，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return (ps->_top == 0);
}

//> 8.销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}