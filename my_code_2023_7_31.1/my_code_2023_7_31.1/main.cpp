//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//class Data1
//{
//public:
//    Data1(int a1)//�ṩ��Ĭ�Ϲ��캯��
//    {
//        _a1 = a1;
//    }
//private:
//    int _a1;
//};
//class Data2
//{
//public:
//    Data2(int a2, int b2, int c2, int d2)
//        //���������ʼ��
//        :_a2(a2)
//        , _b2(b2)
//        , _c2(c2)
//        , _d2(d2)//�൱����ʾ��������Ĺ��캯��
//    {}
//private:
//    int _a2;
//    int _b2;
//    int _c2;
//    Data1 _d2;
//};
//int main()
//{
//    int i = 2;
//    Data1 a(i);
//    Data2 b(5, 5, 5, 5);
//    return 0;
//}
//#include <iostream>
//using namespace std;
//class Data1
//{
//public:
//    Data1(int a1, int b1, int c1, int& d1)
//        : _d1(d1)
//    {
//        _a1 = a1;
//        _b1 = b1;
//        _c1 = c1;
//    }
//private:
//    int _a1;
//    int _b1;
//    int _c1;
//    int& _d1;
//};
//int main()
//{
//    int i = 0;
//    Data1 a(5, 5, 5, i);
//    return 0;
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    A(int a)
//        : _a1(a)//2.���ڳ�ʼ���б��ǰ����������Ⱥ�˳�������ν��г�ʼ����
//        , _a2(_a1)//3.���������_a2����ʼ�������ֵ��_a1������a��ֵ
//    {}
//    void Print()
//    {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    //1.������ǳ�Ա����������˳��
//    int _a1;
//    int _a2;
//};
//int main()
//{
//    A aa(1);
//    aa.Print();
//    return 0;
//}
//������������Ӧ���ǡ�1 ���ֵ��

//#include <iostream>
//using namespace std;
//class Data
//{
//public:
//	Data(int i, int j)
//		: _i(i)
//		, _j(j)
//	{
//		cout << "Data(int i, int j)" << endl;
//	}
//private:
//	int _i;
//	int _j;
//};
//int main()
//{
//	Data a;
//	return 0;
//}

#include <iostream>
using namespace std;
class Data
{
public:
    Data(int x = 1, int y = 0)
        : _x(x)
        , _y(y)
    {}
    void Print(Data a, Data b)
    {
        cout << a._x << " " << a._y << endl;
        cout << b._x << " " << b._y << endl;
    }
private:
    int _x;
    int _y;
};
int main()
{
    Data d1;
    d1.Print(Data(100, 100), Data(32, 123));
    return 0;
}
