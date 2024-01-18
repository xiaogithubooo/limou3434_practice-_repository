#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

class Data
{
public: 
	void Print(float x, double y)
	{
		cout << _data << "-" << x << "-" << y << '\n';
	}
private:
	int _data = 10;
};

int Add(int x, int y, int z)
{
	return x + y + z;
}
int main()
{
	//1.普通函数的绑定
	function<int(int, int, int)> Add_1 = &Add;
	cout << Add_1(1, 2, 3) << '\n';

	function<int(int)> Add_2 = bind(&Add, 1, 2, placeholders::_1);
	cout << Add_2(3) << '\n';

	//2.成员函数的绑定
	Data d;
	function<void(Data*, float, double)> Print_1 = &Data::Print;
	Print_1(&d, 2, 3.14);

	function<void(float, double)> Print_2 = bind(&Data::Print, Data(), placeholders::_2, placeholders::_1);
	Print_2(2, 3.14);
	
	return 0;
}


//void swap_function(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//struct swap_struct
//{
//	void operator()(int& r1, int& r2)
//	{
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	}
//};
//
//int main()
//{
//	int x = 1, y = 10;
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	auto swap_lambda = [](int& r1, int& r2)
//		{
//			int tmp = r1;
//			r1 = r2;
//			r2 = tmp;
//		};
//
//	function<void(int&, int&)> func_1 = swap_function;
//	func_1(x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	function<void(int&, int&)> func_2 = swap_struct();
//	func_2(x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	function<void(int&, int&)> func_3 = swap_lambda;
//	func_3(x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	map<string, function<void(int&, int&)>> swap = {
//		{ "函数指针", swap_function },
//		{ "仿函数", swap_struct() },
//		{ "lambda", swap_lambda }
//	};
//
//	swap["函数指针"](x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	swap["仿函数"](x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	swap["lambda"](x, y);
//	cout << "x = " << x << ", y = " << y << '\n';
//
//	return 0;
//}


//int main()
//{
//    //交换
//    int x = 10, y = 5;
//
//    //lambda表达式没有捕获列表，可以直接赋值给函数指针
//    auto func1 = []() { cout << "Hello, World!" << endl; };
//    void(*ptr1)() = func1;
//    ptr1(); //输出：Hello, World!
//
//    //lambda表达式带有捕获列表，无法直接赋值给函数指针
//    //int(*ptr2)() = [x, &y]() { return x + y; }; //编译错误
//
//    return 0;
//}
