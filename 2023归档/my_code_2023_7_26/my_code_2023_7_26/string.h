#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
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
		//> 2.��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//> 3.��������͸�ֵ���������
		//��ͳд��
		//string(const string& str)
		//	: _capacity(str._capacity),
		//	_size(str._size),
		//	_str(new char[_capacity + 1])
		//{
		//	strcpy(_str, str._str);//���
		//}
		//string& operator=(const string& str)
		//{
		//	if (this != &str)//�����Լ������Լ�����
		//	{
		//		char* cache = new char[_capacity + 1];
		//		strcpy(cache, str._str);//���
		//		delete[] _str;
		//		_capacity = str._capacity;
		//		_size = str._size;
		//		_str = cache;
		//	}
		//	return *this;
		//}
		//�ִ�д����Ч����ʵûʲô���죬���Ǻܼ�ࣩ
		void swap(string& tmp)
		{
			std::swap(_capacity, tmp._capacity);
			std::swap(_size, tmp._size);
			std::swap(_str, tmp._str);
		}
		string(const string& str)
			: _capacity(0)//�����ʼ���б��Ǳ���ģ���������tmp�޷�������
			, _size(0)
			, _str(nullptr)
		{
			string tmp(str._str);//ע�������ǹ��캯��
			swap(tmp);//�����swap()���ǿ�����Ǹ�������ֻ�ǽ���sring��ģ���������Ķ���������
		}
		//string& operator=(const string& str)
		//{
		//	if (this != &str)//�����Լ������Լ�����
		//	{
		//		string tmp(str._str);
		//		swap(tmp);
		//	}
		//	return *this;
		//}//�������Ż�Ϊ�����������
		string& operator=(string str)//str�൱��tmp��λ��������
		{
			swap(str);
			return *this;
		}
		//> 4.�������غ���
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
			//���ú����push_back()
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			//���ú����append()
			append(str);
			return *this;
		}
		//> 4.string����
		//> 4.1.ת��Ϊc���ַ���
		const char* c_str() const
		{
			return _str;
		}
		//> 4.2.����ַ������Ⱥ�����
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		//> 4.3.β���ַ���string����
		void reserve(size_t n)//ȡ��n���ռ�
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//֮������n+1����Ϊ�˱���_size�����ֵ��_capacity�������ܹ��洢'\0'
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
		//> 4.3.β���ַ�����string����
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);//ʹ��strcat()�����ǿ��ԣ����ǻ���Ҫ����'\0'��λ�ã����ʵ����strcat()�������ʵ���ϲ�̫�ã����ڳ�����׷�����ݻ���ɵ�Ч
			_size += len;
		}
		void append(const string& s)
		{
			append(s._str);
		}
		void append(size_t n, char ch)
		{
			//�Ƚ������ݣ�����Ƶ������
			reserve(_size + n);
			for (int i = 0; i < n; i++)
			{
				push_back(ch);
			}
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if(_size == _capacity)//��������
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
		size_t _capacity;//string���������
		size_t _size;//string����Ĵ�С
		char* _str;//c����ַ���
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
	void test_2()
	{
		//���鿽�����캯��
		std::cout << "���鿽�����캯��" << std::endl;
		limou::string s1("abcdef");
		std::cout << "s1��" << s1.c_str() << std::endl;
		limou::string s2(s1);
		std::cout << "s2��" << s2.c_str() << std::endl;
		s2[0] = '0';
		s2[1] = '0';
		s2[2] = '0';
		std::cout << "copy" << std::endl;
		std::cout << "s1��" << s1.c_str() << std::endl;
		std::cout << "s2��" << s2.c_str() << std::endl;
		std::cout << std::endl;

		//���鸳ֵ���أ���д���صĻ���������ǳ�������������ڴ�й¶��
		std::cout << "���鸳ֵ����" << std::endl;
		std::cout << "s1��" << s1.c_str() << std::endl;
		std::cout << "s2��" << s2.c_str() << std::endl;
		s1 = s2;
		std::cout << "��ֵ��" << std::endl;
		std::cout << "s1��" << s1.c_str() << std::endl;
		std::cout << "s2��" << s2.c_str() << std::endl;
		s1[0] = '-';
		s1[1] = '-';
		s1[2] = '-';
		std::cout << "�޸ĺ�" << std::endl;
		std::cout << "s1��" << s1.c_str() << std::endl;
		std::cout << "s2��" << s2.c_str() << std::endl;
		s2[0] = '+';
		s2[1] = '+';
		s2[2] = '+';
		std::cout << "�޸ĺ�" << std::endl;
		std::cout << "s1��" << s1.c_str() << std::endl;
		std::cout << "s2��" << s2.c_str() << std::endl;
		std::cout << std::endl;
	}
	void test_3()
	{
		//���Բ��뵥�ַ�
		string str("abcde");
		str.push_back('f');
		std::cout << str.c_str() << std::endl;
		str.push_back('g');
		std::cout << str.c_str() << std::endl;
		str.push_back('h');
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//����+=���ַ�
		str += 'i';
		std::cout << str.c_str() << std::endl;
		str += 'j';
		std::cout << str.c_str() << std::endl;
		str += 'k';
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//���Բ����ַ���
		str.append("--------");
		std::cout << str.c_str() << std::endl;
		std::cout << str.capacity() << std::endl;
		std::cout << std::endl;

		//����+=�ַ���
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