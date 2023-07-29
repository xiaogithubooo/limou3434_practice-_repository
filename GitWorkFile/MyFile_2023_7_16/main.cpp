#include<iostream>
using namespace std;
inline int add(int a = 0, int b = 0)//被inline修饰的函数
{
	return a + b;
}
int main()
{	
	int c = 0;
	c = add(3, 5);
	cout << c;
	return 0;
}
