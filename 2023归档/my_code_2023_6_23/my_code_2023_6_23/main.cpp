#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Data1
{
public:
	class Data2//2.Data2������Data1�ڲ�������ֻ�ǣ�
	//1.��A����������
	//2.Data2������Data1����Ԫ��
	{
	public:
		void Function(const Data1& a)
		{
			cout << a._a1 << endl;//��Ԫ������
		}
	private:
		int _a2;
		int _b2;
		int _c2;
	};
private:
	int _a1;
	int _b1;
	int _c1;
};
int main()
{
	cout << sizeof(Data1) << endl;
	//1.���12��˵��Data1û�м���Data2��С
	Data1::Data2 D;
	return 0;
}

//class Data
//{
//	friend class FriendData;//1.��Data����������Ԫ��FriendData
//	friend void function(void);
//public:
//	Data(int a = 0, int b = 0, int c = 0)
//		:_a(a), _b(b), _c(c)
//	{
//		cout << "Data()" << endl;
//	}
//	void Print(void)
//	{
//		cout << _a << " " << _b << " " << _b << " " << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//class FriendData
//{
//public:
//	void Fun1()
//	{
//		Data D;
//		cout << D._a << endl;//2.���Ժ��޹˼ɷ���Data�����еĳ�Ա����
//	}
//	void Fun2()
//	{
//		Data D;
//		cout << D._a << endl;//3.���˱������ܷ���Data�����еĳ�Ա����
//		D.Print();
//	}
//	void Fun3()
//	{
//		Data D;
//		cout << D._a << endl;
//	}
//};
//void function(void)
//{
//	Data D;
//	cout << D._a << " " << D._b << " " << D._b << " " << endl;
//	D.Print();
//	FriendData FD;
//	FD.Fun1();
//	FD.Fun2();
//}
//int main()
//{
//	function();
//	return 0;
//}
//class B
//{
//public:
//	static B CreateObj()//3.�ṩһ���ӿڣ������ʹ�ù��캯��
//	{
//		B b;
//		return b;
//	}
//private:
//	B(int x = 0, int y = 0)//2.�ڹ����ʱ��ֻ����ջ�Ͽ��ٿռ䣬�����޷�ʹ���࣬��Ϊ��������޶�����private
//		:_x(x)
//		,_y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//int main()
//{
//	//static B data1;//1.�޷�����
//	B data2 = B::CreateObj();//4.�����ӿڼ�Ӵ�����data2���󣬲��ұ�֤һ������ջ�Ͽ���
//	//5.CreateObjǰ��֮���Լ���static
//	//��Ϊ�˱��⡰���м����������е���������
//	//��Ϊ����û��static��Ҫʹ��CreateObj()��Ҫ�ȴ���һ��B���͵Ķ������ʹ��
//	//���������޶���private��ԭ��û�а취ֱ��ʹ�ù��캯����������
//	//ʹ���ܹ�ֱ��ʹ��CreateObj()
//	return 0;
//}

//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	void Print(void)
//	{
//		cout << _scount << endl;
//	}
//	//int GetScount(void)//11.������һ��
//	//{
//	//	return _scount;
//	//}
//	static int GetScount(void)//13.����������
//	{
//		//_a;//15.�޷����ʷǾ�̬��Ա��������Ϊû��thisָ�룩
//		return _scount;
//	}
//	static int _scount_x;
//private:
//	static int _scount;//1.��̬��Ա
//	int _a = 0;
//};
//int A::_scount = 1;//6.����ֻ���������涨��ͳ�ʼ��
//int A::_scount_x = 0;
//
//int main()
//{
//	A a1;
//	//2.�������Ӵ�����Ϊֻ�о�̬��Ա����ֻ������û�ж��壬��ͨ��Ա�Ǹ�����һ�����
//	//3.������ͨ��ԱC++�涨��ú���Ҫʹ�ó�ʼ���б��ʼ��
//	//4.����̬��Ա�����ǲ���ʹ�ó�ʼ���б�ĳ�ʼ����
//	//5.���Ҿ�̬��Ա����Ҳ���ܸ�ȱʡֵ��������Ϊȱʡֵ�����ǳ�ʼ���б�ģ���˻��ǲ�����
//	
//	//a1._scount;//7.�����ܵ������޶�����Ӱ�죬���Բ���ֱ�ӽ��з���
//
//	a1.Print();//8.���ǿ���ͨ���������ʹ��_scount��Ҳ֤���˾�̬��Ա����ȷʵ�Ǳ������������е�
//	A a2;
//	a2.Print();
//
//	//9.���ܷ����޶������ƣ����������ַ�ʽ���ʾ�̬��Ա����
//	cout << a1._scount_x << endl;
//	A::_scount_x++;
//	cout << a1._scount_x << endl;
//	cout << a2._scount_x << endl;
//
//	//10.������ʹ�ýӿ���ȡ��˽�еľ�̬��Ա����������һ��
//	//cout << a1.GetScount() << endl; 
//
//	//12.Ҳ����ʹ�þ�̬��Ա��������ȡ��̬��Ա��������������
//	cout << A::GetScount() << endl;
//
//	//14.��̬��Ա���������Ե���������û��thisָ�룬����û�а취���ʷǾ�̬�ĳ�Ա
//	return 0;
//}

