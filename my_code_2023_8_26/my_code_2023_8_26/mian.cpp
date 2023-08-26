#include <iostream>
using namespace std;

namespace limou3434_vector
{
	/*
	本质是写了一个结构体模板，该结构体为自定义的迭代器类型，可以使用普通迭代器，也可以使用const迭代器
	*/

	template<class Iterator, class Ref, class Ptr>
	//Ref是引用，Ptr是指针，分别支持 * 和 -> 的返回值
	//可以被一起替换成iterator迭代器的返回值和conts_iterator迭代器的返回值

	//1.反向迭代器的结构体（没有正向迭代器结构体的原因是，vector的正向迭代器本身底层为指针，没有必要再多写一个结构体）
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		//0.不同类型的迭代器，可以是list的迭代器，也可以是vector的迭代器
		Iterator _it;

		//1.构造函数（给反向迭代器赋予对应类型的正向迭代器，也就是说反向迭代器的本质是正向迭代器）
		Reverse_iterator(const Iterator& it)
			: _it(it)
		{}

		//2.Ref引用
		Ref operator*()//返回的是T&或者const T&，T是list或者vector容器内的元素T
		{
			Iterator temp = _it;
			return *(--temp);
		}

		//3.Ptr指针
		Ptr operator->()//返回的是T*和const T*，T是list或者vector容器内的元素T
		{
			return &(operator*());
		}

		//4.++重载
		Self& operator++()
		{
			--_it;
			return *this;
		}

		//4.--重载
		Self& operator--()
		{
			++_it;
			return *this;
		}

		//4.!=重载
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
	};

	//2.vector内部实现
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());//调用了构造函数
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());//调用了构造函数
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());//调用了构造函数
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());//调用了构造函数
		}
		//......
	};
}

namespace limou3434_list
{
	//1.节点结构体
	template <typename T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		//构造函数
		list_node(const T& x = T())//注意不能给0，因为不一定是int，这个内置类型有了模板之后就升级了，也有构造函数了
			: _data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//2.正向迭代器结构体
	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		//构造函数
		__list_iterator(Node* x)
			: _node(x)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	//3.反向迭代器结构体
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> self;

		Iterator _it;
		//1.构造函数
		Reverse_iterator(Iterator it)
			:_it(it)
		{}

		//2.*重载
		Ref operator*()
		{
			Iterator temp = _it;
			return *(--temp);
		}

		//3.->重载
		Ptr operator->()
		{
			return &(operator*());
		}

		//4.++重载
		self& operator++()
		{
			--_it;
			return *this;
		}

		//4.--重载
		self& operator--()
		{
			++_it;
			return *this;
		}

		//5.!=重载
		bool operator!=(const self& it)
		{
			return _it != it._it;
		}
	};

	//4.list内部实现
	template<class T>
	class list
	{
		typedef list_node<T> Node;//一个节点
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		//......
	};
}

//4 5 6 3 2 1
//4 5 3 2 1 6//1
//4 3 2 1 5 6//2
//3 2 1 4 5 6//3

//class Data
//{
//public:
//	Data(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	int getYearDays(int year, int month)
//	{
//		if (month == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			{
//				return 29;
//			}
//		}
//		return yearDays[month];
//	}
//	Data& operator++(int)//后置加加
//	{
//		int days = getYearDays(_year, _month);
//		_day += 1;
//
//		if (_day > days)
//		{
//			_day -= days;
//			_month += 1;
//			if (_month > 12)
//			{
//				_month = 1;
//				_year++;
//			}
//		}
//		return *this;
//	}
//	bool operator!=(const Data& x)
//	{
//		if (_year == x._year
//			&& _month == x._month
//			&& _day == x._day)
//		{
//			return false;
//		}
//		return true;
//	}
//	void Print(void)
//	{
//		cout << _year;
//		cout << "-";
//		printf("%02d", _month);
//		cout << "-";
//		printf("%02d", _day);
//		cout << endl;
//	}
//private:
//	static int yearDays[13];
//	int _year;
//	int _month;
//	int _day;
//};
//int Data::yearDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	int year = 0;
//	int month = 0;
//	int day = 0;
//
//	int count = 0;
//	while (n)
//	{
//		cin >> year >> month >> day;
//		cin >> count;
//
//		Data d(year, month, day);
//
//		while (count != 0)
//		{
//			d++;
//			count--;
//		}
//		d.Print();
//		n--;
//	}
//	return 0;
//}
