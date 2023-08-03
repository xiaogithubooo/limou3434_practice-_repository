#include <iostream>
#include <cassert>
using namespace std;
template<typename T>//也可以改typename成class
class Stack
{
public:
    //2.构造函数
    Stack(size_t capacity = 4)//默认在创建对象的时候开辟4个空间
        :_data(nullptr), _top(0), _capacity(0)//初始化列表初始化
    {
        cout << "Stack(size_t capacity = 4)" << endl;//打印，表示调用了构造函数
        if (capacity > 0)//小于0就无法创建一个栈
        {
            _data = new T[capacity];//创建了容量为capacity的数组
            _capacity = capacity;
            _top = 0;
        }
        else
        {
            cout << "栈容量不合法" << endl;
        }
    }
    //3.析构函数
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] _data;//释放资源
        _capacity = _top = 0;
    }
    //4.入栈
    void Push(const T& x)
    {
        if (_top == _capacity)//扩容机制
        {
            size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
            T* tmp = new T[newCapacity];
            if (_data)//如果数组之前申请成功
            {
                memcpy(tmp, _data, sizeof(T) * _top);//复制一份
                delete[] _data;
            }
            _data = tmp;
            _capacity = newCapacity;
        }
        _data[_top] = x;
        ++_top;
    }
    //5.出栈
    void Pop()
    {
        assert(_top > 0);
        _top--;
    }
    //6.判栈
    bool Empty()
    {
        return _top == 0;
    }
    //7.取栈顶
    T& Top()//这里最好加上引用，这里还可以替代修改栈顶数据的功能，不过如果在最前面加上const就不行了，这具体看需求
    {
        assert(_top > 0);
        return _data[_top - 1];
    }
private:
    //1.定义栈类的相关成员变量
    T* _data;//存储栈数据的数组
    size_t _top;//栈顶
    size_t _capacity;//栈容量
};
int main()
{
    //有关try和catch配合new的使用以后我们会提及
    try//这里是申请空间成功的做法
    {
        Stack<int> a(10);
        a.Push(1);
        a.Push(2);
        a.Push(3);
        a.Push(4);
        a.Push(5);
        a.Push(6);
        a.Top()++;
        while (!a.Empty())
        {
            cout << a.Top() << " ";
            a.Pop();
        }
        cout << endl;

        Stack<float> a(10);
        a.Push(1.1);
        a.Push(2.2);
        a.Push(3.3);
        a.Push(4.4);
        a.Push(5.5);
        a.Push(6.6);
        a.Top()++;
        while (!a.Empty())
        {
            cout << a.Top() << " ";
            a.Pop();
        }
        cout << endl;
    }
    catch (exception& e)//这里是申请空间失败的做法
    {
        cout << e.what() << endl;
    }
    return 0;
}

//#include <iostream>
//using namespace std;
//template<class T>//也可以写成typename
//class Stack
//{
//public:
//    Stack(size_t capacity = 4)
//        :_data(nullptr), _top(0), _capacity(0)//最后一个是为了防止Stack传0的情况    
//    {
//        if (capacity > 0)
//        {
//            _data = new T[capacity];
//            _capacity = capacity;
//            _top = 0;
//        }
//    }
//private:
//    T* _data;
//    size_t _top;
//    size_t _capacity;
//};
//int main()
//{
//    Stack<int> a(10);//1
//    Stack<char> b(5);//2
//    Stack<double> c(8);//3
//    return 0;
//}

/*
    //1.使用new申请一块指针，指向一块对象空间
    Data* pdata1 = new Data;
    //2.使用malloc申请一块指针，指向一块对象空间
    Data* pdata2 = (Data*)malloc(sizeof(Data));
    if (!pdata2) exit(-1);

    //但是此时出现了一个问题没有办法代码初始化内部的成员,
    //在上述代码中，我们使用new运算符创建了Data类型的对象指针。
    //创建对象时，将自动调用Data的构造函数来完成对象的初始化。
    //我们不需要显式调用构造函数，编译器会为我们处理。
    //pdata1->Data(1, 2, 3);//非法
    //pdata2->Data(1, 2, 3);//非法
    //pdata1->~Data();//合法
    //pdata2->~Data();//合法


    //这个时候就可以使用定位new
    new(pdata1)Data(1, 2);//对已经分配的原始内存空间中调用构造函数初始化一个对象
    new(pdata2)Data(10, 20);//对已经分配的原始内存空间中调用构造函数初始化一个对象

    delete pdata1;//释放空间的同时自动调用析构函数
    pdata2->~Data();
    free(pdata2);//释放空间，但是内部资源需要我们手动调用析构函数
*/