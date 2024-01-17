//һ���̴߳�ӡ������һ���̴߳�ӡż������ʽ����ʹ��������������ȷд����
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
	condition_variable cv; //��������
	bool ready = true;

	thread t1([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);

			cv.wait(lock, [&](){ return !ready; }); //����ֵΪ false �ͻ�һֱ�ȴ�����������֮ǰ�Ƚ���
			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;

			ready = true;
			cv.notify_one(); //���������߳�
		}
	});

	thread t2([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			
			cv.wait(lock, [&](){ return ready; }); //����ֵΪ false �ͻ�һֱ�ȴ�����������֮ǰ�Ƚ���
			cout << this_thread::get_id() << ":" << i << endl; 
			i += 1;

			ready = false;
			cv.notify_one(); //���������߳�
		}
	});

	t1.join();
	t2.join();
	return 0;
}

/* ������
��...
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