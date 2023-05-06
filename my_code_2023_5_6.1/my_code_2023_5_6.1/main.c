#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
struct Node 
{
    int val;
    struct Node *next;
    struct Node *random;
};
 
struct Node* BuyNode(int x)
{
    struct Node* cache = (struct Node*)malloc(sizeof(struct Node));
    if (!cache) exit(-1);

    cache->next = cache;
    cache->random = NULL;
    cache->val = x;

    return cache;
}
struct Node* copyRandomList(struct Node* head)
{
    assert(head);
    //1.�Ƚ������ÿ�����ڵ����һ���ڵ㣬�ýڵ�������ǰһ���ڵ��valһ����ע�ⲻ�ڿ�ͷǰ����룬����Ҫ������Ľ�β���룩
    //�������ǳ����������ڡ�ԭ�ڵ㡱�͡����ƽڵ㡱��ԭ�ڵ�͸��ƽڵ�һһ��Ӧ
    //���硰[7]->[13]->[11]->[10]->[1]->NULL�����븴�ƽڵ���ɡ�[7]->(7)->[13]->(13)->[11]->(11)->[10]->(10)->[1]->(1)->NULL�������б�[]��ס���ǡ�ԭ�ڵ㡱����()��ס���ǡ����ƽڵ㡱
    struct Node* cur = head;//���ڱ����ı���
    struct Node* cache;//���ڻ������
    while (cur != NULL)
    {
        cache = cur->next;
        struct Node* newNode = BuyNode(cur->val);
        cur->next = newNode;
        newNode->next = cache;
        cur = cache;
    }
    //2.������ԭ�ڵ�Ľṹ���Աrandomָ��Ľڵ�a����ô���ƽڵ��randomָ��Ľڵ����a->next
    cur = head;
    struct Node* newListCur = BuyNode(0);
    struct Node* newhead = newListCur;
    while (cur != NULL)
    {
        cache = cur->random;
        cur = cur->next;
        if (cache != NULL)
        {
            cur->random = cache->next;
        }
        else
        {
            cur->random = NULL;
        }
        newListCur->next = cur;
        newListCur = newListCur->next;
        cur = cur->next;
    }
    //3.�ڰ���Щ���ƽڵ㵥������һ���������ؾͿ���
    return newhead->next;
}
int main()
{
    struct Node a1;
    struct Node a2;
    struct Node a3;
    struct Node a4;
    struct Node a5;
    a1.val = 7;
    a2.val = 13;
    a3.val = 11;
    a4.val = 10;
    a5.val = 1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = NULL;
    a1.random = NULL;
    a2.random = &a1;
    a3.random = &a5;
    a4.random = &a3;
    a5.random = &a1;
    copyRandomList(&a1);
    return 0;
}