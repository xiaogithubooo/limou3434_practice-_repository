#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define NUMBER 20
//1、测试字符串函数strcmp
int main()
{
	char arr_1[NUMBER] = "nihao biancheng";
	char arr_2[NUMBER] = "nihao bianzheng";

	printf("%d\n", strcmp(arr_1, arr_2));
	printf("%d\n", 'c' - 'z');
	return 0;
}
//2、查验strncmp的用法
int main()
{
	char* arr1 = "abcdef";
	char* arr2 = "ghcdef";

	if (strncmp(arr1, "ab", 1) == 0)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	return 0;
}
//3、查验strncmp的用法
int main()
{
	char* arr1 = "abcdef";
	char* arr2 = "ghcdef";

	if (strncmp(arr1, "abcd", 4) == 0)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
	return 0;
}
//4、strchar的使用
int main()
{
	const char str[] = "http://www.runoob.com";
	const char ch = '.';
	char* ret;

	ret = strchr(str, ch);

	printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);

	return(0);
}
//5、查验strpbrk的用法
int main()
{
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "74";
    char* ret;

    ret = strpbrk(str1, str2);
    if (ret)
    {
        printf("第一个匹配的字符是： %c\n", *ret);
    }
    else
    {
        printf("未找到字符");
    }
    return 0;
}