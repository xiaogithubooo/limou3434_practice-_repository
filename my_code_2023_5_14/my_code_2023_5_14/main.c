#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
//# 题目一
//一.队列的相关接口
//> 1.链式结构：表示队列的一个元素
typedef int QDataType;
typedef struct QListNode
{
    struct QListNode* _pNext;
    QDataType _data;
}QNode;
//> 2.队列的结构 
typedef struct Queue
{
    QNode* _front;//队头
    QNode* _rear;//队尾
}Queue;
//> 3.初始化队列 
void QueueInit(Queue* q);
//> 4.队尾入队列 
void QueuePush(Queue* q, QDataType data);
//> 5.队头出队列 
void QueuePop(Queue* q);
//> 6.获取队列头部元素 
QDataType QueueFront(Queue* q);
//> 7.获取队列中有效元素个数 
int QueueSize(Queue* q);
//> 8.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
//> 9.销毁队列 
void QueueDestroy(Queue* q);

//二.具体的解法
//1.创建一个MyStack结构体，内部存储指向两个队列的指针
typedef struct MyStack
{
    Queue* q1;//队列一
    Queue* q2;//队列二
}MyStack;

//2.创建一个MyStack并且对内部的两个队列指针进行初始化
MyStack* myStackCreate()
{
    //1.申请空间给给模拟的栈使用
    MyStack* cache = (MyStack*)malloc(sizeof(MyStack));
    if (!cache)
        exit(-1);//检查是否申请成功
    //2.申请空间给模拟栈内部的队列、初始化模拟栈内部的队列
    cache->q1 = (Queue*)malloc(sizeof(Queue));
    if (!cache->q1)
        exit(-1);//检查是否申请成功
    cache->q2 = (Queue*)malloc(sizeof(Queue));
    if (!cache->q2)
        exit(-1);//检查是否申请成功
    QueueInit(cache->q1);//初始化队列q1
    QueueInit(cache->q2);//初始化队列q2
    return cache;
    /*需要注意的是这里malloc了三次最后销毁的时候就需要free三次*/
}

//3.模拟压栈
void myStackPush(MyStack* obj, int x)
{
    //1.将队列分类：分为“存放数据的q_data和不存放数据的q_null”
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//队列为空就返回1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.“将数据推入到存放q_data的队尾”这相当于“在MyStack压栈”
    QueuePush(q_data, x);
}

//3.删除栈顶元素
int myStackPop(MyStack* obj)
{
    //1.将队列分类：分为“存放数据的q_data和不存放数据的q_null”
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//队列为空就返回1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.转移数据到q_null
    while (QueueSize(q_data) != 1)
    {
        //2.1.将有q_data的队头元素推到q_null的队尾
        QueuePush(q_null, QueueFront(q_data));
        //2.2.删除q_dat的队头元素
        QueuePop(q_data);
    }
    //3.返回栈顶元素，并且将q_data仅留有的一个元素删除
    int val = q_data->_rear->_data;
    QueuePop(q_data);
    return val;
}

//4.取栈顶元素
int myStackTop(MyStack* obj)
{
    //1.将队列分类：分为“存放数据的q_data和不存放数据的q_null”
    Queue* q_data = NULL;
    Queue* q_null = NULL;
    if (QueueEmpty(obj->q2))//队列为空就返回1
    {
        q_data = obj->q1;
        q_null = obj->q2;
    }
    else
    {
        q_data = obj->q2;
        q_null = obj->q1;
    }
    //2.由于我的队列包含队尾指针，因此可以直接找到然后返回
    return q_data->_rear->_data;
}

//5.检测栈是否为空，栈空返回true
bool myStackEmpty(MyStack* obj)
{
    if (QueueEmpty(obj->q1) && QueueEmpty(obj->q2))//队列都为空就豆返回1
    {
        return true;
    }
    else
    {
        return false;
    }
}

//6.销毁栈（注意malloc了多少次就要销毁多少次）
void myStackFree(MyStack* obj)
{
    QueueDestroy(obj->q1);
    QueueDestroy(obj->q2);
    free(obj);
}

