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
			if (!Full())//没满
			{
				_arr[_tail++] = val;
				_tail = _tail % _capacity;

				_tag = -1;
				if (_front == _tail)
				{
					_tag = 1;//满了
				}

				return true;
			}
			return false;
		}
		bool Pop()
		{
			if (!Empty())//没空
			{
				_front++;
				_front = _front % _capacity;

				_tag = -1;
				if (_front == _tail)
				{
					_tag = 0;//空了
				}

				return true;
			}

			return false;
		}
		T& Front()
		{
			assert(!Empty());//不空
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
		int _capacity;//容量
		T* _arr;//指向数据
		int _front;//头指针
		int _tail;//尾指针
		int _tag;//标志位（空0，满1，其余状态-1）
	};
}