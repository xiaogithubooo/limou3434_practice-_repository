#include <iostream>
using namespace std;

namespace limou3434_vector
{
	/*
	������д��һ���ṹ��ģ�壬�ýṹ��Ϊ�Զ���ĵ��������ͣ�����ʹ����ͨ��������Ҳ����ʹ��const������
	*/

	template<class Iterator, class Ref, class Ptr>
	//Ref�����ã�Ptr��ָ�룬�ֱ�֧�� * �� -> �ķ���ֵ
	//���Ա�һ���滻��iterator�������ķ���ֵ��conts_iterator�������ķ���ֵ

	//1.����������Ľṹ�壨û������������ṹ���ԭ���ǣ�vector���������������ײ�Ϊָ�룬û�б�Ҫ�ٶ�дһ���ṹ�壩
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;

		//0.��ͬ���͵ĵ�������������list�ĵ�������Ҳ������vector�ĵ�����
		Iterator _it;

		//1.���캯��������������������Ӧ���͵������������Ҳ����˵����������ı����������������
		Reverse_iterator(const Iterator& it)
			: _it(it)
		{}

		//2.Ref����
		Ref operator*()//���ص���T&����const T&��T��list����vector�����ڵ�Ԫ��T
		{
			Iterator temp = _it;
			return *(--temp);
		}

		//3.Ptrָ��
		Ptr operator->()//���ص���T*��const T*��T��list����vector�����ڵ�Ԫ��T
		{
			return &(operator*());
		}

		//4.++����
		Self& operator++()
		{
			--_it;
			return *this;
		}

		//4.--����
		Self& operator--()
		{
			++_it;
			return *this;
		}

		//4.!=����
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
	};

	//2.vector�ڲ�ʵ��
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//�������������֧��
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
			return reverse_iterator(end());//�����˹��캯��
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());//�����˹��캯��
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());//�����˹��캯��
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());//�����˹��캯��
		}
		//......
	};
}

namespace limou3434_list
{
	//1.�ڵ�ṹ��
	template <typename T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		//���캯��
		list_node(const T& x = T())//ע�ⲻ�ܸ�0����Ϊ��һ����int�����������������ģ��֮��������ˣ�Ҳ�й��캯����
			: _data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//2.����������ṹ��
	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		//���캯��
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

	//3.����������ṹ��
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ref, Ptr> self;

		Iterator _it;
		//1.���캯��
		Reverse_iterator(Iterator it)
			:_it(it)
		{}

		//2.*����
		Ref operator*()
		{
			Iterator temp = _it;
			return *(--temp);
		}

		//3.->����
		Ptr operator->()
		{
			return &(operator*());
		}

		//4.++����
		self& operator++()
		{
			--_it;
			return *this;
		}

		//4.--����
		self& operator--()
		{
			++_it;
			return *this;
		}

		//5.!=����
		bool operator!=(const self& it)
		{
			return _it != it._it;
		}
	};

	//4.list�ڲ�ʵ��
	template<class T>
	class list
	{
		typedef list_node<T> Node;//һ���ڵ�
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//�������������֧��
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
//	Data& operator++(int)//���üӼ�
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
