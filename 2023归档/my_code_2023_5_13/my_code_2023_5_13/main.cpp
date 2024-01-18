#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void function_1(int n)
{
	;
}
void function_2(int& n)
{
	;
}
void function_3(const int& n)
{ 
	;
}
int main()
{
	int a = 10;
	const int b = 20;

	function_1(a);
	function_1(b);
	function_1(30);

	function_2(a);
	//function_2(b);//这是不被允许的
	//function_2(30);//这是不被允许的

	function_3(a);
	function_3(b);
	function_3(30);

	return 0;
}
//int main()
//{
//    const int c = 20;//c可读不可写
//    //int& d = c;//d把c权限放大了（可读可写），这是不被允许的
//    const int& d = c;//这是允许的，属于权限平移的概念
//
//    int e = 30;
//    const int& f = e;//但是权限缩小是被允许的
//
//    int g = 1;
//    double h = g;//这里产生一个临时变量，将存储数据提升后的g，再赋予h（这里g用显式强转也不行，无论是显式还是隐式，都不会改变g本身的类型）
//    //double& i = g;//这是不被允许的，因为这里产生一个临时变量，将存储数据提升后的g，而这个临时变量具有常属性，临时变量被h引用的话发生了权限放大
//    const double& i = g;//这是被允许的，只是发生了权限平移
//
//    const double& j = 3.14;
//
//    int&& k = 10;
//    return 0;
	//int a = 10;
	//double b = 3.14;
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//return 0;
//}