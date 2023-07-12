#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
void test()
{
	string s;
	s.resize(1000, 'x');
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << endl;
	cout << s << endl;

	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;//至于为什么又多打印了一次，我们以后再来讨论
		}
	}
}
int main()
{
	test();
}