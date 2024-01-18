#include <stdio.h>
void test_1()
{
	int a = 1;//没有使用 static
	a++;
	printf("%d ", a);
}

void test_2()
{
	static int a = 1;//增加了关键字 static
	a++;
	printf("%d ", a);
}

int main()
{
	int i = 0;
	while (i < 10)
	{
		test_1();
		i++;
	}//得到打印结果为 2 2 2 2 2 2 2 2 2 2

	printf("\n");

	int j = 0;
	while (j < 10)
	{
		test_2();
		j++;
	}//得到打印结果为 2 3 4 5 6 7 8 9 10 11

	return 0;
}

//#include <iostream>
//using namespace std;
//
//template <typename Type>
//class SmartPtr
//{
//public:
//	SmartPtr(Type* ptr = nullptr)
//		: _ptr(ptr), _pcount(new int(1))
//	{}
//
//	void _release()
//	{
//		if (--(*_pcount) == 0)
//		{
//			delete _ptr;
//			delete _pcount;
//		}
//	}
//	~SmartPtr()
//	{
//		_release();
//	}
//
//	SmartPtr(const SmartPtr<Type>& sp)
//		: _ptr(sp._ptr), _pcount(sp._pcount)
//	{
//		++(*_pcount);
//	}
//
//	SmartPtr<Type>& operator=(const SmartPtr<Type>& sp)//这个代码需要注意一下
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
//	Type& operator*()
//	{
//		return *_ptr;
//	}
//
//	Type* operator->()
//	{
//		return _ptr;
//	}
//
//	int use_count() const
//	{
//		return *_pcount;
//	}
//
//	Type* get() const
//	{
//		return _ptr;
//	}
//
//private:
//	Type* _ptr;
//	int* _pcount;
//};
//
//template <typename Type>
//class WeakPtr
//{
//public:
//	WeakPtr()
//		: _ptr(nullptr)
//	{}
//
//	WeakPtr(SmartPtr<Type>& sp)
//		: _ptr(sp.get())
//	{}
//
//	WeakPtr<Type>& operator=(const SmartPtr<Type>& sp)
//	{
//		_ptr = sp.get();
//		return *this;
//	}
//
//	Type& operator*()
//	{
//		return *_ptr;
//	}
//
//	Type* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	Type* _ptr;
//};
//
//struct ListNode
//{
//	int val;
//	WeakPtr<ListNode> next;
//	WeakPtr<ListNode> prev;
//	~ListNode()
//	{
//		cout << "~ListNode()" << '\n';
//	}
//};
//
//int main()
//{
//	SmartPtr<ListNode> n1(new ListNode);
//	SmartPtr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << " " << n2.use_count() << '\n';
//
//	n1->next = n2;
//	n2->prev = n1;
//
//	cout << n1.use_count() << " " << n2.use_count() << '\n';
//
//	return 0;
//}