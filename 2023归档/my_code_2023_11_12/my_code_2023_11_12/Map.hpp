#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Map
	{
	private://�ڲ��ࣨ��������
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V>& kv)
			{
				return kv.first;//����ȡ�� key �Ĳ���
			}
		};

	public://������
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;//��ȡ��������Ƕ������Ҫ�õ�typename����Ȼ�޷������Ǿ�̬��Ա�������ͣ�
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

	public://��Ա����
		std::pair<iterator, bool> Insert(const std::pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}
		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = _t.Insert(std::make_pair(key, V()));
			return ret.first->second;
		}

	private://��Ա����
		RBTree<K, std::pair<const K, V>, MapKeyOfT> _t;
	};

	//���Ժ���
	void test_map()
	{
		Map<int, int> m1;
		m1.Insert(std::make_pair(1, 1));
		m1.Insert(std::make_pair(3, 1));
		m1.Insert(std::make_pair(4, 1));
		m1.Insert(std::make_pair(2, 1));
		m1.Insert(std::make_pair(10, 1));
		m1.Insert(std::make_pair(50, 1));
		m1.Insert(std::make_pair(0, 1));

		for (auto e : m1)
		{
			std::cout <<  "<" << e.first << "," << e.second << ">" << " ";
		}
		std::cout << std::endl;

		Map<std::string, int> m2;
		std::vector<std::string> arr = { "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ", "��ɫ" };
		for (auto e : arr)
		{
			m2[e]++;
		}

		for (auto e : m2)
		{
			std::cout << "<" << e.first << "," << e.second << ">" << std::endl;
		}
	}
}