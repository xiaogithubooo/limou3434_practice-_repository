#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int number = (3, 4);

	int arr[] = { 1, 2, number, 5 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%zd", sizeof(arr));
	return 0;
	
}