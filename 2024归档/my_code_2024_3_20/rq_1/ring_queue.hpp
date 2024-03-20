//ring_queue.hpp
#pragma once
#include <vector>
#include "sem.hpp"

const int gDefaultNum = 5;

template <typename T>
class RingQueue
{
public:
	RingQueue(const int& num = gDefaultNum)
		: _ringQueue(num), _num(num)
		, p_step(0), c_step(0)
		, _space_sem(num), _data_sem(0)
	{}

	~RingQueue()
	{}

	void Push(const T& in)
	{
		/*生产者生产数据*/
		//申请空间资源
		_space_sem.P();

		//生产数据放入队列
		_ringQueue[p_step++] = in;
		p_step %= _num;

		//释放数据资源
		_data_sem.V();
	}

	void Pop(T* out)
	{
		/*消费者消费数据*/
		//申请数据资源
		_data_sem.P();

		//消费数据取出队列
		*out = _ringQueue[c_step++];
		c_step %= _num;

		//释放空间资源
		_space_sem.V();
	}

	void Debug()
	{
		std::cerr << "[debug]"
		<< "size:" << _ringQueue.size()
		<< " num:" << _num
		<< '\n';
	}

private:
	std::vector<T> _ringQueue; //循环队列
	int _num; //循环队列的大小
	int p_step; //生产者下标
	int c_step; //消费者下标
	Sem _space_sem; //空间资源
	Sem _data_sem; //数据资源
};
