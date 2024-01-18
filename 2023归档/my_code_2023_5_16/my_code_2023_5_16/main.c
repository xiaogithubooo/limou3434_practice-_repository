#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
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
//解法一
// //1.“模拟队列”结构体
// typedef struct MyQueue
// {
//     Stack* s1;
//     Stack* s2;
// }MyQueue;

// //2.创建“模拟队列”，并且初始化后返回
// MyQueue* myQueueCreate() 
// {
//     //1.申请空间给“模拟队列”
//     MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
//     if(!cache)//检查是否申请成功
//         exit(-1);
//     //2.申请空间给“模拟队列”结构体的成员，并且各自初始化
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

// //3.将数据推到队尾
// void myQueuePush(MyQueue* obj, int x) 
// {
//     //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//栈为空就返回1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.“推入s_data”相当于“推元素到模拟队列”
//     StackPush(s_data, x);
// }

// //4.队头元素出队，并且返回这个元素
// int myQueuePop(MyQueue* obj) 
// {
//     //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//栈为空就返回1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.转移到栈s_null
//     int num = StackSize(s_data);//计算栈s_data的大小
//     while(num != 1)
//     {
//         StackPush(s_null, StackTop(s_data));//将s_data里的元素转移到s_null里
//         StackPop(s_data);
//         num--;
//     }
//     //3.存储s_data栈里剩余的元素，删除掉该元素，调整s_null里的元素顺序
//     //3.1.将s_data里剩余的元素存储起来，并且删除这个元素
//     int val = StackTop(s_data);
//     StackPop(s_data);
//     //3.2.但是注意此时s_null里的数据反了，需要再次放回s_data栈里
//     while(!StackEmpty(s_null))
//     {
//         StackPush(s_data, StackTop(s_null));//将s_null里的元素转移回s_data里
//         StackPop(s_null);
//     }
//     return val;
// }

// //5.返回队头
// int myQueuePeek(MyQueue* obj) 
// {
//     //1.将结构体里的栈进行分类：分为“存放数据的s_data和不存放数据的s_null”
//     Stack* s_data = NULL;
//     Stack* s_null = NULL;
//     if (StackEmpty(obj->s2))//栈为空就返回1
//     {
//         s_data = obj->s1;
//         s_null = obj->s2;
//     }
//     else
//     {
//         s_data = obj->s2;
//         s_null = obj->s1;
//     }
//     //2.转移到栈s_null
//     int num = StackSize(s_data);//计算栈s_data的大小
//     while(num != 1)
//     {
//         StackPush(s_null, StackTop(s_data));//将s_data里的元素转移到s_null里
//         StackPop(s_data);
//         num--;
//     }
//     //3.存储s_data栈里剩余的元素，调整s_null里的元素顺序
//     //3.1.将s_data里剩余的元素存储起来
//     int val = StackTop(s_data);
//     //3.2.但是注意此时s_null里的数据反了，需要再次放回s_data栈里
//     while(!StackEmpty(s_null))
//     {
//         StackPush(s_data, StackTop(s_null));//将s_null里的元素转移回s_data里
//         StackPop(s_null);
//     }
//     return val;
// }

// //6.判断“模拟队列”是否为空，为空则返回true
// bool myQueueEmpty(MyQueue* obj)
// {
//     if (StackEmpty(obj->s1) && StackEmpty(obj->s2))//栈都为空就都返回1
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }   

// //7.销毁“模拟队列”
// void myQueueFree(MyQueue* obj) 
// {
//     //注意要free三次
//     StackDestroy(obj->s1);
//     StackDestroy(obj->s2);
//     free(obj->s1);
//     free(obj->s2);
//     free(obj);
// }
//解法二
//1.“模拟队列”结构体
typedef struct MyQueue
{
    Stack s1;
    Stack s2;
}MyQueue;

//2.创建“模拟队列”，并且初始化后返回
MyQueue* myQueueCreate()
{
    //1.申请空间给“模拟队列”
    MyQueue* cache = (MyQueue*)malloc(sizeof(MyQueue));
    if (!cache)//检查是否申请成功
        exit(-1);
    //2.给“模拟队列”的结构体成员各自进行初始化
    StackInit(&(cache->s1));
    StackInit(&(cache->s2));
    return cache;
}

//3.将数据推到队尾
void myQueuePush(MyQueue* obj, int x)
{
    //一直将数据压栈压到s1
    StackPush(&(obj->s1), x);
}

//4.队头元素出队，并且返回这个元素
int myQueuePop(MyQueue* obj)
{
    if (StackEmpty(&(obj->s2)) == 1)//判断栈s2是否非空，空则返回非零，
    {
        while (StackSize(&(obj->s1)) != 1)//只要s1中有元素就出张转移到s2中
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

//5.返回队头
int myQueuePeek(MyQueue* obj)
{
    if (StackEmpty(&(obj->s2)) == 1)//判断栈s2是否非空，空则返回非零，
    {
        while (StackSize(&(obj->s1)) != 1)//只要s1中有元素就出张转移到s2中
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

//6.判断“模拟队列”是否为空，为空则返回true
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

//7.销毁“模拟队列”
void myQueueFree(MyQueue* obj)
{
    StackDestroy(&(obj->s1));
    StackDestroy(&(obj->s2));
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