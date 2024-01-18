template<typename T>//也可以写成typename
class Data
{
public:
    void Print();
};
template<class T>//这里是声明一下模板参数
void Data<T>::Print()
{
    //函数的具体定义
}
//#include <iostream>
//#include <cassert>
//using namespace std;
//template<class T>//也可以写成typename
//class Stack
//{
//public:
//    Stack(size_t capacity = 4)
//        :_data(nullptr), _top(0), _capacity(0) 
//    {
//        cout << "Stack(size_t capacity = 4)" << endl;
//        if (capacity > 0)
//        {
//            _data = new T[capacity];
//            _capacity = capacity;
//            _top = 0;
//        }
//    }
//    ~Stack()
//    {
//        cout << "~Stack()" << endl;
//        delete[] _data;
//        _capacity = _top = 0;
//    }
//    void Push(const T& x);
//    void Pop()
//    {
//        assert(_top > 0);
//        _top--;
//    }
//    bool Empty()
//    {
//        return _top == 0;
//    }
//    T& Top()//这里最好加上引用，这里还可以替代修改栈顶数据的功能，不过如果在最前面加上const就不行了，这具体看需求
//    {
//        assert(_top > 0);
//        return _data[_top - 1];
//    }
//private:
//    T* _data;
//    size_t _top;
//    size_t _capacity;
//};
//template<class T>//这里是声明一下模板参数
//void Stack<T>::Push(const T& x)//类模板声明与定义分离（同一个文件下）
//{
//    if (_top == _capacity)
//    {
//        size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//        T* tmp = new T[newCapacity];
//        if (_data)//如果栈不为空
//        {
//            memcpy(tmp, _data, sizeof(T) * _top);
//            delete[] _data;
//        }
//        _data = tmp;
//        _capacity = newCapacity;
//    }
//    _data[_top] = x;
//    ++_top;
//}
//int main()
//{
//    //有关try和catch配合new的使用以后我们会提及
//    try//这里是申请空间成功的做法
//    {
//        Stack<int> a(10);
//        a.Push(1);
//        a.Push(2);
//        a.Push(3);
//        a.Push(4);
//        a.Push(5);
//        a.Push(6);
//        a.Top()++;
//        while (!a.Empty())
//        {
//            cout << a.Top() << " ";
//            a.Pop();
//        }
//        cout << endl;
//    }
//    catch (exception& e)//这里是申请空间失败的做法
//    {
//        cout << e.what() << endl;
//    }
//    return 0;
//}