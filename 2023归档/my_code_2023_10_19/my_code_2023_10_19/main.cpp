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
////	void func(int val = 0) {//����/�ض�����func
////		cout << "B->" << val << endl;
////	}
////	//�������̳��� virtual void test(A* const this) �̳е�ʵ���ǿ���ʹ�ø���ĺ����������������һ��������������
////};
////int main() {
////	B* p = new B;
////	p->test();
////	//������B���ڵ�test����������ʹ�ø���ָ�����pָ�룬
////	//��ɶ�̬����˵��õ��������func()������ʵ�����麯����
////	//�麯���ļ̳�ʵ�����Ǽ̳����˸��ຯ���Ľӿڣ�Ȼ����д��ʵ�֣�
////	//��������ڵ�ȱʡֵ�õ��Ǹ����ȱʡֵ�����ࣩ
////
////	p->func();//�����û�й��ɶ�̬�ˣ�Ҳ��û��
////	return 0;
////}
//
//////ʹ�ö�̬���޸�ǰ��
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
//////�����
//////Student:virtual void func()
//////Person : virtual void func()
//////~Person()
//////~Student()
//////~Person()
//////û�г�����