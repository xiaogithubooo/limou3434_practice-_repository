#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//提供一个专门为队列服务的链表
typedef int QueueDataType;
typedef struct QueueNode
{
    struct QueueNode* next;
    QueueDataType data;
}QueueNode;
//队列结构体，注意头节点为队头，执行删除操作
typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;

//1、初始化队列接口函数
void Queue_Init(Queue* pq);
//2、队列销毁接口函数
void Queue_Destory(Queue* pq);
//3、队尾入（加链表节点）
void Queue_Push(Queue* pq, QueueDataType x);
//3、队头出（删链表节点）
void Queue_Pop(Queue* pq);
//4、取出队头接口函数
QueueDataType Queue_Front(Queue* pq);
//5、取出队尾接口函数
QueueDataType Queue_Back(Queue* pq);
//6、计算队列大小接口函数
int Queue_Size(Queue* pq);
//7、判断队列是否为空
bool Queue_Empty(Queue* pq);
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
typedef struct {
    Queue q1;//队列1
    Queue q2;//队列2
} MyStack;

MyStack* myStackCreate()
{
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail!\n");
        exit(-1);
    }
    //初始化两个队列
    Queue_Init(&ps->q1);
    Queue_Init(&ps->q2);

    //返回存放两个队列的结构体的指针
    return ps;
}

void myStackPush(MyStack* obj, int x)
{
    //入数据时，往空的的队列入数据（两个都为空也没关系）
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
    //删数据时，往另外一个空的队列导入数据，直到只剩最后一个数据，将它删除就行
    Queue* emptyQ = &obj->q1;//假设了该队列为空
    Queue* nonemptyQ = &obj->q2;//假设了该队列不为空
    if (!Queue_Empty(&obj->q1))//如果假设错误就换一下
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }//这样就无需具体关注谁是空队列了
    while (Queue_Size(nonemptyQ) > 1)
    {
        Queue_Push(emptyQ, Queue_Front(nonemptyQ));
        Queue_Pop(nonemptyQ);
    }
    //最后nonemptyQ队列中只剩一个元素，不再将它存放入emptyQ，直接删除即可，就是要注意本题在删除栈顶的同时需要要返回栈顶值，返回nonemptyQ中剩余的一个元素就行
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
    return Queue_Empty(&obj->q1) && Queue_Empty(&obj->q2);//一个空为1，同时空则返回1
}

void myStackFree(MyStack* obj)
{
    Queue_Destory(&obj->q1);
    Queue_Destory(&obj->q2);

    //本身也需要释放掉
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
//1、初始化队列接口函数
void Queue_Init(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}
//2、队列销毁接口函数
void Queue_Destory(Queue* pq)
{
    assert(pq);
    //assert(pq->head);这条语句是不用的！！！
    QueueNode* cur = pq->head;
    while (cur)
    {
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
//3、队尾入（加链表节点）
void Queue_Push(Queue* pq, QueueDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    //初始化一下这个新申请的节点
    newnode->data = x;
    newnode->next = NULL;

    //连接新节点
    if (pq->head == NULL)//如果链表没有节点
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;//更新tail
    }
}
//3、队头出（删链表节点）
void Queue_Pop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    //要注意被删到一个节点的情况，防止tail成为野指针
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QueueNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;//更新新的head
    }
}
//4、取出队头接口函数
QueueDataType Queue_Front(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}
//5、取出队尾接口函数
QueueDataType Queue_Back(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->tail->data;
}//这里是自己写的……不知道对不对
//6、计算队列大小接口函数
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
//7、判断队列是否为空
bool Queue_Empty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;//空则返回1
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
