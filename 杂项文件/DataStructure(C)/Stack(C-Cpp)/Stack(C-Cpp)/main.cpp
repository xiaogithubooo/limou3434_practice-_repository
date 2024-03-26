#include "Stack.hpp"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	limou::Stack<int> s(15);
	int number = 10;
	for (int i = 0; i < number; i++)
	{
		s.Push(i);
		s.Print();
		std::cout << "Top:" << s.Top() << std::endl;
	}
	
	for (int i = 0; i < number; i++)
	{
		s.Pop();
		s.Print();
		if(i != number - 1)
			std::cout << "Top:" << s.Top() << std::endl;
	}
	return 0;
}