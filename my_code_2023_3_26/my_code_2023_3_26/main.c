#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//�ṩһ��ר��Ϊ���з��������
typedef int QueueDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
}QueueNode;
//���нṹ�壬ע��ͷ�ڵ�Ϊ��ͷ��ִ��ɾ������
typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;

//1����ʼ�����нӿں���
void Queue_Init(Queue* pq);
//2���������ٽӿں���
void Queue_Destory(Queue* pq);
//3����β�루������ڵ㣩
void Queue_Push(Queue* pq, QueueDataType x);
//3����ͷ����ɾ����ڵ㣩
void Queue_Pop(Queue* pq);
//4��ȡ����ͷ�ӿں���
QueueDataType Queue_Front(Queue* pq);
//5��ȡ����β�ӿں���
QueueDataType Queue_Back(Queue* pq);
//6��������д�С�ӿں���
int Queue_Size(Queue* pq);
//7���ж϶����Ƿ�Ϊ��
bool Queue_Empty(Queue* pq);
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
typedef struct {
    Queue q1;//����1
    Queue q2;//����2
} MyStack;

MyStack* myStackCreate()
{
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail!\n");
        exit(-1);
    }
    //��ʼ����������
    Queue_Init(&ps->q1);
    Queue_Init(&ps->q2);

    //���ش���������еĽṹ���ָ��
    return ps;
}

void myStackPush(MyStack* obj, int x)
{
    //������ʱ�����յĵĶ��������ݣ�������Ϊ��Ҳû��ϵ��
    if (Queue_Empty(&obj->q1))
    {
        Queue_Push(&obj->q1, x);
    }
    else
    {
        Queue_Push(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj)
{
    //ɾ����ʱ��������һ���յĶ��е������ݣ�ֱ��ֻʣ���һ�����ݣ�����ɾ������
    Queue* emptyQ = &obj->q1;//�����˸ö���Ϊ��
    Queue* nonemptyQ = &obj->q2;//�����˸ö��в�Ϊ��
    if (!Queue_Empty(&obj->q1))//����������ͻ�һ��
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }//��������������ע˭�ǿն�����
    while (Queue_Size(nonemptyQ) > 1)
    {
        Queue_Push(emptyQ, Queue_Front(nonemptyQ));
        Queue_Pop(nonemptyQ);
    }
    //���nonemptyQ������ֻʣһ��Ԫ�أ����ٽ��������emptyQ��ֱ��ɾ�����ɣ�����Ҫע�Ȿ����ɾ��ջ����ͬʱ��ҪҪ����ջ��ֵ������nonemptyQ��ʣ���һ��Ԫ�ؾ���
    int top = Queue_Front(nonemptyQ);
    Queue_Pop(nonemptyQ);
    return top;
}

int myStackTop(MyStack* obj)
{
    if (!Queue_Empty(&obj->q1))
    {
        return Queue_Back(&obj->q1);
    }
    else
    {
        return Queue_Back(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    return Queue_Empty(&obj->q1) && Queue_Empty(&obj->q2);//һ����Ϊ1��ͬʱ���򷵻�1
}

void myStackFree(MyStack* obj)
{
    Queue_Destory(&obj->q1);
    Queue_Destory(&obj->q2);

    //����Ҳ��Ҫ�ͷŵ�
    free(obj);
}
/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//1����ʼ�����нӿں���
void Queue_Init(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}
//2���������ٽӿں���
void Queue_Destory(Queue* pq)
{
    assert(pq);
    //assert(pq->head);��������ǲ��õģ�����
    QueueNode* cur = pq->head;
    while (cur)
    {
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
//3����β�루������ڵ㣩
void Queue_Push(Queue* pq, QueueDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    //��ʼ��һ�����������Ľڵ�
    newnode->data = x;
    newnode->next = NULL;

    //�����½ڵ�
    if (pq->head == NULL)//�������û�нڵ�
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;//����tail
    }
}
//3����ͷ����ɾ����ڵ㣩
void Queue_Pop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    //Ҫע�ⱻɾ��һ���ڵ���������ֹtail��ΪҰָ��
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QueueNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;//�����µ�head
    }
}
//4��ȡ����ͷ�ӿں���
QueueDataType Queue_Front(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}
//5��ȡ����β�ӿں���
QueueDataType Queue_Back(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->tail->data;
}//�������Լ�д�ġ�����֪���Բ���
//6��������д�С�ӿں���
int Queue_Size(Queue* pq)
{
    assert(pq);
    //assert(pq->head);
    int size = 0;

    QueueNode* cur = pq->head;
    while (cur)
    {
        ++size;
        cur = cur->next;
    }
    return size;
}
//7���ж϶����Ƿ�Ϊ��
bool Queue_Empty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;//���򷵻�1
}




int main()
{
    MyStack a;
    myStackCreate(&a);
    myStackPush(&a, 1);
    myStackPush(&a, 2);
    myStackTop(&a);
    myStackTop(&a);
    if (myStackEmpty(&a))
    {
        printf("false");
    }
    return 0;
}
