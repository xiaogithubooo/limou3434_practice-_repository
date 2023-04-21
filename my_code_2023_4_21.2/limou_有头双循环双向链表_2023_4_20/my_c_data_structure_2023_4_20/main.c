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
/*
ͷ�ڵ㣺
��һ��ʵ�ʽڵ㣬ʵ�ʴ洢���ݵĽṹ�壬
�����ڱ�ʶ�������ʼλ�ã�
ͷ���ͨ�����洢��Ч���ݣ�
������Ϊ�����ʼ״̬ʱ��Ĭ��ǰ���ڵ�

�ڱ��ڵ㣺
��һ�������ڵ㣬�����洢�κ���Ч���ݣ�
��������Ϊ���ڱ���վ�������ĳ��λ���ϣ�
û���κε�ҵ����Ϣ��
����ֻ��Ϊ�˷��������Ĳ���������ĸ����ڵ㡣
�ڱ��ڵ�������������������ʵ�֣�������ߴ���Ч�ʡ�
�ڱ��ڵ�ͨ������������ڵ�������
Ҳ����˵�������������������һ����
*/
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
//> 1.3.��ʼ����������һ���������ͷ�ڵ㡱��
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
    //3.���ͷŵ�ͷ�ڵ�
    free(plist);
    plist = NULL;
}
//> 1.5.�����ӡ
void ListPrint(ListNode* plist)
{
    assert(plist);
    ListNode* cur = plist->next;//�õ���ʼ��㣬����ͷ�ڵ�
    while (cur != plist)
    {
        printf("[%d]<->", cur->data);
        cur = cur->next;
    }
    printf("[ѭ����ͷ���]\n");
}
//> 1.6.����β��
void ListPushBack(ListNode* plist, LTDataType x)
{
    assert(plist);
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
    assert(plist->next != plist);//��֤������ֻʣ��ͷ�ڵ�

    //1.���ҵ����β�ڵ㣬����������������ַ
    ListNode* tail = plist->prev;
    //2.�����������β�ڵ�
    tail->prev->next = plist;
    plist->prev = tail->prev;
    //3.�ͷű�����ľ�β�ڵ�
    free(tail);
    tail = NULL;
}
//> 1.8.����ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
    assert(plist);
    ListNode* cache = BuyListNode(x);//����ڵ�ռ�
    if (!cache) exit(-1);

    ListNode* p = plist->next;
    plist->next = cache;
    cache->next = p;
    cache->prev = plist;
    p->prev = cache;
}
//> 1.9.����ͷɾ
void ListPopFront(ListNode* plist)
{
    assert(plist);//��֤���ᷢ����ָ�������
    assert(plist->next != plist);//��֤������ֻʣ��ͷ�ڵ�

    ListNode* first = plist->next;//���ҵ�����׽ڵ㣬�����������
    plist->next = first->next;
    first->prev = plist;
    free(first);
    first = NULL;
}
//> 1.10.������ң������ҵ������ݶ�Ӧ�ṹ��ĵ�ַ��
ListNode* ListFind(ListNode* plist, LTDataType x)
{
    assert(plist);//��������ÿ�ָ��
    assert(plist->next != plist);//������ҿ�����
    ListNode* cur = plist->next;//�ҵ���һ���ڵ�
    while (cur != plist)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//> 1.11.������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);//��������ÿ�ָ��
    ListNode* cache = BuyListNode(x);//�����½ڵ�

    ListNode* p = pos->prev;
    pos->prev = cache;
    cache->next = pos;
    cache->prev = p;
    p->next = cache;
}
//> 1.12.����ɾ��posλ�õĽ��
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prev = pos->prev;
    ListNode* next = pos->next;
    prev->next = next;
    next->prev = prev;
    free(pos);
    pos = NULL;
}

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

    printf("%p\n", ListFind(pl, 1));//��������Ϊ1�Ľڵ㣬���Ҵ�ӡ��ַ
    printf("%d\n", ListFind(pl, 1)->data);//��������Ϊ1�Ľڵ㣬���Ҵ�ӡ��ָ��ָ�������
    printf("%p\n", ListFind(pl, 2));//��������Ϊ2�Ľڵ㣬���Ҵ�ӡ��ַ
    printf("%d\n", ListFind(pl, 2)->data);//��������Ϊ2�Ľڵ㣬���Ҵ�ӡ��ָ��ָ�������
    printf("%p\n", ListFind(pl, 3));//��������Ϊ3�Ľڵ㣬���Ҵ�ӡ��ַ
    printf("%d\n", ListFind(pl, 3)->data);//��������Ϊ3�Ľڵ㣬���Ҵ�ӡ��ָ��ָ�������
    printf("%p\n", ListFind(pl, 0));//��������Ϊ1�Ľڵ㣬���Ҵ�ӡ��ַ

    ListPushFront(pl, 0);//ͷ��
    ListPushFront(pl, -1);//ͷ��
    ListPushFront(pl, -2);//ͷ��
    ListPopBack(pl);//βɾ
    ListPopBack(pl);//βɾ
    ListPopBack(pl);//βɾ
    ListPrint(pl);//��ӡ����
    ListPopBack(pl);//βɾ
    ListPopBack(pl);//βɾ
    ListPopBack(pl);//βɾ
    ListPushFront(pl, -2);//ͷ��
    ListPrint(pl);//��ӡ����
    ListPopBack(pl);//βɾ

    ListPushFront(pl, 10);//ͷ��
    ListPushFront(pl, 100);//ͷ��
    ListPushFront(pl, 1000);//ͷ��
    ListPrint(pl);//��ӡ����
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPrint(pl);//��ӡ����
    //ListPopFront(pl);//ͷɾ���Ƿ���
    //ListPrint(pl);//��ӡ����

    ListPushFront(pl, 10);//ͷ��
    ListPushFront(pl, 100);//ͷ��
    ListPushFront(pl, 1000);//ͷ��
    ListPrint(pl);//��ӡ����
    ListInsert(ListFind(pl, 10), -1);//�������
    ListInsert(ListFind(pl, 100), -1);//�������
    ListInsert(ListFind(pl, 1000), -1);//�������
    ListPrint(pl);//��ӡ����
    //ListInsert(ListFind(pl, 1), -1);//������루�Ƿ���
    //ListPrint(pl);//��ӡ����
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPushFront(pl, 10);//ͷ��
    ListPrint(pl);//��ӡ����
    ListInsert(ListFind(pl, 10), -1);//�������
    ListPrint(pl);//��ӡ����

    ListPopFront(pl);//ͷɾ
    ListPopFront(pl);//ͷɾ
    ListPrint(pl);//��ӡ����
    ListPushFront(pl, 10);//ͷ��
    ListPushFront(pl, 100);//ͷ��
    ListPushFront(pl, 1000);//ͷ��
    ListPrint(pl);//��ӡ����
    ListErase(ListFind(pl, 10));//����ɾ��
    ListPrint(pl);//��ӡ����
    ListErase(ListFind(pl, 100));//����ɾ��
    ListPrint(pl);//��ӡ����
    ListErase(ListFind(pl, 1000));//����ɾ��
    ListPrint(pl);//��ӡ����
    //ListErase(ListFind(pl, 1000));//����ɾ�����Ƿ���
    //ListPrint(pl);//��ӡ����

    ListDestory(pl);//��������
}

//# 2.����ͷ˫ѭ��˫�������Ĳ���׫д

//# 3.���Դ���
int main()
{
    test();
    return 0;
}

