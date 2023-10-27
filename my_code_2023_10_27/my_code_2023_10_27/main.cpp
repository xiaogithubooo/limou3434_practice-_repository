#include <iostream>
using namespace std;

class Father
{
public:
	virtual void Function_1()
	{
		cout << "Father:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Father:Function_2()" << endl;
	}
private:
	int _f_number = 1;
};

class Mother
{
public:
	virtual void Function_1()
	{
		cout << "Mother:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Mother:Function_2()" << endl;
	}
private:
	int _m_number = 2;
};
class Son : public Father, public Mother
{
public:
	virtual void Function_1()
	{
		cout << "Son:Function_1()" << endl;
	}
	virtual void Function_3()//这个虚函数被放在第一个虚表里了
	{
		cout << "Son:Function_3()" << endl;
	}

private:
	int _s_number = 3;
};

typedef void(*VFUNC)();
void PrintVFT(VFUNC arr[])//打印虚函数表内的函数
{
	for (size_t i = 0; arr[i] != 0; i++)//这里是根据VS的特殊处理才可以这么写停止循环的条件的，其他环境可能只能自己写固定的循环次数
	{
		printf("[%d]:%p->", i, arr[i]);
		arr[i]();//调用函数
	}
	printf("\n");
}

int main()
{
	Son s;
	//打印虚表
	VFUNC* table1 = (VFUNC*)(*(int*)&s);//第一张虚表
	//VFUNC* table2 = (VFUNC*)( *( (int*)(  (char*)&s + sizeof(Father))));//第二张虚表（直接使用指针操作）
	Mother* ptr = &s;
	VFUNC* table2 = (VFUNC*)(*((int*)ptr));//第二张虚表（利用内置切片让指针偏移）
	PrintVFT(table1);
	PrintVFT(table2);
	printf("Son::Function_1: %x\n", &Son::Function_1);

	//调用函数
	Father* p1 = &s;
	Mother* p2 = &s;
	p1->Function_1();
	p2->Function_1();

	return 0;
}


//#include <string>
//#include <iostream>
//#include "stack.hpp"
//using namespace std;
//
////解法1：
////1.函数逻辑
//class Solution
//{
//public:
//    bool isPalindrome(const std::string& str)
//    {
//		limou::Stack<char> s;
//        int n = str.size() / 2;
//        int i = 0;
//        while (n--)
//        {
//            s.Push(str[i++]);
//        }
//
//        if (str.size() % 2 != 0)//奇数
//            i++;
//        while (!s.empty())
//        {
//            if (s.Top() != str[i++])
//            {
//                return false;
//            }
//            s.Pop();
//        }
//        return true;
//    }
//};
////2.运行逻辑
//
//int main()
//{
//    //test_1();
//    //test_2();
//
//    //2.1.输入字符串数据
//    std::string str;
//    Solution s;
//    std::cout << "Please enter a string:";
//    while (getline(std::cin, str))
//    {
//        //2.2.判断是否回文
//        if (s.isPalindrome(str))
//        {
//            std::cout << "[" << str << "]是回文字符串" << std::endl;
//        }
//        else
//        {
//            std::cout << "[" << str << "]不是回文字符串" << std::endl;
//        }
//        std::cout << "Please enter a string:";
//    }
//    return 0;
//}
////3.测试用例
//void test_1()
//{
//    Solution s;
//    //测试普通回文字符串（偶数个）
//    if (s.isPalindrome("abcddcba"))
//        std::cout << "OK" << std::endl;
//    //测试普通回文字符串（奇数个）
//    if (s.isPalindrome("abcdedcba"))
//        std::cout << "OK" << std::endl;
//    //测试非回文字符串
//    if (!s.isPalindrome("abcd"))
//        std::cout << "NO" << std::endl;
//    //测试重复回文字符串
//    if (s.isPalindrome("AAA"))
//        std::cout << "OK" << std::endl;
//    //测试包含空格字符串
//    if (!s.isPalindrome("A B C   BA"))
//        std::cout << "NO" << std::endl;
//}
//void test_2()
//{
//    Solution s;
//    //测试空字符串
//    if (s.isPalindrome(""))
//        std::cout << "OK" << std::endl;
//    //测试单个字符串
//    if (s.isPalindrome("h"))
//        std::cout << "OK" << std::endl;
//}
//
//////解法2：
//////1.函数逻辑
////class Solution
////{
////public:
////    bool isPalindrome(const std::string& str)
////    {
////        int begin = 0;
////        int end = str.size() - 1;
////
////        while (begin < end)
////        {
////            if (str[begin++] != str[end--])
////            {
////                return false;
////            }
////        }
////        return true;
////    }
////};
////
//////2.运行逻辑
////int main()
////{
////    //test_1();
////    //test_2();
////
////    //2.1.输入字符串数据
////    std::string str;
////    Solution s;
////    std::cout << "Please enter a string:";
////    while (getline(std::cin, str))
////    {
////        //2.2.判断是否回文
////        if (s.isPalindrome(str))
////        {
////            std::cout << "[" << str << "]是回文字符串" << std::endl;
////        }
////        else
////        {
////            std::cout << "[" << str << "]不是回文字符串" << std::endl;
////        }
////        std::cout << "Please enter a string:";
////    }
////
////    return 0;
////}
////
//////3.测试用例
////void test_1()
////{
////    Solution s;
////    //测试普通回文字符串（偶数个）
////    if (s.isPalindrome("abcddcba"))
////        std::cout << "OK" << std::endl;
////    //测试普通回文字符串（奇数个）
////    if (s.isPalindrome("abcdedcba"))
////        std::cout << "OK" << std::endl;
////    //测试非回文字符串
////    if (!s.isPalindrome(""))
////        std::cout << "NO" << std::endl;
////    //测试重复回文字符串
////    if (s.isPalindrome("AAA"))
////        std::cout << "YES" << std::endl;
////    //测试包含空格字符串
////    if (s.isPalindrome("A B C   BA"))
////        std::cout << "NO" << std::endl;
////}
////void test_2()
////{
////    Solution s;
////    //测试空字符串
////    if (s.isPalindrome(""))
////        std::cout << "OK" << std::endl;
////    //测试单个字符串
////    if (s.isPalindrome("h"))
////        std::cout << "OK" << std::endl;
////}