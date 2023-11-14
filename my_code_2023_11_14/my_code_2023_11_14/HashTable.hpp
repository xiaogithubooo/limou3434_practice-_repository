#pragma once
#include <iostream>
#include <utility>
#include <vector>

namespace limou
{
	//1.状态
	enum State
	{
		EMPTY,	//空的
		EXIST,	//存在
		DELETE	//删除
	};

	//2.哈希数据
	template <typename K, typename V>
	struct HashData
	{
		std::pair<K, V> _kv;
		State _state = EMPTY;
	};

	//3.哈希表
	template <typename K, typename V>
	class HashTable
	{
	public://成员函数
		bool Insert(const std::pair<K, V>& kv)
		{
			//排除重复数据
			if (Find(kv.first))	
				return false;

			//检查负载因子
			if (_table.size() == 0 || _n * 10 / _table.size() >= 7)//“本身就没有容量”或者“达到 70% ”就扩容
			{
				//创建出一个新的哈希表，并且其可映射范围为原哈希表的两倍
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				HashTable<K, V> newht;
				newht._table.resize(newSize);

				//将原 vector 重新映射到新 vector 上，防止数据映射错乱
				for (auto& data : _table)
				{
					if (data._state == EXIST)//将原哈希表放入数据映射到新哈希表上
					{
						newht.Insert(data._kv);
					}
				}

				_table.swap(newht._table);
			}

			//给出哈希地址
			size_t hashi = kv.first % _table.size();//不可以使用 capacity()，否则使用 [] 会越界
			
			//解决哈希冲突
			size_t i = 1;
			size_t index = hashi;
			while (_table[index]._state == EXIST)//如果哈希地址上已经有对应值，则向后探测
			{
				index = hashi + i;		//向后探测
				index %= _table.size();	//防止越界，并且达成循环探测
				i++;
			}
			
			_table[index]._kv = kv;
			_table[index]._state = EXIST;
			_n++;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			//避免除零错误
			if (_table.size() == 0)
			{
				return nullptr;//避免后续计算哈希地址时，出现除零错误
			}

			//改变数据状态
			size_t hashi = key % _table.size();
			size_t i = 1;
			size_t index = hashi;
			while (_table[index]._state != EMPTY)//只要不是空就持续走下去
			{
				if (_table[index]._state == EXIST 
					&& _table[index]._kv.first == key)//只要是对应值，并且状态处于“存在”状态（因为后续的删除是“假删除”，原数据还在，只不过是状态改为删除状态），就返回对应指针
				{
					return &_table[index];
				}

				index = hashi + i;		//向后探测
				index %= _table.size();	//防止越界，并且达成循环探测
				i++;

				if (index == hashi)//说明已经查找了一圈，依旧没有找到对应值
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			//注意这是一种假删除，仅仅只是改变状态，因此前面的代码要综合考量
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_n--;
				return true;
			}

			return false;
		}

	private://成员变量
		std::vector<HashData<K, V>> _table;	//直接使用 vector 更加方便，之前我们已经模拟实现顺序表了，就不要反复实现了
		size_t _n = 0;							//存储的数据个数
	};

	void Test_1()
	{
		int arr[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : arr)
		{
			ht.Insert(std::make_pair(e, 1));
		}

		ht.Insert(std::make_pair(15, 1));//扩容了
	}
}