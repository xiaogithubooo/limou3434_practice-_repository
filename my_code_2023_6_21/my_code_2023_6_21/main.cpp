#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A(int x = 0)
	{
		_a = x;
		cout << "A(int x = 0)" << _a << endl;
	}
	A(const A& aa)
	{
		_a = aa._a;//����
		cout << "A(const A& aa)->" << _a << endl;
	}
	~A()
	{
		cout << "~A()->" << _a << endl;
	}
private:
	int _a;
};
void fun0(A aa)
{
	;
}
void fun1(A& aa)
{
	;
}
A fun2(void)
{
	static A aa;
	return aa;
}
A& fun3(void)
{
	static A aa;
	return aa;
}
int main()
{
	A aa0;//ʹ��һ�ι��캯��
	A aa1(aa0);//ʹ��һ�ο�������
	fun0(aa0);//����ʹ�õ��ǿ�����ֵ��ʽ������ʹ��һ���Զ���Ŀ������캯����ʹ�����βκ�ҲҪʹ���Զ�����������
	fun1(aa0);//����ʹ�õ������ô�ֵ��ʽ������ʹ���Զ���Ŀ������캯����Ҳ������ʹ���Զ�����������
	fun2();//�ڲ�������һ��static����aa��ʹ����һ�ι��캯���������䷵��ֵ��Ҫ����������ΪA���������󷵻�����������ʹ����һ���Զ��忽�����캯�������������������Ҫʹ��һ����������
	fun3();//�ڲ��ٴι���һ��static����aa��ʹ����һ�ι��캯��������ʹ�õ������÷��أ���������ʹ�ÿ������캯��
	return 0;
	//���aa0ʹ������������aa1Ҳʹ����������
	//��������static����aa�ֱ�ʹ����������
}

//class A
//{
//public:
//	A(int x)
//	{
//		_a = x;
//		cout << "A():" << "aa" << _a << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << "aa" << _a << endl;
//	}
//private:
//	int _a;
//};
//A aa0(0);
//void f(void)
//{
//	static A aa1(1);
//	A aa2(2);
//	A aa3(3);
//	static A aa4(4);
//}
//int main()
//{
//	f();
//	//����aa0
//	//����aa1
//	//����aa2
//	//����aa3
//	//����aa4
//	//����aa3
//	//����aa2
//	f();
//	//����aa2
//	//����aa3
//	//����aa3
//	//����aa2
//	return 0;
//}
//	//����aa4
//	//����aa1
//	//����aa0

//class A
//{
//public:
//    void f1(int x)
//    {
//        _a = x;
//    }
//    void f2(A x)
//    {
//        cout << x._a << endl;//����û�б���˵��ͬ���ʹ���ǲ��ᱻ�����޶����޶���
//    }
//    void Prin(void)
//    {
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A x;
//    A y;
//    x.f1(2);
//    y.f1(3);
//    x.Prin();
//    y.Prin();
//    y.f2(x);
//    return 0;
//}