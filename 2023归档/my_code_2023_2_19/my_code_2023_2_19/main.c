#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode//��������ṹ��
{
	SLTDataType data;
	struct SListNode* next;//���ﲻ�ǽṹ���׽ṹ�壬��������һ��ָ�룬ָ����һ���ṹ�塣������һ����ַ��
 }SLTNode;

//����β��ӿں���
void SListPushBack(SLTNode* phead, SLTDataType x)
{
	//1�������γ�һ�������Ľڵ㣨����ֵ�Ϳ�ָ�룩
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	// 2�������ǽ����浥���Ľڵ�����Ϊ�������β�ڵ�
	if (phead == NULL)
	{
		phead = newnode;
	}
	else
	{
		//���ҵ���ǰ����β�ڵ�Ŀ�ָ��
		SLTNode* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//�ڽ������β�ڵ��ָ�룬����Ϊָ����β�ڵ��ָ��
		tail->next = newnode;
	}
}

//����ͷ��ӿں���
void SListPushFront(SLTNode* phead, SLTDataType x)
{
	;
}

//�����ӡ��ں���
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
}

//������Ԫ���ÿսӿں���
void TestSList1()
{
	SLTNode* plist = NULL;//��ʱ�����ǿյ�
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPrint(plist);
}

//������������
int main()
{
	TestSList1();
}