//main.cpp内部
#define _CRT_SECURE_NO_WARNINGS 1
#include "Data.h"
void TestData1(void)
{
	Data d1(2022, 7, 24);
	d1.Print();
	Data d2(d1);
	d2.Print();

	Data d3(2022, 8, 24);
	Data d4(2023, 6, 21);
	d4 = d1 = d3;//这里就需要用到赋值运算符重载函数，而不是拷贝构造函数，并且注意这里是连续赋值

	d3.Print();
	d1.Print();
	d4.Print();

	d2 = d2;//这里使用的是自己给自己赋值，赋值运算符重载可以考虑在这里优化
	d2.Print();
}
void TestData2(void)
{
	Data d5(2000, 1, 1);
	Data d6(d5);
	Data d7(1900, 1, 2);
	Data d8(3000, 5, 4);
	if (d5 == d6)
	{
		if (d5 != d7)
		{
			if (d5 > d7)
			{
				if (d5 < d8)
				{
					cout << "成功！" << endl;
				}
			}
		}
	}
}
void TestData3(void)
{
	Data d9(2001, 10, 28);
	d9.Print();
	d9 += 20;
	d9.Print();
	(d9 + 3).Print();
	Data d10 = d9 + 4;
	d10.Print();
	(++d10).Print();//Data operator++(&d10);//前置++
	(d10++).Print();//Data operator++(&d10, 0);//后置++，这里传0，但其实传什么值不重要，只要编译器能做区分就行
	d10.Print();
}
void TestData4(void)
{
	Data d11(2022, 7, 25);
	Data d12(2000, 2, 15);
	cout << d12 - d11 << endl;
	(d11-3).Print();
	(d11--).Print();
	d11.Print();
	(--d11).Print();
}
void TestData5(void)
{
	Data d12(2023, 12, 40);
}
void TestData6(void)
{
	Data d13(2001, 2, 5);
	Data d14(2009, 3, 4);
	Data d15;
	Data d16;
	//cout << d13 << endl;
	//这里不能直接使用cout
	//是因为<<也是运算符
	//只对内置类型重载（库里面写好的）
	//这里没有办法识别d13为何种类型
	//无法匹配得到输出

	//写了重载后
	cout << d13 << d14;//cout也是一个对象

	cin >> d15 >> d16;
	cout << d15 << d16;
}

int main()
{
	cout << "测试例1:" << endl;
	TestData1();
	cout << endl << "测试例2:" << endl;
	TestData2();
	cout << endl << "测试例3:" << endl;
	TestData3();
	cout << endl << "测试例4" << endl;
	TestData4();
	cout << endl << "测试例5" << endl;
	TestData5();
	cout << endl << "测试例6" << endl;
	TestData6();
	return 0;
}