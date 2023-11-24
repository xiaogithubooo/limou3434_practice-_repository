//右值引用优点
#include <iostream>
using namespace std;

void Func(const int& x)
{
    cout << "void Func(const int& x):" << x << '\n';
}
void Func(int&& x)
{
    cout << "void Func(int&& x):" << x << '\n';
}

int main()
{
    int a = 1;
    int b = 2;

    Func(a);//调用了 Func(int& x)
    Func(a + b);//调用了 void Func(int&& x)，优先走右值引用的接口

    return 0;
}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int upperNum = 0;
//	int lowerNum = 0;
//	int digitNum = 0;
//	char sr[30];
//	printf("请输入一串字符，按回车结束:");
//	scanf("%s", &sr);
//
//	while (ch != '\n')
//	{
//		sr[i] = '\0'; 
//		if ((ch >= 'A') && (ch <= 'Z'))
//			++upperNum; 
//		else if ((ch >= 'a') && (ch <= 'z'))
//			++lowerNum;
//		else if ((ch >= '1') && (ch <= '9'))
//			++digitNum;
//		else
//			printf("不合法\n");
//
//		i++;
//	}
//	return 0;
//}


////资源转移
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//#include <cassert>
//using namespace std;
//namespace limou
//{
//    class string
//    {
//        //1.成员函数
//    public:
//        //构造函数
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
//        //拷贝构造
//        void swap(string& s)
//        {
//            ::swap(_str, s._str);
//            ::swap(_size, s._size);
//            ::swap(_capacity, s._capacity);
//        }
//        string(const string& s)
//            :_str(nullptr)
//        {
//            cout << "begin: string(const string& s) -- 深拷贝" << endl;
//            string tmp(s._str);
//            swap(tmp);
//            cout << "end: string(const string& s) -- 深拷贝" << endl;
//        }
//
//        //移动构造
//        string(string&& s) noexcept
//            :_str(nullptr)
//        {
//            cout << "begin: string(string&& s) -- 移动拷贝" << endl;
//            
//            swap(s);
//            cout << "end: string(string&& s) -- 移动拷贝" << endl;
//        }
//
//        //赋值重载
//        string& operator=(const string& s)
//        {
//            cout << "begin: string& operator=(string s) -- 深拷贝" << endl;
//            string tmp(s);
//            swap(tmp);
//            cout << "end: string& operator=(string s) -- 深拷贝" << endl;
//            return *this;
//        }
//
//        //析构函数
//        ~string()
//        {
//            cout << "begin: ~string()" << endl;
//            delete[] _str;
//            _str = nullptr;
//            cout << "end: ~string()" << endl;
//        }
//
//        //其他函数
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
//        //2.成员变量
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity; //不包含最后做标识的\0
//    };
//}
//
//int main()
//{
//    limou::string s1("hello word");//调用构造函数
//    limou::string ret1 = s1;
//
//    limou::string ret2 = move(s1 + '!');//将右值资源转移
//    //上述代码中 (str1 + '!') 整体是一个右值，
//    //整个拷贝过程中会出现一个临时变量接受右值，
//    //如果依旧使用深拷贝，新对象使用新地址
//    //并且复制这个临时变量的资源。
//
//    //这就有一些浪费，因为临时变量最后会死亡。
//    //为何不直接对这个临时变量做资源转移交给 ret2 呢？
//    //右值引用就可以做到这一事情。
//
//    //如果只用 const 的左值引用，
//    //则只能左右值都使用同一个深拷贝函数，
//    //无法区分开做各自的处理
//
//    limou::string ret3 = move(s1);//将左值资源转移，那么左值原有资源就会被窃取，转移到 ret3 上，move(s1) 的返回值是右值
//
//    return 0;
//}