//#include <iostream>
//class Data
//{
//    friend std::ostream& operator<<(std::ostream& out, Data& d);
//public:
//    //1.���캯��
//    Data(int data = 0)
//        :_data(data)
//    {
//        //std::cout << "Data()" << std::endl;
//    }
//    //2.��������
//    ~Data()
//    {
//        //std::cout << "~Data()" << std::endl;
//    }
//private:
//    int _data;
//};
////2.��Ԫ�����������غ���
//std::ostream& operator<<(std::ostream& out, Data& d)
//{
//    out << d._data;
//    return out;
//}
//int main()
//{
//#define NUMEBER 10
//    //1.new��������������
//    //1.1.��ʼ������1
//    int* p1 = new int(1);
//    std::cout << "p1 = " << p1 << " " << "*p1 = " << *p1 << std::endl;
//    //1.2.��ʼ������2
//    int* p2 = new int{ 2 };
//    std::cout << "p2 = " << p2 << " " << "*p2 = " << *p2 << std::endl;
//    //1.3.��ʼ������3
//    int* p3 = new int{ (3) };
//    std::cout << "p3 = " << p3 << " " << "*p3 = " << *p3 << std::endl;
//
//    //2.new��������������
//    //2.1.��ʼ������1
//    int* parr1 = new int[NUMEBER] { (1), (2), (3), (4), (5) };
//    std::cout << "parr1 = " << parr1 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr1[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.2.��ʼ������2
//    int* parr2 = new int[NUMEBER] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
//    std::cout << "parr2 = " << parr2 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr2[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.3.��ʼ������3
//    int* parr3 = new int[NUMEBER] { {(1)}, { (2) }, { (3) }, { (4) }, { (5) } };
//    std::cout << "parr3 = " << parr3 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr3[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.4.��ʼ������4
//    int* parr4 = new int[NUMEBER] { 1, 2, 3, 4, 5 };
//    std::cout << "parr4 = " << parr4 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr4[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "------------" << std::endl;//�������ͺ��Զ������͵ķָ���
//
//    //3.new�������Զ�������
//    //3.1.��ʼ������1
//    Data* d1 = new Data(1);
//    std::cout << "d1 = " << d1 << " " << "*d1 = " << *d1 << std::endl;
//    //3.2.��ʼ������2
//    Data* d2 = new Data{ 2 };
//    std::cout << "d2 = " << d2 << " " << "*d2 = " << *d2 << std::endl;
//    //3.3.��ʼ������3
//    Data* d3 = new Data{ (3) };
//    std::cout << "d3 = " << d3 << " " << "*d3 = " << *d3 << std::endl;
//
//    //4.new���Զ�����������
//    //4.1.��ʼ������1
//    Data* darr1 = new Data[NUMEBER] { (1), (2), (3), (4), (5) };
//    std::cout << "darr1 = " << darr1 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr1[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.2.��ʼ������2
//    Data* darr2 = new Data[NUMEBER] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
//    std::cout << "darr2 = " << darr2 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr2[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.3.��ʼ������3
//    Data* darr3 = new Data[NUMEBER] { { (1) }, { (2) } , { (3) }, { (4) }, { (5) } };
//    std::cout << "darr3 = " << darr3 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr3[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.4.��ʼ������4
//    Data* darr4 = new Data[NUMEBER] { 1, 2 , 3 , 4 , 5 };
//    std::cout << "darr4 = " << darr4 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr4[i] << " ";
//    }
//    std::cout << std::endl;
//
//    //5.�ͷ���Դ
//    delete p1;
//    delete p2;
//    delete p3;
//    delete[] parr1;
//    delete[] parr2;
//    delete[] parr3;
//    delete[] parr4;
//    delete d1;
//    delete d2;
//    delete d3;
//    delete[] darr1;
//    delete[] darr2;
//    delete[] darr3;
//    delete[] darr4;
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	try
//	{
//		char* p1 = new char[0xffffffff];
//		char* p2 = new char[0xffffffff];
//		char* p3 = new char[0xffffffff];
//		cout << "hello word" << endl;
//	}
//	catch(const exception& e)//���newʧ�ܾͻ���ת������
//	{
//		cout << e.what() << endl;//����������������������
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	try
//	{
//		char* p = (char*)operator new(sizeof(char));
//		operator delete(p);
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;//����������������������
//
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	try
//	{
//		int* p = new int[10];
//		//delete p;//��ʽ1
//		//free(p);//��ʽ2
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;//����������������������
//
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
////1.����дһ��Data��
//class Data
//{
//public:
//    Data(int data)
//        :_data(data)
//    {
//        cout << "Data()" << endl;
//    }
//    ~Data()
//    {
//        cout << "~Data()" << endl;
//    }
//private:
//    int _data;
//};
////2.����operator new()��operator delete()
//void* operator new(
//    size_t size, 
//    const char* fileName, 
//    const char* funcName, 
//    size_t lineNo)
//{
//    void* p = ::operator new(size);
//    cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-" << size << endl;
//    return p;
//}
//void operator delete(
//    void* p, 
//    const char* fileName, 
//    const char* funcName, 
//    size_t lineNo)
//{
//    cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << endl;
//    ::operator delete(p);
//}
//
//int main()
//{
//    int* p1 = new(__FILE__, __FUNCTION__, __LINE__) int;
//    operator delete(p1, __FILE__, __FUNCTION__, __LINE__);
//
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//
//    int* p2 = new int;
//    delete(p2);
//    return 0;
//}

//������VS2022��ʵ����
#include <iostream>
using namespace std;
class A
{
public:
    A(int a = 0)
        :_a(a)
    {
        cout << "A()" << endl;
    }
private:
    int _a;
};
class B
{
public:
    B(int b = 0)
        :_b(b)
    {
        cout << "B()" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
private:
    int _b;
};
int main()
{
    B* p2 = new B[5];
    free(p2 - 1);//��ʽ1
    delete p2;//��ʽ2
    //����p2������ռ��ʱ�򣬻������һ���ֿռ䣨�п�����4�ֽڣ��洢��5������ʾ���ٵĿռ�������������Ŀռ��в�������Ҫָ��ƫ�������ٵġ�
    //Ȼ���ٵ���delete[]��ʱ�򣬾Ϳ��Ը��������5��������5������������
    //��������ֱ��ʹ�á�free()���͡�delete�����޷��ͷ��ⲿ��������ʾʹ�ö��ٴ����������Ŀռ䡣
    //���������������ָ���λ�����⡣  

    A* p1 = new A[5];
    free(p1 - 1);//��ʽ1
    delete p1;//��ʽ2
    //����p2������ռ��ʱ�򣬻������һ���ֿռ䣨�п�����4�ֽڣ��洢��5������ʾ���ٵĿռ�������������Ŀռ��в�������Ҫָ��ƫ�������ٵġ�
    //Ȼ���ٵ���delete[]��ʱ�򣬾Ϳ��Ը��������5��������5������������
    //���������û�����������������еı�������ܴ�����֪�����õ���Ĭ�������������ͻ�ֱ�ӷ���ָ���ʶ�ռ��ָ��
    //���ֱ�ӷ��ص�ָ��û�з�����λ��������ֺܴ�����⡣
    return 0;
}