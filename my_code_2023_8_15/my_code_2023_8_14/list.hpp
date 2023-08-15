#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
namespace limou
{
	//1.Node节点结构体
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

	//2.迭代器结构体
	template<typename T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T> iterator;
		Node* _node;

		//构造函数
		__list_iterator(Node* x)
			: _node(x)
		{}

		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()//这个"->"符重载是比较奇怪的
		{
			return &_node->_data;
			//假设某个自定义类A(内部又成员_a)使用了list<A> li来存储A类型对象，
			//list<A>::iterator it = li.begin()
			//而我们解引用迭代器是为了得到“节点内部的A类型内部的_a”
			//cout << *(li)._a << endl;	//没问题（这里使用了两次解引用）
			//cout << li->_a << endl;	//出现问题（必须重载"->"，但是只有一次解引用了）
			//cout << li.operator->()->_a << endl;//由于可读性不好，编译器特殊化后，省略了一个"->"
		}
		bool operator!=(const iterator& s)
		{
			return _node != s._node;
		}
		bool operator==(const iterator& s)
		{
			return _node == s._node;
		}
	};

	//3.list容器
	template <typename T>
	class list
	{
		typedef list_node<T> Node;//节点结构体被重命名
	public:
		typedef __list_iterator<T> iterator;//迭代器结构体被重命名
		void empty_init()//空初始化函数，由于后面有很多该操作，故专门写成一个函数
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_head->_data = 0;

			_size = 0;
		}
		//3.1.Member functions
		list()//初始化好头节点
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
		list<T>& operator=(list<T> tmp)//拷贝构造一份
		{
			//1.传统写法
			//if (this != &lt)
			//{
			//	clear();
			//	for (auto e : lt)
			//	{
			//		push_back(e);
			//	}
			//}
			//return *this;
			//2.现代写法
			swap(tmp);
			return *this;
		}
		//3.2.Iterators
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()//实际上是返回哨兵位节点
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
			//在pos前插入
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
		size_t _size;//方便事先size()，避免效率底下
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
		//迭代器的使用体现了封装的优势
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
}