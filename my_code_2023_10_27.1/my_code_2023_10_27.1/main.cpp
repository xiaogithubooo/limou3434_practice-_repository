#include "queue.hpp"
void Test()
{
	limou::Queue<double> q1(0);//空队列
	q1.Push(1);
	q1.Print();
	q1.Push(3);
	q1.Print();

	limou::Queue<double> q2(5);//普通队列
	int n = 6;
	while (n--)
	{
		q2.Push(n);
	}
	q2.Print();

	q2.Pop();
	q2.Push(-1);
	q2.Print();

	q2.Pop();
	q2.Push(-2);
	q2.Print();

	q2.Pop();
	q2.Push(-3);
	q2.Print();

	q2.Pop();
	q2.Push(-4);
	q2.Print();

	q2.Pop();
	q2.Push(-5);
	q2.Print();

	q2.Pop();
	q2.Push(-6);
	q2.Print();
}
int main()
{
	Test();
	return 0;
}