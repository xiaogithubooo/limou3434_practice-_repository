#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool IsEqual(const char* s, const char* subS)
{
	//����һ��ʼ�ʹ������յ�ģʽ��
	assert(*subS != '\0');

	//һһ�Ƚ�ÿһ���ַ�
	while ((*subS != '\0') && (*s == *subS))
	{
		s++;
		subS++;

		//����ģʽ�ַ����ȴ��������Ӵ������
		if ((*subS != '\0') && (*s == '\0'))
			return false;
	}

	//���˵��ƥ����
	return *subS == '\0';
}

int BF(const char* mainS, const char* subS)
{
	int mainSSize = strlen(mainS);
	int subSSize = strlen(subS);
	int size = mainSSize - subSSize + 1;
	for (int i = 0; i < size; i++)
	{
		if (IsEqual(mainS + i, subS))
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	const char* mainS= "aaabcd"; //����
	const char* subS = "abcd"; //ģʽ��
	int index = BF(mainS, subS); //����ƥ��
	printf("%d\n", index); //�ó������ж��ڵ�����ֵ 
	return 0;
}