#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
//# 0.目标：“有头双循环双向链表”的练习
//>     0.1.复习“有头双循环双向链表”
//			0.1.1.重新看“有头双循环双向链表”的code
//			0.1.2.对“有头双循环双向链表”进行调试
//			0.1.3.while (!(成功写出“有头双循环双向链表”)) { 回去看代码; }
//>     0.2.使用“有头双循环双向链表”思想
//			0.2.1.刷推荐和作业的题目
//			0.2.2.刷力扣的题目
//>     0.3.撰写“有头双循环双向链表”的文章
//          0.3.1.写题解
//          0.3.2.写博客 

//# 1.复习“有头双循环双向链表”
/*
头节点：
是一个实际节点，实际存储数据的结构体，
它用于标识链表的起始位置，
头结点通常不存储有效数据，
可以作为链表初始状态时的默认前驱节点

哨兵节点：
是一个辅助节点，它不存储任何有效数据，
仅仅是作为“哨兵”站在链表的某个位置上，
没有任何的业务信息，
仅仅只是为了方便对链表的操作而引入的辅助节点。
哨兵节点可以用来简化链表操作的实现，进而提高代码效率。
哨兵节点通常不计入链表节点数量，
也就是说，它本身并不属于链表的一部分
*/
//> 1.1.“有头双循环双向链表”结构体 
typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;
//> 1.2.申请节点空间
ListNode* BuyListNode(LTDataType x)
{
    ListNode* cache = (ListNode*)malloc(sizeof(ListNode));//申请一个节点的空间
    if (!cache)
    {
        perror("malloc fail!");
        return NULL;
    }
    cache->data = x;
    cache->next = NULL;
    cache->prev = NULL;
    return cache;
}
//> 1.3.初始化链表（创建一个“链表的头节点”）
ListNode* ListInit(void)
{
    ListNode* cache = BuyListNode(0);
    if (!cache) exit(-1);

    cache->next = cache;
    cache->prev = cache;
    return cache;
}
//> 1.4.双链表销毁
void ListDestory(ListNode* plist)
{
    //1.防止空指针解引用
    assert(plist);
    ListNode* cur = plist->next;//循环变量
    //2.先释放掉循环的链表
    while (cur != plist)
    {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    //3.再释放掉头节点
    free(plist);
    plist = NULL;
}
//> 1.5.链表打印
void ListPrint(ListNode* plist)
{
    assert(plist);
    ListNode* cur = plist->next;//得到起始结点，而非头节点
    while (cur != plist)
    {
        printf("[%d]<->", cur->data);
        cur = cur->next;
    }
    printf("[循环到头结点]\n");
}
//> 1.6.链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
    assert(plist);
    ListNode* cache = BuyListNode(x);//申请节点空间
    if (!cache) exit(-1);

    plist->prev->next = cache;//找到指向尾节点的指针
    cache->prev = plist->prev;
    cache->next = plist;
    plist->prev = cache;
}
//> 1.7.链表尾删
void ListPopBack(ListNode* plist)
{
    assert(plist);//保证不会发生空指针解引用
    assert(plist->next != plist);//保证链表不会只剩下头节点

    //1.先找到这个尾节点，单独隔离出来这个地址
    ListNode* tail = plist->prev;
    //2.更新链表的新尾节点
    tail->prev->next = plist;
    plist->prev = tail->prev;
    //3.释放被隔离的旧尾节点
    free(tail);
    tail = NULL;
}
//> 1.8.链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
    assert(plist);
    ListNode* cache = BuyListNode(x);//申请节点空间
    if (!cache) exit(-1);

    ListNode* p = plist->next;
    plist->next = cache;
    cache->next = p;
    cache->prev = plist;
    p->prev = cache;
}
//> 1.9.链表头删
void ListPopFront(ListNode* plist)
{
    assert(plist);//保证不会发生空指针解引用
    assert(plist->next != plist);//保证链表不会只剩下头节点

    ListNode* first = plist->next;//先找到这个首节点，单独隔离出来
    plist->next = first->next;
    first->prev = plist;
    free(first);
    first = NULL;
}
//> 1.10.链表查找（返回找到的数据对应结构体的地址）
ListNode* ListFind(ListNode* plist, LTDataType x)
{
    assert(plist);//避免解引用空指针
    assert(plist->next != plist);//避免查找空链表
    ListNode* cur = plist->next;//找到第一个节点
    while (cur != plist)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//> 1.11.链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);//避免解引用空指针
    ListNode* cache = BuyListNode(x);//购买新节点

    ListNode* p = pos->prev;
    pos->prev = cache;
    cache->next = pos;
    cache->prev = p;
    p->next = cache;
}
//> 1.12.链表删除pos位置的结点
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prev = pos->prev;
    ListNode* next = pos->next;
    prev->next = next;
    next->prev = prev;
    free(pos);
    pos = NULL;
}

