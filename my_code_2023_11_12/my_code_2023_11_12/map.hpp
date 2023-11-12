#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Map
	{
		//�ڲ��ࣨ��������
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V>& kv)
			{
				return kv.first;//����ȡ�� key �Ĳ���
			}
		};
	public:
		bool Insert(const std::pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, std::pair<const K, V>, MapKeyOfT> _t;
	};

	//���Ժ���
	void test_map1()
	{
		Map<int, int> m;
		m.Insert(std::make_pair(1, 1));
		m.Insert(std::make_pair(3, 1));
		m.Insert(std::make_pair(2, 1));
	}
}