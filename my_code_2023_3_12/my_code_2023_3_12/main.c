#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//1.ʵ��strlen
int my_strlen(const char* arr)
{
	int add = 0;
	assert(arr);//��ֹ��ָ��
	while (*arr++)
	{
		add++;
	}
	return add;
}
//2.ʵ��strcpy
char* my_strcpy(char* arr1, const char* arr2)
{
	char* chs = arr1;
	assert(arr1 && arr2);
	while (*arr2)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = *arr2;//��'\0'Ҳ������
	return chs;
}
//3��ʵ��strcmp
int my_strcmp(const char* str1,const char* str2)
{
	int a = 0;
	assert(str1 && str2);
	while ((*str1 && *str2 && (a = (*str1++) - (*str2++)) == 0));
	return a;
}
//4��ʵ��my_strcat��׷�ӣ�
char* my_strcat(char* str1,const char* str2)
{
	assert(str1 && str2);
	char* chs = str1;
	//while (*str1++);//�ҵ���һ���ַ�����'\0'
	while (*str1 != '\0')
	{
		str1++;
	}
	while (*str1++ = *str2++);
	return chs;
}
//5��ʵ��my_strstr
int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "xxxx";
	printf("%d\n", my_strlen(arr1));
	printf("%s\n", my_strcpy(arr1, arr2));
	char arr3[] = "aaaabcd";
	char arr4[] = "aaaacd";
	printf("%d\n", my_strcmp(arr3, arr4));
	char arr5[15] = "qwert";
	char arr6[] = "yuiop";
	printf("%s\n", my_strcat(arr5, arr6));
	return 0;
}