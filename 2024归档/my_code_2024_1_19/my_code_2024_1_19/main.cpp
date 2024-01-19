#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "mySharedPtr.hpp" //���������Լ�д�� shared_ptr ͷ�ļ�

using namespace std;

int main()
{
	mutex mtx;

	SmartPtr<int> sp1(new int(1));
	SmartPtr<int> sp2(sp1);

	vector<thread> v(5);
	int n = 1000000;
	for (auto& t : v)
	{
		t = thread([&]() {
				for (size_t i = 0; i < n; ++i)
				{
					SmartPtr<int> sp(sp1); //���ڸ��Ʋ����������ü����������ü����������̰߳�ȫ�ģ�
					mtx.lock();
					(*sp)++;
					mtx.unlock();
				}
			}
		);
	}

	for (auto& t : v)
	{
		t.join();
	}

	cout << *sp1 << endl;

	return 0;
}

/* ���н��
������еĽ��Ψһ����Ϊ 50000001��
*/

//int main()
//{
//	shared_ptr<int> sp1(new int(1));
//	shared_ptr<int> sp2(sp1);
//
//	vector<thread> v(4);
//	int n = 100;
//	for (auto& t : v)
//	{
//		t = thread([&]() {
//				for (size_t i = 0; i < n; ++i)
//				{
//					shared_ptr<int> sp(sp1); //���ڸ��Ʋ����������ü���
//				}
//			}
//		);
//	}
//
//	for (auto& t : v)
//	{
//		t.join();
//	}
//
//	cout << sp1.use_count() << endl;
//
//	return 0;
//}