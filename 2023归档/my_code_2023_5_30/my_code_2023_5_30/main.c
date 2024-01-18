#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int GetMax(int number, ...)//注意：可变参数要被使用，则其前面至少有一个及以上个明确参数
{
	//使用四个宏来编写代码：va_list、va_start、va_arg、va_end
	//由于我们自己是不太可能在栈帧空间中一一找到所有临时变量对应的地址并且进行解引用，所以我们为了方便使用，C语言提供了“三个操作符”和“一个类型符”，来完成寻找临时变量的操作
	va_list arg;//1.定义一个可以访问可变参数部分的变量，其实就是一个char*类型的变量，这意味着该变量可以按照一个字节的方式访问数据 
	va_start(arg, number);//2.使arg指向可变参数部分
	int max = va_arg(arg, int);//3.根据类型大小可以获取可变参数列表中的参数数据（这里获取的是第一个int参数数据）
	for (int i = 0; i < number - 1; i++)
	{
		int x = va_arg(arg, int);//4.持续获取下一个参数
		if (max < x)
		{
			max = x;
		}
	}
	va_end(arg);//5.arg使用完毕，收尾工作，本质就是将arg指向NULL（类似free的使用，避免arg成为野指针）
	return max;
}
int main()
{
	int max = GetMax(5, 1, 2, 3, 4, 5);
	printf("%d", max);
	return 0;
}