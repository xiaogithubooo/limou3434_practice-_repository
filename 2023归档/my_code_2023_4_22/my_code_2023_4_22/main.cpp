#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
inline double square(double x)//����ʹ�������ؼ���
{
	return x * x;
}
int main()
{
	//ʹ������
	using namespace std;
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a^2 = " << a << " " << "b^2 = " << b << endl;
	cout << "c^2 = " << square(c++) << endl << "c = " << c << endl;

	//ʹ������
	int number = 100;
	int& num = number;
	cout << "number:" << number << " pnumber:" << &number << endl << "num:" << num << " pnum:" << &num << endl;
	number++;
	num++;
	cout << "number:" << number << " pnumber:" << &number << endl << "num:" << num << " pnum:" << &num << endl;
	return 0;
}