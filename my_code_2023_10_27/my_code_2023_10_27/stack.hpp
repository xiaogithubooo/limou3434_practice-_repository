#include <iostream>
#include <cassert>
namespace limou
{
	template<typename T>
	class Stack
	{
	public:
		//1.��Ա
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
		//2.����
		void Push(const T& val)
		{
			//�ж��Ƿ�����
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
			//��ʼ����
			_arr[_size] = val;
			_size++;
		}
		//3.ɾ��
		void Pop()
		{
			assert(_size != 0);
			_size--;
		}
		//4.ջ��
		T& Top()
		{
			assert(_size != 0);
			return _arr[_size - 1];
		}
		//5.��С
		int Size() { return _size; }
		//6.����
		int Capacity() { return _capacity; }
		//7.����
		bool Full()
		{
			return _capacity == _size;//���������ˣ�����
		}
		//8.�п�
		bool empty()
		{
			return 0 == _size;
		}
		//9.��ӡ
		void Print()
		{
			for (int i = 0; i < _size; i++)
			{
				std::cout << _arr[i] << " ";
			}
			std::cout << std::endl;
		}
	private:
		T* _arr;//�洢ջ��Ԫ��
		int _size;//�洢ջ�Ĵ�С��������top���±꣩
		int _capacity;//�洢ջ������
	};
}