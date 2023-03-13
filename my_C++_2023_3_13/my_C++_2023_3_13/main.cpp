#define _CRT_SECURE_NO_WARNINGS 1
//日志：
//1、使用标准输入输出
//2、使用函数重载
//3、使用引用变量
//4、常引用
//5、内联函数

#include<iostream>
using namespace std;
//1、使用标准输入输出
int main()
{
	//int a = 0;
	//cin >> a;
	//cout << a << endl;

	double b;
	char c;
	long d;
	cin >> b;
	cout << b << endl;

	cin >> c >> d;
	cout << c << " " << d << endl;
	return 0;
}
//2、使用函数重载
void function(int a = 0)
{
	if (a == 0)
	{
		cout << "你好！！！" << endl;
	}
	else
	{
		cout << "hello!!!" << endl;
	}
}
char function(char b)
{
	cout << b << endl;
	return 1; 
}
int main()
{
	function();
	function(1);
	function('c');
	return 0;
}
//3、使用引用变量
#include <stdio.h>
int main()
{
	int a = 10;//实际变量
	int& a1 = a;//引用1
	int& a2 = a;//引用2
	printf("%d %d %d\n", a, a1, a2);
	printf("%p %p %p", &a, &a1, &a2);
	return 0;
}
//4、常引用
int main()
{
	const int a = 10;
	//int& a1 = a;
	const int& a1 = a;

	10;
	//int& b1 = 10;
	const int& b1 = 10;
	
	double c = 3.14159;
	//int& c1 = c;
	const int& c1 = c;
	return 0;
}
//5、内联函数
inline int add(int a = 0, int b = 0)
{
    return a + b;
}
int main()
{
    int c = 0;
    c = add(3, 5);
    cout << c;
    return 0;
}