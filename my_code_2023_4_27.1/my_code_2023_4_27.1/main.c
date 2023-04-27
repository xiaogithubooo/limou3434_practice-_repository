#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//1.����ṹ��
typedef struct listNode
{
    int val;//�ڵ�洢��ֵ
    struct listNode* next;//ָ����һ���ڵ�
    struct listNode* prev;//ָ����һ���ڵ�
    int size;//����ĳ���
}listNode;
//2.��ʼ��ѭ������
listNode* InitList(listNode* plist)
{
    //1.����ڵ㲢�ҳ�ʼ��
    listNode* cache = (listNode*)malloc(sizeof(listNode));
    if (!cache) exit(-1);
    cache->val = 0;
    cache->next = NULL;
    cache->prev = NULL;
    cache->size = 0;
    //2.����һ����ѭ����ѭ��ͷ�ڵ�
    plist = cache;
    plist->next = plist;
    plist->prev = plist;
    return plist;
}
//3.β�庯��
void PushBack(listNode* plist, int x)
{
    listNode* cache = (listNode*)malloc(sizeof(listNode));
    if (!cache) exit(-1);
    cache->val = x;
    cache->next = NULL;
    cache->prev = NULL;

    listNode* prev = plist->prev;
    plist->prev = cache;
    prev->next = cache;
    cache->next = plist;
    cache->prev = prev;

    plist->size++;
}
//4.ɾ��posָ��Ľڵ�
void DelPos(listNode* pos)
{
    listNode* prev = pos->prev;
    listNode* next = pos->next;
    prev->next = next;
    next->prev = prev;
    free(pos);
    pos = NULL;
}
int main()
{
    //1.������ӵ�����
    int N = 0;
    scanf("%d", &N);

    //2.��ʼ��ѭ������
    listNode* plist = NULL;
    plist = InitList(plist);

    //3.ѭ������ѭ������
    for (int i = 1; i <= N; i++)
    {
        PushBack(plist, i);//����β��
    }

    //4.���Ҽ�������ɾ��
    int j = 1;
    listNode* cur = plist->next;
    
    while (plist->size > 1)
    {
        listNode* next = cur->next;
        if (j == 3)
        {
            DelPos(cur);
            plist->size--;
            j = 0;
        }
        j++;
        cur = next;
        if (cur == plist)
        {
            cur = next->next;
        }
    }
    printf("%d", cur->val);
    return 0;
}

//����һ��������С�������Ķ���
int smallestEvenMultiple(int n)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % n == 0 && i % 2 == 0)
            return i;
    }
    return 0;
}
//��������������ѧ��ʽ
int smallestEvenMultiple(int n)
{
    //2���κ���ż�������Լ����2
    //2���κ������������Լ����1
    //���ݡ����Լ��*��С������==��������ˡ��ó��������
    return n % 2 == 0 ? (2 * n) / 2 : (2 * n) / 1;
}