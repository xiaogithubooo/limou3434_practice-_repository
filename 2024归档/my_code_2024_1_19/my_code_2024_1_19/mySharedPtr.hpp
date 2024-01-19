#include <iostream>
#include <atomic>
using namespace std;

template <typename Type>
class SmartPtr
{
public:
	SmartPtr(Type* ptr)
		: _ptr(ptr), _pcount(new atomic<int>(1))
	{}

	void _release()
	{
		if (--(*_pcount) == 0)
		{
			delete _ptr;
			delete _pcount;
		}
	}
	~SmartPtr()
	{
		_release();
	}

	SmartPtr(const SmartPtr<Type>& sp)
		: _ptr(sp._ptr), _pcount(sp._pcount)
	{
		++(*_pcount);
	}

	SmartPtr<Type>& operator=(const SmartPtr<Type>& sp)//这个代码需要注意一下
	{
		_release();
		_ptr = sp._ptr;
		_pcount = sp._pcount;
		++(*_pcount);
		return *this;
	}

	Type& operator*()
	{
		return *_ptr;
	}

	Type* operator->()
	{
		return _ptr;
	}

	int use_count()
	{
		return *_pcount;
	}
private:
	Type* _ptr;
	atomic<int>* _pcount; //改为原子计数
};