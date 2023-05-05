#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
//> ���۵�һ��
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
//> ���۵ڶ���
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //�����������
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    else if (headA == headB)
    {
        return headA;
    }
    //�ֱ���㳤�ȣ�˳�������һ���ڵ��Ƿ�һ��
    int sizeA = 0;
    int sizeB = 0;
    struct ListNode* A = ListSizefunction(headA, &sizeA);
    struct ListNode* B = ListSizefunction(headB, &sizeB);
    if (A != B)  return NULL;
    //�ó�������i��
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
    //��ʼͬʱ��
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
//> ���۵�����
struct ListNode* middleNode(struct ListNode* head, int* number)
{
    struct ListNode* fast = head;//��ָ��
    struct ListNode* slow = head;//��ָ��

    while (fast && fast->next)//ע�����ﲻ��д��fast->next && fast��������д��Ŀ�������ö�·ЧӦ��ֹ��ָ�������
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
    else if (head->next == NULL)//ֻ��һ���ڵ�����
    {
        return true;
    }
    //���������һ����Я�������������������Ľڵ�

    //1.��ת����
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
    //2.��ʼ�Ƚ��ж�
    //�������˵�head��cache0��ʼ�Ƚ�
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