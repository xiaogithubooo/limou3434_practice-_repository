#include <cstdio>
void func()
{
	printf("int");
}
int main()
{
	printf("%p", func);
	func();
}