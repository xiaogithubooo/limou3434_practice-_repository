#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Widget
{
public:
	Widget(int x = 0)
	{
		cout << "Widget()" << endl;
	}
	Widget(const Widget& w)
	{
		cout << "Widget(const Widget& w)" << endl;
	}
	Widget& operator=(const Widget& w)
	{
		cout << "Widget& operator=(const Widget& w)" << endl;
		return *this;
	}
	~Widget()
	{
		cout << "~Widget()" << endl;
	}
};
void f1(Widget u)
{

}
void f2(const Widget& u)
{

}
Widget f3()
{
	Widget ret;//调用构造函数
	return ret;//调用构造函数+拷贝构造函数->连续调用了两次构造，优化为一次构造
}
Widget f(Widget u)
{
	cout << "----" << endl;
	Widget v(u);
	Widget w = v;
	cout << "----" << endl;
	return w;
}
int main()
{
	//Widget w1;
	//f1(w1);
	//f2(w1);
	//f1(Widget());//发现没有调用拷贝构造函数？这是因为编译器优化了，原本应该是“构造+拷贝构造”，直接变成调用“构造”
	//结论是：
	//同一个步骤中，对于连续的构造一般都会进行优化。（拷贝构造也是构造，所以“构造+拷贝构造”为2次构造）
	
	//Widget w2 = w1;
	//这是一个步骤（一行表达式）
	//原本创建w2对象本身调用了构造函数
	//int类型的1则隐式转化给一个匿名的Widget类型对象，这个时候又调用了一次构造函数
	//然后匿名的Widget对象给了w2对象，又调用了一次拷贝构造函数
	//编译器知道这里产生了连续的构造，所以进行了优化，变成了只进行一次构造函数

	//f3();

	//Widget w3 = f3();//w3z直接在f3结束的时候充当临时变量
	
	Widget x;

	//Widget y = f(x);//1次构造，4次拷贝构造（第5次拷贝构造的时候发生优化，y在f(x)结束的时候充当了临时变量）
		//Widget()
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//~Widget()
		//~Widget()
		//~Widget()
		//~Widget()
		//~Widget()

	Widget y = f(f(x));
	//1次构造，7次拷贝构造（VS2022环境）
	//（内函数结束的时候，外函数的形参u充当了临时变量）
	//（外函数结束的时候，y充当临时变量）
		//Widget()
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//~Widget()
		//~Widget()
		//~Widget()
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//~Widget()
		//~Widget()
		//~Widget()
		//~Widget()
		//~Widget()
	//如果换为release模式，又会优化成：
		//Widget()
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//~Widget()
		//~Widget()
		//Widget(const Widget & w)
		//Widget(const Widget & w)
		//~Widget()
		//~Widget()
		//~Widget()
		//~Widget()
	//为什么又少了两次呢？
	//编译器认为f(x)内部的w没有价值，认为直接返回v效率更好，因为调用了两次f(x)故少两次拷贝构造。
	
	//有时间可以在Linux中看看这些优化的程度

	return 0;
}


//一组数据按从小到大的顺序排列为:
//1，2，2，x，5，10，其中x≠5
//己知该组数据的中位数是众数的3/2倍
//< 中位数是(2+x)/2
// 
//< 由于从小到大排列，所以x大于等于2，x小于等于5
//< 由于x≠5，所以x的可能取值是2、3、4
//< ①假设x = 2，众数为2，由于中位数是众数的3/2倍，所以：(2+x)/2 = 2 * (3/2) = 3，解得x = 4，和之前假设x = 2冲突，所以不可能
//< ②假设x = 3，众数为2，由于中位数是众数的3/2倍，所以：(2+x)/2 = 2 * (3/2) = 3，解得x = 4，和之前假设x = 2冲突，所以不可能
//< ③假设x = 4，众数为2，由于中位数是众数的3/2倍，所以：(2+x)/2 = 2 * (3/2) = 3，解得x = 4，和之前假设x = 4符合，所以x的确等于4
//<
//则该组数据的中位数为？标准差为？
//< (1)中位数的计算：
//<              根据x = 4，得到完整的顺序为“1，2，2，4，5，10”，所以中位数为：(2+4)/2 = 3
//<
//< (2)标准差的计算：
//< 先求出平均值 = (1+2+2+4+5+10)/6 = 24/6 = 4
//<          (数据的平均值-数据1)^2 + (数据的平均值-数据2)^2 + (数据的平均值-数据3)^2) + …… + (数据的平均值-数据n)^2
//< 标准差 =  -------------------------------------------------------------------------------------------------
//<                                                      n
//<         (4-1)^2 + (4-2)^2 + (4-2)^2 + (4-4)^2 + (4-5)^2 + (4-10)^2
//<		  =  ---------------------------------------------------------
//<		                                6
//<         (3)^2 + (2)^2 + (2)^2 + (0)^2 + (-1)^2 + (-6)^2
//<		  = -----------------------------------------------
//<		                          6
//<         9 + 4 + 4 + 0 + 1 + 36
//<		  = ----------------------
//<		              6
//<         54
//<		  = --
//<         6
//<
//<		  = 9

