#include "main.hpp"
#include <iostream>
#include <string>
using std::string;

int main()
{
	limou::AVLTree<int, string> a;
	a.Inster(make_pair(10, "a"));
	a.Inster(make_pair(8, "b"));
	a.Inster(make_pair(20, "c"));
	a.Inster(make_pair(5, "d"));
	a.Inster(make_pair(9, "e"));
	a.Inster(make_pair(15, "f"));
	a.Inster(make_pair(25, "g"));
	a.Inster(make_pair(19, "h"));
	a.Inster(make_pair(22, "i"));
	a.Inster(make_pair(30, "j"));
	a.Inster(make_pair(32, "k"));//这个插入需要调整结点

	return 0;
}