#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
namespace limou//��׼�����ռ�
{
	class string
	{
	public:
		typedef char* iterator;//�����������ͣ�������ʵ����������������
		typedef const char* const_iterator;//����������
	public:
		//1.��Ա����
		//1.1.���캯��
		string(const char* s = "")//ȱʡ�������ݿ��ַ�
		{
			std::cout << "string(const char* s = "")" << std::endl;
			_size = strlen(s);//str�ĳ��ȣ�������'\0'
			_capacity = 15;//str��Ĭ��������������'\0'
			_s = new char[_capacity + 1];//Ĭ������16���ռ�����һ���洢'\0'
			while (_size > _capacity)//������������ˣ��ͻ��������
			{
				delete[] _s;
				_s = new char[_capacity * 2];
				_capacity *= 2;
			}
			strcpy(_s, s);
		}
		//1.2.��������
		~string()
		{
			std::cout << "~string()" << std::endl;
			delete[] _s;
		}
		//1.3.��������+��ֵ���غ���
		string(const string& str)
		{
			_size = str._size;
			_capacity = str._capacity;
			_s = new char[_capacity + 1];
			strcpy(_s, str._s);
		}
		string& operator=(const string& str)
		{
			std::cout << "string operator=(const string& str)" << std::endl;
			_size = str._size;
			_capacity = str._capacity;
			_s = new char[_capacity + 1];
			strcpy(_s, str._s);
			return *this;
		}
		//2.������
		iterator begin()
		{
			return _s;
		}
		iterator end()
		{
			return _s + _size;//��"abcd",size=4,_s->a,_s+4->'\0'
		}
		const_iterator begin() const
		{
			return _s;
		}
		const_iterator end() const
		{
			return _s + _size;
		}
		//3.�ݻ�
		const char* c_str() const
		{
			return _s;
		}
		const size_t size() const
		{
			return _size;
		}
		const size_t capacity() const
		{
			return _capacity;
		}
		void reserve(size_t n)//�ı�����
		{
			if (n > _capacity)
			{
				_capacity = n;//�ı�����
				char* cache = new char[n + 1];//������Ӧ�����Ŀռ�
				strcpy(cache, _s);//����Դ�ַ������ݣ��´��'\0'
				delete[] _s;//����Դ�ַ���
				_s = cache;//
			}
			else
			{
				std::cout << "reserve����ֻ������" << std::endl;
			}
		}
		void clear()
		{
			erase(0);
		}
		//3.����
		char& operator[](size_t pos)
		{
			assert(pos <= _size);//������ƵĺͿ���һ���ģ����Է��ʵ�'\0'
			return _s[pos];
		}
		//4.�޸���
		void push_back(char ch)//push_back���ַ�
		{
			//��"abcd",_size=4,_capacity=15,�ռ��㹻,��������
			//��"aaaaabbbbbccccc",_size=15,_capacity=15,�ռ䲻��,��Ҫ����
			if (_size == _capacity)
			{
				reserve(_capacity * 2);//�ı�����Ϊԭ����2��
			}
			_s[_size++] = ch;
			_s[_size] = '\0';
		}
		void append(const char* s)//append�ַ���
		{
			size_t len = _size + strlen(s);
			if (len > _capacity)
			{
				reserve(len);//�ı�����
			}
			strcpy(_s + _size, s);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void inster(size_t pos, char ch)
		{
			//���˿�����˳���Ų�����ݴ�Խ��λ�õ�������ʼ�ȽϺã�Ҳ��������end=_size + 1,��Խ���end��ʼ��
			//"abcdef\0",pos=2,pos->c,s[_size]='\0',"ab cdef"
			//"\0",pos=0,pos->'\0',s[_size]='\0'," \0"
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_s[end] = _s[end - 1];
				end--;
			}
			_s[pos] = ch;
			_size++;
		}
		void inster(size_t pos, const char* s)
		{
			//"abcde\0",pos=1,pos->b,s="xxx","abcde\0"->"a   bcde\0"
			assert(pos <= _size);
			size_t len = strlen(s);
			if (len + _size > _capacity)//��������
			{
				reserve(len + _size);//���ٺ��㹻�Ŀռ�
			}
			size_t end = _size + len;//end=5+3=8
			while (end > pos)//8>1
			{
				_s[end] = _s[end - len];//_s[8] = _s[5]
				end--;
			}
			strncpy(_s + pos, s, len);
			_size += len;
		}
		void erase(size_t pos, size_t len = npos)//lenû��ָ���ͻ�ȫ��ɾ��
		{
			//�����ַ�����һ���֣����Ҽ���_size
			//"bacdef\0",pos=1,len=3,"b   ef\0"->"bef\0"
			assert(pos <= _size);
			if (_size == 0)//����ַ�����СΪ0��ֱ�ӷ��أ�û��Ҫ������
				return;

			if (len == npos || pos + len >= _size)//���û��ָ��len��ֱ��ɾ��pos֮��������ַ��������߳�����Χ��
			{
				_s[pos] = '\0';
				_size = pos;
				return;
			}

			//����ָ��pos�������洦��
			size_t begin = pos + len;//begin=1+3=4,_s[4]='e'
			while (begin <= _size)//begin<6
			{
				_s[begin - len] = _s[begin];//_s[1]=_s[4],'a'->'e'
				begin++;
			}
			_size -= len;
		}
		//5.�Ƚϣ������д��ȫ������Ϊ֧����������ʵ������
		bool operator<(const string& str)
		{
			return (strcmp(_s, str._s) < 0);
		}
		bool operator==(const string& str)
		{
			return (strcmp(_s, str._s) == 0);
		}
		bool operator<=(const string& str)
		{
			return *this < str || *this == str;
		}
		bool operator>(const string& str)
		{
			return !(*this <= str);
		}
		bool operator!=(const string& str)
		{
			return !(*this == str);
		}
		bool operator>=(const string& str)
		{
			return !(*this < str);
		}
		//6.�ַ�������
		//find()ϵ��
	private:
		char* _s;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
		/*
		�²ۣ������ľ�̬��Ա�����������ﶨ�壨Ҳû�а취������ʼ���б���
		����C++�ָ���һ��������const static�����α�������ֱ�������ﶨ�塣
		����һ���Ƚ����׵���ƣ����ž��У�һ��Ҳ������ôд�����׿��ˡ�����Ϊ����������ƻ��﷨����
		*/
	};
	//const size_t string::npos = -1;
	//7.�����أ�����һ��Ҫд����Ԫ��
	std::ostream& operator<<(std::ostream& out, const string& str)
	{
		for (auto ch : str)
			out << ch;
		return out;
	}
	std::istream& operator>>(std::istream& in, string& str)
	{
		//1.����ע�����������Ĵ����ǽ����������ģ���Ϊcin�����ո�ͻ��Զ�����
		//char ch;
		//in >> ch;
		//while (ch != ' ' && ch != '\n')
		//{
		//	str += ch;
		//	in >> ch;
		//}
		//return in;
		//2.����д�����£�
		str.clear();//Ϊ�˱�����β�壬����Ҫ���ԭ�е�����
		char ch;
		ch = in.get();//����istream���ṩ��һ������
		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
		//3.��������������Щ�˷ѣ��������ڽ��иĽ�
	}

