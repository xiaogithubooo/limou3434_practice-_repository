#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    void Init(int year, int month, int day)
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;     // Äê
    int _month;    // ÔÂ
    int _day;      // ÈÕ
};

int main()
{
    Date d1, d2;

    d1.Init(2022, 1, 11);
    d2.Init(2022, 1, 12);

    d1.Print();
    d2.Print();

    return 0;
}