//#include <iostream>
//using namespace std;
////累积创建了n个对象
////累积使用了m个对象
//int n = 0;
//int m = 0;
//class Data
//{
//public:
//	Data()
//	{
//		n++;
//		m++;
//	}
//	Data(const Data& t)
//	{
//		n++;
//		m++;
//	}
//	~Data()
//	{
//		m--;
//	}
//private:
//};
//Data Func(Data a)
//{
//	return a;
//}
//int main()
//{
//	Data d1;
//	cout << n << " " << m << endl;
//	Data d2;
//	cout << n << " " << m << endl;
//	Data ();
//	cout << n << " " << m << endl;
//	Func(d2);
//	cout << n << " " << m << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
////累积创建了n个对象
////累积使用了m个对象
//class Data
//{
//public:
//	Data()
//	{
//		n++;
//		m++;
//	}
//	Data(const Data& t)
//	{
//		n++;
//		m++;
//	}
//	~Data()
//	{
//		m--;
//	}
//	static void Print()
//	{
//		cout << m << " " << n << endl;
//	}
//private:
//	static int n;
//	static int m;
//};
//int Data::n = 0;
//int Data::m = 0;
//Data Func(Data a)
//{
//	return a;
//}
//int main()
//{
//	Data d1;
//	d1.Print();
//	Data d2;
//	Data::Print();
//	Data ();
//	Data::Print();
//	Func(d2);
//	Data::Print();
//	Data* d3 = nullptr;
//	d3->Print();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class B
//{
//public:
//    static B CreateObj()//3.提供一个接口，来间接使用构造函数
//    {
//        B b;
//        return b;
//    }
//private:
//    B(int x = 0, int y = 0)//2.在构造的时候只能在栈上开辟空间，否则无法使用类，因为这里访问限定符是private
//        :_x(x)
//        , _y(y)
//    {}
//private:
//    int _x;
//    int _y;
//};
//int main()
//{
//    //static B data1;//1.无法创建，因为构造函数是私有的
//    B data2 = B::CreateObj();//4.依靠接口间接创建了data2对象，并且保证一定是在栈上开辟（因此没有办法再堆上开辟该类型的对象）
//    
//    //5.CreateObj前面之所以加上static
//    //是为了避免“先有鸡，还是先有蛋”的问题
//    //因为假设没有static，要使用CreateObj()就要先创建一个B类型的对象才能使用
//    //但是由于限定符private的原因没有办法直接使用构造函数创建变量
//    //使得能够直接使用CreateObj()
//    return 0;
//}

//class Solution
//{
//    class Sum
//    {
//    public:
//        Sum()
//        {
//            _ret += _i;
//            _i++;
//        }
//    };
//
//public:
//    int Sum_Solution(int n)
//    {
//        Sum* arr = new Sum[n];
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;

