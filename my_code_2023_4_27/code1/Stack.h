#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//> 栈的实现
//> 1.支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
    STDataType* _a;
    int _top;       // 栈顶
    int _capacity;  // 容量 
}Stack;
//> 2.初始化栈 
void StackInit(Stack* ps);
//> 3.入栈 
void StackPush(Stack* ps, STDataType data);
//> 4.出栈 
void StackPop(Stack* ps);
//> 5.获取栈顶元素 
STDataType StackTop(Stack* ps);
//> 6.获取栈中有效元素个数 
int StackSize(Stack* ps);
//> 7.检测栈是否为空，如果为空返回非零，如果不为空返回0 
int StackEmpty(Stack* ps);
//> 8.销毁栈 
void StackDestroy(Stack* ps);