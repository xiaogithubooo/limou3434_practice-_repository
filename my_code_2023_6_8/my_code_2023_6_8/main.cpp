#include "function.h"
////class A
////{
////public:
////	int i;
////	int j;
////public:
////	void Print(void);
////};
////void A::Print(void)
////{
////	printf("Helow word!\n");
////}
////int main()
////{
////	A* ptr = nullptr;
////	ptr->Print();
////	return 0;
////}
//
//int main()
//{
//	//Person X;
//	//X._name = "limou3434";
//	//X._age = 18;
//	//X._sex = "��";
//	//X.Print();
//
//	// ���м��г�Ա���������г�Ա����
//	class A1
//	{
//	public:
//		void f1() {}
//	private:
//		int _a;
//	};
//	printf("%zd\n", sizeof(A1));
//
//	// ���н��г�Ա����
//	class A2
//	{
//	public:
//		void f2() {}
//	};
//	printf("%zd\n", sizeof(A2));
//
//	// ����ʲô��û��---����
//	class A3
//	{};
//	printf("%zd\n", sizeof(A3));
//
//	//���Ϊ4 1 1
//	return 0;
//}
//class Data
//{
//public:
//	void Init(int year, int month, int day)//3.���Ǻ�������ô�ҵ�ʵ������������_year�أ���ʵ����������Ĳ����б�������һ��thisָ��
//	{
//		_year = year;//2.�������yearֵ�����Ǹ����������_year������ʵ�������d���_year
//		_month = month;
//		_day = day;
//	}
//	void Print(void);
//private:
//	int _year;//1.û�о���ʵ�������࣬��������_yearֻ������
//	int _month;
//	int _day;
//};
//void Data::Print(void)
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	Data d;
//	d.Init(2023, 6, 8);
//	d.Print();
//	return 0;
//}
//class Cl
//{
//public:
//	int x;
//	int y;
//public:
//	void Print()
//	{
//		cout << x << endl;
//	}
//};
//int main()
//{
//	Cl C;
//	C.x = C.y = 10;
//	C.Print();
//	return 0;
//}
//û�й��캯�������
class Cl
{
public:
	Cl(int x = 1)
	{
		_x = x;
	}
public:
	int _x;
};
class Date
{
public:
	//Date(int year = 2000, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << _a1._x;
	}
private:
	Cl _a1;
	Cl _a2;
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}