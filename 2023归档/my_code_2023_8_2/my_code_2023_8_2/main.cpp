//#include <iostream>
//class Data
//{
//    friend std::ostream& operator<<(std::ostream& out, Data& d);
//public:
//    //1.构造函数
//    Data(int data = 0)
//        :_data(data)
//    {
//        //std::cout << "Data()" << std::endl;
//    }
//    //2.析构函数
//    ~Data()
//    {
//        //std::cout << "~Data()" << std::endl;
//    }
//private:
//    int _data;
//};
////2.友元函数：流重载函数
//std::ostream& operator<<(std::ostream& out, Data& d)
//{
//    out << d._data;
//    return out;
//}
//int main()
//{
//#define NUMEBER 10
//    //1.new出单个内置类型
//    //1.1.初始化方法1
//    int* p1 = new int(1);
//    std::cout << "p1 = " << p1 << " " << "*p1 = " << *p1 << std::endl;
//    //1.2.初始化方法2
//    int* p2 = new int{ 2 };
//    std::cout << "p2 = " << p2 << " " << "*p2 = " << *p2 << std::endl;
//    //1.3.初始化方法3
//    int* p3 = new int{ (3) };
//    std::cout << "p3 = " << p3 << " " << "*p3 = " << *p3 << std::endl;
//
//    //2.new出内置类型数组
//    //2.1.初始化方法1
//    int* parr1 = new int[NUMEBER] { (1), (2), (3), (4), (5) };
//    std::cout << "parr1 = " << parr1 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr1[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.2.初始化方法2
//    int* parr2 = new int[NUMEBER] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
//    std::cout << "parr2 = " << parr2 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr2[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.3.初始化方法3
//    int* parr3 = new int[NUMEBER] { {(1)}, { (2) }, { (3) }, { (4) }, { (5) } };
//    std::cout << "parr3 = " << parr3 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr3[i] << " ";
//    }
//    std::cout << std::endl;
//    //2.4.初始化方法4
//    int* parr4 = new int[NUMEBER] { 1, 2, 3, 4, 5 };
//    std::cout << "parr4 = " << parr4 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << parr4[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "------------" << std::endl;//内置类型和自定义类型的分隔符
//
//    //3.new出单个自定义类型
//    //3.1.初始化方法1
//    Data* d1 = new Data(1);
//    std::cout << "d1 = " << d1 << " " << "*d1 = " << *d1 << std::endl;
//    //3.2.初始化方法2
//    Data* d2 = new Data{ 2 };
//    std::cout << "d2 = " << d2 << " " << "*d2 = " << *d2 << std::endl;
//    //3.3.初始化方法3
//    Data* d3 = new Data{ (3) };
//    std::cout << "d3 = " << d3 << " " << "*d3 = " << *d3 << std::endl;
//
//    //4.new出自定义类型数组
//    //4.1.初始化方法1
//    Data* darr1 = new Data[NUMEBER] { (1), (2), (3), (4), (5) };
//    std::cout << "darr1 = " << darr1 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr1[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.2.初始化方法2
//    Data* darr2 = new Data[NUMEBER] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
//    std::cout << "darr2 = " << darr2 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr2[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.3.初始化方法3
//    Data* darr3 = new Data[NUMEBER] { { (1) }, { (2) } , { (3) }, { (4) }, { (5) } };
//    std::cout << "darr3 = " << darr3 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr3[i] << " ";
//    }
//    std::cout << std::endl;
//    //4.4.初始化方法4
//    Data* darr4 = new Data[NUMEBER] { 1, 2 , 3 , 4 , 5 };
//    std::cout << "darr4 = " << darr4 << std::endl;
//    for (int i = 0; i < NUMEBER; i++)
//    {
//        std::cout << darr4[i] << " ";
//    }
//    std::cout << std::endl;
//
//    //5.释放资源
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
//	catch(const exception& e)//如果new失败就会跳转到这里
//	{
//		cout << e.what() << endl;//并且这里是输出错误的理由
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
//		cout << e.what() << endl;//并且这里是输出错误的理由
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
//		//delete p;//方式1
//		//free(p);//方式2
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;//并且这里是输出错误的理由
//
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
////1.首先写一个Data类
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
////2.重载operator new()和operator delete()
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

//以下是VS2022下实验结果
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
    free(p2 - 1);//方式1
    delete p2;//方式2
    //这里p2在申请空间的时候，会多申请一部分空间（有可能是4字节）存储“5”来表示开辟的空间个数。因此申请的空间有部分是需要指针偏移来销毁的。
    //然后再调用delete[]的时候，就可以根据这个“5”来调用5次析构函数。
    //但是由于直接使用“free()”和“delete”就无法释放这部分用来表示使用多少次析构函数的空间。
    //因此真正的问题是指针错位的问题。  

    A* p1 = new A[5];
    free(p1 - 1);//方式1
    delete p1;//方式2
    //这里p2在申请空间的时候，会多申请一部分空间（有可能是4字节）存储“5”来表示开辟的空间个数。因此申请的空间有部分是需要指针偏移来销毁的。
    //然后再调用delete[]的时候，就可以根据这个“5”来调用5次析构函数。
    //由于这个类没有析构函数，所以有的编译器会很聪明，知道调用的是默认析构函数，就会直接返回指向标识空间的指针
    //因此直接返回的指针没有发生错位，不会出现很大的问题。
    return 0;
}