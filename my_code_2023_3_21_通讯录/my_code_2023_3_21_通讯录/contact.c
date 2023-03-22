#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

int scanfNumber = 0;

void Init_Contact(Contact* pcon)
{
	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));//����ʼ����ע��sizeof�������������
}

void Add_Contact(Contact* pcon)
{
	if (pcon->sz == MAX_DATA)
	{
		printf("ͨѶ¼���ˣ��޷������洢!\n");
		return;
	}
	else//��ʼ����
	{
		printf("����������:\n");
		scanfNumber = scanf("%s", pcon->data[pcon->sz].name);

		printf("����������:\n");
		scanfNumber = scanf("%d", &(pcon->data[pcon->sz].age));

		printf("�������Ա�:\n");
		scanfNumber = scanf("%s", pcon->data[pcon->sz].sex);

		printf("������绰:\n");
		scanfNumber = scanf("%s", pcon->data[pcon->sz].tele);

		printf("�������ַ:\n");
		scanfNumber = scanf("%s", pcon->data[pcon->sz].addr);

		pcon->sz++;
		printf("��ӳɹ�!\n");
	}
}

void Show_Contact(const Contact* pcon)
{
	int i = 0;
	printf("%-10s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < (pcon->sz); i++)
	{
		printf("%-10s %-4d %-5s %-12s %-30s\n", pcon->data[i].name, pcon->data[i].age, pcon->data[i].sex, pcon->data[i].tele, pcon->data[i].addr);
	}
}

static int Find_By_Name(const Contact* pcon, char name[])//�ڲ���������������¶����磬����staticֻ���ڱ�.c�ļ�����
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (0 == strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void Dle_Contact(pContact pcon)
{
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼Ϊ0���޷�����ɾ��!\n");
		return;
	}
	//��ʼɾ��
	//1���ҵ�Ҫɾ������ϵ������
	printf("����Ҫɾ���˵�����:\n");
	char name[MAX_NAME] = { 0 };
	scanfNumber = scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����!\n");
		return;
	}
	//2����ʼ��ʽɾ����ϵ������
	//��ҪŲ�����飬����˳������szҪ--
	int i = 0;
	for (i = pos; i < pcon->sz - 1; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->sz--;
	printf("ɾ���ɹ���\n");
}

void Search_Contact(const pContact pcon)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ������ϵ�˵�����:\n");
	scanfNumber = scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����!\n");
	}
	else
	{
		printf("%-10s %-4s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s %-4d %-5s %-12s %-30s\n",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tele,
			pcon->data[pos].addr);
	}
}

void Modify_Contact(Contact* pcon)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:\n");
	scanfNumber = scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����!\n");
		return;
	}
	//��ʼ�����޸�
	printf("����������:\n");
	scanfNumber = scanf("%s", pcon->data[pos].name);

	printf("����������:\n");
	scanfNumber = scanf("%d", &(pcon->data[pos].age));

	printf("�������Ա�:\n");
	scanfNumber = scanf("%s", pcon->data[pos].sex);

	printf("������绰:\n");
	scanfNumber = scanf("%s", pcon->data[pos].tele);

	printf("�������ַ:\n");
	scanfNumber = scanf("%s", pcon->data[pos].addr);

	printf("�޸ĳɹ�!\n");
}

cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);//ע��Ҫд�������ţ�����ֻ����ʱǿ��ת��
}
void Sort_Contact(Contact* pcon)
{
	qsort(pcon->data, pcon->sz, sizeof(PeoInfo), cmp_by_name);//Ҫ��������飬Ԫ�ظ�����һ��Ԫ�ش�С
	printf("����ɹ�!\n");
}