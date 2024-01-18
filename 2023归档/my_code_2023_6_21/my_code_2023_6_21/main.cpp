#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A(int x = 0)
	{
		_a = x;
		cout << "A(int x = 0)" << _a << endl;
	}
	A(const A& aa)
	{
		_a = aa._a;//拷贝
		cout << "A(const A& aa)->" << _a << endl;
	}
	~A()
	{
		cout << "~A()->" << _a << endl;
	}
private:
	int _a;
};
void fun0(A aa)
{
	;
}
void fun1(A& aa)
{
	;
}
A fun2(void)
{
	static A aa;
	return aa;
}
A& fun3(void)
{
	static A aa;
	return aa;
}
int main()
{
	A aa0;//使用一次构造函数
	A aa1(aa0);//使用一次拷贝构造
	fun0(aa0);//由于使用的是拷贝传值方式，所以使用一次自定义的拷贝构造函数，使用完形参后，也要使用自定义析构函数
	fun1(aa0);//由于使用的是引用传值方式，无需使用自定义的拷贝构造函数，也就无需使用自定义析构函数
	fun2();//内部构建了一个static对象aa，使用了一次构造函数。并且其返回值需要拷贝给类型为A的匿名对象返回来，所以又使用了一次自定义拷贝构造函数，并且这个匿名对象还要使用一次析构函数
	fun3();//内部再次构建一个static对象aa，使用了一次构造函数。由于使用的是引用返回，所以无需使用拷贝构造函数
	return 0;
	//最后aa0使用析构函数，aa1也使用析构函数
	//最后把两个static对象aa分别使用析构函数
}

//class A
//{
//public:
//	A(int x)
//	{
//		_a = x;
//		cout << "A():" << "aa" << _a << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << "aa" << _a << endl;
//	}
//private:
//	int _a;
//};
//A aa0(0);
//void f(void)
//{
//	static A aa1(1);
//	A aa2(2);
//	A aa3(3);
//	static A aa4(4);
//}
//int main()
//{
//	f();
//	//构造aa0
//	//构造aa1
//	//构造aa2
//	//构造aa3
//	//构造aa4
//	//析构aa3
//	//析构aa2
//	f();
//	//构造aa2
//	//构造aa3
//	//析构aa3
//	//析构aa2
//	return 0;
//}
//	//析构aa4
//	//析构aa1
//	//析构aa0

//class A
//{
//public:
//    void f1(int x)
//    {
//        _a = x;
//    }
//    void f2(A x)
//    {
//        cout << x._a << endl;//这里没有报错，说明同类的使用是不会被访问限定符限定的
//    }
//    void Prin(void)
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A x;
//    A y;
//    x.f1(2);
//    y.f1(3);
//    x.Prin();
//    y.Prin();
//    y.f2(x);
//    return 0;
//}