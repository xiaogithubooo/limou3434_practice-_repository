#include <iostream>
#include <cassert>
using namespace std;
template<class T>//Ҳ����д��typename
class Stack
{
public:
	Stack(size_t capacity = 4)
		:_data(nullptr), _top(0), _capacity(0)
	{
		cout << "Stack(size_t capacity = 4)" << endl;
		if (capacity > 0)
		{
			_data = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		delete[] _data;
		_capacity = _top = 0;
	}
	void Push(const T& x);
	void Pop()
	{
		assert(_top > 0);
		_top--;
	}
	bool Empty()
	{
		return _top == 0;
	}
	T& Top()//������ü������ã����ﻹ��������޸�ջ�����ݵĹ��ܣ������������ǰ�����const�Ͳ����ˣ�����忴����
	{
		 assert(_top > 0);
		 return _data[_top - 1];
	}
private:
	T* _data;
	size_t _top;
	size_t _capacity;
};
template<class T>//����������һ��ģ�����
void Stack<T>::Push(const T& x)//��ģ�������붨����루ͬһ���ļ��£�
{
	if (_top == _capacity)
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		T* tmp = new T[newCapacity];
		if (_data)//���ջ��Ϊ��
		{
			memcpy(tmp, _data, sizeof(T) * _top);
			delete[] _data;
		}
		_data = tmp;
		_capacity = newCapacity;
	}
	_data[_top] = x;
	++_top;
}
int main()
{
	//�й�try��catch���new��ʹ���Ժ����ǻ��ἰ
	try//����������ռ�ɹ�������
	{
		Stack<int> a(10);
		a.Push(1);
		a.Push(2);
		a.Push(3);
		a.Push(4);
		a.Push(5);
		a.Push(6);
		a.Top()++;
		while (!a.Empty())
		{
			cout << a.Top() << " ";
			a.Pop();
		}
		cout << endl;
	}
	catch (exception& e)//����������ռ�ʧ�ܵ�����
	{
		cout << e.what() << endl;
	}
	return 0;
}
//typedef int STDataType;
////�����typedef�е㷺�ͱ����˼
////�����������ķ��ͱ��
////û�а취�����������Զ��滻����
////ֻ���Լ��ֶ���������
////���C++�ṩ����ģ����﷨
//class Stack
//{
//private:
//	STDataType* _data;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	return 0;
//}

//template<typename T>
//T Add(T x, T y)
//{
//	return x + y;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int i = 2, j = 3;
//	double x = 5, y = 4;
//	cout << Add(i, j) << endl;
//	cout << Add(x, y) << endl;
//	return 0;
//}