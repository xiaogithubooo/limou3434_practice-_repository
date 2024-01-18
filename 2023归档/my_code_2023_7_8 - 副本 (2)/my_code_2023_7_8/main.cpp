#include <iostream>
#include <string>
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

int main()
{
	test_9();
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