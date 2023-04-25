#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;
//����һ������ͷ�ڵ�
ListNode* partition_1(ListNode* pHead, int x)
{
    if (!pHead)
        return NULL;
    ListNode* pNewHead1 = NULL;//ָ��С����
    ListNode* cur1 = NULL;//����С����

    ListNode* pNewHead2 = NULL;//ָ�������
    ListNode* cur2 = NULL;//����������

    ListNode* cur = pHead;//ָ�������
    while (cur)//����������
    {
        ListNode* next = cur->next;
        if (cur->val < x)//����Ҫ��β�嵽NewHead1
        {
            if (pNewHead1 == NULL)//������1Ϊ��
            {
                cur1 = pNewHead1 = cur;
            }
            else//������Ϊ��
            {
                cur1->next = cur;
                cur1 = cur1->next;
            }
        }
        else//������Ҫ��cur->next >= x��β�嵽NewHead2
        {
            if (pNewHead2 == NULL)//������2Ϊ��
            {
                cur2 = pNewHead2 = cur;
            }
            else//������Ϊ��
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

//������������ͷ�ڵ�
ListNode* partition(ListNode* pHead, int x)
{
    ListNode* lesshead, * lesstail, * greaterhead, * greatertail;
    lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
    greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
    if (!lesshead || !greaterhead)//����Ƿ�����ɹ�
    {
        perror("malloc fail!");
        return NULL;
    }

    ListNode* cur = pHead;//��������������
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
    lesstail->next = greaterhead->next;//ע�����ڱ��ڵ�
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

//1.�ҵ��м�ڵ��ַ��ע������������Ϊż�����������м�ƫ��Ľڵ��ַ��
struct ListNode* FindFunction(struct ListNode* head)
{
    assert(head);
    struct ListNode* p1 = head, * p2 = head;//����˫ָ��
    while (p1 && p1->next)//�����ָ��û�е�β�ڵ��NULL�ͼ�����ѭ��
    {
        p1 = p1->next->next;//����p1
        p2 = p2->next;//����p2
    }
    return p2;
}
//2.��������
struct ListNode* reverseFunction(struct ListNode* middle)
{
    //����middle�ڵ�ͺ���Ľڵ㣨��������ż������Ͷ���Ӱ��������жϣ�
    struct ListNode* cur = middle;
    struct ListNode* rhead = NULL;

    while (cur)
    {
        struct ListNode* next = cur->next;

        //ͷ��
        cur->next = rhead;
        rhead = cur;
        cur = next;
    }
    return rhead;
}
//3.��ʼ����ǲ��ǻ�������
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
