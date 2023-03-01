#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[101] = { 0 };
	gets(arr);
	int len = strlen(arr);

	//①逆序整个字符串
	reverse(arr, arr + len - 1);//传入一个首元素和尾元素
	//②逆序各个单词
	char* cur = arr;
	while (*cur)//保证不是一个空指针
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		reverse(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;//跳过空格，到达下一个单词
		}
	}
	printf("%s\n", arr);
	return 0;
}