#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define NUMBER 20
//1�������ַ�������strcmp
int main()
{
	char arr_1[NUMBER] = "nihao biancheng";
	char arr_2[NUMBER] = "nihao bianzheng";

	printf("%d\n", strcmp(arr_1, arr_2));
	printf("%d\n", 'c' - 'z');
	return 0;
}
//2������strncmp���÷�
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
//3������strncmp���÷�
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
//4��strchar��ʹ��
int main()
{
	const char str[] = "http://www.runoob.com";
	const char ch = '.';
	char* ret;

	ret = strchr(str, ch);

	printf("|%c| ֮����ַ����� - |%s|\n", ch, ret);

	return(0);
}
//5������strpbrk���÷�
int main()
{
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "74";
    char* ret;

    ret = strpbrk(str1, str2);
    if (ret)
    {
        printf("��һ��ƥ����ַ��ǣ� %c\n", *ret);
    }
    else
    {
        printf("δ�ҵ��ַ�");
    }
    return 0;
}