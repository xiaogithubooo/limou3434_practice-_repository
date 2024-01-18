#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
//# 0.Ŀ�꣺����ͷ��ѭ��������������ϰ
//>		0.1.��ϰ����ͷ��ѭ����������
//x			0.1.1.���¿�����ͷ��ѭ������������code
//x			0.1.2.�ԡ���ͷ��ѭ�������������е���
//x			0.1.3.while (!(�ɹ�д������ͷ��ѭ����������)) { ��ȥ������; }
//>		0.2.ʹ�á���ͷ��ѭ����������˼��
//			0.2.1.ˢ�Ƽ�����ҵ����Ŀ
//				0.2.1.1.�Ƴ�����Ԫ�أ�https://leetcode.cn/problems/remove-linked-list-elements/description/
//x				0.2.1.2.��ת����https://leetcode.cn/problems/reverse-linked-list/
//				0.2.1.3.������м��㣺https://leetcode.cn/problems/middle-of-the-linked-list/
//				0.2.1.4.�����е�����k����㣺https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//				0.2.1.5.�ϲ�������������https://leetcode.cn/problems/merge-two-sorted-lists/description/
//				0.2.1.6.����ָhttps://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//				0.2.1.7.����Ļ��Ľṹ��https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//				0.2.1.8.�ཻ����https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//              0.2.1.9.������ӣ�https://leetcode.cn/problems/add-two-numbers/
//			0.2.2.ˢ���۵���Ŀ
// 
//>     0.3.д����ͷ��ѭ�����������Ĳ���

//# 1.��ϰ����ͷ��ѭ��������������ʵ�жϽӿڲ����Ƿ��Ƕ���ָ��ܼ򵥣�ֻ��Ҫ�ж��β��Ƿ���Ҫ�ڽӿں����б���ֵ���ɣ�
//> 1.0.����ͷ��ѭ�����������ṹ��
typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;
//> 1.1.��̬����һ�����
SListNode* BuySListNode(SLTDateType x)
{
    //��������һ���ڵ�
    SListNode* chche = (SListNode*)malloc(sizeof(SListNode));
    if (!chche)
    {
        perror("fail malloc");//ע��perrorֻ����malloc���ļ�������ʱ��ſ���
        return NULL;
    }
    else
    {
        //��ʼ���ýڵ�
        chche->data = x;
        chche->next = NULL;
        return chche;
    }
}
//> 1.2.����ͷ��ѭ������������ӡ
void SListPrint(SListNode* plist)
{
    SListNode* cur = plist;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
//> 1.3.����ͷ��ѭ����������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    assert(pplist);
    //��������һ���ڵ�
    SListNode* chche = BuySListNode(x);

    //��ʼβ��ڵ�
    SListNode* cur = *pplist;
    if (cur == NULL)//����ǿ�����
    {
        *pplist = chche;
    }
    else//����Ƿǿ�����
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = chche;
    }
    /*ǧ����ֱ��cur�ҵ����������NULL��Ȼ�������ӵĽڵ㸳ֵ��cur����Ϊ��һ���ڵ��next����ָ��NULL�������ǶϿ��ģ�*/
    /*��ֵ�ı����ǿ���*/
}
//> 1.4.����ͷ��ѭ������������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    //��������һ���ڵ�
    SListNode* chche = BuySListNode(x);
    chche->next = *pplist;//�����䱣֤��������������ԣ�NULL/��NULL��
    *pplist = chche;
}
//> 1.5.����ͷ��ѭ������������βɾ
void SListPopBack(SListNode** pplist)
{
    assert(pplist && *pplist);//�����ָ��Ϳ�����
    if ((*pplist)->next == NULL)//��������ֻ��һ���ڵ�����
    {
        free(*pplist);//��ѽ�������ͷ��ڴ��ˣ�����
        *pplist = NULL;
        return;
    }
    //��ʼβɾ�ڵ�
    SListNode* prev = *pplist;//��һ����һ��ʼû���뵽hhhhhh��prev��Ϊ�˼�¼��һ���ڵ�
    SListNode* cur = *pplist;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    free(cur);//�ͷŵ�β�ڵ�
    prev->next = NULL;//���¶���β�ڵ�
}
//> 1.6.����ͷ��ѭ����������ͷɾ
void SListPopFront(SListNode** pplist)
{
    assert(pplist && *pplist);
    SListNode* p = *pplist;
    *pplist = (*pplist)->next;//��������д��bug����Ϊ��->�������ȼ�Ҫ�ȡ�*����
    free(p);
}
//> 1.7.����ͷ��ѭ��������������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    assert(plist);//��֤������ָ��
    SListNode* cur = plist;
    if ((cur->next == NULL) && (cur->data == x))
    {
        return cur;
    }
    while (cur->next != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
//> 1.8.����ͷ��ѭ������������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿tips:��Ϊû�а취��ǰ���룬���ǵ��������ȱ��
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    //��������һ���ڵ�
    assert(pos);
    SListNode* chche = BuySListNode(x);
    chche->next = pos->next;
    pos->next = chche;
}
//> 1.9.����ͷ��ѭ����������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�tips:Ҳ�����ڵ����ԭ���Ҳ���ȥ
void SListEraseAfter(SListNode* pos)
{
    assert(pos && pos->next);
    SListNode* p1 = pos->next;
    SListNode* p2 = p1->next;
    pos->next = p2;
    free(p1);
}
//> 1.10.�����������
void test()
{
    SListNode* a = NULL;
    SListPushFront(&a, 100);//ͷ��
    SListPushFront(&a, 200);//ͷ��
    SListPushFront(&a, 300);//ͷ��
    SListPrint(a);//��ӡ

    SListNode* p = SListFind(a, 300);//����
    printf("%p\n", p);

    SListPopFront(&a);//ͷɾ
    SListPrint(a);//��ӡ
    SListPopFront(&a);//ͷɾ
    SListPrint(a);//��ӡ
    SListPopFront(&a);//ͷɾ
    SListPrint(a);//��ӡ
    //SListPopFront(&a);//ͷɾ��ͷɾ�˿�����
    //SListPrint(a);//��ӡ

    SListPushBack(&a, 3);//β��
    SListPushBack(&a, 2);//β��
    SListPushBack(&a, 1);//β��
    SListPushBack(&a, 0);//β��
    SListPushFront(&a, 100);//ͷ��
    SListPushFront(&a, 200);//ͷ��
    SListPushFront(&a, 300);//ͷ��
    SListPrint(a);//��ӡ

    SListPopBack(&a);//βɾ
    SListPrint(a);//��ӡ
    SListPopBack(&a);//βɾ
    SListPopBack(&a);//βɾ
    SListPopBack(&a);//βɾ
    SListPrint(a);//��ӡ
    SListPopBack(&a);//βɾ
    SListPopBack(&a);//βɾ
    SListPopBack(&a);//βɾ
    //SListPopBack(&a);//βɾ��βɾ�˿�����
    SListPrint(a);//��ӡ

    SListPushBack(&a, 3);//β��
    SListPushBack(&a, 2);//β��
    SListPushBack(&a, 1);//β��
    SListPushBack(&a, 0);//β��
    SListPushFront(&a, 100);//ͷ��
    SListPushFront(&a, 200);//ͷ��
    SListPushFront(&a, 300);//ͷ��
    SListPushFront(&a, 400);//ͷ��
    SListPrint(a);//��ӡ
    p = SListFind(a, 100);//�Ȳ��ҵõ��ڵ��ַ
    SListInsertAfter(p, 4);//�������ڵ�
    SListPrint(a);//��ӡ
    SListPopFront(&a);//ͷɾ
    SListPopBack(&a);//βɾ
    SListPopFront(&a);//ͷɾ
    SListPopBack(&a);//βɾ
    SListPopFront(&a);//ͷɾ
    SListPopBack(&a);//βɾ
    SListPopFront(&a);//ͷɾ
    SListPopBack(&a);//βɾ
    p = SListFind(a, 4);//�Ȳ��ҵõ��ڵ��ַ
    SListInsertAfter(p, 100000);//�������ڵ�
    SListPrint(a);//��ӡ
    SListPopFront(&a);//ͷɾ
    SListPopFront(&a);//ͷɾ
    SListPrint(a);//��ӡ

    SListPushBack(&a, 1);//β��
    SListPushBack(&a, 0);//β��
    SListPushFront(&a, 100);//ͷ��
    SListPushFront(&a, 200);//ͷ��
    SListPrint(a);//��ӡ
    p = SListFind(a, 200);//�Ȳ��ҵõ��ڵ��ַ
    SListEraseAfter(p);
    SListPrint(a);//��ӡ
    SListEraseAfter(p);
    SListPrint(a);//��ӡ
    SListEraseAfter(p);
    SListPrint(a);//��ӡ
}

