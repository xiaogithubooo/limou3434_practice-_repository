//一个线程打印奇数，一个线程打印偶数（使用条件变量）
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <windows.h>
using namespace std;

int main()
{
	int i = 0;
	int n = 100;
	mutex mtx;
	condition_variable cv; //条件变量

	thread t1([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock); //先提前进入等待状态

			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;
		}
	});

	thread t2([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock); //先提前进入等待状态

			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;
		}
	});

	while (true)
	{
		cv.notify_one(); //主线程依次唤醒子线程
		if (i == 100)
			break;
	}

	t1.join();
	t2.join();
	return 0;
}