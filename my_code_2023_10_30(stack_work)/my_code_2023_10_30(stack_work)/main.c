#include "stack.h"

//1.测试栈的合理性
void test();
//2.十进制转化为N进制
void 
int main()
{
	//test();
	//
	return 0;
}


void test()
{
	Stack st1;//创建一个栈结构体
	StackInit(&st1);//初始化这个栈
	StackPush(&st1, 1);//压栈
	StackPush(&st1, 2);//压栈
	StackPush(&st1, 3);//压栈
	StackPush(&st1, 4);//压栈
	StackPush(&st1, 5);//压栈

	printf("<栈顶>\n");
	while (!StackEmpty(&st1))//只要栈不为空就进入循环
	{
		printf("%3d\n", StackTop(&st1));//取出栈顶元素并且打印
		StackPop(&st1);//删除栈顶元素
	}
	printf("<栈底>\n");
	//StackPop(&st1);//非法删除
	//StackPop(&st1);//非法取栈顶元素
	StackDestroy(&st1);//销毁栈结构体
}