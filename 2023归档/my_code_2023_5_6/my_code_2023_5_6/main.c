#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
struct Node* BuyNode(int x)
{
    struct Node* cache = (struct Node*)malloc(sizeof(struct Node));
    if (!cache) exit(-1);
    cache->next = cache;
    cache->random = cache;
    cache->val = x;
    return cache;
}
struct Node* copyRandomList(struct Node* head)
{
    //1.�����ָ�����
    if (!head) return NULL;

    //2.�Ȳ���˳�ſ��������γ�һ���µĴ�ͷ˫������
    //2.1.������һ��ͷ�ڵ�MyList
    struct Node* MyList = BuyNode(0);
    //2.2.����һ��headָ���cur��������Ϊ��������
    struct Node* cur = head;
    while (cur)
    {
        struct Node* newNode = BuyNode(cur->val);
        struct Node* p = MyList->random;
        MyList->random = newNode;
        p->next = newNode;
        newNode->next = MyList;
        newNode->random = p;

        cur = cur->next;
    }
    //3.�Ƚ��

    return MyList->next;
}
void test_1(void)
{
    struct Node a1;
    struct Node a2;
    struct Node a3;
    struct Node a4;
    struct Node a5;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = NULL;
    a1.val = 7;
    a2.val = 13;
    a3.val = 11;
    a4.val = 10;
    a5.val = 1;
    copyRandomList(&a1);
}

struct ListNode {
    int val;
    struct ListNode* next;
};
bool isPalindrome(struct ListNode* head)
{
    int i = 0;
    int* arr = (int*)malloc(sizeof(int) * 100000);
    if (!arr) return false;

    while (head)
    {
        arr[i] = head->val;
        i++;
        head = head->next;
    }
    int x = 0, y = i - 1;
    while (x < y)
    {
        if (arr[x] != arr[y])
            return false;
        x++;
        y--;
    }
    return true;
}
void test_2(void)
{
    struct ListNode b1;
    struct ListNode b2;
    struct ListNode b3;
    struct ListNode b4;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = NULL;
    b1.val = 1;
    b2.val = 3;
    b3.val = 3;
    b4.val = 1;

    isPalindrome(&b1);
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //�����쳣���
    if ((headA == NULL) || (headB == NULL))
    {
        return NULL;
    }

    //1.��¼��ͷ������ѭ��
    struct ListNode* A = headA;
    struct ListNode* B = headB;

    //2����ʼ����������������ͬ��ѭ��
    while (headA->next != headB->next)
    {
        headA = headA->next;//��������A�ı���
        headB = headB->next;//��������B�ı���
        if (headA == NULL)
        { 
            headA = A;
        }
        if (headB == NULL)
        {
            headB = B;
        }
    }
    if (headA == headB)//��������ĵ�һ���ڵ�����ཻ�ڵ�
    {
        return headA;
    }
    else if (headA->next != NULL)
    {
        return headA->next;
    }
    else
    {
        return NULL;
    }
}

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = NULL;
    struct ListNode* fast = NULL;
    slow = fast = head;
    struct ListNode* meet = NULL;

    struct ListNode* head_1 = head;
    struct ListNode* head_2 = NULL;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            meet = slow;
            head_2 = meet->next;
            meet->next = NULL;
            struct ListNode* p = getIntersectionNode(head_1, head_2);
            //�ָ�ԭ����
            meet->next = head_2;
            return p;
        };
    }
    return NULL;
}
int main()
{
    //test_1();
    test_2();
    return 0;
}
