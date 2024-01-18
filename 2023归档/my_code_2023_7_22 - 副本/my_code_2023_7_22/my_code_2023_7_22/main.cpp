#include <iostream>
#include <cassert>
using namespace std;
class Date
{
public:
	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);/*��� month ��Ч��*/
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		/*
		һ�������������������£�
		1.���������ܹ���4�����������ܱ�100��������Ϊ���ꡣ���磺2008�ꡢ2012��ȡ�
		2.���������ܹ���400��������Ҳ�����ꡣ���磺2000�ꡢ2400��ȡ�
		*/
		if (month == 2
			&& ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
			)
		{
			return 29;
		}
		return monthDays[month];
	}
	//1.ȫȱʡ�Ĺ��캯����ʹ���˳�ʼ���б�
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year), 
		_month(month), 
		_day(day) 
	{
		//�����Ƕ����ڶ����һ�ּ�飬����һ���ٴ�
		if (GetMonthDay(_year, _month) < _day)
		{
			cout << "�Ƿ�����" << endl;
		}
	}
	//2.�������캯��
	//d2(d1)
	Date(const Date& d)//ʵ���ϲ���Ҫ�Լ�д�������죬��Ϊ������ֻ��Ҫǳ��������
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//3.��ֵ��������غ���
	//d2 = d3 --> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	//4.��������
	~Date()
	{
		cout << "�����������������������û��̫���ô�:~Data()" << endl;
	}
	//5.�������غ���
	//����+=��������
	Date& operator+=(int day)
	{
		_day += day;//�Ȳ���3721��ֱ�Ӽ��Ͼ���
		int days = GetMonthDay(_year, _month);//��ȡ����µ�����
		while (_day > days)//��������ǲ���ȷ�ľͽ���ѭ��
		{
			_month++;//�������˾ͼ��·�
			_day -= days;//���Ұ�������СһЩ
			if (_month == 13)//����·ݳ����˾ͼ����
			{
				_year++;
				_month = 1;
			}
			days = GetMonthDay(_year, _month);//���»�ȡ��ȷ������
		}
		return *this;
	}
	//����+�������������
	Date operator+(int day)
	{
		Date cache(*this);//����һ��ԭ�е�*this
		return cache += day;
	}
	//����-=�������������
	Date& operator-=(int day)
	{
		_day -= day;//�Ȳ���3721��ֱ�Ӽ�ȥ����
		int days = GetMonthDay(_year, _month);//��ȡ����µ�����
		while (_day <= 0)//��������ǲ���ȷ�ľͽ���ѭ��
		{
			_month--;//��ȥ�·�
			_day += days;//���Ұ���������һЩ
			if (_month == 0)//����·�Ϊ0�˾ͼ�ȥ���
			{
				_year--;
				_month = 12;
			}
			days = GetMonthDay(_year, _month);//���»�ȡ��ȷ������
		}
		return *this;
	}
	//����-�������������
	Date operator-(int day)
	{
		Date cache(*this);//����һ��ԭ�е�*this
		return cache -= day;
	}
	//ǰ��++���������
	Date& operator++()
	{
		return (*this) += 1;
	}
	//����++���������
	Date operator++(int)
	{
		Date cache(*this);//����һ��ԭ�е�*this
		*this += 1;
		return cache;
	}
	//ǰ��--���������
	Date& operator--()
	{
		return (*this -= 1);
	}
	//����--���������
	Date operator--(int)
	{
		Date cache(*this);//����һ��ԭ�е�*this
		*this -= 1;
		return cache;
	}
	//>���������
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
	//==���������
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}
	//!=���������
	bool operator != (const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}
	//>=���������
	bool operator >= (const Date& d)
	{
		if ((*this) > d || (*this) == d)
			return true;
		return false;
	}
	//<���������
	bool operator < (const Date& d)
	{
		if ((*this) >= d)
			return false;
		return true;
	}
	//<=���������
	bool operator <= (const Date& d)
	{
		if ((*this) > d)
			return false;
		return true;
	}
	//����-����=�����������������
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
	//6.��ӡ�����ຯ��
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

	cout << "(++d4).Print(), ++d4֮ǰ:";
	(++d4).Print();
	cout << "(++d4).Print(), ++d4֮��:";
	d4.Print();

	cout << "d4++.Print(), d4++֮ǰ:";
	(d4++).Print();
	cout << "d4++.Print(), d4++֮��:";
	d4.Print();

	cout << "(--d4).Print(), --d4֮ǰ:";
	(--d4).Print();
	cout << "(--d4).Print(), --d4֮��:";
	d4.Print();

	cout << "(d4--).Print(), d4--֮ǰ:";
	(d4--).Print();
	cout << "(d4--).Print(), d4--֮��:";
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