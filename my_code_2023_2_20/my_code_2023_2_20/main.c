#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//1��������ջ�����������
int main()
{
	int arr[1000 * 1000];
	printf("hello word!");
	return 0;
}
//2����ʹ�ýṹ��ָ�뽫�ṹ��ֱ�Ӵ���
#define NLEN 30
struct namect
{
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

char* s_gets(char* st, int n);
struct namect getinfo(void);
struct namect makeinfo(struct namect info);
void showinfo(struct namect info);

int main()
{
	struct namect person;//������һ���ṹ�����

	person = getinfo();//����ͽṹ���ͬ�ĵط�
	person = makeinfo(person);//���ڿ�����ԭ���Ľṹ�壬��������ͨ����ֵ�ı���һ���ֵĽṹ��
	showinfo(person);//��ӡ�ṹ��
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
		return ret_val;
	}
}
struct namect getinfo(void)
{
	struct namect temp;

	printf("a\n");
	s_gets(temp.fname, NLEN);

	printf("b\n");
	s_gets(temp.lname, NLEN);

	return temp;
}
struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}
void showinfo(struct namect info)
{
	printf("%s %s %d", info.fname, info.lname, info.letters);
}
