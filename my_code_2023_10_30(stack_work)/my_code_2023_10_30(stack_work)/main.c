#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <assert.h>
#include "stack.h"
#define SIZE 10000

//1.测试栈的合理性
void test();
//2.十进制转化为N进制
void conversion();

int main()
{
	//1.栈测试接口
	//test();

	//2.进制转化
	conversion();
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

//1.设置数码
const char arr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
void conversion()
{
	//2.输入数据
	int M = 0;
	int N = 0;
	printf("输入数字和进制：");
	int scanfRet = scanf("%d %d", &M, &N);//输入数字和数制
	if (N <= 0)
	{
		printf("没有该进制，输入非法\n");
		return 0;
	}
	char* number = (char*)malloc(sizeof(char) * SIZE);//最终结果存储的字符串
	int flag = 1;
	//3.提前处理负数和零的情况
	if (M < 0)
	{
		flag = -1;
		M = abs(M);
	}
	else if (M == 0)
	{
		printf("%d", 0);
		return 0;
	}

	//4.进制转换
	int i = 0;
	while (M)
	{
		number[i++] = arr[M % N];//映射插入字符
		M /= N;
	}

	//5.输出数据
	if (flag == -1)
	{
		printf("-");
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", number[j]);
	}

	//6.释放内存
	free(number);
}