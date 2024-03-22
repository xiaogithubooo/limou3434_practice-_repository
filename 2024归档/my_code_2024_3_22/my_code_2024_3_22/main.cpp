//һ���̴߳�ӡ������һ���̴߳�ӡż����ʹ������������
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
	condition_variable cv; //��������

	thread t1([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock); //����ǰ����ȴ�״̬

			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;
		}
	});

	thread t2([&]() {
		while (i < n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock); //����ǰ����ȴ�״̬

			cout << this_thread::get_id() << ":" << i << endl;
			i += 1;
		}
	});

	while (true)
	{
		cv.notify_one(); //���߳����λ������߳�
		if (i == 100)
			break;
	}

	t1.join();
	t2.join();
	return 0;
}