#include <iostream>
#include <cassert>
/*
��Դ���벻Ҫ������һ��һ�п����ȿ��ĵ��ٽ���ʹ�ã��������ܣ������ࡢ�������ӿڣ���Ȼ�����ɴ��¡���֤ϸ��
*/
namespace limou
{
	template <typename T>
	class vector
	{
	public:
		typedef T value_type;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;
	public:
		//1.Menber function
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		~vector()
		{
			delete[] _start;
		}
		//2.Iterator
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		//3.Capacity
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		//4.Element access
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
		//5.Modifiers
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)//�����������
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;//2������
				T* tmp = new T[newCapacity];//�����µĿռ�
				if (_start)//������ǿյ������ͽ����ݿ�����tmp
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				size_t sz = size();
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = _start + newCapacity;
			}
			*_finish = x;
			_finish++;
		}
		//6.Allocator
	private:
		//������������Ա����
		iterator _start;//ָ�򡰴洢�ռ䡱���ߡ��洢����ʼ��λ��
		iterator _finish;//ָ�򡰴洢��������λ��
		iterator _end_of_storage;//ָ�򡰴洢�ռ䡱������λ��
	};
	void test_1()
	{
		vector<int> v1;

		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
			std::cout << v1[i]++ << " ";
		}
		std::cout << std::endl;

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			std::cout << (*it++)++ << " ";
		}
		std::cout << std::endl;

		for (auto in : v1)
		{
			std::cout << in << " ";
		}

		const vector<float> v2;
		
		//for (int i = 0; i < 10; i++)
		//{
		//	v2.push_back((float)i + 0.1);
		//	std::cout << v2[i]++ << " ";
		//}
	}
}
 