#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
namespace limou
{
	template <typename T>//˳����ڵ�Ԫ��
	class SeqList
	{
	public:
		//1.������Ա����
		//1.1.����
		SeqList(int capacity = 4)
			: _arr(nullptr), _size(0), _capacity(0)
		{
			_arr = new T[capacity];
			_capacity = capacity;
		}
		//1.2.����
		~SeqList()
		{
			delete[] _arr;
		}
		//1.3.��������(SeqList<int> seq1 = seq2)
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
				temp.Insert(i, seq._arr[i]);//����β��
			}
			Swap(temp);
		}
		//1.4.��ֵ����(s3 = s2)
		SeqList& operator=(SeqList<T> &seq)
		{
			//this��s3��seq��s2
			SeqList<T> temp(seq);
			Swap(temp);
			return *this;
		}
		
		//2.������Ա����
		//2.1.������루��pos���룩
		void Insert(int pos, const T& val)
		{
			if (IsFull())//���Ϊ��
			{
				std::cout << "˳�����������������" << std::endl;
				Reserve(_capacity * 2);
			}
			for (int i = _size; i > pos; i--)
			{
				std::swap(_arr[i], _arr[i - 1]);
			}
			_size++;
			_arr[pos] = val;
		}
		void PushBack(const T& val)//β��
		{
			Insert(Size(), val);
		}
		//2.2.����ɾ��
		void Erase(int pos)
		{
			if (Empty())//���Ϊ��
			{
				std::cout << "˳����ѿգ���������ɾ" << std::endl;
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
		//2.3.����
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
		//2.4.�пգ���Ϊ�棩
		bool Empty()
		{
			return _size == 0;
		}
		//2.5.��������Ϊ�棩
		bool IsFull()
		{
			return _capacity == _size;
		}
		//2.6.�ı��С���ɴ��С��
		void Resize(int x)
		{
			assert(x >= 0);
			//1.�����������̫�󣬾��п��ܵ�������������
			while (x > _capacity)
			{
				Reserve(2 * _capacity);//���ݼ��ɣ�������Ҫע�ⶼ�����ֵ��
			}
			//2.����ǡ���С�����ߡ��պá���û��ϵ��ֱ��_size��С�Ϳ���
			_size = x;
		}
		//2.7.�ı�������������С��
		void Reserve(int x)
		{
			if (x != _capacity)
			{
				//1.���Ϸ��ԣ���������С��ֻ�ܲ����������
				assert(x >= _capacity);
				//2.��Ϊ�µĿռ䣬����Ǩ������
				T* temp = new T[x];
				for (int i = 0; i < _size; i++)
				{
					temp[i] = _arr[i];
				}
				//3.���پɵĿռ�
				delete[] _arr;
				_arr = temp;
				_capacity = x;
			}
			//x == _capacity
		}
		//2.8.���ش�С
		int Size()
		{
			return _size;
		}
		//2.9.��������
		int Capacity()
		{
			return _capacity;
		}
		//2.10.����������
		T& operator[](int pos)
		{
			assert(pos >= 0);
			assert(pos <= Size());
			return _arr[pos];
		}
		//2.11.������
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
		T* _arr;//�洢����
		int _size;//�洢˳���Ĵ�С
		int _capacity;//�洢˳��������
	};
}