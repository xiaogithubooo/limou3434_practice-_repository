#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;

void Print(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << this_thread::get_id() << " ���:" << i << '\n';
		this_thread::sleep_for(chrono::milliseconds(100)); //���� 100 ΢�������
	}		

}

int main()
{
	vector<thread> threads;
	for (int i = 0; i < 3; i++)
	{
		threads.push_back(thread(Print, 10)); //ע������ֻ��ʹ���ƶ����죨�̶߳���������������˴�����
	}

	for (int i = 0; i < 3; i++)
	{
		threads[i].join();
	}

	return 0;
}