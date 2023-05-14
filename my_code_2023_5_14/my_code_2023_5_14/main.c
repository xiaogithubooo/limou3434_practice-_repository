#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//# ��Ŀһ
//һ.���е���ؽӿ�
//> 1.��ʽ�ṹ����ʾ���е�һ��Ԫ��
typedef int QDataType;
typedef struct QListNode
{
    struct QListNode* _pNext;
    QDataType _data;
}QNode;
//> 2.���еĽṹ 
typedef struct Queue
{
    QNode* _front;//��ͷ
    QNode* _rear;//��β
}Queue;
//> 3.��ʼ������ 
void QueueInit(Queue* q);
//> 4.��β����� 
void QueuePush(Queue* q, QDataType data);
//> 5.��ͷ������ 
void QueuePop(Queue* q);
//> 6.��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
//> 7.��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
//> 8.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
//> 9.���ٶ��� 
void QueueDestroy(Queue* q);

//��.����Ľⷨ
//1.����һ��MyStack�ṹ�壬�ڲ��洢ָ���������е�ָ��
typedef struct MyStack
{
    Queue* q1;//����һ
    Queue* q2;//���ж�
}MyStack;

//2.����һ��MyStack���Ҷ��ڲ�����������ָ����г�ʼ��
MyStack* myStackCreate()
{
    //1.����ռ����ģ���ջʹ��
    MyStack* cache = (MyStack*)malloc(sizeof(MyStack));
    if (!cache)
        exit(-1);//����Ƿ�����ɹ�
    //2.����ռ��ģ��ջ�ڲ��Ķ��С���ʼ��ģ��ջ�ڲ��Ķ���
    cache->q1 = (Queue*)malloc(sizeof(Queue));
    if (!cache->q1)
        exit(-1);//����Ƿ�����ɹ�
    cache->q2 = (Queue*)malloc(sizeof(Queue));
    if (!cache->q2)
        exit(-1);//����Ƿ�����ɹ�
    QueueInit(cache->q1);//��ʼ������q1
    QueueInit(cache->q2);//��ʼ������q2
    return cache;
    /*��Ҫע���������malloc������������ٵ�ʱ�����Ҫfree����*/
}

//3.ģ��ѹջ
void myStackPush(MyStack* obj, int x)
{
    //1.�����з��ࣺ��Ϊ��������ݵ�q_data�Ͳ�������ݵ�q_null��
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//����Ϊ�վͷ���1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.�����������뵽���q_data�Ķ�β�����൱�ڡ���MyStackѹջ��
    QueuePush(q_data, x);
}

//3.ɾ��ջ��Ԫ��
int myStackPop(MyStack* obj)
{
    //1.�����з��ࣺ��Ϊ��������ݵ�q_data�Ͳ�������ݵ�q_null��
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//����Ϊ�վͷ���1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.ת�����ݵ�q_null
    while (QueueSize(q_data) != 1)
    {
        //2.1.����q_data�Ķ�ͷԪ���Ƶ�q_null�Ķ�β
        QueuePush(q_null, QueueFront(q_data));
        //2.2.ɾ��q_dat�Ķ�ͷԪ��
        QueuePop(q_data);
    }
    //3.����ջ��Ԫ�أ����ҽ�q_data�����е�һ��Ԫ��ɾ��
    int val = q_data->_rear->_data;
    QueuePop(q_data);
    return val;
}

//4.ȡջ��Ԫ��
int myStackTop(MyStack* obj)
{
    //1.�����з��ࣺ��Ϊ��������ݵ�q_data�Ͳ�������ݵ�q_null��
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//����Ϊ�վͷ���1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.�����ҵĶ��а�����βָ�룬��˿���ֱ���ҵ�Ȼ�󷵻�
    return q_data->_rear->_data;
}

//5.���ջ�Ƿ�Ϊ�գ�ջ�շ���true
bool myStackEmpty(MyStack* obj)
{
    if (QueueEmpty(obj->q1) && QueueEmpty(obj->q2))//���ж�Ϊ�վͶ�����1
    {
        return true;
    }
    else
    {
        return false;
    }
}

