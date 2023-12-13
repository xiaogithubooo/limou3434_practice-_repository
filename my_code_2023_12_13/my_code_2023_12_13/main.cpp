#include <iostream>
#include "union_find_set.hpp"
using namespace std;
using namespace limou;
int main()
{
	string arr[3] = { "limou", "dimou", "iimou" };
	UnionFindSet<string> ufs(arr, 3);
	return 0;
}