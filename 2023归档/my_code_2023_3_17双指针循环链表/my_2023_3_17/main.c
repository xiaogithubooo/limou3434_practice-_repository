#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int ListDataType;
typedef struct ListNode
{
	struct ListNode* next;//���ָ��
	struct ListNode* prev;//ǰ��ָ��
	ListDataType data;
}ListNode;

//1������ڵ�ռ�ӿں���
ListNode* Buy_List_Node(ListDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//2����ʼ���ڵ�ӿں���
ListNode* List_Init(void)
{
	ListNode* phead = Buy_List_Node(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;//����ָ�������ʼ���ڵ�ĵ�ַ
}

//3��β��ӿں���
void List_Push_Back(ListNode* phead, ListDataType x)
{
	assert(phead);//��ָ֤�����Ч��

	ListNode* tail = phead->prev;//ֱ���ҵ�β�ڵ�

	ListNode* newnode = Buy_List_Node(x);//�ȴ���һ���½ڵ�ռ�

	tail->next = newnode;//ͨ���ĸ��������Ӻ��µĽڵ���������������Ҳ���Կ���newnode���Ǹ�����βΣ����Ǹ����β�ָ��Ľڵ�ĳ�Ա����˲���Ҫ��ͷ�������ָ��
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//4��ͷ��ӿں���
void List_Push_Front(ListNode* phead, ListDataType x)
{
	assert(phead);//��ָ֤�����Ч��
	
	ListNode* first = phead->next;//����ָ��ͷ�ڵ��ָ�룬���û��������ڽ����ڵ�ָ���ʱ���Ҫע��ı��˳��

	ListNode* newnode = Buy_List_Node(x);//����һ���½ڵ㣬׼�������ͷ�ڵ�

	//�ı�ڵ���ָ�룬ʹ�½ڵ���ͷ���
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

//5��βɾ�ӿں���
void List_Pop_Back(ListNode* phead)
{
	assert(phead);//��ָ֤�����Ч��
	assert(phead->next != phead);//ȷ�������ͷŵ��ڱ��ڵ�

	//�ı�ڵ���ָ�룬ʹһ���ڵ㱻����
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;

	//��������Ľڵ��ͷſռ䣬�����ÿ�
	free(tail);
	tail = NULL;
}

//6��ͷɾ�ӿں���
void List_Pop_Front(ListNode* phead)
{
	assert(phead);//��ָ֤�����Ч��
	assert(phead->next != phead);//ȷ�������ͷŵ��ڱ��ڵ�

	//�ı�ڵ���ָ�룬ʹһ���ڵ㱻����
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	//��������Ľڵ��ͷſռ䣬�����ÿ�
	free(first);
	first = NULL;
}

//7�����ҽӿں��������絽pos��������ӿں���ͬʱҲ���������޸�ĳ���ڵ������
ListNode* List_Find(ListNode* phead, ListDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;//Ҳ���Գ��Ե�����
	}
	return NULL;
}

//8���������ӿں�������posǰ���룩
void List_Insert(ListNode* pos, ListDataType x)
{
	assert(pos);//��ָ֤����Ч��

	ListNode* prev = pos->prev;
	ListNode* newnode = Buy_List_Node(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//9������ɾ���ӿں�������posɾ����
void List_Erase(ListNode* pos)
{
	assert(pos);//��ָ֤����Ч��
	assert(pos->next != pos);//ȷ�������ͷŵ��ڱ��ڵ�

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

//10���пսӿں������Ƿ�ֻ���ڱ��ڵ㣬�Ƚϼ򵥣�ֻ��Ҫ�ж��Ƿ�ָ���Լ����У����Ǽǵ�Ҫ��ͷ�ļ�stdbool.h����ʹ��boolֵ��
//bool ListEmpty(ListNode* phead)

//11��size�ӿں������ж�����Ĵ�С��Ҳ�Ƚϼ򵥣�
//int ListSize(ListNode* phead)

//12����ӡ�ӿں���
void List_Print(ListNode* phead)
{
	assert(phead);//��ָ֤�����Ч��

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("|%+2d|<->", cur->data);
		cur = cur->next;
	}
	printf("ѭ������ͷ\n");
}

//13����������ӿں���
void List_Destory(ListNode* phead)
{
	assert(phead);//��ָ֤�����Ч��

	//1�����ٽڵ�
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	//2�������ڱ��ڵ�
	free(phead);
	phead = NULL;
}

//���Ժ���
void Test_List()
{
	//1����ʼ��ͷ���
	ListNode* plist = List_Init();

	//2������β�ڵ�
	List_Push_Back(plist, 1);
	List_Push_Back(plist, 2);
	List_Push_Back(plist, 3);
	List_Push_Back(plist, 4);
	List_Print(plist);

	//3������ͷ�ڵ�
	List_Push_Front(plist, 0);
	List_Push_Front(plist, -1);
	List_Push_Front(plist, -2);
	List_Push_Front(plist, -3);
	List_Print(plist);

	//4��βɾ�ڵ�
	List_Pop_Back(plist);
	List_Print(plist);

	//5��ͷɾ�ڵ�
	List_Pop_Front(plist);
	List_Print(plist);

	//6������ĳ���ڵ�
	ListNode* pos = List_Find(plist, 1);
	if (pos != NULL)
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}
	pos = List_Find(plist, 0);
	if (pos != NULL)
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}
	pos = List_Find(plist, 100);
	if (pos != NULL)
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}

	//7���������ӿں���
	List_Insert(List_Find(plist, 1), 100);
	List_Insert(List_Find(plist, 0), 200);
	List_Print(plist);

	//8������ɾ���ӿں���
	List_Erase(List_Find(plist, 1));
	List_Erase(List_Find(plist, 0));
	List_Print(plist);

	//9������������
	List_Destory(plist);
}

int main()
{
	Test_List();
	return 0;
}