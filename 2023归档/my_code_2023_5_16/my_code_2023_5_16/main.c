#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//һ.ջ����ؽӿ�
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

//��.����ⷨ
//�ⷨһ
// //1.��ģ����С��ṹ��
// typedef struct MyQueue
// {
//     Stack* s1;
//     Stack* s2;
// }MyQueue;

// //2.������ģ����С������ҳ�ʼ���󷵻�
// MyQueue* myQueueCreate() 
// {
//     //1.����ռ����ģ����С�
//     MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
//     if(!cache)//����Ƿ�����ɹ�
//         exit(-1);
//     //2.����ռ����ģ����С��ṹ��ĳ�Ա�����Ҹ��Գ�ʼ��
//     cache->s1 = (Stack*)malloc(sizeof(Stack));
//     if(!(cache->s1))
//         exit(-1);
//     cache->s2 = (Stack*)malloc(sizeof(Stack));
//     if(!(cache->s2))
//         exit(-1);
//     StackInit(cache->s1);
//     StackInit(cache->s2);
//     return cache;
// }

// //3.�������Ƶ���β
// void myQueuePush(MyQueue* obj, int x) 
// {
//     //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//ջΪ�վͷ���1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.������s_data���൱�ڡ���Ԫ�ص�ģ����С�
//     StackPush(s_data, x);
// }

// //4.��ͷԪ�س��ӣ����ҷ������Ԫ��
// int myQueuePop(MyQueue* obj) 
// {
//     //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//ջΪ�վͷ���1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.ת�Ƶ�ջs_null
//     int num = StackSize(s_data);//����ջs_data�Ĵ�С
//     while(num != 1)
//     {
//         StackPush(s_null, StackTop(s_data));//��s_data���Ԫ��ת�Ƶ�s_null��
//         StackPop(s_data);
//         num--;
//     }
//     //3.�洢s_dataջ��ʣ���Ԫ�أ�ɾ������Ԫ�أ�����s_null���Ԫ��˳��
//     //3.1.��s_data��ʣ���Ԫ�ش洢����������ɾ�����Ԫ��
//     int val = StackTop(s_data);
//     StackPop(s_data);
//     //3.2.����ע���ʱs_null������ݷ��ˣ���Ҫ�ٴηŻ�s_dataջ��
//     while(!StackEmpty(s_null))
//     {
//         StackPush(s_data, StackTop(s_null));//��s_null���Ԫ��ת�ƻ�s_data��
//         StackPop(s_null);
//     }
//     return val;
// }

// //5.���ض�ͷ
// int myQueuePeek(MyQueue* obj) 
// {
//     //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//ջΪ�վͷ���1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.ת�Ƶ�ջs_null
//     int num = StackSize(s_data);//����ջs_data�Ĵ�С
//     while(num != 1)
//     {
//         StackPush(s_null, StackTop(s_data));//��s_data���Ԫ��ת�Ƶ�s_null��
//         StackPop(s_data);
//         num--;
//     }
//     //3.�洢s_dataջ��ʣ���Ԫ�أ�����s_null���Ԫ��˳��
//     //3.1.��s_data��ʣ���Ԫ�ش洢����
//     int val = StackTop(s_data);
//     //3.2.����ע���ʱs_null������ݷ��ˣ���Ҫ�ٴηŻ�s_dataջ��
//     while(!StackEmpty(s_null))
//     {
//         StackPush(s_data, StackTop(s_null));//��s_null���Ԫ��ת�ƻ�s_data��
//         StackPop(s_null);
//     }
//     return val;
// }

// //6.�жϡ�ģ����С��Ƿ�Ϊ�գ�Ϊ���򷵻�true
// bool myQueueEmpty(MyQueue* obj)
// {
//     if (StackEmpty(obj->s1) && StackEmpty(obj->s2))//ջ��Ϊ�վͶ�����1
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }   

// //7.���١�ģ����С�
// void myQueueFree(MyQueue* obj) 
// {
//     //ע��Ҫfree����
//     StackDestroy(obj->s1);
//     StackDestroy(obj->s2);
//     free(obj->s1);
//     free(obj->s2);
//     free(obj);
// }
//�ⷨ��
//1.��ģ����С��ṹ��
typedef struct MyQueue
{
    Stack s1;
    Stack s2;
}MyQueue;

//2.������ģ����С������ҳ�ʼ���󷵻�
MyQueue* myQueueCreate()
{
    //1.����ռ����ģ����С�
    MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
    if (!cache)//����Ƿ�����ɹ�
        exit(-1);
    //2.����ģ����С��Ľṹ���Ա���Խ��г�ʼ��
    StackInit(&(cache->s1));
    StackInit(&(cache->s2));
    return cache;
}

