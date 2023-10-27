#include <string>
#include <iostream>
#include "stack.hpp"
using namespace std;

//�ⷨ1��
//1.�����߼�
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

        if (str.size() % 2 != 0)//����
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
//2.�����߼�

int main()
{
    //test_1();
    //test_2();

    //2.1.�����ַ�������
    std::string str;
    Solution s;
    std::cout << "Please enter a string:";
    while (getline(std::cin, str))
    {
        //2.2.�ж��Ƿ����
        if (s.isPalindrome(str))
        {
            std::cout << "[" << str << "]�ǻ����ַ���" << std::endl;
        }
        else
        {
            std::cout << "[" << str << "]���ǻ����ַ���" << std::endl;
        }
        std::cout << "Please enter a string:";
    }
    return 0;
}
//3.��������
void test_1()
{
    Solution s;
    //������ͨ�����ַ�����ż������
    if (s.isPalindrome("abcddcba"))
        std::cout << "OK" << std::endl;
    //������ͨ�����ַ�������������
    if (s.isPalindrome("abcdedcba"))
        std::cout << "OK" << std::endl;
    //���Էǻ����ַ���
    if (!s.isPalindrome("abcd"))
        std::cout << "NO" << std::endl;
    //�����ظ������ַ���
    if (s.isPalindrome("AAA"))
        std::cout << "OK" << std::endl;
    //���԰����ո��ַ���
    if (!s.isPalindrome("A B C   BA"))
        std::cout << "NO" << std::endl;
}
void test_2()
{
    Solution s;
    //���Կ��ַ���
    if (s.isPalindrome(""))
        std::cout << "OK" << std::endl;
    //���Ե����ַ���
    if (s.isPalindrome("h"))
        std::cout << "OK" << std::endl;
}

////�ⷨ2��
////1.�����߼�
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
////2.�����߼�
//int main()
//{
//    //test_1();
//    //test_2();
//
//    //2.1.�����ַ�������
//    std::string str;
//    Solution s;
//    std::cout << "Please enter a string:";
//    while (getline(std::cin, str))
//    {
//        //2.2.�ж��Ƿ����
//        if (s.isPalindrome(str))
//        {
//            std::cout << "[" << str << "]�ǻ����ַ���" << std::endl;
//        }
//        else
//        {
//            std::cout << "[" << str << "]���ǻ����ַ���" << std::endl;
//        }
//        std::cout << "Please enter a string:";
//    }
//
//    return 0;
//}
//
////3.��������
//void test_1()
//{
//    Solution s;
//    //������ͨ�����ַ�����ż������
//    if (s.isPalindrome("abcddcba"))
//        std::cout << "OK" << std::endl;
//    //������ͨ�����ַ�������������
//    if (s.isPalindrome("abcdedcba"))
//        std::cout << "OK" << std::endl;
//    //���Էǻ����ַ���
//    if (!s.isPalindrome(""))
//        std::cout << "NO" << std::endl;
//    //�����ظ������ַ���
//    if (s.isPalindrome("AAA"))
//        std::cout << "YES" << std::endl;
//    //���԰����ո��ַ���
//    if (s.isPalindrome("A B C   BA"))
//        std::cout << "NO" << std::endl;
//}
//void test_2()
//{
//    Solution s;
//    //���Կ��ַ���
//    if (s.isPalindrome(""))
//        std::cout << "OK" << std::endl;
//    //���Ե����ַ���
//    if (s.isPalindrome("h"))
//        std::cout << "OK" << std::endl;
//}