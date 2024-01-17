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
		this_thread::sleep_for(chrono::milliseconds(100)); //休眠 100 微秒再输出
	}		

}

int main()
{
	vector<thread> threads;
	for (int i = 0; i < 3; i++)
	{
		threads.push_back(thread(Print, 10)); //注意这里只能使用移动构造（线程对象不允许拷贝），因此从这里
	}

	for (int i = 0; i < 3; i++)
	{
		threads[i].join();
	}

	return 0;
}