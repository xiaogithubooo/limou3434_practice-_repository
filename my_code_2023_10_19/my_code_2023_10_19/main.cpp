#include <iostream>
using namespace std;

class Base
{
public:
	virtual void Function_1()
	{
		cout << "Base:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Base:Function_2()" << endl;
	}
private:
	int _b_number = 1;
};
class Derive : public Base
{
	virtual void Function_1()
	{
		cout << "Derive:Function_1()" << endl;
	}
private:
	int _d_number = 2;
};

void Function(Base* b)
{
	b->Function_1();
}

int main()
{
	Base b;
	Derive d;

	Function(&b);
	Function(&d);
	return 0;
}

//class A
//{
//public:
//	virtual void function() = 0;
//};
//class B : public A
//{
//public:
//	void function()
//	{
//		cout << "B:I am a function." << endl;
//	}
//};
//class C : public A
//{
//public:
//	void function()
//	{
//		cout << "C:I am a function." << endl;
//	}
//};
//
//void func(A* a)
//{
//	a->function();
//}
//int main()
//{
//	B b;
//	C c;
//	b.function();
//	c.function();
//	return 0;
//}
//
////#include <iostream>
////using namespace std;
////class A {
////public:
////	virtual void func(int val = 1) {
////		cout << "A->" << val << endl;
////	}
////	virtual void test() {
////		func();
////	}
////};
////class B : public A {
////public:
////	void func(int val = 0) {//隐藏/重定义了func
////		cout << "B->" << val << endl;
////	}
////	//还完整继承了 virtual void test(A* const this) 继承的实质是可以使用父类的函数，而不是真的有一个函数在子类中
////};
////int main() {
////	B* p = new B;
////	p->test();
////	//调用了B类内的test函数，但是使用父类指针接受p指针，
////	//造成多态，因此调用的是子类的func()，但是实际上虚函数是
////	//虚函数的继承实际上是继承了了父类函数的接口，然后重写了实现，
////	//因此子类内的缺省值用的是父类的缺省值（子类）
////
////	p->func();//这里就没有构成多态了，也就没有
////	return 0;
////}
//
//////使用多态（修改前）
////#include <iostream>
////using namespace std;
////class Person
////{
////public:
////    virtual void func()
////    {
////        cout << "Person:virtual void func()" << endl;
////    }
////    ~Person()
////    {
////        cout << "~Person()" << endl;
////    }
////};
////class Student : public Person
////{
////public:
////    virtual void func()
////    {
////        cout << "Student:virtual void func()" << endl;
////    }
////    ~Student()
////    {
////        cout << "~Student()" << endl;
////    }
////};
////
////int main()
////{
////    Student s;
////    Person p;
////
////    Person& rs = s;
////    Person& rp = p;
////
////    rs.func();
////    rp.func();
////
////    return 0;
////}
//////输出：
//////Student:virtual void func()
//////Person : virtual void func()
//////~Person()
//////~Student()
//////~Person()
//////没有出问题