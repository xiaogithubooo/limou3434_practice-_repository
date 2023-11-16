#pragma once
#include "hash_table.hpp"

namespace Limou
{
	template<typename K, typename Hash = HashFunc<K>>
	class UnorderedSet
	{
		//仿函数结构体：辅助其他函数取得 key
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		//迭代器
		typedef typename HashBucket::HashTable<K, K, SetKeyOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		//成员函数
	public:
		std::pair<iterator, bool> Insert(const K& key)
		{
			return _ht.Insert(key);
		}
		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}
		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}

		//成员变量
	private:
		HashBucket::HashTable<K, K, SetKeyOfT, Hash> _ht;
	};
}