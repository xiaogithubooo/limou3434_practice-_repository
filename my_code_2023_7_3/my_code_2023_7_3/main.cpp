#include <iostream>
using namespace std;
template <typename T>//����������T���򡰹㷺����T��
T* init(int n)
{
	T* p = new T[n];
	return p;
}
int main()
{
	init<int>(10);//������ʽʵ������û�а취�������������
	return 0;
}
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//template <typename T>//����������T���򡰹㷺����T��
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	double b = 1.23;
//	Add<double>(a, b);//���������Ҳ���ֶ����ݹ�ȥ��
//	return 0;
//}
/*
	int i = 10;
	int j = 20;
	double x = 3.14;
	double y = 8.9;
	Swap(i, j);
	cout << "i,j=" << i << " " << j << endl;
	Swap(x, y);
	cout << "x,y=" << x << " " << y << endl;
*/