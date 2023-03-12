#include<iostream>
#include<stdio.h>

namespace limou3434//后面是这块命名空间的名字
{
	int print = 100;//在命名空间内定义一个变量
	int function(int n)//在命名空间内定义一个函数
	{
		return n + 1;
	}
	struct Limou//在命名空间内定义一个结构体
	{
		int a;
		char b;
		float c;
		double d;
	};
	namespace limou//在命名空间内嵌套一个命名空间
	{
		int e = 1;
		int f = 2;
		int g = 3;
	}
}
using namespace limou3434;
using namespace std;
int main()
{

	cout << print;
	return 0;
}