//三.C语言中栈的具体实现
//!> 队列的实现
//!> 1.链表结构（不带头）
//!typedef int QDataType;
//!typedef struct QListNode
//!{
//!    struct QListNode* _pNext;
//!    QDataType _data;
//!}QNode;
//!> 2.队列结构 
//!typedef struct Queue
//!{
//!    QNode* _front;  //标记队头
//!    QNode* _rear;   //标记队尾
//!}Queue;
//> 3.初始化队列 
void QueueInit(Queue* q)
{
    //1.检查指针的有效性
    assert(q);
    //2.初始化队列（队尾队头都置为空）
    q->_front = NULL;
    q->_rear = NULL;
}
//> 4.队尾入队列（链表尾插）
void QueuePush(Queue* q, QDataType data)
{
    //1.检查指针的有效性
    assert(q);
    //2.先申请一个链表节点并且存储好数据
    QNode* cache = (QNode*)malloc(sizeof(QNode));
    if (!cache)
    {
        perror("malloc fail\n");
        exit(-1);
    }
    cache->_data = data;
    cache->_pNext = NULL;
    //3.开始尾插
    if (q->_rear == NULL)//如果队列为空
    {
        q->_front = q->_rear = cache;
    }
    else
    {
        q->_rear->_pNext = cache;
        q->_rear = cache;//改变队列的队尾标记，形成新的队尾
    }
}
//> 5.队头出队列（链表头删）
void QueuePop(Queue* q)
{
    //1.检查指针有效性
    assert(q);
    assert(q->_front);
    //2.开始出数据
    //2.1.处理特殊情况（只剩一个节点）
    if (q->_front == q->_rear)
    {
        free(q->_front);
        q->_front = q->_rear = NULL;
        return;
    }
    //2.2.处理一般情况
    QNode* delNode = q->_front;
    q->_front = q->_front->_pNext;
    free(delNode);
}
//> 6.获取队列头部元素 
QDataType QueueFront(Queue* q)
{
    //1.检查指针的有效性
    assert(q);
    assert(q->_front);
    //2.返回队头的值
    return q->_front->_data;
}
//> 7.获取队列中有效元素个数 
int QueueSize(Queue* q)
{
    //1.检查指针的有效性
    assert(q);
    //2.循环计数，返回有效元素个数
    int size = 0;
    QNode* cur = q->_front;
    while (cur)
    {
        size++;
        cur = cur->_pNext;
    }
    return size;
}
//> 8.检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
    //1.检查指针的有效性
    assert(q);
    //2.检测队列是否为空
    return q->_front == NULL;
}
//> 9.销毁队列 
void QueueDestroy(Queue* q)
{
    //1.检查指针的有效性
    assert(q);
    //2.开始销毁
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
    MyStack* MS = myStackCreate();//创建一个MyStack并且初始化
    myStackPush(MS, 1);//压栈
    myStackPush(MS, 2);//压栈
    myStackPush(MS, 3);//压栈
    myStackPush(MS, 4);//压栈
    myStackPush(MS, 5);//压栈
    while (!myStackEmpty(MS))//检测栈是否为空，栈空返回true
    {
        printf("%d ", myStackTop(MS));//取栈顶元素
        myStackPop(MS);//删除栈顶
    }
    return 0;
}

void test_1()
{
    MyStack* MS = myStackCreate();//创建一个MyStack并且初始化
    myStackPush(MS, 1);//压栈
    myStackPush(MS, 2);//压栈
    myStackPush(MS, 3);//压栈
    myStackPush(MS, 4);//压栈
    myStackPush(MS, 5);//压栈
    while (!myStackEmpty(MS))//检测栈是否为空，栈空返回true
    {
        printf("%d ", myStackTop(MS));//取栈顶元素
        myStackPop(MS);//删除栈顶
    }
}

//# 题目二
//一.栈的相关接口
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

//二.具体解法
//1.“模拟队列”结构体
typedef struct MyQueue
{
    Stack* s1;
    Stack* s2;
}MyQueue;

//2.创建“模拟队列”，并且初始化后返回
MyQueue* myQueueCreate()
{
    //1.申请空间给“模拟队列”
    MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
    if (!cache)//检查是否申请成功
        exit(-1);
    //2.申请空间给“模拟队列”结构体的成员，并且各自初始化
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

//3.将数据推到队尾
void myQueuePush(MyQueue* obj, int x)
{
    //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//栈为空就返回1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.“推入s_data”相当于“推元素到模拟队列”
    StackPush(s_data, x);
}

//4.队头元素出队，并且返回这个元素
int myQueuePop(MyQueue* obj)
{
    //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//栈为空就返回1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.转移到栈s_null
    int num = StackSize(s_data);//计算栈s_data的大小
    while (num != 1)
    {
        StackPush(s_null, StackTop(s_data));//将s_data里的元素转移到s_null里
        StackPop(s_data);
        num--;
    }
    //3.存储s_data栈里剩余的元素，删除掉该元素，调整s_null里的元素顺序
    //3.1.将s_data里剩余的元素存储起来，并且删除这个元素
    int val = StackTop(s_data);
    StackPop(s_data);
    //3.2.但是注意此时s_null里的数据反了，需要再次放回s_data栈里
    while (!StackEmpty(s_null))
    {
        StackPush(s_data, StackTop(s_null));//将s_null里的元素转移回s_data里
        StackPop(s_null);
    }
    return val;
}

//5.返回队头
int myQueuePeek(MyQueue* obj)
{
    //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
    Stack* s_data = NULL;
    Stack* s_null = NULL;
    if (StackEmpty(obj->s2))//栈为空就返回1
    {
        s_data = obj->s1;
        s_null = obj->s2;
    }
    else
    {
        s_data = obj->s2;
        s_null = obj->s1;
    }
    //2.转移到栈s_null
    int num = StackSize(s_data);//计算栈s_data的大小
    while (num != 1)
    {
        StackPush(s_null, StackTop(s_data));//将s_data里的元素转移到s_null里
        StackPop(s_data);
        num--;
    }
    //3.存储s_data栈里剩余的元素，调整s_null里的元素顺序
    //3.1.将s_data里剩余的元素存储起来
    int val = StackTop(s_data);
    //3.2.但是注意此时s_null里的数据反了，需要再次放回s_data栈里
    while (!StackEmpty(s_null))
    {
        StackPush(s_data, StackTop(s_null));//将s_null里的元素转移回s_data里
        StackPop(s_null);
    }
    return val;
}

//6.判断“模拟队列”是否为空，为空则返回true
bool myQueueEmpty(MyQueue* obj)
{
    if (StackEmpty(obj->s1) && StackEmpty(obj->s2))//栈都为空就都返回1
    {
        return true;
    }
    else
    {
        return false;
    }
}

//7.销毁“模拟队列”
void myQueueFree(MyQueue* obj)
{
    //注意要free三次
    StackDestroy(obj->s1);
    StackDestroy(obj->s2);
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

//三.栈接口的具体实现
//!> 栈的实现
//!> 1.支持动态增长的栈
//!typedef int STDataType;
//!typedef struct Stack
//!{
//!    STDataType* _a;
//!    int _top;       //栈顶
//!    int _capacity;  //容量 
//!}Stack;
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