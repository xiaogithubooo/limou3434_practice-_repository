#include <iostream>
#include <cassert>
using namespace std;
class Date
{
public:
	//获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		const static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//这个静态的编写是因为GetMonthDay有可能会被频繁调用，那么monthDays数组就会不断的被创建，虽然这点消耗挺小，但是如果加上静态关键字，这个数组就会一直存在，不会被反复创建，节省资源。
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
		if ((_month < 1) || (_month > 12) 
			|| _day < 1 || (GetMonthDay(_year, _month) < _day))//检查日期是否非法
		{
			cout << "非法日期：";
			Print();
			cout << endl;
			//exit(-1);
		}
	}
	//2.拷贝构造函数
	//d2(d1)
	//Date(const Date& d)//实际上不用自己写
	//{
		//_year = d._year;
		//_month = d._month;
		//_day = d._day;
	//}
	//3.赋值运算符重载函数
	//d2 = d3 --> d2.operator=(&d2, d3)
	//Date& operator=(const Date& d)
	//{
	//	if (this != &d) 
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;//处理自我赋值的情况
	//}
	//4.析构函数
	//~Date()
	//{
	//	cout << "析构函数在这个日期类里面没有太大用处:~Data()" << endl;
	//}
	//5.符号重载函数
	//日期+=天数重载
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);
		}
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
		if (day < 0)
		{
			return *this += (-day);
		}
		_day -= day;//先不管3721，直接减去就行
		while (_day <= 0)//如果天数是不正确的就进入循环
		{
			_month--;//减去月份
			if (_month == 0)//如果月份为0了就减去年份，并且重置月份
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);//重新获取正确的天数
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
	Date operator++(int)//展开为Date& operator++(const Date* this, int x)，这里的x会自动传值为0或者其他数，只要编译器能够识别即可，反正接受了也没在函数内使用没有影响，只是做一个区分
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
		else if (_year == d._year)
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
		//以下方法一、二是本质是没什么区别的，但是方法一返回的是正数，方法二返回的数带有符号
		//1.方法一
		//Date cache(d);
		//int flag = 0;
		//while ((*this) > cache)
		//{
		//	++cache;
		//	++flag;
		//}
		//while ((*this) < cache)
		//{
		//	--cache;
		//	++flag;
		//}
		//return flag;

		//2.方法二
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (*this < d)
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
	//1.检测合法性是否成立
	cout << "1.检测合法性是否成立" << endl;
	Date d0(2023, 2, 31);

	//2.检测构造函数的运行
	cout << "2.检测构造函数的运行" << endl;
	Date d1;
	cout << "Data d1, d1:";
	d1.Print();
	cout << endl;
	
	//3.检测拷贝构造函数和赋值重载函数
	cout << "3.检测拷贝构造函数和赋值重载函数" << endl;
	Date d2(d1);
	cout << "Data d2(d1), d2:";
	d2.Print();
	Date d3(2000, 1, 1);
	cout << "Data d3(2000, 1, 1), d3:";
	d3.Print();
	d2 = d3;
	cout << "d2 = d3" << endl;
	cout << "d2 = ";
	d2.Print();
	cout << "d3 = ";
	d3.Print();
	cout << endl;

	//4.检测逻辑运算符
	cout << "4.检测逻辑运算符" << endl;
	int a = (d1 == d2);
	cout << "int a = (d1 == d2), a:";
	cout << a << endl;
	int b = (d1 != d3);
	cout << "int b = (d1 != d3), b:";
	cout << b << endl  << endl;

	//5.检测算术运算符
	cout << "5.检测算术运算符" << endl;
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

	//6.检测逻辑运算符
	cout << "6.检测逻辑运算符" << endl;
	Date d5(2016, 10, 6);
	Date d6(2016, 3, 4);
	Date d7(2010, 3, 4);
	Date d8(2010, 3, 4);
	cout << "d5 = ";
	d5.Print();
	cout << "d6 = ";
	d6.Print();
	cout << "d7 = ";
	d7.Print();
	cout << "d8 = ";
	d8.Print();
	cout << endl;

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

	//7.检测日期-日期
	cout << "7.检测日期-日期" << endl;

	Date d9(2023, 7, 27);
	Date d10(2003, 1, 1);
	cout << "d9 = ";
	d9.Print();
	cout << "d10 = ";
	d10.Print();
	cout << "d9 - d10 = " << d9 - d10 << endl;
	cout << "d10 - d9 = " << d10 - d9 << endl;
	cout << endl;

	Date d11(2016, 10, 6);
	Date d12(2023, 7, 22);
	cout << "d11 = ";
	d11.Print();
	cout << "d12 = ";
	d12.Print();
	cout << "d12 - d11 = " << d12 - d11 << endl;
	cout << "d11 - d12 = " << d11 - d12 << endl;
	cout << endl;

	Date d13(2015, 10, 6);
	Date d14(2015, 10, 6);
	cout << "d13 = ";
	d13.Print();
	cout << "d14 = ";
	d14.Print();
	cout << "d13 - d14 = " << d13 - d14 << endl;
	cout << "d14 - d13 = " << d14 - d13 << endl;
	cout << endl;
}
int main()
{
	test();
	return 0;
}