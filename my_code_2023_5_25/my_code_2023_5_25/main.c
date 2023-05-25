#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
int g_value_2; 
int g_value_1 = 10; 
int main() 
{
	printf("code addr: %p\n", main);//代码区
	printf("\n"); 
	const char *str = "hello word!";
	//注意“hello word!”是存储在静态数据区（字符常量区）的，
	//而str变量的空间开辟在栈上，
	//但是str这个指针变量保存的是处于静态数据区内的“hello word!”里'h'的地址，
	//故打印str就是打印静态数据区的地址 
	printf("read only addr: %p\n", str);//静态区
	printf("\n"); 
	printf("init g_value_1 global addr: %p\n", &g_value_1);//已初始化全局变量区
	printf("uninit g_value_2 global addr: %p\n", &g_value_2);//未初始化全局变量区
	printf("\n"); 
	int *p = (int*)malloc(sizeof(int) * 10);
	printf("heap addr: %p\n", p);//堆区
	printf("\n"); 
	printf("stack addr: %p\n", &str);//栈区
	printf("stack addr: %p\n", &p); 
	printf("\n"); 
	free(p); 
	return 0; 
}