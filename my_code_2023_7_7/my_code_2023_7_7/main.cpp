#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
void test()
{
	string s1("1234", 3);//根据字符串的子串长度3初始化
	cout << s1 << endl;
}
int main()
{
	test();
	return 0;
}