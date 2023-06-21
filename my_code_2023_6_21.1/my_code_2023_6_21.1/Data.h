#pragma once
#include <iostream>
using namespace std;
class Data
{
public:
	//1.构造函数（内联的构造函数）
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//2.拷贝构造函数（使用默认的即可）
	
	//3.赋值运算符重载函数
	//3.1.写法1（可以是可以，但是不支持连续赋值）
	//void operator=(const Data& d)
	//{
	//	//this指向的是“=”前面的操作数，d是“=”后面的操作是
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	//3.2.写法2（允许连续赋值）
	Data& operator=(const Data& d)
	{
		//this指向的是“=”前面的操作数，d是“=”后面的操作是
		if(this != &d)//用地址值判断比较好
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//4.比较运算符重载函数，只需要写“>、==”和“<、==”的即可，可以不断复用到其他比较运算符重载函数
	bool operator==(const Data& d);
	bool operator!=(const Data& d);
	bool operator>(const Data& d);
	bool operator>=(const Data& d);
	bool operator<(const Data& d);
	bool operator<=(const Data& d);

	//5.加法与加法赋值运算符重载函数
	Data& operator+=(int day);
	Data operator+(int day);
	//Data& operator++(int day);//直接这么重载“++”是没有办法区分前置和后置的，因此C++提供了重载区分
	Data& operator++();//前置++
	Data operator++(int);//后置++，重载增加一个int参数和前面的前置++构成函数重载进行区分

	//6.减法与减法赋值运算符重载函数
	Data& operator-=(int day);
	Data operator-(int day);
	//Data& operator--(int day);//直接这么重载“--”是没有办法区分前置和后置的，因此C++提供了重载区分
	Data& operator--();
	Data operator--(int);
	int operator-(const Data& d);
public: 
	//7.打印函数
	void Print(void)
	{
		cout << _year << ":" << _month << ":" << _day << endl;
	}

	//8.获取某年某月的天数函数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//静态数组会提高效率，不必重复开辟空间来使用
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
private:
	int _year;
	int _month;
	int _day;
};