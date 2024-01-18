#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout; 
using std::cin;
using std::endl;
namespace limou
{
	//1.Node�ڵ�ṹ��
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

	//2.�������ṹ�壨�϶�Ϊһ��
	
	//2.1.���޸ĵ�����
	//template<typename T>
	//struct __list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef __list_iterator<T> iterator;
	//	Node* _node;
	//
	//	//���캯��
	//	__list_iterator(Node* x)
	//		: _node(x)
	//	{}
	//
	//	iterator& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	iterator operator++(int)
	//	{
	//		iterator tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	iterator& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	iterator operator--(int)
	//	{
	//		iterator tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//	T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	T* operator->()//���"->"�������ǱȽ���ֵ�
	//	{
	//		return &_node->_data;
	//		
	//		//����ĳ���Զ�����A(�ڲ��ֳ�Ա_a)ʹ����list<A> li���洢A���Ͷ���
	//		//list<A>::iterator it = li.begin()
	//		//�����ǽ����õ�������Ϊ�˵õ����ڵ��ڲ���A�����ڲ���_a��
	//		//cout << *(li)._a << endl;	//û���⣨����ʹ�������ν����ã�
	//		//cout << li->_a << endl;	//�������⣨��������"->"��
	//		//cout << li.operator->()->_a << endl;//���ڿɶ��Բ��ã����������⻯��ʡ����һ��"->"
	//	}
	//	bool operator!=(const iterator& s)
	//	{
	//		return _node != s._node;
	//	}
	//	bool operator==(const iterator& s)
	//	{
	//		return _node == s._node;
	//	}
	//};
	////2.2.ֻ�ɶ�������
	//template<typename T>
	//struct __list_const_iterator
	//{
	//	//��Ҫע����ǣ����������������ڵ���������ǰ����const�Ϳ����ˣ��������������û�а취���е����޸ģ��������ж�ȡ
	//	typedef list_node<T> Node;
	//	typedef __list_const_iterator<T> const_iterator;
	//	Node* _node;
	//
	//	//���캯��
	//	__list_const_iterator(Node* x) 
	//		: _node(x)
	//	{}
	//
	//	const_iterator& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	const_iterator operator++(int)
	//	{
	//		const_iterator tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//	const_iterator& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//	const_iterator operator--(int)
	//	{
	//		const_iterator tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	const T* operator->()//���"->"�������ǱȽ���ֵ�
	//	{
	//		return &_node->_data;
	//		//����ĳ���Զ�����A(�ڲ��ֳ�Ա_a)ʹ����list<A> li���洢A���Ͷ���
	//		//list<A>::iterator it = li.begin()
	//		//�����ǽ����õ�������Ϊ�˵õ����ڵ��ڲ���A�����ڲ���_a��
	//		//cout << *(li)._a << endl;	//û���⣨����ʹ�������ν����ã�
	//		//cout << li->_a << endl;	//�������⣨��������"->"������ֻ��һ�ν������ˣ�
	//		//cout << li.operator->()->_a << endl;//���ڿɶ��Բ��ã����������⻯��ʡ����һ��"->"
	//	}
	//	bool operator!=(const const_iterator& s)
	//	{
	//		return _node != s._node;
	//	}
	//	bool operator==(const const_iterator& s)
	//	{
	//		return _node == s._node;
	//	}
	//};
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

	//3.list����
	template <typename T>
	class list
	{
		typedef list_node<T> Node;//�ڵ�ṹ�屻������
	public:
		typedef __list_iterator<T, T&, T*> iterator;//�������ṹ�屻������
		typedef __list_iterator<T, const T&, const T*> const_iterator;//�������ṹ�屻������
		//typedef __list_const_iterator<T> const_iterator;//�������ṹ�屻������
		void empty_init()//�ճ�ʼ�����������ں����кܶ�ò�������ר��д��һ������
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = T();

