#include <string>
#include <iostream>
#include "stack.hpp"
using namespace std;

//解法1：
//1.函数逻辑
class Solution
{
public:
    bool isPalindrome(const std::string& str)
    {
		limou::Stack<char> s;
        int n = str.size() / 2;
        int i = 0;
        while (n--)
        {
            s.Push(str[i++]);
        }

        if (str.size() % 2 != 0)//奇数
            i++;
        while (!s.empty())
        {
            if (s.Top() != str[i++])
            {
                return false;
            }
            s.Pop();
        }
        return true;
    }
};
//2.运行逻辑

int main()
{
    //test_1();
    //test_2();

    //2.1.输入字符串数据
    std::string str;
    Solution s;
    std::cout << "Please enter a string:";
    while (getline(std::cin, str))
    {
        //2.2.判断是否回文
        if (s.isPalindrome(str))
        {
            std::cout << "[" << str << "]是回文字符串" << std::endl;
        }
        else
        {
            std::cout << "[" << str << "]不是回文字符串" << std::endl;
        }
        std::cout << "Please enter a string:";
    }
    return 0;
}
//3.测试用例
void test_1()
{
    Solution s;
    //测试普通回文字符串（偶数个）
    if (s.isPalindrome("abcddcba"))
        std::cout << "OK" << std::endl;
    //测试普通回文字符串（奇数个）
    if (s.isPalindrome("abcdedcba"))
        std::cout << "OK" << std::endl;
    //测试非回文字符串
    if (!s.isPalindrome("abcd"))
        std::cout << "NO" << std::endl;
    //测试重复回文字符串
    if (s.isPalindrome("AAA"))
        std::cout << "OK" << std::endl;
    //测试包含空格字符串
    if (!s.isPalindrome("A B C   BA"))
        std::cout << "NO" << std::endl;
}
void test_2()
{
    Solution s;
    //测试空字符串
    if (s.isPalindrome(""))
        std::cout << "OK" << std::endl;
    //测试单个字符串
    if (s.isPalindrome("h"))
        std::cout << "OK" << std::endl;
}

////解法2：
////1.函数逻辑
//class Solution
//{
//public:
//    bool isPalindrome(const std::string& str)
//    {
//        int begin = 0;
//        int end = str.size() - 1;
//
//        while (begin < end)
//        {
//            if (str[begin++] != str[end--])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//
////2.运行逻辑
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
//
//    return 0;
//}
//
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
//    if (!s.isPalindrome(""))
//        std::cout << "NO" << std::endl;
//    //测试重复回文字符串
//    if (s.isPalindrome("AAA"))
//        std::cout << "YES" << std::endl;
//    //测试包含空格字符串
//    if (s.isPalindrome("A B C   BA"))
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