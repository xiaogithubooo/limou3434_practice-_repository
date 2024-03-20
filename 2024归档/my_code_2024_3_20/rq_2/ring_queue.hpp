//ring_queue.hpp
#pragma once
#include <vector>
#include <pthread.h>
#include "sem.hpp"
#include "lock_guard.hpp"

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
		//申请空间资源（一般先申请信号量，先分配好空间资源，相当于“先买票再来排队进入电影院”，各个生产者都对空间信号量进行了申请，空间信号量迅速减少，相当于预定了资源）
		_space_sem.P();

		//对所有生产者加锁，保证只有一个生产者做生产操作，也就是多个生产者全体只有一次 Push()，避免数据不一致（如果先加锁在申请空间信号量，就只有一个进程会进行 P() 操作，无法尽快分配资源）
		LockGuard psLock(&_plock);

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

		//对所有消费者加锁，和上面类似
		LockGuard csLock(&_clock);

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
	pthread_mutex_t _plock; //生产者之间的锁
	pthread_mutex_t _clock; //消费者之间的锁
};