//6.����ջ��ע��malloc�˶��ٴξ�Ҫ���ٶ��ٴΣ�
void myStackFree(MyStack* obj)
{
    QueueDestroy(obj->q1);
    QueueDestroy(obj->q2);
    free(obj);
}

//��.C������ջ�ľ���ʵ��
//!> ���е�ʵ��
//!> 1.����ṹ������ͷ��
//!typedef int QDataType;
//!typedef struct QListNode
//!{
//!    struct QListNode* _pNext;
//!    QDataType _data;
//!}QNode;
//!> 2.���нṹ 
//!typedef struct Queue
//!{
//!    QNode* _front;  //��Ƕ�ͷ
//!    QNode* _rear;   //��Ƕ�β
//!}Queue;
//> 3.��ʼ������ 
void QueueInit(Queue* q)
{
    //1.���ָ�����Ч��
    assert(q);
    //2.��ʼ�����У���β��ͷ����Ϊ�գ�
    q->_front = NULL;
    q->_rear = NULL;
}
//> 4.��β����У�����β�壩
void QueuePush(Queue* q, QDataType data)
{
    //1.���ָ�����Ч��
    assert(q);
    //2.������һ������ڵ㲢�Ҵ洢������
    QNode* cache = (QNode*)malloc(sizeof(QNode));
    if (!cache)
    {
        perror("malloc fail\n");
        exit(-1);
    }
    cache->_data = data;
    cache->_pNext = NULL;
    //3.��ʼβ��
    if (q->_rear == NULL)//�������Ϊ��
    {
        q->_front = q->_rear = cache;
    }
    else
    {
        q->_rear->_pNext = cache;
        q->_rear = cache;//�ı���еĶ�β��ǣ��γ��µĶ�β
    }
}
//> 5.��ͷ�����У�����ͷɾ��
void QueuePop(Queue* q)
{
    //1.���ָ����Ч��
    assert(q);
    assert(q->_front);
    //2.��ʼ������
    //2.1.�������������ֻʣһ���ڵ㣩
    if (q->_front == q->_rear)
    {
        free(q->_front);
        q->_front = q->_rear = NULL;
        return;
    }
    //2.2.����һ�����
    QNode* delNode = q->_front;
    q->_front = q->_front->_pNext;
    free(delNode);
}
//> 6.��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
    //1.���ָ�����Ч��
    assert(q);
    assert(q->_front);
    //2.���ض�ͷ��ֵ
    return q->_front->_data;
}
//> 7.��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
    //1.���ָ�����Ч��
    assert(q);
    //2.ѭ��������������ЧԪ�ظ���
    int size = 0;
    QNode* cur = q->_front;
    while (cur)
    {
        size++;
        cur = cur->_pNext;
    }
    return size;
}
//> 8.�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
    //1.���ָ�����Ч��
    assert(q);
    //2.�������Ƿ�Ϊ��
    return q->_front == NULL;
}
//> 9.���ٶ��� 
void QueueDestroy(Queue* q)
{
    //1.���ָ�����Ч��
    assert(q);
    //2.��ʼ����
    QNode* cur = q->_front;
    while (cur)
    {
        QNode* next = cur->_pNext;
        free(cur);
        cur = next;
    }
    q->_front = q->_rear = NULL;
}

int main()
{
    MyStack* MS = myStackCreate();//����һ��MyStack���ҳ�ʼ��
    myStackPush(MS, 1);//ѹջ
    myStackPush(MS, 2);//ѹջ
    myStackPush(MS, 3);//ѹջ
    myStackPush(MS, 4);//ѹջ
    myStackPush(MS, 5);//ѹջ
    while (!myStackEmpty(MS))//���ջ�Ƿ�Ϊ�գ�ջ�շ���true
    {
        printf("%d ", myStackTop(MS));//ȡջ��Ԫ��
        myStackPop(MS);//ɾ��ջ��
    }
    return 0;
}

