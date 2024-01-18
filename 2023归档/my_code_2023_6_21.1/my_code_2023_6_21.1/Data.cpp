#define _CRT_SECURE_NO_WARNINGS 1、
#include "Data.h"
//1.比较运算符重载函数
bool Data::operator==(const Data& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);//这里复用了前面的“==”重载函数
}
bool Data::operator>(const Data& d)
{
	if ((_year > d._year)
		||(_year == d._year && _month > d._month)
		||(_year == d._year && _month == d._month && _day > d._day))//一次性判断是否符合三个条件里的一个
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Data::operator>=(const Data& d)
{
	return (*this == d) || (*this > d);
}
bool Data::operator<(const Data& d)
{
	return !(*this >= d);
}
bool Data::operator<=(const Data& d)
{
	return !(*this > d);
}

//2.加法与加法赋值运算符重载
Data& Data::operator+=(int day)//需要支持连续的“+=”所以有返回值
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Data Data::operator+(int day)
{
	Data ret(*this);//也可以写Data ret = *this;
	ret += day;//复用了前面的“+=”重载函数
	return ret;//注意不能使用引用返回，这里是局部变量
}
Data& Data::operator++()
{
	return *this += 1;
}
Data Data::operator++(int)
{
	Data tmp(*this);
	*this += 1;
	return tmp;
}

//3.减法与减法赋值运算符重载函数
Data& Data::operator-=(int day)
{
	;
}
Data Data::operator-(int day)
{
	;
}
Data& Data::operator--()
{
	;
}
Data Data::operator--(int)
{
	;
}
int Data::operator-(const Data& d)
{
	;
}
