#pragma once
#include <iostream>
#include <utility>
#include <vector>

namespace limou
{
	//1.哈希数据
	template <typename K, typename V>
	struct HashNode
	{
		HashNode(const std::pair<K, V>& kv)
			: _next(nullptr),
			_kv(kv)
		{}

		HashNode<K, V>* _next;
		std::pair<K, V> _kv;
	};

	//2.仿函数
	template<typename K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	template<>//仿函数特化
	struct HashFunc<std::string>
	{
		size_t operator()(const std::string& str)
		{
			//return str[0];//这样实现不太好
			size_t add = 0;;
			for (auto ch : str)
			{
				add += ch;
				ch *= 31;//BKDR 算法（“玄学”）
			}
			return add;
		}
	};

	//3.哈希表
	template <typename K, typename V, typename Hash = HashFunc<K>>//最后一个类型是提供给仿函数的
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public://成员函数
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
			}
		}
		bool Insert(const std::pair<K, V>& kv)
		{
			//防止冗余
			if (Find(kv.first))
			{
				return false;
			}

			//扩容机制
			//由于扩容会让哈希表重新映射进而减低冲突概率，
			//因此我们设定负载因子为 1 时发生扩容，
			//这样就不会让链桶太长，导致查找效率降低
			Hash hash;//仿函数
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;//决定新空间大小，生成新哈希表
				std::vector<Node*> newTables;
				newTables.resize(newSize);

				for (auto& cur : _tables)//遍历旧哈希表
				{
					while (cur)//遍历旧哈希表内的桶
					{
						Node* next = cur->_next;//保存 next 链表

						size_t hashi = hash(cur->_kv.first) % newTables.size();//生成旧桶内数据在新哈希表内的哈希地址

						cur->_next = newTables[hashi];//头插到新哈希表内
						newTables[hashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newTables);//交换新旧哈希表
			}

			//映射链桶
			size_t hashi = hash(kv.first) % _tables.size();//根据关键字得到哈希地址

			Node* newNode = new Node(kv);//生成链表结点，存储数据

			newNode->_next = _tables[hashi];//将结点头插到桶的头部
			_tables[hashi] = newNode;

			++_n;//更新负载因子

			return true;
		}
		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;//仿函数
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}

			return nullptr;
		}
		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev != nullptr)
					{
						prev->_next = cur->_next;
					}
					else//prev == nullptr（删除头节点的情况）
					{
						_tables[hashi] = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

	private://成员变量
		size_t _n = 0;					//存储有效数据个数
		std::vector<Node*> _tables;		//链桶头指针存储表，由于 void resize (size_type n, value_type val = value_type()); 
										//所以后续使用 resize()会承担初始化赋值的工作，即：置为空。
										//另外如果出现极端情况（虽然概率很低），可以改为挂接红黑树，提高查找效率（Java 的某个新版本就是这么干的）
	};
}