void test_1()
{
    MyStack* MS = myStackCreate();//����һ��MyStack���ҳ�ʼ��
    myStackPush(MS, 1);//ѹջ
    myStackPush(MS, 2);//ѹջ
    myStackPush(MS, 3);//ѹջ
    myStackPush(MS, 4);//ѹջ
    myStackPush(MS, 5);//ѹջ
    while (!myStackEmpty(MS))//���ջ�Ƿ�Ϊ�գ�ջ�շ���true
    {
        printf("%d ", myStackTop(MS));//ȡջ��Ԫ��
        myStackPop(MS);//ɾ��ջ��
    }
}

//# ��Ŀ��
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
//1.��ģ����С��ṹ��
typedef struct MyQueue
{
    Stack* s1;
    Stack* s2;
}MyQueue;

//2.������ģ����С������ҳ�ʼ���󷵻�
MyQueue* myQueueCreate()
{
    //1.����ռ����ģ����С�
    MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
    if (!cache)//����Ƿ�����ɹ�
        exit(-1);
    //2.����ռ����ģ����С��ṹ��ĳ�Ա�����Ҹ��Գ�ʼ��
    cache->s1 = (Stack*)malloc(sizeof(Stack));
    if (!(cache->s1))
        exit(-1);
    cache->s2 = (Stack*)malloc(sizeof(Stack));
    if (!(cache->s2))
        exit(-1);
    StackInit(cache->s1);
    StackInit(cache->s2);
    return cache;
}

//3.�������Ƶ���β
void myQueuePush(MyQueue* obj, int x)
{
    //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//ջΪ�վͷ���1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.������s_data���൱�ڡ���Ԫ�ص�ģ����С�
    StackPush(s_data, x);
}

//4.��ͷԪ�س��ӣ����ҷ������Ԫ��
int myQueuePop(MyQueue* obj)
{
    //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//ջΪ�վͷ���1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.ת�Ƶ�ջs_null
    int num = StackSize(s_data);//����ջs_data�Ĵ�С
    while (num != 1)
    {
        StackPush(s_null, StackTop(s_data));//��s_data���Ԫ��ת�Ƶ�s_null��
        StackPop(s_data);
        num--;
    }
    //3.�洢s_dataջ��ʣ���Ԫ�أ�ɾ������Ԫ�أ�����s_null���Ԫ��˳��
    //3.1.��s_data��ʣ���Ԫ�ش洢����������ɾ�����Ԫ��
    int val = StackTop(s_data);
    StackPop(s_data);
    //3.2.����ע���ʱs_null������ݷ��ˣ���Ҫ�ٴηŻ�s_dataջ��
    while (!StackEmpty(s_null))
    {
        StackPush(s_data, StackTop(s_null));//��s_null���Ԫ��ת�ƻ�s_data��
        StackPop(s_null);
    }
    return val;
}

//5.���ض�ͷ
int myQueuePeek(MyQueue* obj)
{
    //1.���ṹ�����ջ���з��ࣺ��Ϊ��������ݵ�s_data�Ͳ�������ݵ�s_null��
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//ջΪ�վͷ���1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.ת�Ƶ�ջs_null
    int num = StackSize(s_data);//����ջs_data�Ĵ�С
    while (num != 1)
    {
        StackPush(s_null, StackTop(s_data));//��s_data���Ԫ��ת�Ƶ�s_null��
        StackPop(s_data);
        num--;
    }
    //3.�洢s_dataջ��ʣ���Ԫ�أ�����s_null���Ԫ��˳��
    //3.1.��s_data��ʣ���Ԫ�ش洢����
    int val = StackTop(s_data);
    //3.2.����ע���ʱs_null������ݷ��ˣ���Ҫ�ٴηŻ�s_dataջ��
    while (!StackEmpty(s_null))
    {
        StackPush(s_data, StackTop(s_null));//��s_null���Ԫ��ת�ƻ�s_data��
        StackPop(s_null);
    }
    return val;
}

//6.�жϡ�ģ����С��Ƿ�Ϊ�գ�Ϊ���򷵻�true
bool myQueueEmpty(MyQueue* obj)
{
    if (StackEmpty(obj->s1) && StackEmpty(obj->s2))//ջ��Ϊ�վͶ�����1
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
    //ע��Ҫfree����
    StackDestroy(obj->s1);
    StackDestroy(obj->s2);
    free(obj->s1);
    free(obj->s2);
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