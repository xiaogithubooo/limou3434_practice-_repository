#define _CRT_SECURE_NO_WARNINGS	1
#pragma once
#include <cstring>
#include <iostream>
namespace limou
{
	//模拟实现string
	class string
	{
	public:
		//1.构造函数
		string(const char * str = "")//“ "" ”的内部隐含了'\0'
			:_str(new char[strlen(str)+1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{
			strcpy(_str, str);
		}
		//2.析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test_1()
	{
		limou::string s1("hello world");
		limou::string s2;
		std::cout << s1.c_str() << std::endl;
		std::cout << s2.c_str() << std::endl;
	}
}