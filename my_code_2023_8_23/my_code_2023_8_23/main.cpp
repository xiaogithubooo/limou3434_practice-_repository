#include <iostream>
#include <vector>
#include <list>
using namespace std;
void test_1()
{
		vector<int>array;
		array.push_back(100);
		array.push_back(300);
		array.push_back(300);
		array.push_back(300);
		array.push_back(300);
		array.push_back(500);
		//100 300 300 500

		vector<int>::iterator itor;
		for (itor = array.begin(); itor != array.end(); itor++)
		{
			if (*itor == 300)
			{
				itor = array.erase(itor);
			}
		}
		for (itor = array.begin(); itor != array.end(); itor++)

		{
			cout << *itor << " ";
		}
}
void test_2()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);//得到10
	vector<int> v(ar, ar + n);

	cout << v.size() << ":" << v.capacity() << endl;
	//输出10 : 10

	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;
	//输出20 : 100

	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;
	//输出5 : 100
}
void test_3()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);//得9
	vector<int> v(ar, ar + n);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it != 0)//1 2 3 4 |5 6 7 8 9
			cout << *it;
		else
			v.erase(it);
		it++;
	}
}
void test_4()
{
	//构造好链表
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);//得到10
	list<int> mylist(ar, ar + n);

	//查早5这个元素，返回指向5的迭代器
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);//->4, 3, 2, 1, 0, 5, 6, 7, 8, 9
	reverse(pos, mylist.end());//->4, 3, 2, 1, 0, 9, 8, 7, 6, 5
	list<int>::const_reverse_iterator crit = mylist.crbegin();
	while (crit != mylist.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;//5,6,7,8,9,0,1,2,3,4
}

template<typename T>
void removeDuplicates(list<T> &aList)
{
	T curValue;
	typename list<T>::iterator cur, p;
	cur = aList.begin();
	while (cur != aList.end())
	{
		curValue = *cur;
		p = ++cur;
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				if (p == cur)//之所以有这个情况是因为
				{
					cur = p = aList.erase(p);
				}
				else
				{
					p = aList.erase(p);
				}
			}
			else
			{
				p++;
			}
		}
	}
}
void test_5()
{
	list<int> li;
	li.push_back(1);
	li.push_back(3);
	li.push_back(3);
	li.push_back(3);
	li.push_back(4);
	//1133131444

	removeDuplicates(li);
	list<int>::iterator it = li.begin();
	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << " ";
	}
}

int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();
	return 0;
}

////void test_1()
////{
////	unsigned int un = 3000;
////	//30 0000 0000的二进制是1011 0010 1101 0000 0101 1110 0000 0000
////	//存储的方式是无符号整数因此补码就是：1011 0010 1101 0000 0101 1110 0000 0000
////
////	//如果以有符号打印，就会认为是负数
////	//1011 0010 1101 0000 0101 1110 0000 0000（补码）
////	//1011 0010 1101 0000 0101 1101 1111 1111（反码）
////	//1100 1101 0010 1111 1010 0010 0000 0000（原码）
////	//1001101001011111010001000000000 = -1294967296
////	printf("%u %d", un, un);
////}
////void test_2()
////{
////	//a=97, b=98 ,c=99, d=100
////	//小端
////
////	char a = 'abcd';
////	
////	int b = 'abcd';
////	//由于是小端所以逆向字节存储
////	//100 99 98 97
////	//64 63 62 61，刚好就是内存中的值
////	//如果取出来，那就是61 62 63 64
////	//也就是01100001 01100010 01100011 01100100
////	//01100001011000100110001101100100作为int类型打印
////	//故打印1633837924
////	printf("%c %d", a, b);
////}
////void test_3()
////{
////	printf("Hello\vWorld!\n");//在字符串中使用\v
////	puts("Hello\vWorld!");//在puts函数中使用\v
////}
////void test_4()
////{
////	float a = 3.4E38 * 100.0f;
////	printf("%f", a);
////}
////void test_5()
////{
/////*
////NaN 是“IEEE 754”浮点数标准中定义的特殊值，表示“非数字”（Not a Number）。
////NaN 在计算中通常用于表示无效或未定义的操作结果，以及与非数字值的运算。它可以由以下情况产生：
////1.零除以零：例如，0.0/0.0。
////2.无穷大减去无穷大：例如，INFINITY - INFINITY。
////3.无效的算术运算：例如，负数的平方根、负数的对数等、asin()输入大于1的参数。
////4.将 NaN 作为函数的参数。
////
////NaN 的特点是：
////1.NaN 不等于任何数，包括它自身。这意味着 NaN == NaN 的结果为 false。
////2.对 NaN 进行任何比较操作（如 <、>、==）的结果都是 false。
////3.对 NaN 进行算术运算（如加法、减法、乘法、除法）的结果仍然是 NaN。
////4.在 C 语言中，可以使用 isnan() 函数来检测一个值是否为 NaN。此函数返回一个非零值如果给定的浮点数是 NaN，否则返回 0。
////*/
////	//double a = 0.0 / 0.0;  //计算结果为NaN
////	double b = sqrt(-1.0); //计算结果为NaN
////	//if (isnan(a))
////	//{
////	//	printf("a 是 NaN\n");
////	//}
////	if (isnan(b))
////	{
////		printf("b 是 NaN\n");
////	}
////	//if (a != a)
////	//{
////	//	printf("a 不等于自身\n");
////	//}
////	if (b != b)
////	{
////		printf("b 不等于自身\n");
////	}
////}
//void test_6()
//{
//	printf("abcdef");
//	fflush(stdout);
//}
//int main()
//{
//	//test_1();
//	//test_2();
//	//test_3();
//	//test_4();
//	//test_5();
//	test_6();
//
//	return 0;
//}
///*
//??=include <stdio.h>
//int main()
//??<
//	printf("??(??)");
//	return 0;
//??>
//*/