//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//#include <cassert>
//using namespace std;
//namespace bit
//{
//	class string
//	{
//		//1.成员函数
//	public:
//		//构造函数
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		//拷贝构造
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		//移动构造
//		string(string&& s)
//			:_str(nullptr)
//		{
//			cout << "string(string&& s) -- 移动拷贝" << endl;
//			swap(s);
//		}
//
//		//赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//
//			return *this;
//		}
//
//		//析构函数
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//其他函数
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		string operator+(char ch)
//		{
//			string tmp(*this);
//			tmp += ch;
//			return tmp;
//		}
//
//		//2.成员变量
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; //不包含最后做标识的\0
//	};
//}
//
//int main()
//{
//	bit::string s1("hello world");
//
//	bit::string ret1 = s1;
//	bit::string ret2 = (s1 + '!');
//
//	bit::string ret3 = move(s1);
//
//	return 0;
//}
