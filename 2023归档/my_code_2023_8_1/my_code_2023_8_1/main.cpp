//#include <iostream>
//using namespace std;
////�ۻ�������n������
////�ۻ�ʹ����m������
//int n = 0;
//int m = 0;
//class Data
//{
//public:
//	Data()
//	{
//		n++;
//		m++;
//	}
//	Data(const Data& t)
//	{
//		n++;
//		m++;
//	}
//	~Data()
//	{
//		m--;
//	}
//private:
//};
//Data Func(Data a)
//{
//	return a;
//}
//int main()
//{
//	Data d1;
//	cout << n << " " << m << endl;
//	Data d2;
//	cout << n << " " << m << endl;
//	Data ();
//	cout << n << " " << m << endl;
//	Func(d2);
//	cout << n << " " << m << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
////�ۻ�������n������
////�ۻ�ʹ����m������
//class Data
//{
//public:
//	Data()
//	{
//		n++;
//		m++;
//	}
//	Data(const Data& t)
//	{
//		n++;
//		m++;
//	}
//	~Data()
//	{
//		m--;
//	}
//	static void Print()
//	{
//		cout << m << " " << n << endl;
//	}
//private:
//	static int n;
//	static int m;
//};
//int Data::n = 0;
//int Data::m = 0;
//Data Func(Data a)
//{
//	return a;
//}
//int main()
//{
//	Data d1;
//	d1.Print();
//	Data d2;
//	Data::Print();
//	Data ();
//	Data::Print();
//	Func(d2);
//	Data::Print();
//	Data* d3 = nullptr;
//	d3->Print();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class B
//{
//public:
//    static B CreateObj()//3.�ṩһ���ӿڣ������ʹ�ù��캯��
//    {
//        B b;
//        return b;
//    }
//private:
//    B(int x = 0, int y = 0)//2.�ڹ����ʱ��ֻ����ջ�Ͽ��ٿռ䣬�����޷�ʹ���࣬��Ϊ��������޶�����private
//        :_x(x)
//        , _y(y)
//    {}
//private:
//    int _x;
//    int _y;
//};
//int main()
//{
//    //static B data1;//1.�޷���������Ϊ���캯����˽�е�
//    B data2 = B::CreateObj();//4.�����ӿڼ�Ӵ�����data2���󣬲��ұ�֤һ������ջ�Ͽ��٣����û�а취�ٶ��Ͽ��ٸ����͵Ķ���
//    
//    //5.CreateObjǰ��֮���Լ���static
//    //��Ϊ�˱��⡰���м����������е���������
//    //��Ϊ����û��static��Ҫʹ��CreateObj()��Ҫ�ȴ���һ��B���͵Ķ������ʹ��
//    //���������޶���private��ԭ��û�а취ֱ��ʹ�ù��캯����������
//    //ʹ���ܹ�ֱ��ʹ��CreateObj()
//    return 0;
//}

//class Solution
//{
//    class Sum
//    {
//    public:
//        Sum()
//        {
//            _ret += _i;
//            _i++;
//        }
//    };
//
//public:
//    int Sum_Solution(int n)
//    {
//        Sum* arr = new Sum[n];
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;

