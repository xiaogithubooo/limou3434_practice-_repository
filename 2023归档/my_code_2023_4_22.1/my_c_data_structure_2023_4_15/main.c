#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
//# 0.目标：“无头无循环单向链表”的练习
//>		0.1.复习“无头无循环单向链表”
//x			0.1.1.重新看“无头无循环单向链表”的code
//x			0.1.2.对“无头无循环单向链表”进行调试
//x			0.1.3.while (!(成功写出“无头无循环单向链表”)) { 回去看代码; }
//>		0.2.使用“无头无循环单向链表”思想
//			0.2.1.刷推荐和作业的题目
//				0.2.1.1.移除链表元素：https://leetcode.cn/problems/remove-linked-list-elements/description/
//x				0.2.1.2.反转链表：https://leetcode.cn/problems/reverse-linked-list/
//				0.2.1.3.链表的中间结点：https://leetcode.cn/problems/middle-of-the-linked-list/
//				0.2.1.4.链表中倒数第k个结点：https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//				0.2.1.5.合并两个有序链表：https://leetcode.cn/problems/merge-two-sorted-lists/description/
//				0.2.1.6.链表分割：https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//				0.2.1.7.链表的回文结构：https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//				0.2.1.8.相交链表：https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//              0.2.1.9.两数相加：https://leetcode.cn/problems/add-two-numbers/
//			0.2.2.刷力扣的题目
// 
//>     0.3.写“无头无循环单向链表”的博客

//# 1.复习“无头无循环单向链表”（其实判断接口参数是否是二级指针很简单，只需要判断形参是否需要在接口函数中被赋值即可）
//> 1.0.“无头无循环单向链表”结构体
typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;
//> 1.1.动态申请一个结点
SListNode* BuySListNode(SLTDateType x)
{
    //单独申请一个节点
    SListNode* chche = (SListNode*)malloc(sizeof(SListNode));
    if (!chche)
    {
        perror("fail malloc");//注意perror只有在malloc、文件操作的时候才可用
        return NULL;
    }
    else
    {
        //初始化该节点
        chche->data = x;
        chche->next = NULL;
        return chche;
    }
}
//> 1.2.“无头无循环单向链表”打印
void SListPrint(SListNode* plist)
{
    SListNode* cur = plist;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
//> 1.3.“无头无循环单向链表”尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    assert(pplist);
    //单独申请一个节点
    SListNode* chche = BuySListNode(x);

    //开始尾插节点
    SListNode* cur = *pplist;
    if (cur == NULL)//如果是空链表
    {
        *pplist = chche;
    }
    else//如果是非空链表
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = chche;
    }
    /*千万不能直接cur找到整个链表的NULL，然后将新增加的节点赋值给cur（因为上一个节点的next依旧指向NULL，链表是断开的）*/
    /*赋值的本质是拷贝*/
}
//> 1.4.“无头无循环单向链表”的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    //单独申请一个节点
    SListNode* chche = BuySListNode(x);
    chche->next = *pplist;//这个语句保证了两种情况都可以（NULL/非NULL）
    *pplist = chche;
}
//> 1.5.“无头无循环单向链表”的尾删
void SListPopBack(SListNode** pplist)
{
    assert(pplist && *pplist);//避免空指针和空链表
    if ((*pplist)->next == NULL)//单独处理只有一个节点的情况
    {
        free(*pplist);//哎呀，忘记释放内存了，补上
        *pplist = NULL;
        return;
    }
    //开始尾删节点
    SListNode* prev = *pplist;//这一步我一开始没有想到hhhhhh，prev是为了记录上一个节点
    SListNode* cur = *pplist;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    free(cur);//释放掉尾节点
    prev->next = NULL;//重新定义尾节点
}
//> 1.6.“无头无循环单向链表”头删
void SListPopFront(SListNode** pplist)
{
    assert(pplist && *pplist);
    SListNode* p = *pplist;
    *pplist = (*pplist)->next;//这里容易写出bug，因为“->”的优先级要比“*”高
    free(p);
}
//> 1.7.“无头无循环单向链表”查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    assert(plist);//保证不传空指针
    SListNode* cur = plist;
    if ((cur->next == NULL) && (cur->data == x))
    {
        return cur;
    }
    while (cur->next != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//> 1.8.“无头无循环单向链表”在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？tips:因为没有办法往前插入，这是单向链表的缺点
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    //单独申请一个节点
    assert(pos);
    SListNode* chche = BuySListNode(x);
    chche->next = pos->next;
    pos->next = chche;
}
//> 1.9.“无头无循环单向链表”删除pos位置之后的值
// 分析思考为什么不删除pos位置？tips:也是由于单向的原因，找不回去
void SListEraseAfter(SListNode* pos)
{
    assert(pos && pos->next);
    SListNode* p1 = pos->next;
    SListNode* p2 = p1->next;
    pos->next = p2;
    free(p1);
}
//> 1.10.链表测试用例
void test()
{
    SListNode* a = NULL;
    SListPushFront(&a, 100);//头插
    SListPushFront(&a, 200);//头插
    SListPushFront(&a, 300);//头插
    SListPrint(a);//打印

    SListNode* p = SListFind(a, 300);//查找
    printf("%p\n", p);

    SListPopFront(&a);//头删
    SListPrint(a);//打印
    SListPopFront(&a);//头删
    SListPrint(a);//打印
    SListPopFront(&a);//头删
    SListPrint(a);//打印
    //SListPopFront(&a);//头删（头删了空链表）
    //SListPrint(a);//打印

    SListPushBack(&a, 3);//尾插
    SListPushBack(&a, 2);//尾插
    SListPushBack(&a, 1);//尾插
    SListPushBack(&a, 0);//尾插
    SListPushFront(&a, 100);//头插
    SListPushFront(&a, 200);//头插
    SListPushFront(&a, 300);//头插
    SListPrint(a);//打印

    SListPopBack(&a);//尾删
    SListPrint(a);//打印
    SListPopBack(&a);//尾删
    SListPopBack(&a);//尾删
    SListPopBack(&a);//尾删
    SListPrint(a);//打印
    SListPopBack(&a);//尾删
    SListPopBack(&a);//尾删
    SListPopBack(&a);//尾删
    //SListPopBack(&a);//尾删（尾删了空链表）
    SListPrint(a);//打印

    SListPushBack(&a, 3);//尾插
    SListPushBack(&a, 2);//尾插
    SListPushBack(&a, 1);//尾插
    SListPushBack(&a, 0);//尾插
    SListPushFront(&a, 100);//头插
    SListPushFront(&a, 200);//头插
    SListPushFront(&a, 300);//头插
    SListPushFront(&a, 400);//头插
    SListPrint(a);//打印
    p = SListFind(a, 100);//先查找得到节点地址
    SListInsertAfter(p, 4);//任意插入节点
    SListPrint(a);//打印
    SListPopFront(&a);//头删
    SListPopBack(&a);//尾删
    SListPopFront(&a);//头删
    SListPopBack(&a);//尾删
    SListPopFront(&a);//头删
    SListPopBack(&a);//尾删
    SListPopFront(&a);//头删
    SListPopBack(&a);//尾删
    p = SListFind(a, 4);//先查找得到节点地址
    SListInsertAfter(p, 100000);//任意插入节点
    SListPrint(a);//打印
    SListPopFront(&a);//头删
    SListPopFront(&a);//头删
    SListPrint(a);//打印

    SListPushBack(&a, 1);//尾插
    SListPushBack(&a, 0);//尾插
    SListPushFront(&a, 100);//头插
    SListPushFront(&a, 200);//头插
    SListPrint(a);//打印
    p = SListFind(a, 200);//先查找得到节点地址
    SListEraseAfter(p);
    SListPrint(a);//打印
    SListEraseAfter(p);
    SListPrint(a);//打印
    SListEraseAfter(p);
    SListPrint(a);//打印
}

