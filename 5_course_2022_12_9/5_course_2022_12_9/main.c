#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//关于堆区、栈区、动态区的“坑爹”的用法
//char* GetMemory(void)
//{
//	char p[] = "heiio word";
//	return p;
//	//虽然被返回p了，但是p被销毁了，非法访问内存的现象，把空间还回去了（并且内部的值重新被变成随机值）又被找回来了…
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}//返回栈空间的地址的问题，栈空间的地址不要随便返回！！盲目返回，谁去用它，改成什么都是未知的，也可能篡改别的变量存放的值

//int* test()
//{
//	int a = 10;//栈区，但是如果在旁边加上一个关键字static那就没有问题，a就不在栈区而在静态区了
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;//解引用了一块非法栈区，并且VS2022编译器没法检测出来
//	return 0;
//}

//int* test()
//{
//	int* ptr = malloc(100);//开辟了一块100字节的空间，并且将空间的首地址赋给ptr，方便找到该空间
//	return ptr;//返回了这个空间的值，但是ptr变量被销毁，只记住了地址，然而这个空间开辟在堆区，只要不还给系统，这个空间就依旧存在，故这种写法就可以
//}
//int main()
//{
//	int* p = test();
//	return 0;
//}
//因此区分C语言角度的三区：栈区、堆区、动态区是很重要的我！

//另外；
//int*ptr;
//*ptr=10;这就是//就是使用了野指针的问题