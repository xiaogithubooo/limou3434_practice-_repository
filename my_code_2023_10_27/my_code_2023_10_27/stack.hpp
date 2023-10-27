#include <iostream>
#include <cassert>
namespace limou
{
	template<typename T>
	class Stack
	{
	public:
		//1.成员
		Stack(int capacity = 4)
			: _arr(new T[capacity]),
			_size(0),
			_capacity(capacity)
		{}
		//Stack(const T& val) {}
		~Stack()
		{
			delete[] _arr;
			_size = 0;
			_capacity = 0;
		}
		//2.插入
		void Push(const T& val)
		{
			//判断是否满了
			if (Full())
			{
				_capacity == 0 ? _capacity = 4 : _capacity = _capacity * 2;
				T* newArr = new T[_capacity];
				for (int i = 0; i < _size; i++)
				{
					newArr[i] = _arr[i];
				}
				delete _arr;
				_arr = newArr;
			}
			//开始插入
			_arr[_size] = val;
			_size++;
		}
		//3.删除
		void Pop()
		{
			assert(_size != 0);
			_size--;
		}
		//4.栈顶
		T& Top()
		{
			assert(_size != 0);
			return _arr[_size - 1];
		}
		//5.大小
		int Size() { return _size; }
		//6.容量
		int Capacity() { return _capacity; }
		//7.判满
		bool Full()
		{
			return _capacity == _size;//容量不够了，满了
		}
		//8.判空
		bool empty()
		{
			return 0 == _size;
		}
		//9.打印
		void Print()
		{
			for (int i = 0; i < _size; i++)
			{
				std::cout << _arr[i] << " ";
			}
			std::cout << std::endl;
		}
	private:
		T* _arr;//存储栈的元素
		int _size;//存储栈的大小（并且是top的下标）
		int _capacity;//存储栈的容量
	};
}