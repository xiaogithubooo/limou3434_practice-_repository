#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int function(const int& a, const int& b)
{
	return a + b;
}
int main()
{
	int a = 10;
	int b = 2;
	cout << function(a, b) << endl;
	cout << function(10, 2) << endl;
	return 0;
}