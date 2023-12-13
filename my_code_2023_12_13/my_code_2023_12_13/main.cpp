#include <iostream>
#include "union_find_set.hpp"
using namespace std;
using namespace limou;
int main()
{
	//{0}, {1}, {2}, {3}
	UnionFindSet<> ufs(4);
	cout << ufs.Count() << '\n';
	if (ufs.InSet(1, 2))
		cout << "OK" << '\n';

	//{0, 1, 2}, {3}
	ufs.Union(0, 1);
	ufs.Union(1, 2);
	cout << ufs.Count() << '\n';
	if (ufs.InSet(1, 2))
		cout << "OK" << '\n';

	//{0, 1, 2} root->0
	//{3} root->3
	cout << ufs.FindRoot(2) << '\n';
	cout << ufs.FindRoot(3) << '\n';

	return 0;
}