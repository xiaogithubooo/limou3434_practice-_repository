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
	int _f_number = 1;
};

class Mother
{
public:
	virtual void Function_1()
	{
		cout << "Mother:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Mother:Function_2()" << endl;
	}
private:
	int _m_number = 2;
};
class Son : public Father, public Mother
{
public:
	virtual void Function_1()
	{
		cout << "Son:Function_1()" << endl;
	}
	virtual void Function_3()//这个虚函数被放在第一个虚表里了
	{
		cout << "Son:Function_3()" << endl;
	}

private:
	int _s_number = 3;
};

typedef void(*VFUNC)();
void PrintVFT(VFUNC arr[])//打印虚函数表内的函数
{
	for (size_t i = 0; arr[i] != 0; i++)//这里是根据VS的特殊处理才可以这么写停止循环的条件的，其他环境可能只能自己写固定的循环次数
	{
		printf("[%d]:%p->", i, arr[i]);
		arr[i]();//调用函数
	}
	printf("\n");
}

int main()
{
	Son s;
	VFUNC* table1 = (VFUNC*)( *(int*)&s );//第一张虚表
	//VFUNC* table2 = (VFUNC*)( *( (int*)( (char*)&s + sizeof(Father))));//第二张虚表（直接使用指针操作）
	Mother* ptr = &s;
	VFUNC* table2 = (VFUNC*)( *( (int*)ptr ) );//第二张虚表（利用内置切片让指针偏移）
	PrintVFT(table1);
	PrintVFT(table2); 
	return 0;
}


//#include <iostream>
//using namespace std;
//
//class Father
//{
//public:
//	virtual void Function_1()
//	{
//		cout << "Father:Function_1()" << endl;
//	}
//	virtual void Function_2()
//	{
//		cout << "Father:Function_2()" << endl;
//	}
//private:
//	int _b_number = 1;
//};
//class Son : public Father
//{
//public:
//	virtual void Function_1()
//	{
//		cout << "Son:Function_1()" << endl;
//	}
//	virtual void Function_3()
//	{
//		cout << "Son:Function_3()" << endl;
//	}
//	virtual void Function_4()
//	{
//		cout << "Son:Function_4()" << endl;
//	}
//	void Function_5()
//	{
//		cout << "Son:Function_5()" << endl;
//	}
//private:
//	int _d_number = 2;
//};
//class Grandson : public Son
//{
//public:
//	virtual void Function_3()
//	{
//		cout << "Grandson:Function_3()" << endl;
//	}
//};
//void Function(Father* f)
//{
//	f->Function_1();
//}
//
//void test_1()
//{
//	Father f;
//	Son s;
//	Grandson g;
//
//	static int a = 0;
//	int b = 0;
//	int* p1 = new int;
//	const char* p2 = "hello";
//
//	printf("静态区：%p\n", &a);
//	printf("栈区：%p\n", &b);
//	printf("堆区：%p\n", p1);
//	printf("代码段/常理量区：%p\n", p2);
//	printf("虚表地址：%p\n", *((int*)(&s)));
//
//	printf("Father::Function_1 虚函数地址：%p\n", &Father::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Father::Function_2 虚函数地址：%p\n", &Father::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Son::Function_1 虚函数地址：%p\n", &Son::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Son::Function_2 虚函数地址：%p\n", &Son::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Son::Function_3 虚函数地址：%p\n", &Son::Function_3);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Son::Function_4 虚函数地址：%p\n", &Son::Function_4);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Grandson::Function_1 虚函数地址：%p\n", &Grandson::Function_1);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Grandson::Function_2 虚函数地址：%p\n", &Grandson::Function_2);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Grandson::Function_3 虚函数地址：%p\n", &Grandson::Function_3);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	printf("Grandson::Function_4 虚函数地址：%p\n", &Grandson::Function_4);//成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//
//	printf("普通函数地址：%p\n", Function);
//	//注意：成员函数这里有一个语法规定，不能只使用函数名，必须加上取地址
//	//注意：不可以使用 bTest.Function_1 这种方式打印虚函数地址，因为函数地址没有被存储在对象中
//}
//
//typedef void(*VFUNC)();
//void PrintVFT(VFUNC arr[])//打印虚函数表内的函数
//{
//	for (size_t i = 0; arr[i] != 0; i++)//这里是根据VS的特殊处理才可以这么写停止循环的条件的，其他环境可能只能自己写固定的循环次数
//	{
//		printf("[%d]:%p->", i, arr[i]);
//		arr[i]();//调用函数
//	}
//	printf("\n");
//}
//void test_2()
//{
//	Father f;
//	VFUNC* vPtrT1 = (VFUNC*)(*(int*)&f);//虚函数表地址
//	PrintVFT(vPtrT1);
//
//	Son s;
//	VFUNC* vPtrT2 = (VFUNC*)(*(int*)&s);//虚函数表地址
//	PrintVFT(vPtrT2);
//
//	Grandson g;
//	VFUNC* vPtrT3 = (VFUNC*)(*(int*)&g);//虚函数表地址
//	PrintVFT(vPtrT3);
//}
//int main()
//{
//	test_1();
//	test_2();
//	return 0;
//}
////64位的输出有可能不一样，建议换成32位平台