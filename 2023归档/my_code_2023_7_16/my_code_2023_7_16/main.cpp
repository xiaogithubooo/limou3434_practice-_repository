#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void func(int a)
{
	cout << "void func(int a)" << endl;
}
void func(int a, int b = 1)
{
	cout << "void func(int a,int b)" << endl;
}
int main()
{
	func(1, 2);//调用成功
	func(1);//调用失败，重载语义模糊
	return 0;
}

// namespace limou3434//后面是这块命名空间的名字，前者namespace是命名空间的关键字
//{
//	int print = 100;//在命名空间内定义一个变量
//	int function(int n)//在命名空间内定义一个函数
//	{
//		return n + 1;
//	}
//	struct Limou//在命名空间内定义一个结构体
//	{
//		int a;
//		char b;
//		float c;
//		double d;
//	};
//	namespace limou//在命名空间内嵌套一个命名空间
//	{
//		int e = 1;
//		int f = 2;
//		int g = 3;
//	}
//}
//int main()
//{
//	printf("%d\n", limou3434::print);
//	printf("%d\n", limou3434::function(9));
//	limou3434::Limou A;
//	A.a = 100;
//	printf("%d\n", A.a);
//	printf("%d\n", limou3434::limou::e);
//	return 0;
//}