#define _CRT_SECURE_NO_WARNINGS 1
#include "link.h"

int main()
{
	//1.�û���������
	int len = 0;			//����ʽ�ĳ���
	int ret = 0;			//����ĳЩ����

	//1.1.������ʽ1
	printf("������ ����ʽ1 �� [��С]:\n");
	ret = scanf("%d", &len);
	if(len != 0)
		printf("������ ����ʽ1 ��ÿһ��� [ϵ��,����]��\n"
		"ϵ����������Ӣ�Ķ��Ÿ�����ÿһ���ÿո������"
		"������Ҫ����ߴε���ʹ�����:\n");
	ListNode* pl1 = ListInit();
	while (len--)
	{
		//�洢�����
		Data data = { 0,0 };
		ret = scanf("%d,%d", &data._coefficient, &data._power);
		ListPushBack(pl1, data);
	}

	//1.2.������ʽ2
	printf("������ ����ʽ2 �� [��С]:\n");
	ret = scanf("%d", &len);
	if (len != 0)
		printf("������ ����ʽ2 ��ÿһ��� [ϵ��,����]��\n"
		"ϵ����������Ӣ�Ķ��Ÿ�����ÿһ���ÿո������"
		"������Ҫ����ߴε���ʹ�����:\n");
	ListNode* pl2 = ListInit();
	while (len--)
	{
		//�洢�����
		Data data = { 0,0 };
		ret = scanf("%d,%d", &data._coefficient, &data._power);
		ListPushBack(pl2, data);
	}

	//2.��Ӳ��������ӽ��
	printf("���ʽ1:");
	ListPrint(pl1);
	printf("���ʽ2:");
	ListPrint(pl2);
	printf("���Ϊ :");
	ListPrint(AddTwoLink(pl1, pl2));

	//3.���������Դ
	ListDestory(pl1);
	ListDestory(pl2);
	return 0;
}