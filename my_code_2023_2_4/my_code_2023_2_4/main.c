#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1��һ�β�֪���������Ĵ���
int main()
{
	char words[10];
	if (fgets(words, 10, stdin) && words[9] != '\n');
	int b = getchar();
	int a = putchar(stdout);
	puts(words);
	return 0;
}
//2������
int main()
{
	int word[10];
	fgets(word, 10, stdin);
	puts(word);
	return 0;
}
//3������
int main()
{
	char word[10];
	gets_s(word, 10);
	
	return 0;

}
//4��ʹ��fgets��ʹ��
#define NUMBER 10
int main()
{
	char words[NUMBER];
	while (fgets(words, NUMBER, stdin) != NULL && words[0] != '\n')//1����֤����ɹ������ҵ�һ���ַ�����/n
	{
		int i = 0;
		while (words[i] != '\n' && words[i] != '\0')//2�������ַ��� == ����;�������\n�����������Զ�����\0��
		{
			i++;
		}
		if (words[i] != '\n')//3�������ӵ�\n�ı��Ϊ\0
		{
			words[i] = '\0';
		}
		else//4�������ǽ�β\0�ˣ�������û�ж�ȡ������
		{
			while (getchar() != '\n')
			{
				;//5�������滻��continue
			}
		}
	}
	return 0;
}
//5��s_gets�����Ĺ���
char* s_gets(char* st, int n)//�洢������Ԫ�ص�ַ���洢�ַ���С
{
	char* ret_val;//����ֵ
	int i = 0;//�����±�

	ret_val = fgets(st, n, stdin);
	if (ret_val)//��NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
		{
			st[i] == '\n';
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}
//6������һ�����룺ʹ��puts�ľ������
int main()
{
	char side_a[] = "Side A";
	char dont[] = { 'W', 'O', 'W', '!' };
	char side_b[] = "side B";

	puts(dont);

	return 0;
}