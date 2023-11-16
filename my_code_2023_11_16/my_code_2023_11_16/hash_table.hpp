#pragma once
#include <iostream>
#include <utility>
#include <vector>

//�º�
//��������Ҫ�� unordered_set �� unordered_map �� key����Ҫ֧�֣���ת��Ϊ��ȡģ���ͷº������͡�== �Ƚϡ�
//��������Ҫ�� map �� set �� key����Ҫ֧�֣����º��� < �ıȽϡ�
template<typename K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<>//�º����ػ�
struct HashFunc<std::string>
{
	size_t operator()(const std::string& str)
	{
		//return str[0];//����ʵ�ֲ�̫�ã���ͻ���ʸ�
		size_t add = 0;;
		for (auto ch : str)
		{
			add += ch;
			ch *= 31;//BKDR �㷨������ѧ����
		}
		return add;
	}
};

namespace HashBucket
{
	//1.��ϣ����
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

	//2.������
	//ǰ����������Ϊ��������˻������õ����⣩
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
			return _node != s._node;//�Ƚ�ָ�뼴��
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
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();//�õ���ǰͰ��λ��
				hashi++;//���ڵ�ǰλ��һ��Ϊ�գ����ֱ��������ǰλ�õ��ж�
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

				//�����ߵ�����ֻ�����������һ�����������������ˣ����� break ������
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

	//3.��ϣ��
	template <typename K, typename T, typename KeyOfT, typename Hash>
	//��һ����� key �����ͣ��ڶ����� key �� data<key, value> �����ͣ����������ṩ���º�����
	class HashTable
	{
		//��Ԫ��
		template <typename K, typename T, typename KeyOfT, typename Hash>
		friend struct __HashIterator;

		//�����ض���
	private:
		typedef HashNode<T> Node;//T �Ѿ��Ƿ��ͣ��п����� key��Ҳ�п����� key-value
	
		//������
	public:
		typedef __HashIterator<K, T, KeyOfT, Hash> iterator;
		iterator begin()
		{
			Node* cur = nullptr;//һ��ʼ�Ľڵ�λ�ñ���Ҫ���¼����������Ϊ����֤��һ��Ͱ�ĵ�һ��Ԫ�ؾ��ǿ�ʼ���
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

		//��Ա����
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
			//��ֹ����
			KeyOfT kot;
			iterator it = Find(kot(data));
			if (it != end())
			{
				return std::make_pair(it, false);
			}

			//���ݻ���
			//�������ݻ��ù�ϣ������ӳ��������ͳ�ͻ���ʣ�
			//��������趨��������Ϊ 1 ʱ�������ݣ�
			//�����Ͳ�������Ͱ̫�������²���Ч�ʽ���
			Hash hash;//�º���
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;//�����¿ռ��С�������¹�ϣ��
				std::vector<Node*> newTables;
				newTables.resize(newSize);

				for (auto& cur : _tables)//�����ɹ�ϣ��
				{
					while (cur)//�����ɹ�ϣ���ڵ�Ͱ
					{
						Node* next = cur->_next;//���� next ����

						size_t hashi = hash(kot(cur->_data)) % newTables.size();//���ɾ�Ͱ���������¹�ϣ���ڵĹ�ϣ��ַ

						cur->_next = newTables[hashi];//ͷ�嵽�¹�ϣ����
						newTables[hashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newTables);//�����¾ɹ�ϣ��
			}

			//ӳ����Ͱ
			size_t hashi = hash(kot(data)) % _tables.size();//���ݹؼ��ֵõ���ϣ��ַ

			Node* newNode = new Node(data);//���������㣬�洢����

			newNode->_next = _tables[hashi];//�����ͷ�嵽Ͱ��ͷ��
			_tables[hashi] = newNode;

			++_n;//���¸�������

			return std::make_pair(iterator(newNode, this), true);
		}
		iterator Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return end();
			}

			KeyOfT kot;//�º����������ҵ� key
			Hash hash;//�º������ҵ��ʺϵ�ӳ�䷽ʽ������ int
			
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
					else//prev == nullptr��ɾ��ͷ�ڵ�������
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

		//��Ա����
	private:
		std::vector<Node*> _tables;		//��Ͱͷָ��洢������ void resize (size_type n, value_type val = value_type()); ���Ժ���ʹ�� resize()��е���ʼ����ֵ�Ĺ�����������Ϊ�գ�
		size_t _n = 0;					//�洢��Ч���ݸ���
	};
}