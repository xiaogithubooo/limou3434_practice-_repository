#include <iostream>
#include <string>
#include <list>
using namespace std;
void test_1()
{
	string s1;
	string s2 = "hello world";

	//1.��������ͬ���͵�string�����໥��ֵ
	s1 = s2;
	cout << s1 << endl;

	//2.sָ��ĳ�������ַ�����������ַ��������Ѿ����ȶ������string����
	s1 = "xxxx";
	cout << s1 << endl;

	//3.cΪĳ���ַ���������ַ������Ѿ����ȶ������string����
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
		++lit;//���ںܵײ��C��������ʵ������û�а취��ֱ�ӡ�������
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

	//ȫ���ܣ��Զ��������Զ��жϽ���
	for (auto ch : s)//����ȡs�е�ÿ���ַ�����ch
	{
		cout << ch << " ";
	}//���Ƿ�Χforʵ����ûʲô���˵ģ��ײ�ԭ��ʵ���Ͼ����滻���������ĵ��������������ֻ��Ҫ���Ժ�ѧ�õ������ĵײ�ԭ�����
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

	//�����������
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

//�������۵�һ����Ŀ
////�е����ƿ���
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