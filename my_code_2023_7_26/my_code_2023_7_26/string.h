#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <cstring>
#include <cassert>
#include <iostream>
namespace limou
{
	//模拟实现string
	class string
	{
	public:
		//> 0.迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		//> 1.构造函数
		string(const char* str = "")/* “ "" ”的内部隐含了'\0'，如果自己再写'\0'实际上是画蛇添足，没有必要 */
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//> 2.析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//> 3.拷贝构造和赋值运算符重载
		//传统写法
		//string(const string& str)
		//	: _capacity(str._capacity),
		//	_size(str._size),
		//	_str(new char[_capacity + 1])
		//{
		//	strcpy(_str, str._str);//深拷贝
		//}
		//string& operator=(const string& str)
		//{
		//	if (this != &str)//避免自己拷贝自己问题
		//	{
		//		char* cache = new char[_capacity + 1];
		//		strcpy(cache, str._str);//深拷贝
		//		delete[] _str;
		//		_capacity = str._capacity;
		//		_size = str._size;
		//		_str = cache;
		//	}
		//	return *this;
		//}
		//现代写法（效率其实没什么差异，但是很简洁）
		void swap(string& tmp)
		{
			std::swap(_capacity, tmp._capacity);
			std::swap(_size, tmp._size);
			std::swap(_str, tmp._str);
		}
		string(const string& str)
			: _capacity(0)//这个初始化列表是必须的，避免后面的tmp无法被析构
			, _size(0)
			, _str(nullptr)
		{
			string tmp(str._str);//注意这里是构造函数
			swap(tmp);//这里的swap()不是库里的那个函数，只是交换sring类的，这个函数的定义在上面
		}
		//string& operator=(const string& str)
		//{
		//	if (this != &str)//避免自己拷贝自己问题
		//	{
		//		string tmp(str._str);
		//		swap(tmp);
		//	}
		//	return *this;
		//}//还可以优化为下面这个代码
		string& operator=(string str)//str相当于tmp单位拷贝构造
		{
			swap(str);
			return *this;
		}
		//> 4.符号重载函数
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		string& operator+=(char ch)
		{
			//复用后面的push_back()
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			//复用后面的append()
			append(str);
			return *this;
		}
		//> 4.string工具
		//> 4.1.转化为c的字符串
		const char* c_str() const
		{
			return _str;
		}
		//> 4.2.求得字符串长度和容量
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		//> 4.3.尾插字符到string对象
		void reserve(size_t n)//取得n个空间
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//之所以是n+1，是为了保持_size的最大值是_capacity，并且能够存储'\0'
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//> 4.3.尾插字符串到string对象
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);//使用strcat()可以是可以，但是还需要查早'\0'的位置，因此实际上strcat()这个函数实际上不太好，对于持续的追加数据会造成低效
			_size += len;
		}
		void append(const string& s)
		{
			append(s._str);
		}
		void append(size_t n, char ch)
		{
			//先进行扩容，避免频繁扩容
			reserve(_size + n);
			for (int i = 0; i < n; i++)
			{
				push_back(ch);
			}
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if(_size == _capacity)//满则扩容
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			for(size_t end = _size; end + 1 > pos; end--)
			{
				_str[end + 1] = _str[end];
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
	private:
		size_t _capacity;//string对象的容量
		size_t _size;//string对象的大小
		char* _str;//c风格字符串
	};
	void test_1()
	{
		limou::string s1("hello world");
		limou::string s2;
		std::cout << s1.c_str() << std::endl;
		std::cout << s2.c_str() << std::endl;

		for (int i = 0; i < s1.size(); i++)
		{
			std::cout << s1[i] << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < s1.size(); i++)
		{
			std::cout << ++s1[i] << " ";
		}
		std::cout << std::endl;

		//迭代器测试
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		for (auto ch : s1)//这里之所以什么都没做就可以实现范围for是因为底层就是迭代器
		{
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
	void test_2()
	{
		//检验拷贝构造函数
		std::cout << "检验拷贝构造函数" << std::endl;
		limou::string s1("abcdef");
		std::cout << "s1：" << s1.c_str() << std::endl;
		limou::string s2(s1);
		std::cout << "s2：" << s2.c_str() << std::endl;
		s2[0] = '0';
		s2[1] = '0';
		s2[2] = '0';
		std::cout << "copy" << std::endl;
		std::cout << "s1：" << s1.c_str() << std::endl;
		std::cout << "s2：" << s2.c_str() << std::endl;
		std::cout << std::endl;

		//检验赋值重载（不写重载的话，不仅是浅拷贝，还存在内存泄露）
		std::cout << "检验赋值重载" << std::endl;
		std::cout << "s1：" << s1.c_str() << std::endl;
		std::cout << "s2：" << s2.c_str() << std::endl;
		s1 = s2;
		std::cout << "赋值后" << std::endl;
		std::cout << "s1：" << s1.c_str() << std::endl;
		std::cout << "s2：" << s2.c_str() << std::endl;
		s1[0] = '-';
		s1[1] = '-';
		s1[2] = '-';
		std::cout << "修改后" << std::endl;
		std::cout << "s1：" << s1.c_str() << std::endl;
		std::cout << "s2：" << s2.c_str() << std::endl;
		s2[0] = '+';
		s2[1] = '+';
		s2[2] = '+';
		std::cout << "修改后" << std::endl;
		std::cout << "s1：" << s1.c_str() << std::endl;
		std::cout << "s2：" << s2.c_str() << std::endl;
		std::cout << std::endl;
	}
	void test_3()
	{
		//测试插入单字符
		string str("abcde");
		str.push_back('f');
		std::cout << str.c_str() << std::endl;
		str.push_back('g');
		std::cout << str.c_str() << std::endl;
		str.push_back('h');
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//测试+=单字符
		str += 'i';
		std::cout << str.c_str() << std::endl;
		str += 'j';
		std::cout << str.c_str() << std::endl;
		str += 'k';
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//测试插入字符串
		str.append("--------");
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//测试+=字符串
		str += "++++++++";
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		string s("********");
		str.append(s);
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		str.append(20, 'h');
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		string st;
		st.insert(0, 'c');
		std::cout << st.c_str() << std::endl;
		std::cout << st.capacity() << std::endl;
		st.insert(0, 'x');
		std::cout << st.c_str() << std::endl;
		std::cout << st.capacity() << std::endl;
		st.insert(2, 'd');
		std::cout << st.c_str() << std::endl;
		std::cout << st.capacity() << std::endl;
		st.insert(1, 'c');
		std::cout << st.c_str() << std::endl;
		std::cout << st.capacity() << std::endl;
		st.insert(3, 'o');
		std::cout << st.c_str() << std::endl;
		std::cout << st.capacity() << std::endl;
		std::cout << std::endl;
	}
}