#include <iostream>
#include <cassert>
#include <string>
/*
看源代码不要上来就一行一行看，先看文档再进行使用，再整理框架（梳理类、变量、接口），然后“连蒙带猜”验证细节
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
			if (n > capacity())//如果指定的数字大于现有容量就扩容
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)//如果不是空容器
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				_start = tmp;//由于这里更换成了tmp
				_finish = tmp + sz;//而这里原本的_finish是指向别的空间指针，所以必须要修改
				_end_of_storage = tmp + n;//同理这里也做修改
			}
		}
		void resize(size_t n, const T& val = T())
			//这里给了默认匿名参数T()，
			//注意匿名对象具有常属性，
			//这也是为什么在C++之后支持“int i = int(3);”
			//这种语法就是因为：
			//在类模板出现后没有办法确认是内置类型，还是自定义类型
			//并且还会给与自定义类型默认值
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
			//if (_finish == _end_of_storage)//如果容量不足
			//{
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);//2倍容量
			//}
			//*_finish = x;
			//_finish++;
			inster(end(), x);
		}
		void insert(iterator pos, const T& x)
		{
			//检验是否合法
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)//如果容量不足
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);//2倍容量
				pos = _start + len;
				//上面这里还解决了迭代器失效的问题。
				//由于扩容导致的问题，pos指向旧空间的某个位置时，
				//旧空间没了，没能指向新空间，因此这里必须进行更新。
				
				//但是由于这里没有办法使用引用（传过来的pos迭代器是一个值），
				//因此本函数insert()使用过后迭代器就会失效，只能保证在本函数内有效。
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
		//三个迭代器成员变量
		iterator _start;//指向“存储空间”或者“存储”开始的位置
		iterator _finish;//指向“存储”结束的位置
		iterator _end_of_storage;//指向“存储空间”结束的位置
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
			std::cout << "空字符=[" << str3 << "]" << " ";
		}std::cout << std::endl;

		vector<std::string> v4;
		v4.resize(5, "abcd");
		for (auto str4 : v4)
		{
			std::cout << "字符=[" << str4 << "]" << " ";
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
		v1.push_back(1);//内部使用了一次insert()因此迭代器失效
		std::cout << v1[0] << std::endl;
		v1.push_back(2);//但是又重新使用insert()的时候重新计算了迭代器，使用后迭代器又失效了
		std::cout << v1[0] << std::endl;
		v1.push_back(3);
		std::cout << v1[0] << std::endl;

		vector<int> v2;
		v2.insert(v2.begin(), 1);//内部使用了一次insert()因此迭代器失效
		std::cout << v2[0] << std::endl;
		v2.insert(v2.begin(), 2);//但是又重新使用insert()的时候重新计算了迭代器，使用后迭代器又失效了
		std::cout << v2[0] << std::endl;
		v2.insert(v2.begin(), 3);
		std::cout << v2[0] << std::endl;


	}
}
 