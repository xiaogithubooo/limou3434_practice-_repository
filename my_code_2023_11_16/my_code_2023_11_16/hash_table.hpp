#pragma once
#include <iostream>
#include <utility>
#include <vector>

//仿函
//任意类型要做 unordered_set 和 unordered_map 的 key，需要支持：“转化为可取模整型仿函数”和“== 比较”
//任意类型要做 map 和 set 的 key，需要支持：“仿函数 < 的比较”
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
		//return str[0];//这样实现不太好，冲突概率高
		size_t add = 0;;
		for (auto ch : str)
		{
			add += ch;
			ch *= 31;//BKDR 算法（“玄学”）
		}
		return add;
	}
};

namespace HashBucket
{
	//1.哈希数据
	template <typename T>
	struct HashNode
	{
		HashNode(const T& data)
			: _next(nullptr),
			_data(data)
		{}

		HashNode<T>* _next;
		T _data;
	};

	//2.迭代器
	//前置声明（因为这里出现了互相引用的问题）
	template <typename K, typename T, typename KeyOfT, typename Hash>
	class HashTable;

	template <typename K, typename T, typename KeyOfT, typename Hash>
	struct __HashIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef __HashIterator<K, T, KeyOfT, Hash> Self;

		__HashIterator(Node* node, HT* ht) : _node(node), _ht(ht) {}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;//比较指针即可
		}

		Self& operator++()
		{
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				Hash hash;
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();//得到当前桶的位置
				hashi++;//由于当前位置一定为空，因此直接跳过当前位置的判断
				while (hashi < _ht->_tables.size())
				{
					if (_ht->_tables[hashi])
					{
						_node = _ht->_tables[hashi];
						break;
					}
					else
					{
						hashi++;
					}
				}

				//代码走到这里只有两种情况：一是整个表都被遍历完了，二是 break 出来的
				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;

		}

		Node* _node;
		HT* _ht;
	};

	//3.哈希表
	template <typename K, typename T, typename KeyOfT, typename Hash>
	//第一个标记 key 的类型，第二个是 key 或 data<key, value> 的类型，第三个是提供给仿函数的
	class HashTable
	{
		//友元类
		template <typename K, typename T, typename KeyOfT, typename Hash>
		friend struct __HashIterator;

		//类型重定义
	private:
		typedef HashNode<T> Node;//T 已经是泛型，有可能是 key，也有可能是 key-value
	
		//迭代器
	public:
		typedef __HashIterator<K, T, KeyOfT, Hash> iterator;
		iterator begin()
		{
			Node* cur = nullptr;//一开始的节点位置必须要重新计算出来，因为不保证第一个桶的第一个元素就是开始结点
			for (size_t i = 0; i < _tables.size(); i++)
			{
				cur = _tables[i];
				if (cur != nullptr)
				{
					break;
				}
			}
			return iterator(cur, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		//成员函数
	public:
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
		std::pair<iterator, bool> Insert(const T& data)
		{
			//防止冗余
			KeyOfT kot;
			iterator it = Find(kot(data));
			if (it != end())
			{
				return std::make_pair(it, false);
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

						size_t hashi = hash(kot(cur->_data)) % newTables.size();//生成旧桶内数据在新哈希表内的哈希地址

						cur->_next = newTables[hashi];//头插到新哈希表内
						newTables[hashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newTables);//交换新旧哈希表
			}

			//映射链桶
			size_t hashi = hash(kot(data)) % _tables.size();//根据关键字得到哈希地址

			Node* newNode = new Node(data);//生成链表结点，存储数据

			newNode->_next = _tables[hashi];//将结点头插到桶的头部
			_tables[hashi] = newNode;

			++_n;//更新负载因子

			return std::make_pair(iterator(newNode, this), true);
		}
		iterator Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return end();
			}

			KeyOfT kot;//仿函数，辅助找到 key
			Hash hash;//仿函数，找到适合的映射方式，返回 int
			
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}
				cur = cur->_next;
			}

			return end();
		}
		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
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

		//成员变量
	private:
		std::vector<Node*> _tables;		//链桶头指针存储表（由于 void resize (size_type n, value_type val = value_type()); 所以后续使用 resize()会承担初始化赋值的工作，即：置为空）
		size_t _n = 0;					//存储有效数据个数
	};
}