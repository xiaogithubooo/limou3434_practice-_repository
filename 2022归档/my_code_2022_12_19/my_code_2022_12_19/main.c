#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1、研究scanf的返回值
int main()
{
	int a = 0; 
	int b = 0;
	int c = 0;
	c = scanf("%d%d", &a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", EOF);
	return 0;
}
//在我手上的《C Primer Pius》第82页谈到“scanf的返回值”有谈到这件事情
//①输入三行^z^z就会出现c=-1的情况，即返回EOF即读取到“文件结尾”；
//②如果是输入两个整形就会返回2；
//③如果是输入为非整形，例如“c、c”返回0，表示读取失败。

//2、研究了Linux的文件权限，还复习了前天学习的Linux命令

//3、依旧在发烧……真是没办法，明天再学吧，这几天学得好少