#include <iostream>
#include <cassert>
#include <string>
/*
��Դ���벻Ҫ������һ��һ�п����ȿ��ĵ��ٽ���ʹ�ã��������ܣ������ࡢ�������ӿڣ���Ȼ�����ɴ��¡���֤ϸ��
*/
namespace limou
{
	template <typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
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
		void reserve(size_t n)
		{
			if (n > capacity())//���ָ�������ִ�����������������
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)//������ǿ�����
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				_start = tmp;//���������������tmp
				_finish = tmp + sz;//������ԭ����_finish��ָ���Ŀռ�ָ�룬���Ա���Ҫ�޸�
				_end_of_storage = tmp + n;//ͬ������Ҳ���޸�
			}
		}
		void resize(size_t n, const T& val = T())
			//�������Ĭ����������T()��
			//ע������������г����ԣ�
			//��Ҳ��Ϊʲô��C++֮��֧�֡�int i = int(3);��
			//�����﷨������Ϊ��
			//����ģ����ֺ�û�а취ȷ�����������ͣ������Զ�������
			//���һ�������Զ�������Ĭ��ֵ
		{
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			reserve(n);
			while (_finish < _start + n)
			{
				*_finish = val;
				_finish++;
			}
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
			//if (_finish == _end_of_storage)//�����������
			//{
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);//2������
			//}
			//*_finish = x;
			//_finish++;
			inster(end(), x);
		}
		void insert(iterator pos, const T& x)
		{
			//�����Ƿ�Ϸ�
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)//�����������
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);//2������
				pos = _start + len;
				//�������ﻹ����˵�����ʧЧ�����⡣
				//�������ݵ��µ����⣬posָ��ɿռ��ĳ��λ��ʱ��
				//�ɿռ�û�ˣ�û��ָ���¿ռ䣬������������и��¡�
				
				//������������û�а취ʹ�����ã���������pos��������һ��ֵ����
				//��˱�����insert()ʹ�ù���������ͻ�ʧЧ��ֻ�ܱ�֤�ڱ���������Ч��
			}

			iterator end = _finish - 1;
			//1,2,3,4,5
		   //^       ^
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
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
	void test_2()
	{
		vector<int> v1;
		v1.resize(5);
		for (auto in : v1)
		{
			std::cout << in << " ";
		}std::cout << std::endl;

		vector<int*> v2;
		v2.resize(5);
		for (auto p : v2)
		{
			std::cout << (void*)p << " ";
		}std::cout << std::endl;

		vector<std::string> v3;
		v3.resize(5);
		for (auto str3 : v3)
		{
			std::cout << "���ַ�=[" << str3 << "]" << " ";
		}std::cout << std::endl;

		vector<std::string> v4;
		v4.resize(5, "abcd");
		for (auto str4 : v4)
		{
			std::cout << "�ַ�=[" << str4 << "]" << " ";
		}std::cout << std::endl;
	}
	void test_3()
	{
		vector<int> v1;
		v1.insert(v1.begin(), 1);
		v1.insert(v1.begin() + 1, 2);
		v1.insert(v1.begin() + 2, 3);
		for (auto in : v1)
		{
			std::cout << in << " ";
		}
		std::cout << std::endl;
	}
	void test_4()
	{
		vector<int> v1;
		v1.push_back(1);//�ڲ�ʹ����һ��insert()��˵�����ʧЧ
		std::cout << v1[0] << std::endl;
		v1.push_back(2);//����������ʹ��insert()��ʱ�����¼����˵�������ʹ�ú��������ʧЧ��
		std::cout << v1[0] << std::endl;
		v1.push_back(3);
		std::cout << v1[0] << std::endl;

		vector<int> v2;
		v2.insert(v2.begin(), 1);//�ڲ�ʹ����һ��insert()��˵�����ʧЧ
		std::cout << v2[0] << std::endl;
		v2.insert(v2.begin(), 2);//����������ʹ��insert()��ʱ�����¼����˵�������ʹ�ú��������ʧЧ��
		std::cout << v2[0] << std::endl;
		v2.insert(v2.begin(), 3);
		std::cout << v2[0] << std::endl;


	}
}
 