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
    //1.先将链表的每两个节点插入一个节点，该节点和链表的前一个节点的val一样（注意不在开头前面插入，但是要在链表的结尾插入）
    //于是我们称这个链表存在“原节点”和“复制节点”，原节点和复制节点一一对应
    //例如“[7]->[13]->[11]->[10]->[1]->NULL”插入复制节点后变成“[7]->(7)->[13]->(13)->[11]->(11)->[10]->(10)->[1]->(1)->NULL”，其中被[]框住的是“原节点”，被()框住的是“复制节点”
    struct Node* cur = head;//用于遍历的变量
    struct Node* cache;//用于缓存变量
    while (cur != NULL)
    {
        cache = cur->next;
        struct Node* newNode = BuyNode(cur->val);
        cur->next = newNode;
        newNode->next = cache;
        cur = cache;
    }
    //2.而假设原节点的结构体成员random指向的节点a，那么复制节点的random指向的节点就是a->next
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
    //3.在把这些复制节点单独串成一个新链表返回就可以
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