//# 2.ʹ�á���ͷ��ѭ����������˼��
//> 2.1.�Ƴ�����Ԫ��
//����һ������������ģ��е����Ĵ��룩��
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (!head)
    {
        return NULL;
    }
    struct ListNode* cur = head;//�������������ڵ��valֵ�Ƿ񡢵���val
    struct ListNode* p = NULL;//����������
    struct ListNode* newhead = NULL;//��¼���������ʼ�ڵ�
    int flag = 0;
    while (cur)//ֱ��curΪ��
    {
        if (cur->val != val)
        {
            if (flag == 0)//��¼��һ�γ��ֵĽڵ�
            {
                newhead = cur;
                flag = 1;
            }
            //β��
            if (p == NULL)//������������
            {
                p = cur;
            }
            else//�ǿ�����
            {
                p->next = cur;
                p = p->next;
            }
        }
        cur = cur->next;
    }
    if (flag != 0)
        p->next = NULL;
    return newhead;
}
void text_1()
{
    struct ListNode p1;
    struct ListNode p2;
    struct ListNode p3;
    struct ListNode p4;
    struct ListNode p5;
    struct ListNode p6;
    struct ListNode p7;
    p1.val = 7;
    p2.val = 7;
    p3.val = 7;
    p4.val = 7;
    p5.val = 7;
    p6.val = 7;
    p7.val = 7;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;
    p6.next = &p7;
    p7.next = NULL;
    removeElements(&p1, 7);
}
//�������������Ͻ���
// 
//> 2.2.��ת����
struct ListNode* reverseList_1(struct ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = head;
    struct ListNode* p3 = head->next; 
    while(p2)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if(p3 != NULL)
        {
            p3 = p3->next;
        }
    }
    return p1;
}
struct ListNode* reverseList_2(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;

        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

//# 3.д����ͷ��ѭ�����������Ĳ���

int main()
{
    //test();
    text_1();
    return 0;
}