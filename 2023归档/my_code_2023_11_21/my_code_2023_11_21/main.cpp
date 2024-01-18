#include <iostream>
using namespace std;

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

template<typename T>
void PerfectForward(T&& t)
{
	Fun(std::forward<T>(t));
}

int main()
{
	PerfectForward(10);

	int a;
	PerfectForward(a);
	PerfectForward(std::move(a));

	const int b = 8;
	PerfectForward(b);
	PerfectForward(std::move(b));
	return 0;
}

//#include <string>
//#include <list>
//#include <iostream>
//using namespace std;
//template<typename T>
//void Print(T&& t)
//{
//	cout << "Yes" << endl;
//}
//int main()
//{
//	int a = 0;
//	const int b = 10;
//	Print(a);			//��ֵ
//	Print(10);			//��ֵ
//	Print(b);				//const ��ֵ
//	Print(move(b));	//const ��ֵ
//	return 0;
//}

//int main()
//{
//	list<string> lt;
//	string s1 = "hello";
//	cout << s1 << '\n';
//	lt.push_back(s1);
//	cout << s1 << '\n';
//	lt.push_back(move(s1));
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//
//	cout << s1 << '\n';
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//	vector<vector<int>> generate(int numRows)
//	{
//		vector<vector<int>> vv(numRows);
//		for (int i = 0; i < numRows; i++)
//		{
//			vv[i].resize(i + 1, 1);
//		}
//
//		for (int i = 2; i < numRows; i++)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//			}
//		}
//
//		return vv;
//	}
//};

////��Դת��
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//#include <cassert>
//using namespace std;
//namespace limou
//{
//    class string
//    {
//        //1.��Ա����
//    public:
//        //���캯��
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            cout << "begin: string(const char* str = \"\")" << '\n';
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//            cout << "end: string(const char* str = \"\")" << '\n';
//        }
//
//        //��������
//        void swap(string& s)
//        {
//            ::swap(_str, s._str);
//            ::swap(_size, s._size);
//            ::swap(_capacity, s._capacity);
//        }
//        string(const string& s)
//            :_str(nullptr)
//        {
//            cout << "begin: string(const string& s) -- ���" << endl;
//            string tmp(s._str);
//            swap(tmp);
//            cout << "end: string(const string& s) -- ���" << endl;
//        }
//
//        //�ƶ�����
//        string(string&& s)
//            :_str(nullptr)
//        {
//            cout << "begin: string(string&& s) -- �ƶ�����" << endl;
//            swap(s);
//            cout << "end: string(string&& s) -- �ƶ�����" << endl;
//        }
//
//        //��ֵ����
//        string& operator=(const string& s)
//        {
//            cout << "begin: string& operator=(string s) -- ���" << endl;
//            string tmp(s);
//            swap(tmp);
//            cout << "end: string& operator=(string s) -- ���" << endl;
//            return *this;
//        }
//
//        //��������
//        ~string()
//        {
//            cout << "begin: ~string()" << endl;
//            delete[] _str;
//            _str = nullptr;
//            cout << "end: ~string()" << endl;
//        }
//
//        //��������
//        char& operator[](size_t pos)
//        {
//            assert(pos < _size);
//            return _str[pos];
//        }
//        void reserve(size_t n)
//        {
//            if (n > _capacity)
//            {
//                char* tmp = new char[n + 1];
//                strcpy(tmp, _str);
//                delete[] _str;
//                _str = tmp;
//                _capacity = n;
//            }
//        }
//        void push_back(char ch)
//        {
//            if (_size >= _capacity)
//            {
//                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                reserve(newcapacity);
//            }
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
//        }
//        string& operator+=(char ch)
//        {
//            push_back(ch);
//            return *this;
//        }
//        string operator+(char ch)
//        {
//            string cache(*this);
//            cache += ch;
//            return cache;
//        }
//
//        //2.��Ա����
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity; //�������������ʶ��\0
//    };
//}
//
//int main()
//{
//    limou::string s1("hello word");
//    limou::string ret1 = s1;
//
//    limou::string ret2 = (s1 + '!');
//
//    return 0;
//}