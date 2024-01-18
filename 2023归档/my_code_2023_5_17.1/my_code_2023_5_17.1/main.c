#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 100;
	int c = 50;
	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);

	printf("\n");

	int number[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		printf("&number[%d] = %p\n", i, &number[i]);
	}

	char* str1 = "hello word"; int len1 = strlen(str1); for (int i = 0; i < len1; i++) 
	{
		printf("%d", *(str1 + i));//从访问角度来看，这是先找到栈里的变量str1，使用str1的右值+i，得到一个新的地址，解引用这个地址，找到字符常量区里“hello word”第i+1个字符
	} 
	char str2[] = "hello word"; 
	int len2 = strlen(str2); 
	for(int j = 0 ; j < len2; j++) 
	{
		printf("%d", *(str2+j));//从访问角度来看，这是先找到栈里的str2指向的字符'h'，然后通过+i，访问存储在栈内的有字符构成的字符串 
	}
	return 0;
} 