#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
namespace limou//标准命名空间
{
	class string
	{
	public:
		typedef char* iterator;//迭代器的类型，迭代器实际上是重命名来的
		typedef const char* const_iterator;//常量迭代器
	public:
		//1.成员函数
		//1.1.构造函数
		string(const char* s = "")//缺省参数传递空字符
		{
			std::cout << "string(const char* s = "")" << std::endl;
			_size = strlen(s);//str的长度，不计入'\0'
			_capacity = 15;//str的默认容量，不计入'\0'
			_s = new char[_capacity + 1];//默认申请16个空间其中一个存储'\0'
			while (_size > _capacity)//如果容量不够了，就会进行扩容
			{
				delete[] _s;
				_s = new char[_capacity * 2];
				_capacity *= 2;
			}
			strcpy(_s, s);
		}
		//1.2.析构函数
		~string()
		{
			std::cout << "~string()" << std::endl;
			delete[] _s;
		}
		//1.3.拷贝构造+赋值重载函数
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
		//2.迭代器
		iterator begin()
		{
			return _s;
		}
		iterator end()
		{
			return _s + _size;//若"abcd",size=4,_s->a,_s+4->'\0'
		}
		const_iterator begin() const
		{
			return _s;
		}
		const_iterator end() const
		{
			return _s + _size;
		}
		//3.容积
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
		void reserve(size_t n)//改变容量
		{
			if (n > _capacity)
			{
				_capacity = n;//改变容量
				char* cache = new char[n + 1];//创建对应容量的空间
				strcpy(cache, _s);//拷贝源字符串数据，会拷贝'\0'
				delete[] _s;//销毁源字符串
				_s = cache;//
			}
			else
			{
				std::cout << "reserve操作只能扩容" << std::endl;
			}
		}
		void clear()
		{
			erase(0);
		}
		//3.访问
		char& operator[](size_t pos)
		{
			assert(pos <= _size);//这里设计的和库是一样的，可以访问到'\0'
			return _s[pos];
		}
		//4.修改器
		void push_back(char ch)//push_back单字符
		{
			//若"abcd",_size=4,_capacity=15,空间足够,无需扩容
			//若"aaaaabbbbbccccc",_size=15,_capacity=15,空间不够,需要扩容
			if (_size == _capacity)
			{
				reserve(_capacity * 2);//改变容量为原来的2倍
			}
			_s[_size++] = ch;
			_s[_size] = '\0';
		}
		void append(const char* s)//append字符串
		{
			size_t len = _size + strlen(s);
			if (len > _capacity)
			{
				reserve(len);//改变容量
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
			//个人看法：顺序表挪动数据从越界位置的索引开始比较好（也就是下面end=_size + 1,从越界的end开始）
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
			if (len + _size > _capacity)//容量不够
			{
				reserve(len + _size);//开辟好足够的空间
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
		void erase(size_t pos, size_t len = npos)//len没有指定就会全部删除
		{
			//擦除字符串的一部分，并且减少_size
			//"bacdef\0",pos=1,len=3,"b   ef\0"->"bef\0"
			assert(pos <= _size);
			if (_size == 0)//如果字符串大小为0就直接返回，没必要清理了
				return;

			if (len == npos || pos + len >= _size)//如果没有指定len就直接删除pos之后的所有字符串（或者超出范围）
			{
				_s[pos] = '\0';
				_size = pos;
				return;
			}

			//对于指定pos就如下面处理
			size_t begin = pos + len;//begin=1+3=4,_s[4]='e'
			while (begin <= _size)//begin<6
			{
				_s[begin - len] = _s[begin];//_s[1]=_s[4],'a'->'e'
				begin++;
			}
			_size -= len;
		}
		//5.比较（库里的写成全局是因为支持其他的类实例化）
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
		//6.字符串运算
		//find()系列
	private:
		char* _s;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
		/*
		吐槽：单纯的静态成员不可以在这里定义（也没有办法传给初始化列表），
		但是C++又搞了一个特例，const static的整形变量可以直接在这里定义。
		这是一个比较离谱的设计，记着就行，一般也不会这么写，容易坑人……因为这个特例会破坏语法规则
		*/
	};
	//const size_t string::npos = -1;
	//7.流重载（并不一定要写成友元）
	std::ostream& operator<<(std::ostream& out, const string& str)
	{
		for (auto ch : str)
			out << ch;
		return out;
	}
	std::istream& operator>>(std::istream& in, string& str)
	{
		//1.这里注意下面这样的代码是解决不了问题的，因为cin遇到空格就会自动跳过
		//char ch;
		//in >> ch;
		//while (ch != ' ' && ch != '\n')
		//{
		//	str += ch;
		//	in >> ch;
		//}
		//return in;
		//2.更正写法如下：
		str.clear();//为了避免变成尾插，还需要清楚原有的数据
		char ch;
		ch = in.get();//这是istream类提供的一个函数
		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
		//3.不过上述扩容有些浪费，还可以在进行改进
	}

	//8.测试
	//构造测试
	void test_1()
	{
		//1.库中的默认构造实现（测试）
		std::string str;
		std::cout << str.c_str() << std::endl;
		std::cout << "str.size = " << str.size() << std::endl;
		std::cout << "str.capacity = " << str.capacity() << std::endl;
		std::cout << "----" << std::endl << std::endl;

		//2.我们自己的构造实现（测试）
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
	//迭代器测试
	void test_2()
	{
		//1.使用[]遍历访问
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

		//2.使用迭代器遍历
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

		//3.使用范围for，本质为迭代器（测试）
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
	//修改器测试
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
	//比较测试
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
	//流测试
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
//注意我们写的只是string类，而不是一个类模板，因此有些地方上面的代码对于其他的实例化可能不够适用