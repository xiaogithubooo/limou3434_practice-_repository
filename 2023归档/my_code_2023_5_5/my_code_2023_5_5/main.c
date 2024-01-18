#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
//> 力扣第一题
struct ListNode* ListSizefunction(struct ListNode* head, int* psize)
{
    int number = 0;
    struct ListNode* cache = NULL;
    while (head)
    {
        cache = head;
        head = head->next;
        number++;
    }
    *psize = number;
    return cache;
}
//> 力扣第二题
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //处理特殊情况
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    else if (headA == headB)
    {
        return headA;
    }
    //分别计算长度，顺便检查最后一个节点是否一样
    int sizeA = 0;
    int sizeB = 0;
    struct ListNode* A = ListSizefunction(headA, &sizeA);
    struct ListNode* B = ListSizefunction(headB, &sizeB);
    if (A != B)  return NULL;
    //让长的先走i步
    int i = abs(sizeA - sizeB);
    int longSize = sizeA;
    int shortSize = sizeB;
    struct ListNode* longcur = headA;
    struct ListNode* shortcur = headB;
    if (sizeA < sizeB)
    {
        longSize = sizeB;
        shortSize = sizeA;
        longcur = headB;
        shortcur = headA;
    }
    while (i)
    {
        longcur = longcur->next;
        i--;
    }
    //开始同时走
    while (longcur->next != shortcur->next)
    {
        longcur = longcur->next;
        shortcur = shortcur->next;
    }
    if (longcur->next != NULL)
    {
        return longcur->next;
    }
    else if (longcur == shortcur)
    {
        return longcur;
    }
    return NULL;
}
//> 力扣第三题
struct ListNode* middleNode(struct ListNode* head, int* number)
{
    struct ListNode* fast = head;//快指针
    struct ListNode* slow = head;//慢指针

    while (fast && fast->next)//注意这里不能写成fast->next && fast，不这样写的目的是利用短路效应防止空指针解引用
    {
        slow = slow->next;
        fast = fast->next->next;
        (*number)++;
    }
    return slow;
}
bool isPalindrome(struct ListNode* head)
{
    if (head == NULL)
    {
        return false;
    }
    else if (head->next == NULL)//只有一个节点的情况
    {
        return true;
    }
    //后面的链表一定是携带有两个或以上数量的节点

    //1.逆转链表
    int number = 0;
    struct ListNode* mid = middleNode(head, &number);
    struct ListNode* cache0 = mid;
    struct ListNode* cache1 = mid->next;
    struct ListNode* cache2 = NULL;
    if (cache1 && cache1->next != NULL)
    {
        cache2 = mid->next->next;
    }
    else
    {
        cache2 = NULL;
    }
    while (cache1 != NULL)
    {
        cache1->next = cache0;
        cache0 = cache1;
        cache1 = cache2;
        if (cache2 != NULL)
            cache2 = cache2->next;
    }
    //2.开始比较判断
    //最后从两端的head和cache0开始比较
    while (number)
    {
        if (head->val != cache0->val)
        {
            return false;
        }
        head = head->next;
        cache0 = cache0->next;
        number--;
    }
    return true;
}

int main()
{
    struct ListNode a1;
    struct ListNode a2;
    //struct ListNode a3;
    //struct ListNode a4;
    //struct ListNode a5;
    //struct ListNode a6;
     
    a1.val = 1;
    a2.val = 2;
    //a3.val = 3;
    //a4.val = 3;
    //a5.val = 2;
    //a6.val = 1;

    a1.next = &a2;
    //a2.next = &a3;
    //a3.next = &a4;
    //a4.next = &a5;
    //a5.next = &a6;
    a2.next = NULL;

    bool b = isPalindrome(&a1);
    printf("%d", b);
    return 0;
}