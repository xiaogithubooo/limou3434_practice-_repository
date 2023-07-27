#include <iostream>
#include <cassert>
using namespace std;
class Date
{
public:
	//获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);/*检查 month 有效性*/
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		/*
		一个年份是闰年的条件如下：
		1.如果该年份能够被4整除，但不能被100整除，则为闰年。例如：2008年、2012年等。
		2.如果该年份能够被400整除，则也是闰年。例如：2000年、2400年等。
		*/
		if (month == 2
			&& ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
			)
		{
			return 29;
		}
		return monthDays[month];
	}
	//1.全缺省的构造函数（使用了初始化列表）
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year), 
		_month(month), 
		_day(day) 
	{
		//下面是对日期对象的一种检查，避免一错再错
		if (GetMonthDay(_year, _month) < _day)
		{
			cout << "非法日期" << endl;
		}
	}
	//2.拷贝构造函数
	//d2(d1)
	Date(const Date& d)//实际上不需要自己写拷贝构造，因为日期类只需要浅拷贝即可
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//3.赋值运算符重载函数
	//d2 = d3 --> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	//4.析构函数
	~Date()
	{
		cout << "析构函数在这个日期类里面没有太大用处:~Data()" << endl;
	}
	//5.符号重载函数
	//日期+=天数重载
	Date& operator+=(int day)
	{
		_day += day;//先不管3721，直接加上就行
		int days = GetMonthDay(_year, _month);//获取这个月的天数
		while (_day > days)//如果天数是不正确的就进入循环
		{
			_month++;//天数多了就加月份
			_day -= days;//并且把天数减小一些
			if (_month == 13)//如果月份超过了就加年份
			{
				_year++;
				_month = 1;
			}
			days = GetMonthDay(_year, _month);//重新获取正确的天数
		}
		return *this;
	}
	//日期+天数运算符重载
	Date operator+(int day)
	{
		Date cache(*this);//拷贝一份原有的*this
		return cache += day;
	}
	//日期-=天数运算符重载
	Date& operator-=(int day)
	{
		_day -= day;//先不管3721，直接减去就行
		int days = GetMonthDay(_year, _month);//获取这个月的天数
		while (_day <= 0)//如果天数是不正确的就进入循环
		{
			_month--;//减去月份
			_day += days;//并且把天数增大一些
			if (_month == 0)//如果月份为0了就减去年份
			{
				_year--;
				_month = 12;
			}
			days = GetMonthDay(_year, _month);//重新获取正确的天数
		}
		return *this;
	}
	//日期-天数运算符重载
	Date operator-(int day)
	{
		Date cache(*this);//拷贝一份原有的*this
		return cache -= day;
	}
	//前置++运算符重载
	Date& operator++()
	{
		return (*this) += 1;
	}
	//后置++运算符重载
	Date operator++(int)
	{
		Date cache(*this);//拷贝一份原有的*this
		*this += 1;
		return cache;
	}
	//前置--运算符重载
	Date& operator--()
	{
		return (*this -= 1);
	}
	//后置--运算符重载
	Date operator--(int)
	{
		Date cache(*this);//拷贝一份原有的*this
		*this -= 1;
		return cache;
	}
	//>运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if(_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
	//==运算符重载
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}
	//!=运算符重载
	bool operator != (const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}
	//>=运算符重载
	bool operator >= (const Date& d)
	{
		if ((*this) > d || (*this) == d)
			return true;
		return false;
	}
	//<运算符重载
	bool operator < (const Date& d)
	{
		if ((*this) >= d)
			return false;
		return true;
	}
	//<=运算符重载
	bool operator <= (const Date& d)
	{
		if ((*this) > d)
			return false;
		return true;
	}
	//日期-日期=返回天数运算符重载
	int operator-(const Date& d)
	{
		Date cache(d);
		int flag = 0;
		while ((*this) > cache)
		{
			++cache;
			++flag;
		}
		while ((*this) < cache)
		{
			--cache;
			++flag;
		}
		return flag;
	}
	//6.打印日期类函数
	void Print(void)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test(void)
{
	Date d1;
	cout << "Data d1, d1:";
	d1.Print();
	Date d2(d1);
	cout << "Data d2(d1), d2:";
	d2.Print();
	Date d3(2000, 1, 1);
	cout << "Data d3(2000, 1, 1), d3:";
	d3.Print();

	int a = (d1 == d2);
	cout << "a = (d1 == d2), a:";
	cout << a << endl;
	int b = (d1 != d3);
	cout << "b = (d1 != d3), b:";
	cout << b << endl;

	d1 = d3;
	cout << "d1 = d3, d1:";
	d1.Print();

	int days = d1.GetMonthDay(2016, 1);
	cout << "days = d1.GetMonthDay(2016, 1), days = " << days << endl;

	d1 += 3653;
	cout << "d1 += 3653, d1:";
	d1.Print();

	d2 = d1 + 3653;
	cout << "d2 = d1 + 3653, d1:";
	d1.Print();
	cout << "d2 = d1 + 3653, d2:";
	d2.Print();

	d1 -= 3653;
	cout << "d1 -= 3653, d1:";
	d1.Print();

	d2 = d1 - 33456;
	cout << "d2 = d1 - 33456, d1:";
	d1.Print();
	cout << "d2 = d1 - 33456, d2:";
	d2.Print();

	cout << endl;
	Date d4(2023, 7, 22);

	cout << "(++d4).Print(), ++d4之前:";
	(++d4).Print();
	cout << "(++d4).Print(), ++d4之后:";
	d4.Print();

	cout << "d4++.Print(), d4++之前:";
	(d4++).Print();
	cout << "d4++.Print(), d4++之后:";
	d4.Print();

	cout << "(--d4).Print(), --d4之前:";
	(--d4).Print();
	cout << "(--d4).Print(), --d4之后:";
	d4.Print();

	cout << "(d4--).Print(), d4--之前:";
	(d4--).Print();
	cout << "(d4--).Print(), d4--之后:";
	d4.Print();

	cout << endl;
	Date d5(2016, 10, 6);
	Date d6(2016, 3, 4);
	Date d7(2010, 3, 4);
	Date d8(2010, 3, 4);
	if (d5 > d7)
	{
		cout << "d5 > d7" << endl;
	}
	if (d7 >= d8)
	{
		cout << "d7 >= d8" << endl;
	}	
	if (d5 >= d8)
	{
		cout << "d5 >= d8" << endl;
	}	
	if (d6 < d5)
	{
		cout << "d6 < d5" << endl;
	}
	if (d7 <= d8)
	{
		cout << "d7 <= d8" << endl;
	}
	if (d7 <= d6)
	{
		cout << "d7 <= d6" << endl;
	}

	cout << endl;
	Date d9(2016, 10, 6);
	Date d10(2016, 10, 4);
	cout << "d9 - d10 = " << d9 - d10 << endl;
	cout << "d10 - d9 = " << d10 - d9 << endl;
	Date d11(2016, 10, 6);
	Date d12(2023, 7, 22);
	cout << "d12 - d11 = " << d12 - d11 << endl;
	cout << "d11 - d12 = " << d11 - d12 << endl;
	Date d13(2015, 10, 6);
	Date d14(2015, 10, 6);
	cout << "d12 - d11 = " << d13 - d14 << endl;
	cout << "d11 - d12 = " << d14 - d13 << endl;
}
int main()
{
	test();
	return 0;
}