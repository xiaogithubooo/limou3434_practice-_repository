#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	//vector<int> arr{ 1, 2, 3, 4, 5 };
	array<int, 5> arr{ 1, 2, 3, 4, 5 };
	//int arr[5]{ 1, 2, 3, 4, 5 };
	arr.at(6) = 0;
	cout << arr[6] << endl;
	return 0;
}