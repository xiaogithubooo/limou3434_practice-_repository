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
//> 1.3.创建一个“链表的哨兵节点”
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
    //3.再释放掉哨兵节点
    free(plist);
    plist = NULL;
}
//> 1.5.链表打印
void ListPrint(ListNode* plist)
{
    assert(plist);
    ListNode* cur = plist->next;//得到头结点，而非哨兵节点
    while (cur != plist)
    {
        printf("[%d]<->", cur->data);
        cur = cur->next;
    }
    printf("[循环到哨兵结点]\n");
}
//> 1.6.链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
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
    assert(plist->next != plist);//保证链表不会只剩下哨兵节点

    //1.先找到这个尾节点，单独隔离出来这个地址
    ListNode* tail = plist->prev;
    //2.更新链表的新尾节点
    tail->prev->next = plist;
    plist->prev = tail->prev;
    //3.释放被隔离的旧尾节点
    free(tail);
    tail = NULL;
}
// 链表头插
void ListPushFront(ListNode* plist, LTDataType x);
// 链表头删
void ListPopFront(ListNode* plist);
// 链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);
// 链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 链表删除pos位置的结点
void ListErase(ListNode* pos);

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

    ListDestory(pl);//销毁链表
}

//# 2.“有头双循环双向链表”的博客撰写

int main()
{
    test();
    return 0;
}