//#include <iostream>
//using namespace std;
//class Widget
//{
//public:
//    //1.���캯��
//    Widget(int x = 0)
//    {
//        cout << "Widget()" << endl;
//        _x = x;
//    }
//    //2.�������캯��
//    Widget(const Widget& w)
//    {
//        cout << "Widget(const Widget& w)" << endl;
//    }
//    //3.��ֵ���غ���
//    Widget& operator=(const Widget& w)
//    {
//        cout << "Widget& operator=(const Widget& w)" << endl;
//        return *this;
//    }
//    //4.��������
//    ~Widget()
//    {
//        cout << "~Widget()" << endl;
//    }
//private:
//    int _x;
//};
//void f1(Widget u)
//{
//
//}
//Widget f2()
//{
//    Widget d; 
//    return d;
//}
//Widget f3()
//{
//    return Widget(1);
//}
//int main()
//{
//    //����1
//    Widget w1;
//    f1(w1);
//    cout << "----" << endl;
//    //�ȵ��� ���캯��Widget()
//    //Ȼ����ú�����ʱ����βε��� �������캯��Widget(const Widget & w) ��������ʱ����u
//    //������ ��������~Widget() ��������ʱ����u
//
//    //����2
//    f1(Widget(2));
//    cout << "----" << endl;
//    /*
//    ԭ��Ӧ���ǵ��� ���캯��Widget() ����һ����������
//    Ȼ����� �������캯��Widget(const Widget & w) ��������ʱ����u��
//    ���ʹ�� ��������~Widget() ������u��
//    ���ǣ����ڱ��������Ż������ġ����족+���������족---->��ֱ�ӹ��족��
//    ���Ա������ĵ��ã�
//    */
//    //Widget()
//    //~Widget()
//
//    //����3
//    f1(2);
//    cout << "----" << endl;
//    /*
//    ԭ��Ӧ���ǵ��� ���캯��Widget() ����һ����ʱ����
//    Ȼ����� �������캯��Widget(const Widget & w) ��������ʱ����u��
//    ���ʹ�� ��������~Widget() ������u��
//    ���ǣ����ڱ��������Ż������ġ����족+���������족---->��ֱ�ӹ��족��
//    ���Ա������ĵ��ã�
//    */
//    //Widget()
//    //~Widget()
//
//    //����4
//    Widget d2 = Widget(3);
//    cout << "----" << endl;
//    /*
//    ԭ��Ӧ���ǵ��� ���캯��Widget() ����һ����ʱ����
//    Ȼ��ʹ�� �������캯��Widget(const Widget & w) ������d2����
//    ���ǣ����ڱ��������Ż������ġ����족+���������족---->��ֱ�ӹ��족��
//    ���Ա������ĵ��ã�
//    */
//    //Widget()
//
//    //����5
//    f2();
//    cout << "----" << endl;
//    /*
//    ����f(2)�ĺ�������
//    Widget f2()
//    {
//        Widget d; 
//        return d;
//    }
//    ԭ��Ӧ���ǵ��� ���캯��Widget() ����d����
//    Ȼ��ʹ�� �������캯��Widget(const Widget & w) ����һ����ʱ�������ڷ��غ���ֵ
//    ������������ʱ����
//    ���ǣ����ڱ��������Ż������ġ����족+���������족---->��ֱ�ӹ��족��
//    ���Ա������ĵ��ã�
//    */
//    //Widget()
//    //~Widget()
//
//    //����6
//    Widget ret1 = f2();
//    cout << "----" << endl;
//    /*
//    ����f(2)�ĺ�������
//    Widget f2()
//    {
//        Widget d; 
//        return d;
//    }
//    ԭ��Ӧ���ǵ��� ���캯��Widget() ����d����
//    Ȼ��ʹ�� �������캯��Widget(const Widget & w) ��d������һ����ʱ������ڷ��غ���ֵ��
//    �ٵ��� �������캯��Widget(const Widget & w) ����ʱ���󿽱���ret1
//    Ȼ�����������ʱ������
//    ���������ֱ�Ӳ�������ʱ��������dֱ�ӵ��� �������캯��Widget(const Widget & w) ��ret1��
//    �����ڱ��������Ż������ġ����족+���������족---->��ֱ�ӹ��족��
//    ����� Widget ret1 = f2(); ��һ��ĵ����о�ֻʣ���ˡ�ֱ�ӹ��족��
//    */
//    //Widget()
//
//    //����7
//    Widget ret2;
//    ret2 = f2();
//    cout << "----" << endl;
//    /*
//    ��ʹ�� ���캯��Widget() ����һ��ret2����
//    Ȼ����f2()�ڵ��� ���캯��Widget() ����d����
//    Ȼ��ʹ�� �������캯��Widget(const Widget & w) ��d������һ����ʱ������ڷ��غ���ֵ��
//    ��ʹ�� ��ֵ���غ���Widget& operator=(const Widget& w) ����ʱ������ֵ��ret2��
//    ���������ʱ������
//    ���ڲ�����һ�д��������������������������������ֻ�Ż��˲��֣���f2()�ڵĹ���Ϳ�����������ֱ�ӹ��죩��û��ȫ���Ż���
//    */
//    //Widget()
//    //Widget()
//    //Widget& operator=(const Widget & w)
//    //~Widget()
//
//    //����8
//    Widget ret3 = f3();
//    cout << "----" << endl;
//    /*
//    ����f3()�ڲ����죺
//    Widget f3()
//    {
//        return Widget(1);
//    }
//    ԭ�����ǵ��� ���캯�� ����һ����������
//    Ȼ��ͨ�� �������캯�� ���������󿽱�����ʱ����
//    Ȼ��ʹ�� �������캯�� ����ʱ����������ret3��
//    ��������Ż��ͱ��������������
//    */
//    //Widget()
//    return 0;
//}
#include <iostream>
using namespace std;
class ListNode
{
public:
	ListNode(int val = 0)
		:_val(val)
		,_next(nullptr)
	{}
	int _val;
	ListNode* _next;
};
int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	
	l1->_next = l2;
	l2->_next = l3;
	l3->_next = l4;
	l4->_next = l5;

	delete l1;
	delete l2;
	delete l3;
	delete l4;
	delete l5;
	return 0;
}