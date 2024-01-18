#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1、一段不知道哪里出错的代码
int main()
{
	char words[10];
	if (fgets(words, 10, stdin) && words[9] != '\n');
	int b = getchar();
	int a = putchar(stdout);
	puts(words);
	return 0;
}
//2、测试
int main()
{
	int word[10];
	fgets(word, 10, stdin);
	puts(word);
	return 0;
}
//3、测试
int main()
{
	char word[10];
	gets_s(word, 10);
	
	return 0;

}
//4、使用fgets的使用
#define NUMBER 10
int main()
{
	char words[NUMBER];
	while (fgets(words, NUMBER, stdin) != NULL && words[0] != '\n')//1、保证输入成功，并且第一个字符不是/n
	{
		int i = 0;
		while (words[i] != '\n' && words[i] != '\0')//2、“是字符” == “中途输入就有\n”或“输完了自动加了\0”
		{
			i++;
		}
		if (words[i] != '\n')//3、将混杂的\n改变成为\0
		{
			words[i] = '\0';
		}
		else//4、即就是结尾\0了，将后面没有读取的舍弃
		{
			while (getchar() != '\n')
			{
				;//5、或者替换成continue
			}
		}
	}
	return 0;
}
//5、s_gets函数的构建
char* s_gets(char* st, int n)//存储数组首元素地址、存储字符大小
{
	char* ret_val;//返回值
	int i = 0;//数组下标

	ret_val = fgets(st, n, stdin);
	if (ret_val)//非NULL
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
//6、测试一个代码：使用puts的经典错误
int main()
{
	char side_a[] = "Side A";
	char dont[] = { 'W', 'O', 'W', '!' };
	char side_b[] = "side B";

	puts(dont);

	return 0;
}