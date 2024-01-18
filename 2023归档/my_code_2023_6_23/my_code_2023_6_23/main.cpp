#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Data1
{
public:
	class Data2//2.Data2定义在Data1内部，仅仅只是：
	//1.被A的类域限制
	//2.Data2天生是Data1的友元类
	{
	public:
		void Function(const Data1& a)
		{
			cout << a._a1 << endl;//友元的体现
		}
	private:
		int _a2;
		int _b2;
		int _c2;
	};
private:
	int _a1;
	int _b1;
	int _c1;
};
int main()
{
	cout << sizeof(Data1) << endl;
	//1.输出12，说明Data1没有计算Data2大小
	Data1::Data2 D;
	return 0;
}

//class Data
//{
//	friend class FriendData;//1.给Data类设置了友元类FriendData
//	friend void function(void);
//public:
//	Data(int a = 0, int b = 0, int c = 0)
//		:_a(a), _b(b), _c(c)
//	{
//		cout << "Data()" << endl;
//	}
//	void Print(void)
//	{
//		cout << _a << " " << _b << " " << _b << " " << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//class FriendData
//{
//public:
//	void Fun1()
//	{
//		Data D;
//		cout << D._a << endl;//2.可以毫无顾忌访问Data对象中的成员变量
//	}
//	void Fun2()
//	{
//		Data D;
//		cout << D._a << endl;//3.除了变量还能访问Data对象中的成员函数
//		D.Print();
//	}
//	void Fun3()
//	{
//		Data D;
//		cout << D._a << endl;
//	}
//};
//void function(void)
//{
//	Data D;
//	cout << D._a << " " << D._b << " " << D._b << " " << endl;
//	D.Print();
//	FriendData FD;
//	FD.Fun1();
//	FD.Fun2();
//}
//int main()
//{
//	function();
//	return 0;
//}
//class B
//{
//public:
//	static B CreateObj()//3.提供一个接口，来间接使用构造函数
//	{
//		B b;
//		return b;
//	}
//private:
//	B(int x = 0, int y = 0)//2.在构造的时候只能在栈上开辟空间，否则无法使用类，因为这里访问限定符是private
//		:_x(x)
//		,_y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//int main()
//{
//	//static B data1;//1.无法创建
//	B data2 = B::CreateObj();//4.依靠接口间接创建了data2对象，并且保证一定是在栈上开辟
//	//5.CreateObj前面之所以加上static
//	//是为了避免“先有鸡，还是先有蛋”的问题
//	//因为假设没有static，要使用CreateObj()就要先创建一个B类型的对象才能使用
//	//但是由于限定符private的原因没有办法直接使用构造函数创建变量
//	//使得能够直接使用CreateObj()
//	return 0;
//}

//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	void Print(void)
//	{
//		cout << _scount << endl;
//	}
//	//int GetScount(void)//11.（方法一）
//	//{
//	//	return _scount;
//	//}
//	static int GetScount(void)//13.（方法二）
//	{
//		//_a;//15.无法访问非静态成员变量（因为没有this指针）
//		return _scount;
//	}
//	static int _scount_x;
//private:
//	static int _scount;//1.静态成员
//	int _a = 0;
//};
//int A::_scount = 1;//6.所以只能在类外面定义和初始化
//int A::_scount_x = 0;
//
//int main()
//{
//	A a1;
//	//2.出现链接错误，因为只有静态成员变量只有声明没有定义，普通成员是跟着类一起定义的
//	//3.但是普通成员C++规定最好好需要使用初始化列表初始化
//	//4.而静态成员变量是不能使用初始化列表的初始化的
//	//5.并且静态成员变量也不能给缺省值，这是因为缺省值给的是初始化列表的，因此还是不能用
//	
//	//a1._scount;//7.由于受到访问限定符的影响，所以不能直接进行访问
//
//	a1.Print();//8.但是可以通过类来间接使用_scount，也证明了静态成员变量确实是被对象们所共有的
//	A a2;
//	a2.Print();
//
//	//9.不受访问限定符限制，所以有两种方式访问静态成员变量
//	cout << a1._scount_x << endl;
//	A::_scount_x++;
//	cout << a1._scount_x << endl;
//	cout << a2._scount_x << endl;
//
//	//10.还可以使用接口来取得私有的静态成员变量（方法一）
//	//cout << a1.GetScount() << endl; 
//
//	//12.也可以使用静态成员函数来获取静态成员变量（方法二）
//	cout << A::GetScount() << endl;
//
//	//14.静态成员函数最明显的特征就是没有this指针，所以没有办法访问非静态的成员
//	return 0;
//}

