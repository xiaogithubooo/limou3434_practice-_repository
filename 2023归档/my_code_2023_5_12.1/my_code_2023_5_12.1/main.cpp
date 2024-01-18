#include <iostream>
using namespace std;
void fun(int a = 0);
int main()
{
	fun();
	return 0;
}
void fun(int a = 0)
{
	if (a == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", a);
	}
}