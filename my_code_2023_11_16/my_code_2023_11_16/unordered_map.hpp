#pragma once
#include "hash_table.hpp"

namespace Limou
{
	template<typename K, typename V, typename Hash = HashFunc<K>>
	class UnorderedMap
	{
	public:
		//�º����ṹ�壺������������ȡ�� key
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		//������
		typedef typename HashBucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		//��Ա����
	public:
		std::pair<iterator, bool> Insert(const std::pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}
		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}
		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = Insert(std::make_pair(key, V()));
			return ret.first->second;
		}

		//��Ա����
	private:
		HashBucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash> _ht;
	};
}