//class Data1
//{
//public:
//	Data1(int year)
//		:_year(year)
//	{
//		cout << "Data1(int year)" << endl;
//	}
//	Data1(const Data1& d)
//	{
//		cout << "Data1(const Data1& d)" << endl;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	Data1 dd1(2021);
//	Data1 dd2 = 2022;
//	//上述两种写法效果一样，但是过程不一样
//	//1.dd1是：“直接调用构造函数”
//	//2.dd2是：隐式转化---->“构造函数”+“拷贝构造函数”+编译器优化---->“直接调用构造函数”
//	//如果在构造函数前面加上explicit关键字，就会取消这种隐式转化
//
//	//而上面的dd2的创建过程实际上就是一种隐式类型转化，所有的隐式类型转化都会生成临时变量，临时变量具有常属性
//	int i = 10;
//	//double& d = i;//这样做是不被允许的
//	const double& d = i;//这里引用的是“i赋值给d时产生”的临时变量，所以是被允许的
//
//	const Data1& dd3 = 2023;
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		: _a1(a)//初始化列表是按照声明的先后顺序来依次进行初始化的
//		, _a2(_a1)//所以这里的_a2被初始化了随机值
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//	return 0;
//}

//class A
//{
//public:
//	A(int N)
//		:_a((int*)malloc(sizeof(int)* N))
//		,_N(N)
//	{
//		if (_a == NULL)
//		{
//			perror("malloc fail\n");
//		}
//		memset(_a, 0, sizeof(int) * N);
//	}
//private:
//	int* _a;
//	int _N;
//};
//int main()
//{
//	A aa0(100);
//	return 0;
//}

////class Data1
////{
////public:
////	Data1(int a1 = 0)//提供了默认构造函数
////	{
////		_a1 = a1;
////	}
////private:
////	int _a1;
////};
////class Data2
////{
////public:
////	Data2(int a2, int b2, int c2 = 0, int d2 = 0, int e2 = 0, int f2 = 0)
////	//函数体外初始化
////		:_c2(c2)
////		,_d2(d2)
////		,_e2(e2)
////		,_f2(f2)
////	{
////		Data1 D(b2);
////		_b2 = D;
////	}
////
////private:
////	int _a2 = 0;//这里使用了默认构造函数
////
////	Data1 _b2;//这里不是初始化而是缺省值
////
////	int _c2;//这里使用了初始化列表
////	Data1 _d2;//这里使用了初始列表
////	const int _e2;//这里使用了初始列表
////	int& _f2;//这里使用了初始列表
////};
////int main()
////{
////	Data2 c;
////	return 0;
////}
//
////#define _CRT_SECURE_NO_WARNINGS 1
////#include <iostream>
////using namespace std;
//class Data1
//{
//public:
//	Data1(int a1 = 0)//提供了默认构造函数
//	{
//		_a1 = a1;
//	}
//private:
//	int _a1;
//};
//class Data2
//{
//public:
//	Data2(int a1)/*int a2, int b2, int c2,*/
//	{
//		//函数体内初始化
//	/*	_a2 = a2;
//		_b2 = b2;
//		_c2 = c2;*/
//		Data1 D(a1);
//		_d2 = D;
//	}
//private:
//	//int _a2;
//	//int _b2;
//	//int _c2;
//	Data1 _d2;
//};
//int main()
//{
//	Data2 b;
//	return 0;
//}