//circular_queue.hpp
/* 原理解释
本阻塞队列头指针指向第一个元素，尾指针指向插入元素的后一个位置，
并且队列留出一个空间区分空和满，并且本阻塞队列没有设置扩容机制，
避免线程不安全和复杂度提高。
a. 写环形队列时，可以先从 IsFull()、Empty() 开始书写，这一步基本可以定义好您对头尾指针的定位，并且两者的实现有利于后续的复用
b. 然后写 push_back()、pop_front() 逻辑，您一定会注意到，插入和删除逻辑在修正指针的时候是一样的逻辑
c. 最后写一个简单的取队头元素的 Top() 同时写一些测试样例，调试检查元素
*/
#include <iostream>

const int gDefaultCapacity = 4;

template<typename T>
class CircularQueue
{
public:
	CircularQueue(int capacity = gDefaultCapacity)
		: _arr(nullptr), _front(0), _rear(0), _capacity(capacity)
	{
		_arr = new T[_capacity + 1]; //多一个空间用来区分“满”和“空”两种状态
	}

	~CircularQueue()
	{
		delete[] _arr;
	}

	bool IsFull()
	{
		//原理就是 “尾指针+1 == 头指针” 为满，但是需要特殊判断头指针在左，尾指针在右的情况
		return _front == (_rear + 1) % (_capacity + 1);
	}

	bool Empty()
	{
		//原理就是队列里留有一个空间，和满区分开来，只要 “_front == _rear” 即为空
		return _front == _rear;
	}

	void push_back(const T& val)
	{
		if (!IsFull()) //非满
		{
			_arr[_rear++] = val; //插入值后尾指针向后移动
			_rear = _rear % (_capacity + 1); //在 _rear 向右越界后进行修正
		}
		else
		{
			std::cout << "full!" << std::endl;
		}
	}

	void pop_front()
	{
		if (!Empty())//非空
		{
			_front++; //直接移动头指针，让用户无法访问也是一种删除
			_front = _front % (_capacity + 1); //在 _front 向右越界后进行修正
		}
		else
		{
			std::cout << "empty!" << std::endl;
		}
	}

	T& Top()
	{
		return _arr[_front];
	}

	size_t Size()
	{
		//这个原理可以用以前我提及的方法来理解，原本是 size == rear-front，但是需要避免头尾指针交换的情况做出的妥协
		return ((_rear + _capacity + 1) - _front) % (_capacity + 1);
	}

	void Print()
	{
		for(int i = 0; i < _capacity + 1; i++)
			std::cout << _arr[i] << ", ";
		std::cout << std::endl;
	}

private:
	T* _arr; //存储 T 元素的数组
	int _front; //头指针
	int _rear; //尾指针
	int _capacity; //循环队列所能存储的容量
};