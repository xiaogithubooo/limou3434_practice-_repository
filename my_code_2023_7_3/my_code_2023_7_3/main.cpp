#include <iostream>
using namespace std;
template <typename T>//“虚拟类型T”或“广泛类型T”
T* init(int n)
{
	T* p = new T[n];
	return p;
}
int main()
{
	init<int>(10);//不用显式实例化是没有办法调用这个函数的
	return 0;
}
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//template <typename T>//“虚拟类型T”或“广泛类型T”
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	double b = 1.23;
//	Add<double>(a, b);//相对于类型也被手动传递过去了
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