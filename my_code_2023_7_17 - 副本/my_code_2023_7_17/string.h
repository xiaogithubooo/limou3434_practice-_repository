#define _CRT_SECURE_NO_WARNINGS	1
#pragma once
#include <cstring>
#include <cassert>
#include <iostream>
namespace limou
{
	//ģ��ʵ��string
	class string
	{
	public:
		//> 0.������
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
		//> 1.���캯��
		string(const char* str = "")/* �� "" �����ڲ�������'\0'������Լ���д'\0'ʵ�����ǻ������㣬û�б�Ҫ */
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& str)
		{
		
		}
		//> 2.��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//> 3.�������غ���
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
		//> 4.string����
		//> 4.1.ת��Ϊc���ַ���
		const char* c_str() const
		{
			return _str;
		}
		//> 4.2.����ַ�������
		size_t size() const
		{
			return _size;
		}
		//> 4.3.β���ַ���string����
		void push_back(char ch)
		{
		
		}
		//> 4.3.β���ַ�����string����
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

		//����������
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		for (auto ch : s1)//����֮����ʲô��û���Ϳ���ʵ�ַ�Χfor����Ϊ�ײ���ǵ�����
		{
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
}