//#include <iostream>
//using namespace std;
//class Widget
//{
//public:
//    //1.构造函数
//    Widget(int x = 0)
//    {
//        cout << "Widget()" << endl;
//        _x = x;
//    }
//    //2.拷贝构造函数
//    Widget(const Widget& w)
//    {
//        cout << "Widget(const Widget& w)" << endl;
//    }
//    //3.赋值重载函数
//    Widget& operator=(const Widget& w)
//    {
//        cout << "Widget& operator=(const Widget& w)" << endl;
//        return *this;
//    }
//    //4.析构函数
//    ~Widget()
//    {
//        cout << "~Widget()" << endl;
//    }
//private:
//    int _x;
//};
//void f1(Widget u)
//{
//
//}
//Widget f2()
//{
//    Widget d; 
//    return d;
//}
//Widget f3()
//{
//    return Widget(1);
//}
//int main()
//{
//    //调用1
//    Widget w1;
//    f1(w1);
//    cout << "----" << endl;
//    //先调用 构造函数Widget()
//    //然后调用函数的时候给形参调用 拷贝构造函数Widget(const Widget & w) 拷贝给临时变量u
//    //最后调用 析构函数~Widget() 析构掉临时变量u
//
//    //调用2
//    f1(Widget(2));
//    cout << "----" << endl;
//    /*
//    原本应该是调用 构造函数Widget() 构造一个匿名对象，
//    然后调用 拷贝构造函数Widget(const Widget & w) 拷贝给临时变量u，
//    最后使用 析构函数~Widget() 析构掉u。
//    但是！由于编译器会优化连续的“构造”+“拷贝构造”---->“直接构造”。
//    所以变成下面的调用：
//    */
//    //Widget()
//    //~Widget()
//
//    //调用3
//    f1(2);
//    cout << "----" << endl;
//    /*
//    原本应该是调用 构造函数Widget() 构造一个临时对象，
//    然后调用 拷贝构造函数Widget(const Widget & w) 拷贝给临时变量u，
//    最后使用 析构函数~Widget() 析构掉u。
//    但是！由于编译器会优化连续的“构造”+“拷贝构造”---->“直接构造”。
//    所以变成下面的调用：
//    */
//    //Widget()
//    //~Widget()
//
//    //调用4
//    Widget d2 = Widget(3);
//    cout << "----" << endl;
//    /*
//    原本应该是调用 构造函数Widget() 构造一个临时对象，
//    然后使用 拷贝构造函数Widget(const Widget & w) 拷贝给d2对象
//    但是！由于编译器会优化连续的“构造”+“拷贝构造”---->“直接构造”。
//    所以变成下面的调用：
//    */
//    //Widget()
//
//    //调用5
//    f2();
//    cout << "----" << endl;
//    /*
//    根据f(2)的函数内容
//    Widget f2()
//    {
//        Widget d; 
//        return d;
//    }
//    原本应该是调用 构造函数Widget() 构造d对象，
//    然后使用 拷贝构造函数Widget(const Widget & w) 交给一个临时变量便于返回函数值
//    最后析构这个临时变量
//    但是！由于编译器会优化连续的“构造”+“拷贝构造”---->“直接构造”。
//    所以变成下面的调用：
//    */
//    //Widget()
//    //~Widget()
//
//    //调用6
//    Widget ret1 = f2();
//    cout << "----" << endl;
//    /*
//    根据f(2)的函数内容
//    Widget f2()
//    {
//        Widget d; 
//        return d;
//    }
//    原本应该是调用 构造函数Widget() 构造d对象，
//    然后使用 拷贝构造函数Widget(const Widget & w) 将d拷贝给一个临时对象便于返回函数值，
//    再调用 拷贝构造函数Widget(const Widget & w) 将临时对象拷贝给ret1
//    然后析构这个临时变量。
//    这里编译器直接不生成临时变量，将d直接调用 拷贝构造函数Widget(const Widget & w) 给ret1。
//    再由于编译器会优化连续的“构造”+“拷贝构造”---->“直接构造”，
//    因此在 Widget ret1 = f2(); 这一句的调用中就只剩下了“直接构造”。
//    */
//    //Widget()
//
//    //调用7
//    Widget ret2;
//    ret2 = f2();
//    cout << "----" << endl;
//    /*
//    先使用 构造函数Widget() 构造一个ret2对象
//    然后在f2()内调用 构造函数Widget() 构造d对象，
//    然后使用 拷贝构造函数Widget(const Widget & w) 将d拷贝给一个临时对象便于返回函数值，
//    再使用 赋值重载函数Widget& operator=(const Widget& w) 将临时变量赋值给ret2，
//    最后析构临时变量。
//    由于不是在一行代码内连续构造析构，所以这里编译器只优化了部分（在f2()内的构造和拷贝构造变成了直接构造），没有全部优化。
//    */
//    //Widget()
//    //Widget()
//    //Widget& operator=(const Widget & w)
//    //~Widget()
//
//    //调用8
//    Widget ret3 = f3();
//    cout << "----" << endl;
//    /*
//    根据f3()内部构造：
//    Widget f3()
//    {
//        return Widget(1);
//    }
//    原本先是调用 构造函数 构造一个匿名对象，
//    然后通过 拷贝构造函数 将匿名对象拷贝给临时对象，
//    然后使用 拷贝构造函数 将临时变量拷贝给ret3，
//    最后由于优化就变成了下面这样：
//    */
//    //Widget()
//    return 0;
//}
#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int val = 0)
		:_val(val)
		,_next(nullptr)
	{}
	int _val;
	ListNode* _next;
};
int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	
	l1->_next = l2;
	l2->_next = l3;
	l3->_next = l4;
	l4->_next = l5;

	delete l1;
	delete l2;
	delete l3;
	delete l4;
	delete l5;
	return 0;
}