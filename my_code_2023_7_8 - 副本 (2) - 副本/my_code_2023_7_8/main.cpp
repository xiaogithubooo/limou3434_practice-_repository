#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cassert>
#include <list>
using namespace std;
void test_1()
{
	string s1;
	string s2 = "hello world";

	//1.这是两个同类型的string对象相互赋值
	s1 = s2;
	cout << s1 << endl;

	//2.s指向某个常量字符串，将这个字符串赋给已经事先定义过的string对象
	s1 = "xxxx";
	cout << s1 << endl;

	//3.c为某个字符，将这个字符赋给已经事先定义过的string对象
	s1 = 'c';
	cout << s1 << endl;
}
void test_2()
{
	string s1("hello word");
	cout << s1[1] << endl;
	s1[1] = 'l';
	cout << s1 << endl;
}
void test_3()
{
	string s1("hello word");
	cout << s1.size() << endl;
}
void test_4()
{
	string s("Hello word. I am limou.");
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
}
void test_5()
{
	string s("Hello word. I am limou.");
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
}
void test_6()
{
	string s("Hello word. I am limou.");
	string::const_iterator cit = s.begin();
	while (cit != s.end())
	{
		cout << *cit;
		++cit;
	}
}
void test_7()
{
	list<int> lt(10, 1);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;//这在很底层的C语言链表实现中是没有办法”直接“做到的
	}
	cout << endl;
}
void test_8()
{
	string s("hello word");
	string::iterator it = s.begin();
	while (it != s.end())
	{
		(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//全智能，自动迭代，自动判断结束
	for (auto ch : s)//依次取s中的每个字符赋给ch
	{
		cout << ch << " ";
	}//但是范围for实际上没什么大不了的，底层原理实际上就是替换成了上述的迭代器，因此我们只需要在以后学好迭代器的底层原理就行
	cout << endl;
}
void test_9()
{
	string s("hello");
	s.push_back('-');
	s.push_back('-');
	cout << s << endl;

	s.pop_back();
	cout << s << endl;

	s.append("word");
	cout << s << endl;

	s += '@';
	cout << s << endl;

	s += "abcd";
	cout << s << endl;

	//迭代区间插入
	string str1("HELLO");
	string str2("WROD");
	str1.append(str2.begin() + 1, str2.end() - 1);
	cout << str1 << endl;
}
void test_10()
{
	string str("wo lai le");
	for (size_t i = 0; i < str.size();)
	{
		if (str[i] == ' ')
		{
			str.insert(i, "20%");//这个插入是挪动数据后才进行插入
			i += 4;
		}
		else
		{
			++i;
		}
	}
	cout << str << endl;
}
void test_11()
{
	string str("wo lai le");
	for (size_t i = 0; i < str.size();)
	{
		if (str[i] == ' ')
		{
			str.insert(i, "20%");//这个插入是挪动数据后才进行插入
			i += 4;
		}
		else
		{
			++i;
		}
	}
	cout << str << endl;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(i, 1);
		}
		cout << str << endl;
	}

	str.erase();
	cout << "str:" << str << endl;
}

void test_12()
{
	string str("wo lai le");
	string newstr;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			newstr += str[i];
		}
		else
		{
			newstr += "20%";
		}
	}
	cout << newstr << endl;
}

void test_13()
{
	string filename("main.cpp");
	FILE* fout = fopen(filename.c_str(), "r");
	assert(fout);
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
}

void test_14()
{
	string str("abcd.sd");
	size_t pos = str.find('.');//如果没有找到就会返回整型的最大值npos
	if (pos != string::npos)
	{
		string suff = str.substr(pos, str.size() - pos);//substr是取当前字符串的子字符串
		cout << suff << endl;
	}
}
void function(string& url)
{
	size_t pos1 = url.find("://");
	if (pos1 == string::npos)
	{
		cout << "非法" << endl;
		return;
	}
	string protocol = url.substr(0, pos1);//取得协议
	cout << protocol << endl;

	size_t pos2 = url.find('/', pos1 + 3);//从pos1+3位置开始往后找'/'
	if (pos2 == string::npos)
	{
		cout << "非法" << endl;
		return;
	}
	string domain = url.substr(pos1 + 3,pos2 - pos1 - 3);//取得域名
	cout << domain << endl;

	string uri = url.substr(pos2 + 1);
	cout << uri << endl;
}
void test_15()
{
	string url("https://baidu.com/iamlimou3434");
	function(url);
}

int main()
{
	test_15();
	return 0;
}

//做了力扣的一道题目
////有点类似快排
//class Solution
//{
//public:
//    bool IsLetter(const char& ch)
//    {
//        if ((ch >= 'a' && ch <= 'z')
//            || (ch >= 'A' && ch <= 'Z')
//            )
//        {
//            return true;
//        }
//        return false;
//    }
//    string reverseOnlyLetters(string s)
//    {
//        size_t begin = 0;
//        size_t end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !IsLetter(s[begin]))
//            {
//                begin++;
//            }
//            while (begin < end && !IsLetter(s[end]))
//            {
//                end--;
//            }
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//        return s;
//    }
//};