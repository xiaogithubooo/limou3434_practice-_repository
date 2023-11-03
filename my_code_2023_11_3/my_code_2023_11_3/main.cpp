//打印虚函数表地址和虚函数地址，以及虚函数表地址和其他区域地址的对比
#include <iostream>
using namespace std;

class Father
{
public:
	virtual void Function_1()
	{
		cout << "Father:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Father:Function_2()" << endl;
	}
private:
	int _b_number = 1;
};

class Son : public Father
{
public:
	virtual void Function_1()
	{
		cout << "Son:Function_1()" << endl;
	}
	virtual void Function_3()
	{
		cout << "Son:Function_3()" << endl;
	}
	virtual void Function_4()
	{
		cout << "Son:Function_4()" << endl;
	}
	void Function_5()
	{
		cout << "Son:Function_5()" << endl;
	}
private:
	int _d_number = 2;
};

class Grandson : public Son
{
public:
	virtual void Function_3()
	{
		cout << "Grandson:Function_3()" << endl;
	}
};

void Function(Father* f)
{
	f->Function_1();
}

void test_1()
{
	Father f;
	Son s;
	Grandson g;

	static int a = 0;
	int b = 0;
	int* p1 = new int;
	const char* p2 = "hello";

	printf("静态区：%p\n", &a);
	printf("栈区：%p\n", &b);
	printf("堆区：%p\n", p1);
	printf("代码段/常量区：%p\n", p2);
	printf("虚表地址：%p\n", *((int*)(&s)));

	printf("Father::Function_1 虚函数地址：%p\n", &Father::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Father::Function_2 虚函数地址：%p\n", &Father::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Son::Function_1 虚函数地址：%p\n", &Son::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Son::Function_2 虚函数地址：%p\n", &Son::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Son::Function_3 虚函数地址：%p\n", &Son::Function_3);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Son::Function_4 虚函数地址：%p\n", &Son::Function_4);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Grandson::Function_1 虚函数地址：%p\n", &Grandson::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Grandson::Function_2 虚函数地址：%p\n", &Grandson::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Grandson::Function_3 虚函数地址：%p\n", &Grandson::Function_3);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	printf("Grandson::Function_4 虚函数地址：%p\n", &Grandson::Function_4);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址

	printf("普通函数地址：%p\n\n", Function);
	//注意：成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
	//注意：不可以使用 bTest.Function_1 这种方式打印虚函数地址，因为函数地址没有被存储在对象中
}

typedef void(*VFUNC)();
void PrintVFT(VFUNC arr[])//接受虚函数表指针，并且打印虚函数表内的函数地址内容，然后进行调用
{
	for (size_t i = 0; arr[i] != 0; i++)//这里是根据 VS 的特殊处理才可以这么写停止循环的条件的，其他环境可能只能自己写固定的循环次数
	{
		printf("_vfptr[%d]:%p->", i, arr[i]);
		arr[i]();//调用函数
	}
	printf("\n");
}
void test_2()
{
	Father f;
	VFUNC* vPtrT1 = (VFUNC*)(*(int*)&f);//虚函数表地址，如果是 64 位可以改 (int*) 为 (long long*)
	PrintVFT(vPtrT1);

	Son s;
	VFUNC* vPtrT2 = (VFUNC*)(*(int*)&s);//虚函数表地址，如果是 64 位可以改 (int*) 为 (long long*)
	PrintVFT(vPtrT2);

	Grandson g;
	VFUNC* vPtrT3 = (VFUNC*)(*(int*)&g);//虚函数表地址，如果是 64 位可以改 (int*) 为 (long long*)
	PrintVFT(vPtrT3);
}

int main()
{
	//64位的输出会不一样（因为指针长度变成了 8 字节），建议换成32位平台再运行

	test_1();
	test_2();
	return 0;
}

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Function_1();//先声明，后定义
//	virtual void Function_2();//后声明，先定义
//private:
//	int _b_number = 1;
//};
//
//class Derive : public Base
//{
//	virtual void Function_1()
//	{
//		cout << "Derive:Function_1()" << endl;
//	}
//private:
//	int _d_number = 2;
//};
//
//void Base::Function_2()
//{
//	cout << "Base:Function_2()" << endl;
//}
//void Base::Function_1()
//{
//	cout << "Base:Function_1()" << endl;
//}
//
//void Function(Base* b)
//{
//	b->Function_1();
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	Function(&b);
//	Function(&d);
//	return 0;
//}
//
//////隐藏的多态
////#include <iostream>
////using namespace std;
////class A
////{
////public:
////	virtual void func(int val = 1)
////	{
////		cout << "A->" << val << endl;
////	}
////	virtual void test()
////	{
////		func();
////	}
////};
////class B : public A
////{
////public:
////	void func(int val = 0)//隐藏/重定义了func
////	{
////		cout << "B->" << val << endl;
////	}
////	//继承了 virtual void test(A* const this)，因此继承的实质是可以使用父类的函数，而不是真的有一个函数在子类中
////};
////int main()
////{
////	B* p = new B;
////	p->test();
////	//调用 B 类内的 test()，由于继承的实质是可以使用父类的函数，
////	//因此实际是使用了父类函数里的 test()，全写为 void test(A* const this)
////	//父类 this 指针接受 p 指针，使用 this->func() 就造成多态调用（是父类指针的调用），
////	//因此内部调用的是子类的 func()
////	
////	//而虚函数的继承实际上是继承了了父类函数的接口，然后重写了实现，
////	//因此子类内的缺省值用的是父类的缺省值（子类）
////
////	p->func();//这里就没有构成多态了，正常调用了子类成员函数
////	return 0;
////}