#include <iostream>
#include <string>
using namespace std;
// comparing apples with apples
#include <iostream>
#include <string>
int main()
{
    string str1("green apple");
    string str2("red apple");
    //g < r <=> g - r < 0

    //"green apple" < "red apple"
    if (str1.compare(str2) < 0)
        cout << str1 << " is not " << str2 << endl;

    //"apple" == "apple"
    if (str1.compare(6, 5, "apple") == 0)
        cout << "still, " << str1 << " is an apple" << endl;

    //"apple" == "apple"
    if (str2.compare(str2.size() - 5, 5, "apple") == 0)
        cout << "and " << str2 << " is also an apple" << endl;

    //"apple" == "apple" 
    if (str1.compare(6, 5, str2, 4, 5) == 0)
        cout << "therefore, both are apples" << endl;

    const char* str3 = "green apple";
    if (str1.compare(str3) == 0)
        cout << "one and the same" << endl;

    return 0;
}

//int main()
//{
//	string str("awwwwf");
//	cout << str.substr(1, 4) << endl;
//	return 0;
//}

//int main()
//{
//	//1.寻找string子串
//	string str1("abcd-abcd-abcd");
//	string str2("abcd");
//	cout << str1.find(str2, 0) << endl;
//	cout << str1.find(str2, 1) << endl;
//	cout << str1.find(str2, 6) << endl << endl;
//	
//	//2.寻找C风格子串
//	string str3("ABCD-ABCD-ABCD");
//	const char* str4 = "ABCD";
//	cout << str3.find(str4, 0) << endl;
//	cout << str3.find(str4, 1) << endl;
//	cout << str3.find(str4, 6) << endl << endl;
//
//	//3.在范围内寻找C风格子串
//	string str5("ABCD-AB-ABCD-AB-ABCD");
//	const char* str6 = "ABCD";
//	cout << str5.find(str6, 0, 2) << endl;
//	cout << str5.find(str6, 1, 2) << endl;
//	cout << str5.find(str6, 6, 2) << endl;
//	cout << str5.find(str6, 9, 2) << endl;
//	cout << str5.find(str6, 14, 2) << endl << endl;
//
//	//4.寻找字符
//	string str7("xxxxxxx_xxxx_xxxxxxxxxx_");
//	char ch = '_';
//	int j = -1;
//	for (int i = 0; i < str7.size(); i++)
//	{
//		int z = str7.find(ch, i);
//		if (j != z)
//		{
//			cout << z << " ";
//			j = z;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	std::string str("abcd");
//	char s[3] = { 0 };//如果这里没有加入初始化{ 0 }，那么后续打印s数组就会出现乱码，原因就是找不到空字符
//	str.copy(s, 2);
//	std::cout << s << std::endl;
//	return 0;
//}

//#include <cstring>
//int main()
//{
//    int length;
//
//    string str = "Test string";
//    const char* cstr = "Test string";
//
//    if (str.length() == strlen(cstr))
//    {
//        cout << "1" << endl;
//
//        if (memcmp(cstr, str.data(), str.length()) == 0)
//        {
//            cout << "1" << endl;
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str("abcdef");
//	cout << "str" << " = " << str << " 类型：" << typeid(str).name() << endl << endl;
//
//	char* ch;
//	cout << typeid(ch).name() << endl;
//	cout << "str.c_str()" << " = " << str.c_str() << " 类型：" << typeid(str.c_str()).name() << endl;
//	cout << "str.data()" << " = " << str.data() << " 类型：" << typeid(str.data()).name() << endl;
//	return 0;
//}

//int main()
//{
//	cout << "1.string& insert (size_t pos, const string& str);" << endl;
//	string str1("abcdef");
//	cout << str1 << endl;
//	string sstr1 = "xxxxx";
//	str1.insert(0, sstr1);
//	cout << str1 << endl << endl;
//
//	cout << "2.string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);" << endl;
//	string str2("abcdef");
//	cout << str2 << endl;
//	string sstr2 = "ABCDEEEEFGHIJK";
//	str2.insert(str2.size(), sstr2, 4, 4);
//	cout << str2 << endl << endl;
//
//	cout << "3.string& insert (size_t pos, const char* s);" << endl;
//	string str3 = "abcdef";//这是一个C风格的字符串
//	cout << str3 << endl;
//	const char* sstr3 = "__________";
//	str3.insert(str3.size(), sstr3);
//	cout << str3 << endl << endl;;
//
//	cout << "4.string& insert (size_t pos, const char* s, size_t n);" << endl;
//	string str4("abcdef");
//	cout << str4 << endl;
//	const char* sstr4 = "bbbbbxxxxxxxxxxxxxx";//只想截取长度为前5个字符的字符
//	str4.insert(1, sstr4, 5);
//	cout << str4 << endl << endl;;
//
//	cout << "5.string& insert (size_t pos, size_t n, char c);" << endl;
//	string str5("ABCDEFG");
//	cout << str5 << endl;
//	str5.insert(1, 20, '+');
//	cout << str5 << endl << endl;
//
//	cout << "6.iterator insert(const_iterator p, size_t n, char c);" << endl;
//	string str6  = "QWERT";
//	str6.insert(str6.begin() + 3, 10, 'c');
//	cout << str6 << endl << endl;
//
//	cout << "7.iterator insert (const_iterator p, char c);" << endl;
//	string str7 = "AAAAAAAAA";
//	str7.insert(str7.end(), 'c');
//	cout << str7 << endl << endl;
//
//	cout << "8.template <class InputIterator> " << endl;
//	cout << "  iterator insert(iterator p, InputIterator first, InputIterator last);" << endl;
//	string str8 = "XXXX";
//	string sstr8 = "|bcde|";
//	str8.insert(str8.begin(), sstr8.begin() + 1, sstr8.end() - 1);
//	cout << str8 << endl << endl;
//
//	cout << "9. string& insert (const_iterator p, initializer_list<char> il);" << endl;
//	string str9 = "XXXX";
//	str9.insert(str9.begin() + 2, { 'a', 'b', 'c' });
//	cout << str9 << endl << endl;
//
//	return 0;
//}