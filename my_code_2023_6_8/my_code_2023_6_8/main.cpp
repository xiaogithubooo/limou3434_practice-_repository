#include "function.h"
////class A
////{
////public:
////	int i;
////	int j;
////public:
////	void Print(void);
////};
////void A::Print(void)
////{
////	printf("Helow word!\n");
////}
////int main()
////{
////	A* ptr = nullptr;
////	ptr->Print();
////	return 0;
////}
//
//int main()
//{
//	//Person X;
//	//X._name = "limou3434";
//	//X._age = 18;
//	//X._sex = "男";
//	//X.Print();
//
//	// 类中既有成员变量，又有成员函数
//	class A1
//	{
//	public:
//		void f1() {}
//	private:
//		int _a;
//	};
//	printf("%zd\n", sizeof(A1));
//
//	// 类中仅有成员函数
//	class A2
//	{
//	public:
//		void f2() {}
//	};
//	printf("%zd\n", sizeof(A2));
//
//	// 类中什么都没有---空类
//	class A3
//	{};
//	printf("%zd\n", sizeof(A3));
//
//	//结果为4 1 1
//	return 0;
//}
//class Data
//{
//public:
//	void Init(int year, int month, int day)//3.但是函数是这么找到实例化后变量里的_year呢？其实就是在这里的参数列表隐藏了一个this指针
//	{
//		_year = year;//2.而这里的year值并不是赋给了类里的_year，而是实例化后的d里的_year
//		_month = month;
//		_day = day;
//	}
//	void Print(void);
//private:
//	int _year;//1.没有经过实例化的类，因此这里的_year只是声明
//	int _month;
//	int _day;
//};
//void Data::Print(void)
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	Data d;
//	d.Init(2023, 6, 8);
//	d.Print();
//	return 0;
//}
//class Cl
//{
//public:
//	int x;
//	int y;
//public:
//	void Print()
//	{
//		cout << x << endl;
//	}
//};
//int main()
//{
//	Cl C;
//	C.x = C.y = 10;
//	C.Print();
//	return 0;
//}
//没有构造函数的情况
class Cl
{
public:
	Cl(int x = 1)
	{
		_x = x;
	}
public:
	int _x;
};
class Date
{
public:
	//Date(int year = 2000, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << _a1._x;
	}
private:
	Cl _a1;
	Cl _a2;
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}