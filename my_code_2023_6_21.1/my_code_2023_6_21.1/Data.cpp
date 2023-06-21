#define _CRT_SECURE_NO_WARNINGS 1��
#include "Data.h"
//1.�Ƚ���������غ���
bool Data::operator==(const Data& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);//���︴����ǰ��ġ�==�����غ���
}
bool Data::operator>(const Data& d)
{
	if ((_year > d._year)
		||(_year == d._year && _month > d._month)
		||(_year == d._year && _month == d._month && _day > d._day))//һ�����ж��Ƿ���������������һ��
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

//2.�ӷ���ӷ���ֵ���������
Data& Data::operator+=(int day)//��Ҫ֧�������ġ�+=�������з���ֵ
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
	Data ret(*this);//Ҳ����дData ret = *this;
	ret += day;//������ǰ��ġ�+=�����غ���
	return ret;//ע�ⲻ��ʹ�����÷��أ������Ǿֲ�����
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

//3.�����������ֵ��������غ���
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
