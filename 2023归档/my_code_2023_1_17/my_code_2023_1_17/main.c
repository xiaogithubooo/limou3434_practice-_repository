#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1������һ�δ���
int main()
{
	char ch[80] = "123abcdEFG*&";
	int j;
	puts(ch);
	for (j = 0; ch[j] != '\0'; j++)
		if (ch[j] >= 'A' && ch[j] <= 'Z')
			ch[j] = ch[j] + 'e' - 'E';
	puts(ch);
	return 0;
}
//2�����Եڶ��δ���
#include <stdio.h>
int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
			ch = ch - 'a' + 'A';
		putchar(ch);
	}
	printf("\n");
	return 0;
}
//3�����Ե����δ���
void print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}
int main()
{
	char str[] = "Geneius";
	print(str);
	return 0;
}
//4�����Ե��Ķδ���
int fun(int x)
{
	return (x == 1) ? 1 : (x + fun(x - 1));
}
int main()
{
	printf("%d", fun(10));
	return 0;
}
