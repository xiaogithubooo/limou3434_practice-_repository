#define _CRT_SECURE_NO_WARNINGS 1
//日志
//有关数组和指针的练习题
#include <stdio.h>
#include <string.h>
//1、第一题
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int* ptr = (int*)(&a + 1);//&a取出整个数组的地址，+1后跳过整个数组得到一个地址，并且强制转化为(int*)类型
    printf("%d, %d", *(a + 1), *(ptr - 1));
    //a+1是第二个元素地址，解引用得到第二个元素
    //ptr是-1得到数组的最后一个元素地址，解引用得到最后一个元素
    return 0;
}
//2、第二题
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

//已知，结构体Test类型的变量大小是20个字节
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}
//3、第三题
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x, %x", ptr1[-1], *ptr2);
	return 0;
}