void test()
{
    ListNode* pl = ListInit();//创建一个头节点

    //根据这个头结点进行“增删查改”
    ListPushBack(pl, 1);//尾插
    ListPushBack(pl, 2);//尾插
    ListPushBack(pl, 3);//尾插
    ListPushBack(pl, 4);//尾插
    ListPrint(pl);//打印链表

    ListPopBack(pl);//尾删
    ListPopBack(pl);//尾删
    ListPrint(pl);//打印链表
    ListPopBack(pl);//尾删
    ListPrint(pl);//打印链表
    ListPopBack(pl);//尾删
    ListPrint(pl);//打印链表
    //ListPopFront(pl);//尾删（非法）
    //ListPrint(pl);//打印链表

    ListPushBack(pl, 1);//尾插
    ListPushBack(pl, 2);//尾插
    ListPushBack(pl, 3);//尾插
    ListPushBack(pl, 4);//尾插
    ListPopBack(pl);//尾删
    ListPrint(pl);//打印链表

    printf("%p\n", ListFind(pl, 1));//查找数据为1的节点，并且打印地址
    printf("%d\n", ListFind(pl, 1)->data);//查找数据为1的节点，并且打印出指针指向的数据
    printf("%p\n", ListFind(pl, 2));//查找数据为2的节点，并且打印地址
    printf("%d\n", ListFind(pl, 2)->data);//查找数据为2的节点，并且打印出指针指向的数据
    printf("%p\n", ListFind(pl, 3));//查找数据为3的节点，并且打印地址
    printf("%d\n", ListFind(pl, 3)->data);//查找数据为3的节点，并且打印出指针指向的数据
    printf("%p\n", ListFind(pl, 0));//查找数据为1的节点，并且打印地址

    ListPushFront(pl, 0);//头插
    ListPushFront(pl, -1);//头插
    ListPushFront(pl, -2);//头插
    ListPopBack(pl);//尾删
    ListPopBack(pl);//尾删
    ListPopBack(pl);//尾删
    ListPrint(pl);//打印链表
    ListPopBack(pl);//尾删
    ListPopBack(pl);//尾删
    ListPopBack(pl);//尾删
    ListPushFront(pl, -2);//头插
    ListPrint(pl);//打印链表
    ListPopBack(pl);//尾删

    ListPushFront(pl, 10);//头插
    ListPushFront(pl, 100);//头插
    ListPushFront(pl, 1000);//头插
    ListPrint(pl);//打印链表
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPrint(pl);//打印链表
    //ListPopFront(pl);//头删（非法）
    //ListPrint(pl);//打印链表

    ListPushFront(pl, 10);//头插
    ListPushFront(pl, 100);//头插
    ListPushFront(pl, 1000);//头插
    ListPrint(pl);//打印链表
    ListInsert(ListFind(pl, 10), -1);//任意插入
    ListInsert(ListFind(pl, 100), -1);//任意插入
    ListInsert(ListFind(pl, 1000), -1);//任意插入
    ListPrint(pl);//打印链表
    //ListInsert(ListFind(pl, 1), -1);//任意插入（非法）
    //ListPrint(pl);//打印链表
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPushFront(pl, 10);//头插
    ListPrint(pl);//打印链表
    ListInsert(ListFind(pl, 10), -1);//任意插入
    ListPrint(pl);//打印链表

    ListPopFront(pl);//头删
    ListPopFront(pl);//头删
    ListPrint(pl);//打印链表
    ListPushFront(pl, 10);//头插
    ListPushFront(pl, 100);//头插
    ListPushFront(pl, 1000);//头插
    ListPrint(pl);//打印链表
    ListErase(ListFind(pl, 10));//任意删除
    ListPrint(pl);//打印链表
    ListErase(ListFind(pl, 100));//任意删除
    ListPrint(pl);//打印链表
    ListErase(ListFind(pl, 1000));//任意删除
    ListPrint(pl);//打印链表
    //ListErase(ListFind(pl, 1000));//任意删除（非法）
    //ListPrint(pl);//打印链表

    ListDestory(pl);//销毁链表
}

//# 2.“有头双循环双向链表”的博客撰写

//# 3.测试代码
int main()
{
    test();
    return 0;
}

