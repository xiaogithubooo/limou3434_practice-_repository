#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;
//方法一：不带头节点
ListNode* partition_1(ListNode* pHead, int x)
{
    if (!pHead)
        return NULL;
    ListNode* pNewHead1 = NULL;//指向小链表
    ListNode* cur1 = NULL;//遍历小链表

    ListNode* pNewHead2 = NULL;//指向大链表
    ListNode* cur2 = NULL;//遍历大链表

    ListNode* cur = pHead;//指向旧链表
    while (cur)//遍历旧链表
    {
        ListNode* next = cur->next;
        if (cur->val < x)//符合要求，尾插到NewHead1
        {
            if (pNewHead1 == NULL)//新链表1为空
            {
                cur1 = pNewHead1 = cur;
            }
            else//新链表不为空
            {
                cur1->next = cur;
                cur1 = cur1->next;
            }
        }
        else//不符合要求，cur->next >= x，尾插到NewHead2
        {
            if (pNewHead2 == NULL)//新链表2为空
            {
                cur2 = pNewHead2 = cur;
            }
            else//新链表不为空
            {
                cur2->next = cur;
                cur2 = cur2->next;
            }
        }
        cur = next;
    }
    if (cur1 == NULL)
        return pNewHead2;
    if (cur2 == NULL)
        return pNewHead1;
    cur1->next = pNewHead2;
    cur2->next = NULL;
    return pNewHead1;
}

//方法二：带有头节点
ListNode* partition(ListNode* pHead, int x)
{
    ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
    lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
    greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
    if (!lesshead || !greaterhead)//检查是否申请成功
    {
        perror("malloc fail!");
        return NULL;
    }

    ListNode* cur = pHead;//用来遍历旧链表
    while (cur)
    {
        if (cur->val < x)
        {
            lesstail->next = cur;
            lesstail = lesstail->next;
        }
        else//cur->val >= x
        {
            greatertail->next = cur;
            greatertail = greatertail->next;
        }
        cur = cur->next;
    }
    if (lesshead->next == NULL)
    {
        return greaterhead->next;
    }
    if (greaterhead->next == NULL)
    {
        return lesshead->next;
    }
    lesstail->next = greaterhead->next;//注意是哨兵节点
    pHead = lesshead->next;
    greatertail->next = NULL;
    free(lesshead);
    free(greaterhead);
    return pHead;
}

int main()
{
    ListNode phead1;
    phead1.val = 6;
    ListNode phead2;
    phead2.val = 2;
    ListNode phead3;
    phead3.val = 8;
    ListNode phead4;
    phead4.val = 3;
    ListNode phead5;
    phead5.val = 1;

    phead1.next = &phead2;
    phead2.next = &phead3;
    phead3.next = &phead4;
    phead4.next = &phead5;
    phead5.next = NULL;

    ListNode* p = partition(&phead1, 3);
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}

//1.找到中间节点地址（注意如果链表个数为偶数个，返回中间偏左的节点地址）
struct ListNode* FindFunction(struct ListNode* head)
{
    assert(head);
    struct ListNode* p1 = head, * p2 = head;//快慢双指针
    while (p1 && p1->next)//如果快指针没有到尾节点或NULL就继续走循环
    {
        p1 = p1->next->next;//更新p1
        p2 = p2->next;//更新p2
    }
    return p2;
}
//2.逆置链表
struct ListNode* reverseFunction(struct ListNode* middle)
{
    //逆置middle节点和后面的节点（无论是奇偶个链表就都不影响后续的判断）
    struct ListNode* cur = middle;
    struct ListNode* rhead = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;

        //头插
        cur->next = rhead;
        rhead = cur;
        cur = next;
    }
    return rhead;
}
//3.开始检查是不是回文链表
bool isPalindrome(struct ListNode* head)
{
    struct ListNode* middle = FindFunction(head);
    struct ListNode* reverseMiddle = reverseFunction(middle);

    while (reverseMiddle)
    {
        if (reverseMiddle->val != head->val)
        {
            return false;
        }
        else
        {
            reverseMiddle = reverseMiddle->next;
            head = head->next;
        }
    }
    return true;
}
