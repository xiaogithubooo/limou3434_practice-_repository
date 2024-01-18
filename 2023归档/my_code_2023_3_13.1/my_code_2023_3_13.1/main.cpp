#define _CRT_SECURE_NO_WARNINGS 1
//日志：
//C++的基于范围for使用
#include <iostream>
using namespace std;
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	cout << typeid(b).name() << " " << b << endl;
	cout << typeid(c).name() << " " << c << endl;
	cout << typeid(d).name() << " " << d << endl;
	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
	return 0;
}
int main()
{
	int x = 100;

	auto a = &x;
	auto* b = &x;

	auto& c = x;

	cout << typeid(a).name() << " " << a << endl;
	cout << typeid(b).name() << " " << b << endl;
	cout << typeid(c).name() << " " << c << endl;

	*a = 10;
	*b = 20;
	c = 30;

	return 0;
}
void TestFor()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        array[i] *= 2;
    for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
        cout << *p << endl;
}
int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (auto& e : array)
        e *= 2;
    for (auto e : array)
        cout << e << " ";    
    return 0;
}