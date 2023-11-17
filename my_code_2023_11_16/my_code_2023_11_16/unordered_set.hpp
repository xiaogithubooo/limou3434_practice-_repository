#pragma once
#include "hash_table.hpp"

namespace Limou
{
	template<typename K, typename Hash = HashFunc<K>>
	class UnorderedSet
	{
		//�º����ṹ�壺������������ȡ�� key
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		//������
		typedef typename HashBucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator iterator;
		typedef typename HashBucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator const_iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		const_iterator begin() const
		{
			return _ht.begin();
		}
		const_iterator end() const
		{
			return _ht.end();
		}

		//��Ա����
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

		//��Ա����
	private:
		HashBucket::HashTable<K, K, SetKeyOfT, Hash> _ht;
	};
}