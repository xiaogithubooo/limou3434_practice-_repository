#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//练习使用malloc和free等动态内存分配函数，以及一道题目的练习
//int main()
//{
//	int* p;
//	int i = 0;
//	printf("请输入：%d\n",i);
//	scanf("%d", &i);
//	if (i = 1)
//	{
//		p = (int*)malloc(10 * sizeof(int));//申请10个整形变量内存
//	}
//	else
//	{
//		p = (int*)malloc(INT_MAX + 1);//申请整形变量内存
//	}
//
//	if (p == NULL)//检查是否错误开辟空间
//	{
//		printf("%s\n", strerror(errno));//错误码对应的原因被打印出来
//	}
//	else//正常使用空间
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
// /////////////////////////////////////
//	{
//		free(p);//把空间还回去
//		p = NULL;//一般是一起使用的
//	}
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)//检查是否错误开辟空间
//	{
//		printf("%s\n", strerror(errno));//错误码对应的原因被打印出来
//	}
//	else//正常使用空间
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;//这里不初始化也是可以的，本身这个函数就会初始化为0，屏蔽注释掉这一个循环语句，下面就会打印出一系列的0
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);//释放动态空间
//	p = NULL;
//}

//int main()//演示一个疯狂消耗内存（堆站）的例子
//{
//	while (1)
//	{
//		malloc(1);
//		//Sleep(500);//可以慢一点消耗
//	}
//	return 0;
//}//这个程序的后果就是内存会被疯狂消耗掉
////当一个程序出现内存泄漏那将是十分恐怖的事情

//一道笔试题
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);//1、首先没有释放动态内存
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello word");
//	printf("%s\n",str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//解法1，有点小捞
//void Test(void)
//{
//	char* str = NULL;
//	str = (char*)malloc(100);
//	strcpy(str, "hello word");
//	printf("%s\n", str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//解法2，更加能够实现题目初衷
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);//1、首先没有释放动态内存
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello word");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//解法3
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello word");
//	printf("%s\n",str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
