#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//��־��
//ʵ��strstr����
char* my_strstr(const char* str1,const char* str2)
{
	assert(str1, str2);
	char* s1 = str1;
	char* s2 = str2;
	while (*str1)
	{
		s1 = str1;
		s2 = str2;
		while (*s1 != *s2)//�ҵ���һ����ȵĵط�
		{
			s1++;
			if (*s1 == '\0')//һֱ��û�ҵ���ȵĵط����ͷ��ؿ�ָ��
			{
				return NULL;
			}
		}
		char* t = s1;//���������һ����ȵĵط�
		while (*s1 == *s2)
		{
			s1++;
			s2++;
			if (*s2 == '\0')//ֱ��s2��������ȣ�˵���ҵ���
			{
				return t;
			}
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char arr_1[] = "bbbbbbbbbedcbbbbbdebbbcdbbbcdeffffff";
	char arr_2[] = "bcde";
	printf("%s\n",my_strstr(arr_1, arr_2));
	return 0;
}