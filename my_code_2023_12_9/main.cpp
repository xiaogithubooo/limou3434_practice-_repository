#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	volatile const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;

    printf("%p\n", &a);
    cout << &a << endl;
    cout << (int*)&a << endl;

	return 0;
}