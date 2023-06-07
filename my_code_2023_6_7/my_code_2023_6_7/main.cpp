#define _CRT_SECURE_NO_WARNINGS 1
//类和对象的使用
#include <iostream>
#include <cstdio>
#include "function.h"
using namespace std;
class str
{
private:
	int a;
	int b;
public:
	int Xadd(int x, int y)//C++的结构体是升级版本的结构体
	{
		a = 2;
		b = 5;
		return a * x + b * y;
	}
};
int main()
{
	str X; 
	cl C;
	printf("%d\n", X.Xadd(1, 2));
	C.function();
	return 0;
}