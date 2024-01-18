#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//# 1.��̬�����ʵ��

//>	1.1.��̬����ṹ��
#define MAXSIZE 10
typedef int ElemType;
typedef struct SLListNode
{
	ElemType data;
	int cur;
}SLListNode;
//> 1.2.��̬�����ʼ��
void InitList(SLListNode* list)
{
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		list[i].cur = i + 1;
	}
	list[MAXSIZE - 1].cur = 0;
}
//> 1.3.��̬�������
//�������������ҿ��õĽڵ㣬�ɹ��򷵻طǸ�ֵ��ʧ�ܾͷ���-1
int MallocSLL(SLListNode* list)
{
	assert(list);
	//1.ȡ��������洢�Ŀ�����������
	int index = list[0].cur;
	//2.�޸�������Ĵ�ʱ�洢�Ŀ�����������
	if (index != MAXSIZE - 1)//��������������ĩ����������ͽ���
	{
		list[0].cur = list[index].cur;//�޸�
		return index;
	}
	return -1;
}
void InsertList(SLListNode* list, ElemType x)
{
	assert(list);
	//1.�����������
	int index = MallocSLL(list);//�ҿ�������
	assert(index != -1);//����Ƿ��ҵ�
	//2.����
	list[index].data = x;
	//3.ע��ĩ�ڵ�
	if (list[MAXSIZE - 1].cur == 0)
		list[MAXSIZE - 1].cur = index;
}
//> 1.4.��̬������
int LengthList(SLListNode* list)
{
	assert(list);
	int i = list[MAXSIZE - 1].cur;
	int number = 0;
	while (i)
	{
		i = list[i].cur;
		number++;
	}
	return number;
}
//> 1.5.��̬����ɾ��
void Free(SLListNode* list, int behind)
{
	assert(list);
	list[behind].cur = list[0].cur;
	list[behind].cur = behind;
}
void DeleList(SLListNode* list, int k)
{
	assert(list);
	//1.���k����Ч��
	assert(k < 1 || k > LengthList(list));
	//2.��ʼɾ��
	int front = MAXSIZE - 1, behind = 0;//front���桰ָ��Ҫɾ���ڵ��ǰһ���ڵ�ġ�cur��behind���桰ָ��Ҫɾ���ڵ�ġ�cur
	for (int i = 0; i < k; i++)
	{
		front = list[front].cur;
	}//���front�洢���ǡ�ָ��Ҫɾ���ڵ��ǰһ���ڵ�ġ�cur
	behind = list[front].cur;//���behind�洢���ǡ�ָ��Ҫɾ���ڵ�ġ�cur
	list[front].cur = list[behind].cur;
	//3.���������ɾ���Ľڵ㣬���ҷ���������е�������������
	Free(list, behind);
}
void test_1(void)
{
	SLListNode list[MAXSIZE] = { 0 };//����һ����̬����
	InitList(list);//��ʼ��
	InsertList(list, 1);//��������
	InsertList(list, 2);//��������
	InsertList(list, 3);//��������
	InsertList(list, 4);//��������
	DeleList(list, 3);//ɾ������
}
int main()
{
	test_1();
	return 0;
}