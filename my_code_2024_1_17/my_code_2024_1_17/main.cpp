#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;

void Print(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << this_thread::get_id() << " 结果:" << i << '\n';
	}
}

int main()
{
	//vector<thread> threads;
	//for (int i = 0; i < 3; i++)
	//{
	//	threads.push_back(thread(Print, 10));
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	threads[i].join();
	//}

	char ch = 'A';
	int number = int(ch); //等价于 (int)ch
	cout << ch << " = " << number << endl;

	return 0;
}