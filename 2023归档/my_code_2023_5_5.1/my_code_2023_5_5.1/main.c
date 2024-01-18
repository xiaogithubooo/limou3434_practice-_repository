#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode* detectCycle(struct ListNode* head)
{
    //1.���ҵ�����ָ���������meet
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //2.��ʼ����ڵ㣬���ݹ�ʽ������ͷ���뻷��ľ���L��==�����ĳ���C��-���뻷�㵽���������X������meetָ�������ͷheadָ��ͬʱ�߶���meet��head������ʱ����ǻ�����ڵ�
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
