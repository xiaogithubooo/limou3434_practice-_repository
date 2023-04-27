#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//> ջ��ʵ��
//> 1.֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
    STDataType* _a;
    int _top;       // ջ��
    int _capacity;  // ���� 
}Stack;
//> 2.��ʼ��ջ 
void StackInit(Stack* ps);
//> 3.��ջ 
void StackPush(Stack* ps, STDataType data);
//> 4.��ջ 
void StackPop(Stack* ps);
//> 5.��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
//> 6.��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
//> 7.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط��㣬�����Ϊ�շ���0 
int StackEmpty(Stack* ps);
//> 8.����ջ 
void StackDestroy(Stack* ps);