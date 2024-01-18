#pragma once
#include <iostream>
#include <utility>
#include <vector>

namespace limou
{
	//1.��ϣ����
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

	//2.��ϣ��
	template <typename K, typename V>
	class HashTable
	{
		typedef HashNode<K, V> Node;

	public://��Ա����
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
			//��ֹ����
			if (Find(kv.first))
			{
				return false;
			}

			//���ݻ���
			
			//�������ݻ��ù�ϣ������ӳ��������ͳ�ͻ���ʣ�
			//��������趨��������Ϊ 1 ʱ�������ݣ�
			//�����Ͳ�������Ͱ̫�������²���Ч�ʽ���
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;//�����¿ռ��С�������¹�ϣ��
				std::vector<Node*> newTables;
				newTables.resize(newSize);

				for (auto&cur : _tables)//�����ɹ�ϣ��
				{
					while (cur)//�����ɹ�ϣ���ڵ�Ͱ
					{
						Node* next = cur->_next;//���� next ����

						size_t hashi = cur->_kv.first % newTables.size();//���ɾ�Ͱ���������¹�ϣ���ڵĹ�ϣ��ַ

						cur->_next = newTables[hashi];//ͷ�嵽�¹�ϣ����
						newTables[hashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newTables);//�����¾ɹ�ϣ��
			}

			//ӳ����Ͱ
			size_t hashi = kv.first % _tables.size();//���ݹؼ��ֵõ���ϣ��ַ

			Node* newNode = new Node(kv);//���������㣬�洢����

			newNode->_next = _tables[hashi];//�����ͷ�嵽Ͱ��ͷ��
			_tables[hashi] = newNode;
			
			++_n;//���¸�������

			return true;
		}
		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			size_t hashi = key % _tables.size();
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
			size_t hashi = key % _tables.size();
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

	private://��Ա����
		std::vector<Node*> _tables;		//��Ͱͷָ��洢������ void resize (size_type n, value_type val = value_type()); ���Ժ���ʹ�� resize()��е���ʼ����ֵ�Ĺ�����������Ϊ�գ�
		size_t _n = 0;					//�洢��Ч���ݸ���
	};
}