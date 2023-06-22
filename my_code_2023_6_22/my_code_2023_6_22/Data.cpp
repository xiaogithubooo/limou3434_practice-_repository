//Data.cpp内部
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
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))//一次性判断是否符合三个条件里的一个
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
	if (day < 0)//这里的if语句是为了预防加上负数的情况
	{
		return *this -= -day;
	}
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
	if (day < 0)//这里if语句也是避免减去负数的情况
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)//一个月没有0号这个说法
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Data Data::operator-(int day)
{
	Data ret(*this);
	ret -= day;
	return ret;
}
Data& Data::operator--()
{
	return *this-=1;
}
Data Data::operator--(int)
{
	Data tmp(*this);
	*this -= 1;
	return tmp;
}
int Data::operator-(const Data& d)
{
	int flag = 1;
	Data max(*this);
	Data min(d);
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n * flag;
}

//4.流运算符重载函数（不能写成成员函数，并且注意友元的问题）
ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}//这个函数也推荐写成内联函数，不过就不能声明和定义分离了
istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckData());//检查输入的合法性
	return in;
}