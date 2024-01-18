#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode* detectCycle(struct ListNode* head)
{
    //1.先找到快慢指针的相遇点meet
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //2.开始求入口点，根据公式“链表开头到入环点的距离L”==“环的长度C”-“入环点到相遇点距离X”，让meet指针和链表开头head指针同时走动，meet和head相遇的时候就是环的入口点
            struct ListNode* meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}
