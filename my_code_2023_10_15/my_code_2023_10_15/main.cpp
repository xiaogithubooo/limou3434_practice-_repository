#include "AVLTree.hpp"
int main()
{
	limou::AVLTree<int, string> A;
	pair<int, string> a1(4, "aaa");
	pair<int, string> a2(1, "bbb");
	pair<int, string> a3(5, "ccc");
	pair<int, string> a4(2, "ddd");
	A.Inster(a1);
	A.Inster(a2);
	A.Inster(a3);
	A.Inster(a4);
	return 0;
}