//Data.cpp�ڲ�
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
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))//һ�����ж��Ƿ���������������һ��
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
	if (day < 0)//�����if�����Ϊ��Ԥ�����ϸ��������
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
	if (day < 0)//����if���Ҳ�Ǳ����ȥ���������
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)//һ����û��0�����˵��
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

//4.����������غ���������д�ɳ�Ա����������ע����Ԫ�����⣩
ostream& operator<<(ostream& out, const Data& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}//�������Ҳ�Ƽ�д�����������������Ͳ��������Ͷ��������
istream& operator>>(istream& in, Data& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckData());//�������ĺϷ���
	return in;
}