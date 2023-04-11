#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//1.ջ�ṹ��
typedef int StackDataType;
typedef struct Stack
{
    StackDataType* a;//�������д��������Ǿ�̬ջ
    int top;//�궨ջ��
    int capacity;//�궨ջ����
}Stack;

//2.��ʼ��ջ�ӿں���
void Stack_Init(Stack* ps);

//3.����ջ�ӿں���
void Stack_Destory(Stack* ps);

//4.��ջ�ӿں���
void Stack_Push(Stack* ps, StackDataType x);

//5.��ջ�ӿں���
void Stack_Pop(Stack* ps);

//6.ȡ��ջ��Ԫ�ؽӿں���
StackDataType Stack_Top(Stack* ps);

//7.��ǰջ��Ԫ�ظ����ӿں�����������������
int Stack_Size(Stack* ps);

//8.�ж�ջ�Ƿ�Ϊ�սӿں���
bool Stack_Empty(Stack* ps);