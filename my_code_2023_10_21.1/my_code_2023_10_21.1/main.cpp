#include "AVLTree.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 1000000

int main()
{
	limou::AVLTree<int, char> a;
	//vector<int> arr = { 16,3,7,11,9,26,18,14,15 };
	//vector<int> arr = { 4,2,6,1,3,5,15,7,16,14 };
	//vector<int> arr = {};
	//vector<int> arr = { 1 };
	//vector<int> arr = { 1, 2, 3 };

	srand((unsigned)time(0));
	vector<int> arr;
	for (int i = 0; i < SIZE; i++)
	{
		arr.push_back(rand() % SIZE);
	}

	for (auto it : arr)
	{
		a.Inster(make_pair(it, 'a' + (it % 26)));
	}
	a.InOrder();

	if (a.IsBalance())
	{
		cout << "OK" << endl;
	}

	return 0;
}

