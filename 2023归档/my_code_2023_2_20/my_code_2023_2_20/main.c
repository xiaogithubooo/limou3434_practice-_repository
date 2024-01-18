#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//1、测试了栈区溢出的问题
int main()
{
	int arr[1000 * 1000];
	printf("hello word!");
	return 0;
}
//2、不使用结构体指针将结构体直接传参
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
	struct namect person;//创建了一个结构体变量

	person = getinfo();//数组和结构体最不同的地方
	person = makeinfo(person);//由于拷贝了原来的结构体，所以这里通过赋值改变了一部分的结构体
	showinfo(person);//打印结构体
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
