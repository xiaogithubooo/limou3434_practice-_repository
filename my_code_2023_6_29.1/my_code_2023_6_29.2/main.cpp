#include <iostream>
using namespace std;
int globalVar = 1;//全局变量，存储在数据段
static int staticGlobalVar = 1;//静态全局变量，存储在数据段
void Test(void)
{
	static int staticVar = 1;//静态局部变量，存储在数据段
	int localVar = 1;//局部变量，存储在栈

	int num1[10] = { 1,2,3,4 };//多个局部变量一次性创建，整体存储在栈
	char char2[] = "abcd";//（这里实际上是把常量区得“abcd\0”拷贝给char数组）常量表达式“abcd”，存储在代码段，但是char2数组存储在栈
	const char* pChar3 = "abcd";//常量表达式，“abcd”存储在代码段，pChar3存储在栈上
	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1存储在栈上，*ptr1存储在堆上
	int* ptr2 = (int*)calloc(4, sizeof(int));//ptr2存储在栈上，*ptr2存储在堆上
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);//ptr3存储在栈上，*ptr3存储在堆上
	free(ptr1);
	free(ptr3);
}
int main()
{
	Test();
	return 0;
}