//# 2.使用“无头无循环单向链表”思想
//> 2.1.移除链表元素
//方法一：离谱想出来的（有点拉的代码）…
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (!head)
    {
        return NULL;
    }
    struct ListNode* cur = head;//遍历旧链表，检查节点的val值是否、等于val
    struct ListNode* p = NULL;//遍历新链表
    struct ListNode* newhead = NULL;//记录新链表的起始节点
    int flag = 0;
    while (cur)//直到cur为空
    {
        if (cur->val != val)
        {
            if (flag == 0)//记录第一次出现的节点
            {
                newhead = cur;
                flag = 1;
            }
            //尾插
            if (p == NULL)//空链表单独处理
            {
                p = cur;
            }
            else//非空链表
            {
                p->next = cur;
                p = p->next;
            }
        }
        cur = cur->next;
    }
    if (flag != 0)
        p->next = NULL;
    return newhead;
}
void text_1()
{
    struct ListNode p1;
    struct ListNode p2;
    struct ListNode p3;
    struct ListNode p4;
    struct ListNode p5;
    struct ListNode p6;
    struct ListNode p7;
    p1.val = 7;
    p2.val = 7;
    p3.val = 7;
    p4.val = 7;
    p5.val = 7;
    p6.val = 7;
    p7.val = 7;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;
    p6.next = &p7;
    p7.next = NULL;
    removeElements(&p1, 7);
}
//方法二：课堂上讲的
// 
//> 2.2.反转链表
struct ListNode* reverseList_1(struct ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = head;
    struct ListNode* p3 = head->next; 
    while(p2)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if(p3 != NULL)
        {
            p3 = p3->next;
        }
    }
    return p1;
}
struct ListNode* reverseList_2(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;

        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

//# 3.写“无头无循环单向链表”的博客

int main()
{
    //test();
    text_1();
    return 0;
}