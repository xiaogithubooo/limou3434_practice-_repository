//��Դת��
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
namespace limou
{
    class string
    {
        //1.��Ա����
    public:
        //���캯��
        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            cout << "begin: string(const char* str = \"\")" << '\n';
            _str = new char[_capacity + 1];
            strcpy(_str, str);
            cout << "end: string(const char* str = \"\")" << '\n';
        }

        //��������
        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
        string(const string& s)
            :_str(nullptr)
        {
            cout << "begin: string(const string& s) -- ���" << endl;
            string tmp(s._str);
            swap(tmp);
            cout << "end: string(const string& s) -- ���" << endl;
        }

        //�ƶ�����
        string(string&& s) noexcept
            :_str(nullptr)
        {
            cout << "begin: string(string&& s) -- �ƶ�����" << endl;
            
            swap(s);
            cout << "end: string(string&& s) -- �ƶ�����" << endl;
        }

        //��ֵ����
        string& operator=(const string& s)
        {
            cout << "begin: string& operator=(string s) -- ���" << endl;
            string tmp(s);
            swap(tmp);
            cout << "end: string& operator=(string s) -- ���" << endl;
            return *this;
        }

        //��������
        ~string()
        {
            cout << "begin: ~string()" << endl;
            delete[] _str;
            _str = nullptr;
            cout << "end: ~string()" << endl;
        }

        //��������
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        string operator+(char ch)
        {
            string cache(*this);
            cache += ch;
            return cache;
        }

        //2.��Ա����
    private:
        char* _str;
        size_t _size;
        size_t _capacity; //�������������ʶ��\0
    };
}

int main()
{
    limou::string s1("hello word");//���ù��캯��
    limou::string ret1 = s1;

    limou::string ret2 = move(s1 + '!');//����ֵ��Դת��
    //���������� (str1 + '!') ������һ����ֵ��
    //�������������л����һ����ʱ����������ֵ��
    //�������ʹ��������¶���ʹ���µ�ַ
    //���Ҹ��������ʱ��������Դ��

    //�����һЩ�˷ѣ���Ϊ��ʱ��������������
    //Ϊ�β�ֱ�Ӷ������ʱ��������Դת�ƽ��� ret2 �أ�
    //��ֵ���þͿ���������һ���顣

    //���ֻ�� const ����ֵ���ã�
    //��ֻ������ֵ��ʹ��ͬһ�����������
    //�޷����ֿ������ԵĴ���

    limou::string ret3 = move(s1);//����ֵ��Դת�ƣ���ô��ֵԭ����Դ�ͻᱻ��ȡ��ת�Ƶ� ret3 �ϣ�move(s1) �ķ���ֵ����ֵ

    return 0;
}