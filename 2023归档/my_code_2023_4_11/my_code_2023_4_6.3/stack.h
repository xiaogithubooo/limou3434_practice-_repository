#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//1.栈结构体
typedef int StackDataType;
typedef struct Stack
{
    StackDataType* a;//这里如果写成数组就是静态栈
    int top;//标定栈顶
    int capacity;//标定栈容量
}Stack;

//2.初始化栈接口函数
void Stack_Init(Stack* ps);

//3.销毁栈接口函数
void Stack_Destory(Stack* ps);

//4.入栈接口函数
void Stack_Push(Stack* ps, StackDataType x);

//5.出栈接口函数
void Stack_Pop(Stack* ps);

//6.取出栈顶元素接口函数
StackDataType Stack_Top(Stack* ps);

//7.求当前栈的元素个数接口函数（而不是容量）
int Stack_Size(Stack* ps);

//8.判断栈是否为空接口函数
bool Stack_Empty(Stack* ps);