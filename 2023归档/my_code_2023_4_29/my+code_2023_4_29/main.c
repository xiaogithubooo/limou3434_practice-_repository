#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_NUM 50
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//1.��̬����ṹ��
/*��Ҫע����ǣ�
* 1.1.��̬�����ÿһ����ЧԪ�ص�cur�洢��һ����ЧԪ�ص����������ǡ���һ����������Ԫ�ص�cur�洢��һ����������Ԫ�ص��±ꡱ�������һ����Ч����Ԫ�ص�cur�洢0����ʾû��ָ�����ݡ�
* 1.2.��̬��������һ����������Ԫ�ص�cur�洢������������ġ���һ����Ч���ݡ���������Ҳ����˵��������Ϊ�յ�ʱ������һ��Ԫ�ص�cur�洢0��
*/
typedef int ElemType;
typedef struct StaticLinkList
{
	ElemType data;//�洢����
	int cur;//�洢��һ�����������
}StaticLinkList;
//2.����������
int LitsLenght(StaticLinkList* plist)
{
	;
}
//3.��ʼ������
void InitList(StaticLinkList* plist, ElemType listNum)
{
	//1.���ָ�����Ч��
	assert(plist);
	//2.��ʼ��ʼ��
	int i = 0;
	for (i = 0; i < listNum - 1; i++)
	{
		plist[i].cur = i + 1;
	}
	plist[i].cur = 0;
}
//4.���뺯��
//4.1.���ҵ���������Ԫ�ص��±꣬����������malloc����
int MallocSLL(StaticLinkList* plist)
{
	//1.ȡ����������Ԫ�ص��±�
	int i = plist[0].cur;
	//2.�޸ĵ�һ������Ԫ�������cur��ָ���µĿ��������±�
	plist[0].cur = plist[i].cur;
	return i;
}
//4.2.�����ҵ���Ԫ����ʵ���������
void InsertList(StaticLinkList* plist, int index, ElemType x)
{
	//1.���ָ����Ч�Ժ�index�ĺϷ���
	assert(plist);
	if (index < 1 || index > LitsLenght(plist))	exit(-1);
	//2.��ʼ����Ԫ��
	int i = MallocSLL(plist);//���ҵ���������Ԫ�ص��±�
	plist[i].data = x;
}

int main()
{
	StaticLinkList list[LIST_NUM];
	InitList(list, LIST_NUM);//��ʼ��
	return 0;
}