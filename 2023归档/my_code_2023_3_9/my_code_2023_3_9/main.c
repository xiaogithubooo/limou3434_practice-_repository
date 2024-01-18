#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//日志：
//1、题目一，这个题目印刷有问题
//2、题目二，运算符题目
//3、题目三，运算符题目
//4、题目四，结构体题目
//5、题目五，水仙花数的实现

//1、题目一，这个题目印刷有问题
//int main()
//{
//	int x = 5;
//	x += x *= x + 1;//x *= 6后得到36，x += 36得到72
//	if (a > 10)
//	{
//
//	}
//	return 0;
//}
//2、题目二
int main()
{
	//int x[10] = { 1,2,3,4,5,6,7,8,9,10 }, *p = &x[2], y;
	//y = p[4];
	//等价于以下代码
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };//创建了一个int数组
	int* p = &x[2];//x[2]是第三个元素，取出第三个元素地址赋给p，地址类型是int*
	int y;//定义了一个int变量，没有进行初始化
	y = p[4];//p[4]等价于*(p+4)，由于p原本存储的是第三个元素的地址，所以+4跳过4个字节，因此p+4得到第七个元素地址，再解引用得到第七个元素的值，即7

	//此外可以测试y的值是不是数组的第七个元素，即7
	printf("%d", y);
	return 0;
}
//3、题目三
int main()
{
	int x = 1, y = 2, z = 0;
	//printf("%d\n", (!z++));
	//逻辑非!的优先级低于++，先进行++的效果，但是由于是后置++，++的效果就表现在先用z
	//因此!z++的值是1
	printf("%d\n", x || y && z);
	//等价于(x || (y && z))==(x || 0)==1
	return 0;
}
//4、题目四
int main()
{
	struct a
	{
		int x;
		char y[4];
		float z;
	};
	//一种朴素的想法当然是4+4+4啦，但是肯定不对……
	//不信你看这个程序
	printf("%zd\n", sizeof(struct a));
	//输出的也是12啊，怎么不对了？是的，不对，这个只是巧合，因为成员刚好大小都是4个字节，这与放了三个int成员没有太大区别
	//但是如果是不同的就涉及到结构体内存对齐的问题了
	//假设我们将结构体内部成员换一下，存在一个char类型的成员
	struct b
	{
		char i;
		int x;
		char y[4];
		float z;
	};
	//按照直接加的逻辑，就是1+4+4+4==13
	printf("%zd\n", sizeof(struct b));
	//你会发现结果是16！

	//如果可以系统了解一下结构体对齐的知识吧，需要的话我可以发个链接给你
	//但是这道题比较简单，因为结构体成员的类型都是4个字节，直接简单相加得到的结果确实是对的，都是理解方式是有问题的！！
	return 0;
}
//5、题目五
int function1(int number)//计算数字有几位数的函数
{
	int i = 0;
	while (number)
	{
		number % 10;
		number /= 10;
		i++;
	}
	return i;
}
int function2(int n, int number)//计算阶乘的函数
{
	if (number == 0 && n != 0)
	{
		return 0;
	}
	int add = 1;
	while (n)
	{
		add *= number;
		n--;
	}
	return add;
}
int main()
{
	int number = 0;//存储一个数字
	int accumulate = 0;//存储最后的结果
	scanf("%d", &number);//输入一个数
	int num = number;//记下这个输入的数字
	int n = function1(num);//计算出输入数字的位数
	while (num)
	{
		accumulate += function2(n, num % 10);
		num /= 10;
	}
	if (accumulate == number)
	{
		printf("%d是水仙花数\n", number);
	}
	else
	{
		printf("不是\n");
	}
	return 0;
}