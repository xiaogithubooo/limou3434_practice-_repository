#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Time
{
public:
	//1.构造函数
	Time(int x = 2000, int y = 1, int z = 1)
	{
		_year = x;
		_month = y;
		_day = z;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//2.运算符重载函数
	int operator-(Time* const this, Time x)
	{
		return this->_year - x._year;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Time A;
	A.Print();
	Time B(2023, 1, 1);
	B.Print();
	Time C = (&B - A);
	C.Print();
	return 0;
}

//using namespace std;
//class Data1
//{
//public:
//	//1.构造函数
//	Data1(int x = 1, int y = 1)
//	{
//		_x = x;
//		_y = y;
//		cout << "Data()" << endl;
//		int* cache = (int*)malloc(sizeof(int) * 4);
//		if (!cache) exit(-1);
//		_arr = cache;
//	}
//	//2.析构函数
//	~Data1()
//	{
//		cout << "~Data1()" << endl;
//		free(_arr);
//		_arr = nullptr;
//		_x = _y = 0;
//	}
//	//3.拷贝构造函数
//	Data1(const Data1& d)
//	{
//		_x = d._x;
//		_y = d._y;
//		int* cache = (int*)malloc(sizeof(int) * 4);
//		if (!cache) exit(-1);
//		memcpy(cache, d._arr, sizeof(int) * 4);
//		_arr = cache;
//	}
//	//4.其他接口
//	void Print(void);
//	int Add(void);
//	void ForPrint(void);
//public:
//	int _x;
//	int _y;
//	int* _arr;
//};
//class Data2
//{
//public:
//	void Print(void)
//	{
//		cout << _data1._x << " " << _data1._y << endl;
//		cout << _data3 << " " << _data4 << endl;
//	}
//	void Fun(int x, int y)
//	{
//		_data1._x = x;
//		_data1._y = y;
//		_data3 = 100000;
//		_data4 = 'X';
//	}
//public:
//	Data1 _data1;
//	Data1 _data2;
//	int _data3 = 0;
//	char _data4 = 'a';
//};
//void test(void)
//{
//	Data2 H;
//	H.Print();
//	cout << endl;
//	H.Fun(100000, 100000);
//	H.Print();
//	cout << endl;
//	Data2 I(H);
//	//这一步拷贝，使用的是编译器自动给出的默认拷贝构造函数。
//	//对于内置类型会自己进行拷贝，没必要我们写出来
//	//对于自定义类型则会回去调用自定义类型的拷贝函数
//	I.Print();
//}
//int main()
//{
//	test();
//	return 0;
//}
//void Data1::Print(void)
//{
//	printf("%d %d\n", _x, _y);
//}
//int Data1::Add(void)
//{
//	return _x + _y;
//}
//void Data1::ForPrint(void)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		_arr[i] = i * i;
//		printf("%d ", _arr[i]);
//	}
//	printf("\n");
//}

//Data1 E(2, 3);
//E.Print();
//printf("%d\n", E.Add());
////方法一：兼容C的一种拷贝方法
//Data1 F = E;
//E.Print();
////方法二：使用类的拷贝构造函数
//Data1 G(E);
//G.Print();
//Data2 D;
//cout << D._a._arr;//这个arr就会被默认的析构函数清理，因为_a的数据类型书自定义类型，拥有自己的析构函数，默认的析构函数去调用了这个自定义的析构函数
//cout << D._d;//这里_d就不会被默认的析构函数释放掉，因为其是内置类型，因此造成了内存泄露
//Data1 C;
//C.Print();
//printf("%d\n", C.Add());
//C.ForPrint();
//Data1 A(2, 3);
//A.Print();
//cout << A.Add() << endl;
//Data2 B;
//B.Print();