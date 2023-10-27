#include <iostream>
#include <cassert>
namespace limou
{
	template<typename T>
	class Queue
	{
	public:
		Queue(int capacity = 10)
			: _capacity(capacity)
			, _arr(new T[_capacity])
			, _front(0)
			, _tail(_front)
			, _tag(0)
		{}
		bool Push(const T& val)
		{
			if (!Full())//û��
			{
				_arr[_tail++] = val;
				_tail = _tail % _capacity;

				_tag = -1;
				if (_front == _tail)
				{
					_tag = 1;//����
				}

				return true;
			}
			return false;
		}
		bool Pop()
		{
			if (!Empty())//û��
			{
				_front++;
				_front = _front % _capacity;

				_tag = -1;
				if (_front == _tail)
				{
					_tag = 0;//����
				}

				return true;
			}

			return false;
		}
		T& Front()
		{
			assert(!Empty());//����
			return _arr[_front];
		}
		int Size()
		{
			if (!Full())
			{
				return (_tail + _capacity - _front) % _capacity;
			}
			return _capacity;
		}
		bool Full()
		{
			if (_tag == 1 || _capacity == 0)
			{
				return true;
			}
			return false;
		}
		bool Empty()
		{
			if (_tag == 0)
			{
				return true;
			}
			return false;
		}
		void Print()
		{
			int cur = _front;
			int n = Size();
			while (n--)
			{
				std::cout << _arr[cur] << " ";
				cur++;
				cur = cur % _capacity;
			}
			std::cout << std::endl;
		}
	private:
		int _capacity;//����
		T* _arr;//ָ������
		int _front;//ͷָ��
		int _tail;//βָ��
		int _tag;//��־λ����0����1������״̬-1��
	};
}