#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void test_1(void)
{
	char a = 101;
	//101的二进制为0110 0101，存进char没毛病
	int sum = 200;
	//200的二进制是1100 1000，存进int没有毛病

	a += 27;
	//a发生整型提升，101+27=128，二进制为1000 0000，发生溢出（char取值[-128,127]）
	//而a的类型是有符号char，以-128的形式存储进a中

	sum += a;//200-128=72
	printf("%d\n", sum);//输出72
}

void test_2(void)
{
	int value = 1024;
	//定义一个变量value，
	//存储了1024的补码0000 0100 0000 0000，
	//小端环境高地址存储高字节位，
	//低地址----0000 0000 0100 0000----高地址

	char condition = *((char*)(&value));
	//取得value的地址，强制妆化指针类型位char*，
	//因此解引用只能读取一个字节0000，
	//因此condition变量存储补码0000

	if (condition)//此if语句不执行
		value += 1;

	condition = *((char*)(&value));
	//相对于啥也没做

	if (condition)//此if语句不执行
		value += 1;

	condition = *((char*)(&value));
	//相对于啥也没做

	printf("%d %d", value, condition);
	//打印处1024和0
}

void func_3(char para[])//这里有100和没100是一样的
{
	void* p = malloc(100);//申请了100个字节的空间
	printf("%d, %d\n", sizeof(para), sizeof(p));//输出4/8和4/8
}
void test_3(void)
{
	char arr[100];
	func_3(arr);
}

void func_4(char* p) 
{
	p = p + 1;
}
void test_4()
{
	char s[] = { '1', '2', '3', '4' };
	func_4(s);
	printf("%c", *s);//还是输出字符1
}
bool fun(int k, int n)
{
	int number = k - n;
	while (((number % 10) == 0) + ((n / 10) != 0) == 2)
	{
		number /= 10;
		n /= 10;
	}
	if (number % 10 == 0 || (n / 10) != 0)
	{
		return true;
	}
	return false;
}
void test_5(void)
{
	int n = 0;
	scanf("%d", &n);
	int flag = 0;
	while (n >= 0)
	{
		int k = n * n;
		if (fun(k, n))//是就让flag++
		{
			flag++;
		}
		n--;
	}
	printf("%d", flag);
}
int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();
}