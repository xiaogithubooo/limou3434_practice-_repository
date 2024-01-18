#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1、复习switch语句的使用
int main()
{
    int b = 0;
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        printf("123\n");
    case 2:
        printf("456\n");
    case 3:
        printf("789\n");
    }
    return 0;
}
//2、复习while的使用
int main()
{
    int i = 0;
    while (i < 10)
    {
        printf("abcd\n");
        i++;
    }
    return 0;
}
//3、清空缓冲函数的使用
int main()
{
    char ch = 0;
    printf("请输入一个字符\n");
    scanf("%c", &ch);
    printf("请确认输入(Y/N)\n");
    getchar();
    if ('Y' == ch) {
        printf("确认成功\n");
    }
    else
    {
        printf("确认失败\n");
    }
    return 0;
}
//下面这个代码好像也有问题……
void empty(void)
{
    int ch = 0;
    while ((ch = getchar)!= EOF)
    {
        putchar(ch);
    }
}

int main()
{
    char ch = 0;
    printf("请输入一个字符\n");
    scanf("%c", &ch);
    printf("请确认输入(Y/N)\n");

    empty();

    getchar();
    if ('Y' == ch)
    {
        printf("确认成功\n");
    }
    else
    {
        printf("确认失败\n");
    }
    return 0;
}
//4、写一个代码打印1-100之间所有3的倍数的数字
int main()
{
	int num = 1;
	for (num = 1; num <= 100; num++)
	{
		if (0 == num % 3)
		{
			printf("%d\n", num);
		}
	}
	return 0;
}
//5、写代码将三个整数数按从大到小输出
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
//6、打印100~200之间的素数
int main()
{
	int num = 100;
	int i = 0;
	for (num = 100; num <= 200; num++)
	{
		for (i = 101; i <= num; i++)
		{
			if (num % i == 0)
			{
				break;
			}
		}
		if (num == i)
		{
			printf("%d ", num);
		}
	}
	return 0;
}
//7、求最大公约数
 //辗转相除法
int function(int a, int b) 
{
	if (a % b == 0)
	{
		return b;
	}
	return function(b, a % b);
}
int main() 
{
	int a = 20, b = 40;
	int o = scanf("%d %d", &a, &b);
	printf("%d\n", function(a, b));
	return 0;
}
//8、闰年
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0) 
		{
			if (0 != year % 100)
			{
				printf(" %d", year);
			}
		}
		if (0 == year % 400)
		{
			printf(" %d", year);
		}
	}
	return 0;
}