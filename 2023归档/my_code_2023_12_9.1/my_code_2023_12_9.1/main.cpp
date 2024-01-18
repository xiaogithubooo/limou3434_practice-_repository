#include <iostream>
using namespace std;

class Father
{
public:
	virtual void f() {}
};

class Son : public Father
{};

void fun(Father* pf)
{
	//dynamic_cast 会先检查是否能转化成功，能成功转化，不能则返回 nullptr
	//如果 pf 得到的是子类指针还好，但如果真的就是父类指针本身，转化为子类后就有可能会造成越界问题
	Son* pb1 = static_cast<Son*>(pf);
	Son* pb2 = dynamic_cast<Son*>(pf);
	cout << "pb1:" << pb1 << " pb2:" << pb2 << endl;
}
int main()
{
	Father f;
	Son s;

	fun(&f);
	fun(&s);

	return 0;
}

//#include <iostream>
//#include <typeinfo>
//using namespace std;
//
//// 定义一个函数 func，返回类型为 int
//int func()
//{
//    return 42;
//}
//
//int main()
//{
//    //使用 decltype 推导出变量 Father 的类型
//    //a 的类型为 int，与 func() 的返回类型相同
//    decltype(func()) a = 10;
//
//    cout << typeid(a).name() << endl;
//    return 0;
//}

//#include <iostream>
//#include <typeinfo>
//using namespace std;
//
//class Base
//{
//    //...
//};
//
//class Derived : public Base
//{
//    //...
//};
//
//int main()
//{
//    Base* ptr1 = new Derived();
//    Derived* ptr2 = new Derived();
//
//    if (typeid(*ptr1) == typeid(Derived))
//    {
//        cout << "YES" << endl;
//    }
//    if (typeid(*ptr2) == typeid(Derived))
//    {
//        cout << "YES" << endl;
//    }
//
//    cout << typeid(ptr1).name() << endl;
//
//    delete ptr1;
//    delete ptr2;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Test()
//{
//	const int a = 10;
//	int* pa = const_cast<int*>(&a);
//	*pa = 3;
//	cout << a << endl;//由于 a 是一个常量，因此就会导致这里提前被替换为 10，还来不及被指针修改
//	cout << *pa << endl;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);//转化成功
//	cout << a << endl;
//
//	//int* p = static_cast<int*>(a);//转化失败
//	int* p = reinterpret_cast<int*>(a);//转化成功
//	cout << p << endl;
//	
//	return 0;
//}

//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//
//	////禁掉 operator new 可以把用 new 调用拷贝构造申请对象给禁掉
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//
//private:
//	int _a;
//};
//
//int main()
//{
//	StackOnly obj = StackOnly::CreateObj();
//	StackOnly obj;
//	//StackOnly* ptr1 = new StackOnly();//禁用
//	//StackOnly* ptr2 = new StackOnly(obj);//禁用，这个不能私有拷贝构造，只能删除 new 的底层调用 operator new，否则就无法返回 CreateObj() 的结果
//	//delete& obj;//禁用
//
//	return 0;
//}

//class HeapOnly
//{
//public:
//    static void Destroy_1(HeapOnly* ptr)
//    {
//        delete ptr;
//    }
//    //or
//    void Destroy_2()
//    {
//        delete this;
//    }
//
//private:
//    ~HeapOnly() {}
//};
//
//int main()
//{
//    //HeapOnly h1;//禁用
//
//    HeapOnly* ph1 = new HeapOnly;
//    HeapOnly::Destroy_1(ph1);
//
//    HeapOnly* ph2 = new HeapOnly;
//    ph2->Destroy_2();
//
//    //HeapOnly h2(*ph1);//禁用
//
//    return 0;
//}

//class CopyBan
//{
//public:
//	CopyBan()
//		: _c(1) 
//	{}
//	//拷贝构造私有化
//	CopyBan(const CopyBan&) = delete;
//	//赋值重载私有化
//	CopyBan& operator=(const CopyBan&) = delete;
//
//private:
//	int _c;
//};
//
//int main()
//{
//	CopyBan c;
//	//CopyBan copy(c);//禁用了
//
//	return 0;
//}

////模拟实现定制删除器
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <functional>
//
//template <typename Type>
//class SmartPtr
//{
//public:
//	//构造
//	SmartPtr(Type* ptr = nullptr)
//		: _ptr(ptr), _pcount(new int(1))
//	{}
//	//重载构造
//	template <typename Deleter>
//	SmartPtr(Type* ptr, Deleter del)
//		: _ptr(ptr), _pcount(new int(1)), _del(del)
//	{}
//
//	//析构
//	void _release()
//	{
//		if (--(*_pcount) == 0)
//		{
//			//delete _ptr;
//			_del(_ptr);
//			delete _pcount;
//
//		}
//	}
//	~SmartPtr()
//	{
//		_release();
//	}
//
//	//拷贝构造
//	SmartPtr(const SmartPtr<Type>& sp)
//		: _ptr(sp._ptr), _pcount(sp._pcount)
//	{
//		++(*_pcount);
//	}
//
//	//赋值重载
//	SmartPtr<Type>& operator=(const SmartPtr<Type>& sp)
//	{
//		if (_ptr != sp._ptr)//防止给自己赋值
//		{
//			_release();
//			_ptr = sp._ptr;
//			_pcount = sp._pcount;
//			++(*_pcount);
//		}
//		return *this;
//	}
//
//	//指针行为
//	Type& operator*()
//	{
//		return *_ptr;
//	}
//	Type* operator->()
//	{
//		return _ptr;
//	}
//
//	//引用个数
//	int use_count() const
//	{
//		return *_pcount;
//	}
//
//	//获取原生指针
//	Type* get_ptr() const
//	{
//		return _ptr;
//	}
//
//private:
//	Type* _ptr;
//	int* _pcount;
//	std::function<void(Type*)> _del = [](Type* ptr) { delete ptr; };
//};
//
//template<class T>
//struct DelArray
//{
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//
//int main()
//{
//	SmartPtr<std::string> sp1(new std::string[10], DelArray<std::string>());
//	SmartPtr<std::string> sp2(new std::string[10], [](std::string* ptr) { delete[] ptr; });
//	SmartPtr<FILE> sp3(fopen("limou.txt", "w+"), [](FILE* ptr) { fclose(ptr); });
//	SmartPtr<int> sp4(new int(1));
//	return 0;
//}