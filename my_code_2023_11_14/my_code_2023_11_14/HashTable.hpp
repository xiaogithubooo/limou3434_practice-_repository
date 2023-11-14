#pragma once
#include <iostream>
#include <utility>
#include <vector>

namespace limou
{
	//1.״̬
	enum State
	{
		EMPTY,	//�յ�
		EXIST,	//����
		DELETE	//ɾ��
	};

	//2.��ϣ����
	template <typename K, typename V>
	struct HashData
	{
		std::pair<K, V> _kv;
		State _state = EMPTY;
	};

	//3.��ϣ��
	template <typename K, typename V>
	class HashTable
	{
	public://��Ա����
		bool Insert(const std::pair<K, V>& kv)
		{
			//�ų��ظ�����
			if (Find(kv.first))	
				return false;

			//��鸺������
			if (_table.size() == 0 || _n * 10 / _table.size() >= 7)//�������û�����������ߡ��ﵽ 70% ��������
			{
				//������һ���µĹ�ϣ���������ӳ�䷶ΧΪԭ��ϣ�������
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				HashTable<K, V> newht;
				newht._table.resize(newSize);

				//��ԭ vector ����ӳ�䵽�� vector �ϣ���ֹ����ӳ�����
				for (auto& data : _table)
				{
					if (data._state == EXIST)//��ԭ��ϣ���������ӳ�䵽�¹�ϣ����
					{
						newht.Insert(data._kv);
					}
				}

				_table.swap(newht._table);
			}

			//������ϣ��ַ
			size_t hashi = kv.first % _table.size();//������ʹ�� capacity()������ʹ�� [] ��Խ��
			
			//�����ϣ��ͻ
			size_t i = 1;
			size_t index = hashi;
			while (_table[index]._state == EXIST)//�����ϣ��ַ���Ѿ��ж�Ӧֵ�������̽��
			{
				index = hashi + i;		//���̽��
				index %= _table.size();	//��ֹԽ�磬���Ҵ��ѭ��̽��
				i++;
			}
			
			_table[index]._kv = kv;
			_table[index]._state = EXIST;
			_n++;

			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			//����������
			if (_table.size() == 0)
			{
				return nullptr;//������������ϣ��ַʱ�����ֳ������
			}

			//�ı�����״̬
			size_t hashi = key % _table.size();
			size_t i = 1;
			size_t index = hashi;
			while (_table[index]._state != EMPTY)//ֻҪ���ǿվͳ�������ȥ
			{
				if (_table[index]._state == EXIST 
					&& _table[index]._kv.first == key)//ֻҪ�Ƕ�Ӧֵ������״̬���ڡ����ڡ�״̬����Ϊ������ɾ���ǡ���ɾ������ԭ���ݻ��ڣ�ֻ������״̬��Ϊɾ��״̬�����ͷ��ض�Ӧָ��
				{
					return &_table[index];
				}

				index = hashi + i;		//���̽��
				index %= _table.size();	//��ֹԽ�磬���Ҵ��ѭ��̽��
				i++;

				if (index == hashi)//˵���Ѿ�������һȦ������û���ҵ���Ӧֵ
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			//ע������һ�ּ�ɾ��������ֻ�Ǹı�״̬�����ǰ��Ĵ���Ҫ�ۺϿ���
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_n--;
				return true;
			}

			return false;
		}

	private://��Ա����
		std::vector<HashData<K, V>> _table;	//ֱ��ʹ�� vector ���ӷ��㣬֮ǰ�����Ѿ�ģ��ʵ��˳����ˣ��Ͳ�Ҫ����ʵ����
		size_t _n = 0;							//�洢�����ݸ���
	};

	void Test_1()
	{
		int arr[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : arr)
		{
			ht.Insert(std::make_pair(e, 1));
		}

		ht.Insert(std::make_pair(15, 1));//������
	}
}