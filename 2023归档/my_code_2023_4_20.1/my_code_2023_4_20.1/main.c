#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct ListNode
{
    int data;
    struct ListNode* next;
};
struct ListNode* reverseList_1(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = head;
    struct ListNode* p3 = head->next;
    while (p2)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL)
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
