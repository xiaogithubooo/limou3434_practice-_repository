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
		template <typename InputIterator>//����֮������Ƕ��һ����ģ���ԭ���ǣ��ܹ�ʹ�ö�������ĵ�����������������T���͵ĵ�����
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		vector(size_t n, const T& val = T())//����һ���������󣬲����Զ���ʼ��
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())//���������ר�Ÿ���������׼���ģ�����int�������ؾͻ���óɵ�������ʼ��
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector<T>& operator=(vector tmp)//�ȿ���һ�ݣ�����������һ�죬��������д��vector��vector<T>��һ���ģ���Ȼ���ǽ���дȫ
		{
			swap(tmp);
			return *this;
		}
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
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		//3.1.ʹ��memcpy()��������ǳ���������⣬��˲�����ʹ���������
		//void reserve(size_t n)
		//{
		//	if (n > capacity())//���ָ�������ִ�����������������
		//	{
		//		T* tmp = new T[n];
		//		size_t sz = size();
		//		if (_start)//������ǿ�����
		//		{
		//			memcpy(tmp, _start, sizeof(T) * sz);
		//			delete[] _start;//�����п�����Ϊǳ����������
		//		}
		//		_start = tmp;//���������������tmp
		//		_finish = tmp + sz;//������ԭ����_finish��ָ���Ŀռ�ָ�룬���Ա���Ҫ�޸�
		//		_end_of_storage = tmp + n;//ͬ������Ҳ���޸�
		//	}
		//}
		//3.2.�����������ʹ�ÿ�������
		void reserve(size_t n)
		{
			if (n > capacity())//���ָ�������ִ�����������������
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)//������ǿ�����
				{
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
						//�������������Զ����ò�ͬ���͵��������ֵ�������أ���
						//�������п���������д��Ҳ�п����ǿ���ġ���
					}
					delete[] _start;
				}
				_start = tmp;//���������������tmp
				_finish = _start + sz;//������ԭ����_finish��ָ���Ŀռ�ָ�룬���Ա���Ҫ�޸�
				_end_of_storage = _start + n;//ͬ������Ҳ���޸�
			}
		}
		//3.3.��Ȼ������һ�ַ�����ʹ�����ü����������������������ʱ����������ط����������string����ʹ�����ü���Ч�ʾͻ��кܴ����ߣ�
		//3.4.���⣬���е�ʵ��ʹ���˿������죬��Ϊ�˼�ʹ�õ��Ƕ�λnew����˿��Ե��ã��������Լ���ֱ��ʹ��new�ģ��Ѿ��������������ˣ�ֻ��ʹ�ø�ֵ����
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
		//ע��insert()��erase()��ʹ�ù������������ʧЧ���ڿ��оͿ������÷���ֵ�����������⣬�����Լ�ʵ�ֵľ�û��ʵ��insert()�ķ���ֵ
		void push_back(const T& x)
		{
			//if (_finish == _end_of_storage)//�����������
			//{
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);//2������
			//}
			//*_finish = x;
			//_finish++;
			insert(end(), x);
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
		//1.��һ��erase����д������˵�����ʧЧ������
		//void erase(iterator pos)
		//{
		//	//�����Ƿ�Ϸ�
		//	assert(pos >= _start);
		//	assert(pos <= _finish);
		//	//{1,2,3,4,5}
		//	//pos->3,it->4,{1,2,4,5}
		//	//{1},pos->1,it=_finish
		//	iterator it = pos + 1;
		//	while (it < _finish)
		//	{
		//		*(it - 1) = *it;
		//		it++;
		//	}
		//	--_finish;
		//}
		//2.�ڶ��ֿ��Խ��������ʧЧ�����⣬���ص���ԭpos�ĺ�һ�����ݵĵ�������Ҳ����ɾ����pos��λ��
		iterator erase(iterator pos)
		{
			//�����Ƿ�Ϸ�
			assert(pos >= _start);
			assert(pos <= _finish);
			//{1,2,3,4,5}
			//pos->3,it->4,{1,2,4,5}
			//{1},pos->1,it=_finish
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
			return pos;
		}
		//6.other
		void swap(vector<int>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
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
		std::cout << v1[v1.size() - 1] << " ";
		v1.push_back(2);//����������ʹ��insert()��ʱ�����¼����˵�������ʹ�ú��������ʧЧ��
		std::cout << v1[v1.size() - 1] << " ";
		v1.push_back(3);
		std::cout << v1[v1.size() - 1] << " ";
		std::cout << std::endl;

		vector<int> v2;
		v2.insert(v2.begin(), 1);//�ڲ�ʹ����һ��insert()��˵�����ʧЧ
		std::cout << v2[v2.size() - 1] << " ";
		v2.insert(v2.begin(), 2);//����������ʹ��insert()��ʱ�����¼����˵�������ʹ�ú��������ʧЧ��
		std::cout << v2[v2.size() - 2] << " ";
		v2.insert(v2.begin(), 3);
		std::cout << v2[v2.size() - 3] << " ";
		std::cout << std::endl;

		//����ʾ������Ϊ������ʧЧ��
		vector<int> v3;
		v3.insert(v3.begin(), 4);
		v3.insert(v3.begin(), 3);
		v3.insert(v3.begin(), 2);
		vector<int>::iterator it = v3.begin();
		v3.insert(it, 1);//��������������ʧЧ��
		v3.insert(it, 0);
		v3.insert(it, 0);
		for (int i = 0; i < 7; i++)
		{
			std::cout << v3[i] << " ";
		}std::cout << std::endl;
	}
	void test_5()
	{
		////1.ʹ��erase()��ʱ��һ�㲻����ֵ�����ʧЧ������
		//vector<int> v;
		//v.push_back(0);
		//std::cout << v[0] << std::endl;
		//v.erase(v.begin());
		//v.push_back(1);
		//v.push_back(2);
		//v.push_back(3);
		//v.push_back(4);
		//vector<int>::iterator it = v.begin();
		//while (it != v.end())
		//{
		//	std::cout << *it << " ";
		//	it++;
		//}

		//2.������һ��������Σ��
		//��������Ҫɾ��һ�������е�ż��
		//������һ������
		//{1,2,3,4,5}����
		//{1,2,3,4,5,6}����
		//{2,2,3,4,5}�������
		vector<int> vbug;
		vbug.push_back(1);
		vbug.push_back(2);
		vbug.push_back(3);
		vbug.push_back(4);
		vbug.push_back(5);
		vbug.push_back(6);
		vbug.push_back(7);
		vbug.push_back(8);
		vbug.push_back(9);
		vbug.push_back(10);

		auto it = vbug.begin();

		//1.����ʹ��
		//while (it != vbug.end())
		//{
		//	if (*it % 2 == 0)
		//	{
		//		vbug.erase(it);
		//	}
		//	//����{1,2,3,4,5,6,7,8,9,10}
		//	//�����һ��ֻʣ��{1,3,5,7,9,10}��ʱ��
		//	//it->10,_finish->10����Ŀռ䣬�����erase��ʱ��ɾ��10�Ĳ������_finish--
		//	//����ѭ����������end()ָ���λ�û���ԭ����_finishλ��
		//	it++;
		//	//�������һ����ʹ��it++,it->�ɵ�_finish
		//	//���ص�ѭ��������ʱ��end()���½����˼��㣨����Ϊ�µ�_finish--��
		//	//��ʱit��end()��λ��*it������Ұָ��
		//  //���µ�����ʧЧ
		//}

		//for (auto e : vbug)
		//{
		//	std::cout << e << " ";
		//}
		//std::cout << std::endl;

		//2.debug��
		while (it != vbug.end())
		{
			if (*it % 2 == 0)
			{
				vbug.erase(it);
			}

			if (it == vbug.end())
				break;
			it++;
		}

		for (auto e : vbug)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		//3.ʹ���ܽ�
		//����ʵ����������ݴ���������ż������ʹ��debug��İ汾Ҳ��������⣨��������ܹ�ֻ���ɺϣ�
		//����ں��ھͻ�����һЩ����ָ��Ľ������
		//���������Ϊʹ��erase()��ᵼ��֮ǰ�ĵ�����ʧЧ
 	}
	//���ڵ�����ʧЧ������һ��������������޸ķ���ֵ������
	void test_6()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(6);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
	}
	void test_7()
	{
		vector<std::string> v1;
		v1.push_back("1111111111111111111111");
		v1.push_back("1111111111111111111111");
		v1.push_back("1111111111111111111111");
		v1.push_back("1111111111111111111111");
		v1.push_back("1111111111111111111111");
		for (auto e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	void test_8()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		vector<int> v2(v1);
		for (auto& e : v1)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
		for (auto& e : v2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		vector<int> v3;
		v3 = v2;
		for (auto& e : v3)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	void test_9()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		std::string str("abcdef");

		vector<int> v2(v1.begin(), v1.end());
		for (int i = 0; i < v2.size(); i++)
		{
			std::cout << v2[i] << " ";
		}std::cout << std::endl;

		vector<int> v3(str.begin() + 1, str.end() - 1);
		for (int j = 0; j < v3.size(); j++)
		{
			std::cout << v3[j] << " ";
		}std::cout << std::endl;
	}
	void test_10()
	{
		vector<int> v1(10, 1);
		vector<std::string> v2(5, "xxxx");
		for (int i = 0; i < v1.size(); i++)
		{
			std::cout << v1[i] << " ";
		}
		std::cout << std::endl;
		for (int j = 0; j < v2.size(); j++)
		{
			std::cout << v2[j] << " ";
		}
		std::cout << std::endl;
	}
}
/*
vectorû�������أ���Ϊ����֣����޷�֪������ʲô���ĸ�ʽ�������������
*/