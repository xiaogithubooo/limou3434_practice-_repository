#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char char_arr[26] = { 0 };//�洢��a��z�ĵ����ַ�
	char ch;
	int max = 0;
	int number = 0;
	while ((ch = getchar()) != '\n')//�����뻺������ȡ�����ַ����д���
	{
		char_arr[ch - 'a']++;
		//�����ch=='a'����ô'a'-'a'==0������char_arr[0]�ϵ�0+1�������ҵ�һ��a
		//�����һ���ַ�ch=='c'����ô'c'-'a'==2������char_arr[2]�ϵ�0+1�������ҵ�һ��c
		//�����һ���ַ�ch=='a'����ô'a'-'a'==0������char_arr[0]�ϵ�1+1���������ҵ�һ��a�����ʱ��char_arr[0]�洢��һ��2������Ŀǰ�ҵ�����a
		//�Դ����ƣ�char_arr[0]�洢����a���ֵĸ�����char_arr[1]�洢����b���ֵĸ�������
	}

	for (int i = 0; i < 26; i++)
	{
		if (char_arr[i] > max)//�ҳ������д������Ԫ�أ����Ұ��������Ԫ���±��ҵ�
		{
			number = i;
			max = char_arr[i];
		}
	}

	printf("%d %c\n", char_arr[number], number + 'a');
	return 0;
}