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
			cout << "capacity changed: " << sz << endl;//����Ϊʲô�ֶ��ӡ��һ�Σ������Ժ���������
		}
	}
}
int main()
{
	test();
}