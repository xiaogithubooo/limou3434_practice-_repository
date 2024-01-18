#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <iostream>
using namespace std;
inline int ADD(int X, int Y)
{
	return X + Y;
}
int main()
{
	printf("%d\n", ADD(1, 2));
	printf("%d", ADD(1 * 2, 3));
	cout << ADD(2, 3) << endl;
	return 0;
}