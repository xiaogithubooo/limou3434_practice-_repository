#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
namespace limou
{
	template <typename T>//顺序表内的元素
	class SeqList
	{
	public:
		//1.基本成员函数
		//1.1.构造
		SeqList(int capacity = 4)
			: _arr(nullptr), _size(0), _capacity(0)
		{
			_arr = new T[capacity];
			_capacity = capacity;
		}
		//1.2.析构
		~SeqList()
		{
			delete[] _arr;
		}
		//1.3.拷贝构造(SeqList<int> seq1 = seq2)
		void Swap(SeqList<T>& seq)
		{
			std::swap(_arr, seq._arr);
			std::swap(_size, seq._size);
			std::swap(_capacity, seq._capacity);
		}
		SeqList(SeqList<T>& seq)
		{
			SeqList<T> temp;
			for (int i = 0; i < seq._size; i++)
			{
				temp.Insert(i, seq._arr[i]);//不断尾插
			}
			Swap(temp);
		}
		//1.4.赋值重载(s3 = s2)
		SeqList& operator=(SeqList<T> &seq)
		{
			//this是s3，seq是s2
			SeqList<T> temp(seq);
			Swap(temp);
			return *this;
		}
		
		//2.操作成员函数
		//2.1.任意插入（向pos插入）
		void Insert(int pos, const T& val)
		{
			if (IsFull())//如果为满
			{
				std::cout << "顺序表已满，继续扩容" << std::endl;
				Reserve(_capacity * 2);
			}
			for (int i = _size; i > pos; i--)
			{
				std::swap(_arr[i], _arr[i - 1]);
			}
			_size++;
			_arr[pos] = val;
		}
		void PushBack(const T& val)//尾插
		{
			Insert(Size(), val);
		}
		//2.2.任意删除
		void Erase(int pos)
		{
			if (Empty())//如果为空
			{
				std::cout << "顺序表已空，不可以再删" << std::endl;
				return;
			}
			for (int i = pos + 1; i < _size; i++)
			{
				std::swap(_arr[i], _arr[i - 1]);
			}
			_size--;
		}
		void PopBack()
		{
			Erase(Size());
		}
		//2.3.查找
		int Find(const T& val)
		{
			for (int i = 0; i < _size; i++)
			{
				if (_arr[i] == val)
				{
					return i;
				}
			}
			return -1;
		}
		//2.4.判空（空为真）
		bool Empty()
		{
			return _size == 0;
		}
		//2.5.判满（满为真）
		bool IsFull()
		{
			return _capacity == _size;
		}
		//2.6.改变大小（可大可小）
		void Resize(int x)
		{
			assert(x >= 0);
			//1.但是如果扩容太大，就有可能导致容量不够用
			while (x > _capacity)
			{
				Reserve(2 * _capacity);//扩容即可，不过需要注意都是随机值。
			}
			//2.如果是“缩小”或者“刚好”就没关系，直接_size减小就可以
			_size = x;
		}
		//2.7.改变容量（不可缩小）
		void Reserve(int x)
		{
			if (x != _capacity)
			{
				//1.检查合法性（不可以缩小，只能不变或者增大）
				assert(x >= _capacity);
				//2.改为新的空间，并且迁移数据
				T* temp = new T[x];
				for (int i = 0; i < _size; i++)
				{
					temp[i] = _arr[i];
				}
				//3.销毁旧的空间
				delete[] _arr;
				_arr = temp;
				_capacity = x;
			}
			//x == _capacity
		}
		//2.8.返回大小
		int Size()
		{
			return _size;
		}
		//2.9.返回容量
		int Capacity()
		{
			return _capacity;
		}
		//2.10.方括号重载
		T& operator[](int pos)
		{
			assert(pos >= 0);
			assert(pos <= Size());
			return _arr[pos];
		}
		//2.11.迭代器
		typedef T* iterator;
		iterator Begin()
		{
			return _arr;
		}
		iterator End()
		{
			//1,2,3,4  size = 4
			return _arr + _size;
		}

	private:
		T* _arr;//存储数据
		int _size;//存储顺序表的大小
		int _capacity;//存储顺序表的容量
	};
}