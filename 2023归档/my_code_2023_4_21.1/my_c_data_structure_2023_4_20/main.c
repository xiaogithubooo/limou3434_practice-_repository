#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
//# 0.Ŀ�꣺����ͷ˫ѭ��˫����������ϰ
//>     0.1.��ϰ����ͷ˫ѭ��˫������
//			0.1.1.���¿�����ͷ˫ѭ��˫��������code
//			0.1.2.�ԡ���ͷ˫ѭ��˫���������е���
//			0.1.3.while (!(�ɹ�д������ͷ˫ѭ��˫������)) { ��ȥ������; }
//>     0.2.ʹ�á���ͷ˫ѭ��˫������˼��
//			0.2.1.ˢ�Ƽ�����ҵ����Ŀ
//			0.2.2.ˢ���۵���Ŀ
//>     0.3.׫д����ͷ˫ѭ��˫������������
//          0.3.1.д���
//          0.3.2.д����

//# 1.��ϰ����ͷ˫ѭ��˫������
//> 1.1.����ͷ˫ѭ��˫�������ṹ��
typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* prev;
}ListNode;
//> 1.2.����ڵ�ռ�
ListNode* BuyListNode(LTDataType x)
{
    ListNode* cache = (ListNode*)malloc(sizeof(ListNode));//����һ���ڵ�Ŀռ�
    if (!cache)
    {
        perror("malloc fail!");
        return NULL;
    }
    cache->data = x;
    cache->next = NULL;
    cache->prev = NULL;
    return cache;
}
//> 1.3.����һ����������ڱ��ڵ㡱
ListNode* ListInit(void)
{
    ListNode* cache = BuyListNode(0);
    if (!cache) exit(-1);

    cache->next = cache;
    cache->prev = cache;
    return cache;
}
//> 1.4.˫��������
void ListDestory(ListNode* plist)
{
    //1.��ֹ��ָ�������
    assert(plist);
    ListNode* cur = plist->next;//ѭ������
    //2.���ͷŵ�ѭ��������
    while (cur != plist)
    {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    //3.���ͷŵ��ڱ��ڵ�
    free(plist);
    plist = NULL;
}
//> 1.5.�����ӡ
void ListPrint(ListNode* plist)
{
    assert(plist);
    ListNode* cur = plist->next;//�õ�ͷ��㣬�����ڱ��ڵ�
    while (cur != plist)
    {
        printf("[%d]<->", cur->data);
        cur = cur->next;
    }
    printf("[ѭ�����ڱ����]\n");
}
//> 1.6.����β��
void ListPushBack(ListNode* plist, LTDataType x)
{
    ListNode* cache = BuyListNode(x);//����ڵ�ռ�
    if (!cache) exit(-1);

    plist->prev->next = cache;//�ҵ�ָ��β�ڵ��ָ��
    cache->prev = plist->prev;
    cache->next = plist;
    plist->prev = cache;
}
//> 1.7.����βɾ
void ListPopBack(ListNode* plist)
{
    assert(plist);//��֤���ᷢ����ָ�������
    assert(plist->next != plist);//��֤������ֻʣ���ڱ��ڵ�

    //1.���ҵ����β�ڵ㣬����������������ַ
    ListNode* tail = plist->prev;
    //2.�����������β�ڵ�
    tail->prev->next = plist;
    plist->prev = tail->prev;
    //3.�ͷű�����ľ�β�ڵ�
    free(tail);
    tail = NULL;
}
// ����ͷ��
void ListPushFront(ListNode* plist, LTDataType x);
// ����ͷɾ
void ListPopFront(ListNode* plist);
// �������
ListNode* ListFind(ListNode* plist, LTDataType x);
// ������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ����ɾ��posλ�õĽ��
void ListErase(ListNode* pos);

void test()
{
    ListNode* pl = ListInit();//����һ��ͷ�ڵ�

    //�������ͷ�����С���ɾ��ġ�
    ListPushBack(pl, 1);//β��
    ListPushBack(pl, 2);//β��
    ListPushBack(pl, 3);//β��
    ListPushBack(pl, 4);//β��
    ListPrint(pl);//��ӡ����

    ListPopBack(pl);//βɾ
    ListPopBack(pl);//βɾ
    ListPrint(pl);//��ӡ����
    ListPopBack(pl);//βɾ
    ListPrint(pl);//��ӡ����
    ListPopBack(pl);//βɾ
    ListPrint(pl);//��ӡ����
    //ListPopFront(pl);//βɾ���Ƿ���
    //ListPrint(pl);//��ӡ����

    ListPushBack(pl, 1);//β��
    ListPushBack(pl, 2);//β��
    ListPushBack(pl, 3);//β��
    ListPushBack(pl, 4);//β��
    ListPopBack(pl);//βɾ
    ListPrint(pl);//��ӡ����

    ListDestory(pl);//��������
}

//# 2.����ͷ˫ѭ��˫�������Ĳ���׫д

int main()
{
    test();
    return 0;
}