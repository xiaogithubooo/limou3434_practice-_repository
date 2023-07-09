#include <iostream>
#include <string>
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
int main()
{
	test_4();
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