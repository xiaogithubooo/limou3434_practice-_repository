#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[101] = { 0 };
	gets(arr);
	int len = strlen(arr);

	//�����������ַ���
	reverse(arr, arr + len - 1);//����һ����Ԫ�غ�βԪ��
	//�������������
	char* cur = arr;
	while (*cur)//��֤����һ����ָ��
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		reverse(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;//�����ո񣬵�����һ������
		}
	}
	printf("%s\n", arr);
	return 0;
}