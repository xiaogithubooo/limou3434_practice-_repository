//circular_queue.hpp
/* ԭ�����
����������ͷָ��ָ���һ��Ԫ�أ�βָ��ָ�����Ԫ�صĺ�һ��λ�ã�
���Ҷ�������һ���ռ����ֿպ��������ұ���������û���������ݻ��ƣ�
�����̲߳���ȫ�͸��Ӷ���ߡ�
a. д���ζ���ʱ�������ȴ� IsFull()��Empty() ��ʼ��д����һ���������Զ��������ͷβָ��Ķ�λ���������ߵ�ʵ�������ں����ĸ���
b. Ȼ��д push_back()��pop_front() �߼�����һ����ע�⵽�������ɾ���߼�������ָ���ʱ����һ�����߼�
c. ���дһ���򵥵�ȡ��ͷԪ�ص� Top() ͬʱдһЩ�������������Լ��Ԫ��
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
		_arr = new T[_capacity + 1]; //��һ���ռ��������֡������͡��ա�����״̬
	}

	~CircularQueue()
	{
		delete[] _arr;
	}

	bool IsFull()
	{
		//ԭ����� ��βָ��+1 == ͷָ�롱 Ϊ����������Ҫ�����ж�ͷָ������βָ�����ҵ����
		return _front == (_rear + 1) % (_capacity + 1);
	}

	bool Empty()
	{
		//ԭ����Ƕ���������һ���ռ䣬�������ֿ�����ֻҪ ��_front == _rear�� ��Ϊ��
		return _front == _rear;
	}

	void push_back(const T& val)
	{
		if (!IsFull()) //����
		{
			_arr[_rear++] = val; //����ֵ��βָ������ƶ�
			_rear = _rear % (_capacity + 1); //�� _rear ����Խ����������
		}
		else
		{
			std::cout << "full!" << std::endl;
		}
	}

	void pop_front()
	{
		if (!Empty())//�ǿ�
		{
			_front++; //ֱ���ƶ�ͷָ�룬���û��޷�����Ҳ��һ��ɾ��
			_front = _front % (_capacity + 1); //�� _front ����Խ����������
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
		//���ԭ���������ǰ���ἰ�ķ�������⣬ԭ���� size == rear-front��������Ҫ����ͷβָ�뽻���������������Э
		return ((_rear + _capacity + 1) - _front) % (_capacity + 1);
	}

	void Print()
	{
		for(int i = 0; i < _capacity + 1; i++)
			std::cout << _arr[i] << ", ";
		std::cout << std::endl;
	}

private:
	T* _arr; //�洢 T Ԫ�ص�����
	int _front; //ͷָ��
	int _rear; //βָ��
	int _capacity; //ѭ���������ܴ洢������
};