	//8.����
	//�������
	void test_1()
	{
		//1.���е�Ĭ�Ϲ���ʵ�֣����ԣ�
		std::string str;
		std::cout << str.c_str() << std::endl;
		std::cout << "str.size = " << str.size() << std::endl;
		std::cout << "str.capacity = " << str.capacity() << std::endl;
		std::cout << "----" << std::endl << std::endl;

		//2.�����Լ��Ĺ���ʵ�֣����ԣ�
		//string()
		string str0;
		const char* s0 = str0.c_str();
		std::cout << s0 << std::endl;
		std::cout << "str0.size = " << str0.size() << std::endl;
		std::cout << "str0.capacity = " << str0.capacity() << std::endl;
		//string(const char* s)
		string str1("Hello, My name is Limou3434.");
		const char* s1 = str1.c_str();
		std::cout << s1 << std::endl;
		//string(const string& str)
		string str2(str1);
		const char* s2 = str2.c_str();
		std::cout << s2 << std::endl;
		//string& operator=(const string& str)
		string str3("aaaa");
		string str4("bbbb");
		string str5;
		str5 = (str4 = str3);
		const char* s3 = str3.c_str();
		const char* s4 = str4.c_str();
		const char* s5 = str5.c_str();
		std::cout << s3 << " | " << s4 << " | " << s5 << std::endl;
	}
	//����������
	void test_2()
	{
		//1.ʹ��[]��������
		string str1("Hello");
		for (int i = 0; str1[i]; i++)
		{
			std::cout << str1[i]++ << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < str1.size(); i++)
		{
			std::cout << str1[i] << " ";
		}
		std::cout << std::endl;

		//2.ʹ�õ���������
		string str2("Iamlimou");
		limou::string::iterator it = str2.begin();
		while(it < str2.end())
		{
			std::cout << (*it)++ << " ";
			it++;
		}
		std::cout << std::endl;
		it = str2.begin();
		while(it < str2.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;

		//3.ʹ�÷�Χfor������Ϊ�����������ԣ�
		string str3;
		str3 = "WordWordWord";
		for (auto& ch : str3)
		{
			std::cout << ch++ << " ";
		}
		std::cout << std::endl;
		for (auto& ch : str3)
		{
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
	//�޸�������
	void test_3()
	{
		//1.push_back()
		string str1 = "abcd";
		str1.push_back('e');
		std::cout << str1.c_str() << std::endl;

		for (int i = 0; i < 50; i++)
		{
			str1.push_back('x');
			std::cout << str1.c_str() << std::endl;
		}
		std::cout << std::endl;

		//2.append()
		str1.append("________________________________");
		std::cout << str1.c_str() << std::endl;

		//3.operator+=()
		string str2;
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		str2 += '#';
		std::cout << str2.c_str() << std::endl;
		str2 += "######################################################";
		std::cout << str2.c_str() << std::endl;
	
		//4.inster()
		string str4;
		for (int i = 0; i < 10; i++)
		{
			str4.inster(0, '#');
			std::cout << str4.c_str() << std::endl;
		}
		str4.inster(1, '%');
		std::cout << str4.c_str() << std::endl;
		str4.inster(str4.size(), '%');
		std::cout << str4.c_str() << std::endl;
		
		string str5;
		str5.inster(0, "xxx");
		std::cout << str5.c_str() << std::endl;
		str5.inster(3, "aaaaaaaaaaaaaaa");
		std::cout << str5.c_str() << std::endl;
		str5.inster(5, "*");
		std::cout << str5.c_str() << std::endl;

		//5.erase()
		string str6("abcdef");
		str6.erase(2, 3);
		std::cout << str6.c_str() << std::endl;
		str6.erase(0);
		std::cout << str6.c_str() << std::endl;

		str6.push_back('c');
		std::cout << str6.c_str() << std::endl;

		string str7("xxcdef");
		str7.erase(2, 100);
		std::cout << str7.c_str() << std::endl;
	}
	//�Ƚϲ���
	void test_4()
	{
		string str1 = "a";
		string str2 = "a";
		string str3 = "b";
		string str4 = "c";
		if (str1 < str3)
		{
			std::cout << "true" << std::endl;
		}		
		if (str1 == str2)
		{
			std::cout << "true" << std::endl;
		}		
		if (str1 <= str3)
		{
			std::cout << "true" << std::endl;
		}
		if (str1 <= str2)
		{
			std::cout << "true" << std::endl;
		}
		if (str4 > str3)
		{
			std::cout << "true" << std::endl;
		}		
		if (str1 != str3)
		{
			std::cout << "true" << std::endl;
		}		
		if (str4 >= str3)
		{
			std::cout << "true" << std::endl;
		}
		if (str4 >= str4)
		{
			std::cout << "true" << std::endl;
		}
	}
	//������
	void test_5()
	{
		string str1("abc");
		string str2("efg");
		std::cin >> str1;
		std::cin >> str2;
		std::cout << str1 << std::endl;
		std::cout << str2 << std::endl;
	}
}
//ע������д��ֻ��string�࣬������һ����ģ�壬�����Щ�ط�����Ĵ������������ʵ�������ܲ�������