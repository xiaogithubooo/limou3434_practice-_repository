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
	//dynamic_cast ���ȼ���Ƿ���ת���ɹ����ܳɹ�ת���������򷵻� nullptr
	//��� pf �õ���������ָ�뻹�ã��������ľ��Ǹ���ָ�뱾��ת��Ϊ�������п��ܻ����Խ������
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
//// ����һ������ func����������Ϊ int
//int func()
//{
//    return 42;
//}
//
//int main()
//{
//    //ʹ�� decltype �Ƶ������� Father ������
//    //a ������Ϊ int���� func() �ķ���������ͬ
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
//	cout << a << endl;//���� a ��һ����������˾ͻᵼ��������ǰ���滻Ϊ 10������������ָ���޸�
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
//	int a = static_cast<int>(d);//ת���ɹ�
//	cout << a << endl;
//
//	//int* p = static_cast<int*>(a);//ת��ʧ��
//	int* p = reinterpret_cast<int*>(a);//ת���ɹ�
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
//	////���� operator new ���԰��� new ���ÿ�������������������
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
//	//StackOnly* ptr1 = new StackOnly();//����
//	//StackOnly* ptr2 = new StackOnly(obj);//���ã��������˽�п������죬ֻ��ɾ�� new �ĵײ���� operator new��������޷����� CreateObj() �Ľ��
//	//delete& obj;//����
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
//    //HeapOnly h1;//����
//
//    HeapOnly* ph1 = new HeapOnly;
//    HeapOnly::Destroy_1(ph1);
//
//    HeapOnly* ph2 = new HeapOnly;
//    ph2->Destroy_2();
//
//    //HeapOnly h2(*ph1);//����
//
//    return 0;
//}

//class CopyBan
//{
//public:
//	CopyBan()
//		: _c(1) 
//	{}
//	//��������˽�л�
//	CopyBan(const CopyBan&) = delete;
//	//��ֵ����˽�л�
//	CopyBan& operator=(const CopyBan&) = delete;
//
//private:
//	int _c;
//};
//
//int main()
//{
//	CopyBan c;
//	//CopyBan copy(c);//������
//
//	return 0;
//}

////ģ��ʵ�ֶ���ɾ����
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <functional>
//
//template <typename Type>
//class SmartPtr
//{
//public:
//	//����
//	SmartPtr(Type* ptr = nullptr)
//		: _ptr(ptr), _pcount(new int(1))
//	{}
//	//���ع���
//	template <typename Deleter>
//	SmartPtr(Type* ptr, Deleter del)
//		: _ptr(ptr), _pcount(new int(1)), _del(del)
//	{}
//
//	//����
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
//	//��������
//	SmartPtr(const SmartPtr<Type>& sp)
//		: _ptr(sp._ptr), _pcount(sp._pcount)
//	{
//		++(*_pcount);
//	}
//
//	//��ֵ����
//	SmartPtr<Type>& operator=(const SmartPtr<Type>& sp)
//	{
//		if (_ptr != sp._ptr)//��ֹ���Լ���ֵ
//		{
//			_release();
//			_ptr = sp._ptr;
//			_pcount = sp._pcount;
//			++(*_pcount);
//		}
//		return *this;
//	}
//
//	//ָ����Ϊ
//	Type& operator*()
//	{
//		return *_ptr;
//	}
//	Type* operator->()
//	{
//		return _ptr;
//	}
//
//	//���ø���
//	int use_count() const
//	{
//		return *_pcount;
//	}
//
//	//��ȡԭ��ָ��
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