//class Data1
//{
//public:
//	Data1(int year)
//		:_year(year)
//	{
//		cout << "Data1(int year)" << endl;
//	}
//	Data1(const Data1& d)
//	{
//		cout << "Data1(const Data1& d)" << endl;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	Data1 dd1(2021);
//	Data1 dd2 = 2022;
//	//��������д��Ч��һ�������ǹ��̲�һ��
//	//1.dd1�ǣ���ֱ�ӵ��ù��캯����
//	//2.dd2�ǣ���ʽת��---->�����캯����+���������캯����+�������Ż�---->��ֱ�ӵ��ù��캯����
//	//����ڹ��캯��ǰ�����explicit�ؼ��֣��ͻ�ȡ��������ʽת��
//
//	//�������dd2�Ĵ�������ʵ���Ͼ���һ����ʽ����ת�������е���ʽ����ת������������ʱ��������ʱ�������г�����
//	int i = 10;
//	//double& d = i;//�������ǲ��������
//	const double& d = i;//�������õ��ǡ�i��ֵ��dʱ����������ʱ�����������Ǳ������
//
//	const Data1& dd3 = 2023;
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		: _a1(a)//��ʼ���б��ǰ����������Ⱥ�˳�������ν��г�ʼ����
//		, _a2(_a1)//���������_a2����ʼ�������ֵ
//	{}
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//	return 0;
//}

//class A
//{
//public:
//	A(int N)
//		:_a((int*)malloc(sizeof(int)* N))
//		,_N(N)
//	{
//		if (_a == NULL)
//		{
//			perror("malloc fail\n");
//		}
//		memset(_a, 0, sizeof(int) * N);
//	}
//private:
//	int* _a;
//	int _N;
//};
//int main()
//{
//	A aa0(100);
//	return 0;
//}

////class Data1
////{
////public:
////	Data1(int a1 = 0)//�ṩ��Ĭ�Ϲ��캯��
////	{
////		_a1 = a1;
////	}
////private:
////	int _a1;
////};
////class Data2
////{
////public:
////	Data2(int a2, int b2, int c2 = 0, int d2 = 0, int e2 = 0, int f2 = 0)
////	//���������ʼ��
////		:_c2(c2)
////		,_d2(d2)
////		,_e2(e2)
////		,_f2(f2)
////	{
////		Data1 D(b2);
////		_b2 = D;
////	}
////
////private:
////	int _a2 = 0;//����ʹ����Ĭ�Ϲ��캯��
////
////	Data1 _b2;//���ﲻ�ǳ�ʼ������ȱʡֵ
////
////	int _c2;//����ʹ���˳�ʼ���б�
////	Data1 _d2;//����ʹ���˳�ʼ�б�
////	const int _e2;//����ʹ���˳�ʼ�б�
////	int& _f2;//����ʹ���˳�ʼ�б�
////};
////int main()
////{
////	Data2 c;
////	return 0;
////}
//
////#define _CRT_SECURE_NO_WARNINGS 1
////#include <iostream>
////using namespace std;
//class Data1
//{
//public:
//	Data1(int a1 = 0)//�ṩ��Ĭ�Ϲ��캯��
//	{
//		_a1 = a1;
//	}
//private:
//	int _a1;
//};
//class Data2
//{
//public:
//	Data2(int a1)/*int a2, int b2, int c2,*/
//	{
//		//�������ڳ�ʼ��
//	/*	_a2 = a2;
//		_b2 = b2;
//		_c2 = c2;*/
//		Data1 D(a1);
//		_d2 = D;
//	}
//private:
//	//int _a2;
//	//int _b2;
//	//int _c2;
//	Data1 _d2;
//};
//int main()
//{
//	Data2 b;
//	return 0;
//}