			_size = 0;
		}
		//3.1.Member functions
		list()//��ʼ����ͷ�ڵ�
		{
			empty_init();
		}
		list(list<T>& li)
		{
			empty_init();
			for (auto e : li)
			{
				push_back(e);
			}
		}
		list<T>& operator=(list<T> tmp)//��������һ��
		{
			//1.��ͳд��
			//if (this != &lt)
			//{
			//	clear();
			//	for (auto e : lt)
			//	{
			//		push_back(e);
			//	}
			//}
			//return *this;
			//2.�ִ�д��
			swap(tmp);
			return *this;
		}
		//3.2.Iterators
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()//ʵ�����Ƿ����ڱ�λ�ڵ�
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const//ʵ�����Ƿ����ڱ�λ�ڵ�
		{
			return _head;
		}
		//3.3.Capacity
		size_t size()
		{
			return _size;
		}
		//3.4.Element access

		//3.5.Modifiers
		iterator inster(iterator pos, const T& x)
		{
			//��posǰ����
			Node* newNode = new Node(x);

			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;

			_size++;
			return iterator(newNode);
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
			_size--;

			return iterator(next);
		}
		void push_back(const T& x)
		{
			inster(end(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& x)
		{
			inster(begin(), x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		//3.6.Operations

		//3.7.Observers

		//3.8.Non-member function overloads
		void swap(list<T>& li)
		{
			std::swap(_head, li._head);
			std::swap(_size, li._size);
		}
	private:
		Node* _head;
		size_t _size;//��������size()������Ч�ʵ���
	};
	void test_1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			(*it) += 50;
			++it;
		}
		cout << endl;

		for (auto in : l1)
		{
			cout << in << " ";
		}
		cout << endl;
		//��������ʹ�������˷�װ������
	}
	void test_2()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_front(1);
		l1.push_front(2);
		l1.push_front(3);
		for (auto in : l1)
		{
			cout << in << " ";
		}
		cout << endl;
		l1.pop_back();
		l1.pop_front();
		for (auto in : l1)
		{
			cout << in << " ";
		}
		cout << endl;
		l1.clear();
		for (auto in : l1)
		{
			cout << in << " ";
		}
	}
	void test_3()
	{
		list<double> l1;
		l1.push_back(1.2);
		l1.push_back(5.0);
		l1.push_back(1.3);
		l1.push_back(0.89);
		l1.push_back(-0.12);
		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << l1.size() << endl;

		list<double> l2(l1);
		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << l2.size() << endl;

		list<double> l3;
		l3 = l2;
		for (auto e : l3)
		{
			cout << e << " ";
		}
		cout << l3.size() << endl;
	}
	void test_4()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		const list<int> l2 = l1;
		list<int>::const_iterator it = l2.begin();
		while (it != l2.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_5()
	{
		class A
		{
		public:
			int _a = 1;
		};
		list<A> li;
		A a1;
		A a2;
		A a3;
		li.push_back(a1);
		li.push_back(a2);
		li.push_back(a3);

		list<A>:: iterator it = li.begin();

		cout << (*it)._a << endl;

		cout << it->_a << endl;//it.operator->()->_a
	}
	
	template<typename T>
	void print_list(const list<T>& li)
	{
		typename list<T>::const_iterator it = li.begin();//����������typename����Ȼ�ú����ڱ����ڼ��޷�ȷ��ʵ��������̬��Ա���������ͣ���
		//��������Ĺؼ���typename���Ǹ��߱���������һ�����ͣ���list<T>ʵ��������ȥ������ȡ
	
		while (it != li.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	template<typename Container>
	void print_container(const Container& con)//�����������
	{
		typename Container::const_iterator it = con.begin();//����������typename����Ȼ�ú����ڱ����ڼ��޷�ȷ��ʵ��������̬��Ա���������ͣ���
		//��������Ĺؼ���typename���Ǹ��߱���������һ�����ͣ���list<T>ʵ��������ȥ������ȡ

		while (it != con.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_6()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		print_list(l1);

		list<std::string> l2;
		l2.push_back("aaaa");
		l2.push_back("abbb");
		l2.push_back("cccc");
		l2.push_back("dddd");
		print_list(l2);

		std::vector<std::string> v;
		v.push_back("1111");
		v.push_back("2222");
		v.push_back("3333");
		v.push_back("4444");
		print_container(v);//���������ǿ�������˷��ͱ��
	}
}