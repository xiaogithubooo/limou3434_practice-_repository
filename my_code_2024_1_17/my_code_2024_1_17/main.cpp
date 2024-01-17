//一个线程打印奇数，一个线程打印偶数（方式三：使用条件变量，正确写法）
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int main()
{
	int i = 0;
	int n = 100;
	mutex mtx;
	condition_variable cv; //条件变量
	bool ready = true;

	thread t1([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);

			cv.wait(lock, [&](){ return !ready; }); //返回值为 false 就会一直等待，并且在那之前先解锁
			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;

			ready = true;
			cv.notify_one(); //唤醒其他线程
		}
	});

	thread t2([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			
			cv.wait(lock, [&](){ return ready; }); //返回值为 false 就会一直等待，并且在那之前先解锁
			cout << this_thread::get_id() << ":" << i << endl; 
			i += 1;

			ready = false;
			cv.notify_one(); //唤醒其他线程
		}
	});

	t1.join();
	t2.join();
	return 0;
}

/* 输出结果
略...
*/

//int main()
//{
//	int m = 5;
//	int n = 5;
//	vector<thread> threads(m);
//	mutex mtx;
//	for (int i = 0; i < m; ++i)
//	{
//		threads[i] = thread(
//			[&]() {
//				for (int i = 0; i < n; ++i)
//				{
//					lock_guard<mutex> Lock(mtx);
//					cout << this_thread::get_id() << ":" << i << endl;
//					this_thread::sleep_for(chrono::milliseconds(100));
//				}
//			}
//		);
//	}
//
//	for (auto& e : threads)
//	{
//		e.join();
//	}
//
//	return 0;
//}