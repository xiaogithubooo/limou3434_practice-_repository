#include <iostream>
#include <cmath>
using namespace std;

//判断是否是完全数
bool IsOk(int number)
{
	//25 < 28 < 36
	//5 < sqrt(28) < 6
	//1、2、4 ---- 28、14、7
	//然后去掉28即可
	//1.找到约数
	int add = 0;
	for (int i = 1; i < sqrt(number); i++)
	{
		if (number % i == 0)
		{
			add += (i + (number / i));
		}
	}

	if (add == 2 * number)
	{
		return true;
	}

	return false;
}

int main()
{
	//1.输入最大范围
	int k = 0;
	cin >> k;

	//2.统计符合的数
	int count = 0;
	while (k > 0)
	{
		if (IsOk(k))
		{
			count++;
		}
		k--;
	}

	//3.输出统计结果
	cout << count;
	return 0;
}

// 64 位输出请用 printf("%lld")

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Function_1()
//	{
//		cout << "Base:Function_1()" << endl;
//	}
//	virtual void Function_2()
//	{
//		cout << "Base:Function_2()" << endl;
//	}
//private:
//	int _b_number = 1;
//};
//class Derive : public Base
//{
//private:
//	int _d_number = 2;
//};
//
//void Function(Base* x)
//{
//	x->Function_1();
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	Function(&b);
//	Function(&d);
//
//	Base bb;
//	return 0;
//}