//3.�������Ƶ���β
void myQueuePush(MyQueue* obj, int x)
{
    //һֱ������ѹջѹ��s1
    StackPush(&(obj->s1), x);
}

//4.��ͷԪ�س��ӣ����ҷ������Ԫ��
int myQueuePop(MyQueue* obj)
{
    if (StackEmpty(&(obj->s2)) == 1)//�ж�ջs2�Ƿ�ǿգ����򷵻ط��㣬
    {
        while (StackSize(&(obj->s1)) != 1)//ֻҪs1����Ԫ�ؾͳ���ת�Ƶ�s2��
        {
            StackPush(&(obj->s2), StackTop(&(obj->s1)));
            StackPop(&(obj->s1));
        }
        int val = StackTop(&(obj->s1));
        StackPop(&(obj->s1));
        return val;
    }
    else
    {
        int val = StackTop(&(obj->s2));
        StackPop(&(obj->s2));
        return val;
    }
}

//5.���ض�ͷ
int myQueuePeek(MyQueue* obj)
{
    if (StackEmpty(&(obj->s2)) == 1)//�ж�ջs2�Ƿ�ǿգ����򷵻ط��㣬
    {
        while (StackSize(&(obj->s1)) != 1)//ֻҪs1����Ԫ�ؾͳ���ת�Ƶ�s2��
        {
            StackPush(&(obj->s2), StackTop(&(obj->s1)));
            StackPop(&(obj->s1));
        }
        int val = StackTop(&(obj->s1));
        StackPush(&(obj->s2), val);
        StackPop(&(obj->s1));
        return val;
    }
    else
    {
        int val = StackTop(&(obj->s2));
        return val;
    }
}

//6.�жϡ�ģ����С��Ƿ�Ϊ�գ�Ϊ���򷵻�true
bool myQueueEmpty(MyQueue* obj)
{
    if (StackEmpty(&(obj->s1)) && StackEmpty(&(obj->s2)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//7.���١�ģ����С�
void myQueueFree(MyQueue* obj)
{
    StackDestroy(&(obj->s1));
    StackDestroy(&(obj->s2));
    free(obj);
}

//��.ջ�ӿڵľ���ʵ��
//!> ջ��ʵ��
//!> 1.֧�ֶ�̬������ջ
//!typedef int STDataType;
//!typedef struct Stack
//!{
//!    STDataType* _a;
//!    int _top;       //ջ��
//!    int _capacity;  //���� 
//!}Stack;
//> 2.��ʼ��ջ 
void StackInit(Stack* ps)
{
    //1.���ָ����Ч��
    assert(ps);

    //2.��ʼ��ջ����Ϣ
    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);//�ȸ���4���ռ䣬���Ҽ���Ƿ�����ɹ�
    if (!ps->_a)
    {
        perror("malloc fail!\n");
        return;
    }
    ps->_top = 0;//�����ֵҲ������-1
    ps->_capacity = 4;
}
//> 3.��ջ 
void StackPush(Stack* ps, STDataType data)
{
    //1.���ָ����Ч��
    assert(ps);
    //2.���ջ�����Ƿ�����
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
    //3.��ջ���Ҹ���ջ������
    ps->_a[ps->_top] = data;
    ps->_top++;
}
//> 4.��ջ 
void StackPop(Stack* ps)
{
    //1.���ָ����Ч��
    assert(ps);
    //2.���ջ�Ƿ���Ԫ��
    assert(ps->_top > 0);
    //3.ֱ�������±ꡰɾ����Ԫ�أ�ע��ջ�ڴ洢Ԫ�صġ�ʵ���±ꡱ�ȡ�_top������ֵС1
    ps->_top--;
}
//> 5.��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
    //1.���ָ�����Ч��
    assert(ps);
    //2.���ջ�Ƿ���Ԫ��
    assert(ps->_top > 0);
    //3.ȡ��ջ��Ԫ��
    return ps->_a[ps->_top - 1];
}
//> 6.��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
    //1.���ָ�����Ч��
    assert(ps);
    //2.��ȡԪ�ظ���
    return ps->_top;
}
//> 7.���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط��㣬�����Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
    assert(ps);
    return (ps->_top == 0);
}
//> 8.����ջ 
void StackDestroy(Stack* ps)
{
    assert(ps);
    free(ps->_a);
    ps->_a = NULL;
    ps->_capacity = ps->_top = 0;
}