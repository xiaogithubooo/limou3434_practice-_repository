#include "TSMatrix.hpp"

int main()
{
	using Limou::TupNode;
	using Limou::TSMatrix;

	TupNode<int> t1(1, 1, 3);
	TupNode<int> t2(2, 2, 4);
	TSMatrix<int> ts1;
	ts1.Push(t1);
	ts1.Push(t2);

	TupNode<int> t3(3, 3, 5);
	TSMatrix<int> ts2;
	ts2.Push(t3);

	ts1.Add(ts2);
	ts1.Print();

	return 0;
}