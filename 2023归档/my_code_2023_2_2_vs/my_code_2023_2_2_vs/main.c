#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1������ָ����ַ���
int main()
{
	char* a = "hello word";
	*(a + 1) = 'E';
	printf("%s\n", a);
	printf("%s\n", "hello word");
	return 0;
}
//2������char*�Ĵ�С
int main()
{
	printf("%zd", sizeof(char*));
	return 0;
}
//3������¼�������Ƿ�ɼ�
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}
