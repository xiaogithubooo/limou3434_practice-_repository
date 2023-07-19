#define _CRT_SECURE_NO_WARNINGS	1
#pragma once
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
		string(const string& str)
		{
		
		}
		//> 2.析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//> 3.符号重载函数
		string& operator=(const string& str)
		{
			
		}
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

		}
		string& operator+=(const char* str)
		{

		}
		//> 4.string工具
		//> 4.1.转化为c的字符串
		const char* c_str() const
		{
			return _str;
		}
		//> 4.2.求得字符串长度
		size_t size() const
		{
			return _size;
		}
		//> 4.3.尾插字符到string对象
		void push_back(char ch)
		{
		
		}
		//> 4.3.尾插字符串到string对象
		void append(const char* str)
		{

		}
	private:
		size_t _capacity;
		size_t _size;
		char* _str;
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
}