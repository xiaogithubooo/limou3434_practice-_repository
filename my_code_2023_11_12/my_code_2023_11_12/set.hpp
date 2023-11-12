#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Set
	{
		//�ڲ��ࣨ��������
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;//����ȡ�� key������Ϊ�˺� map ͬ��
			}
		};
	public:
		bool Insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	//���Ժ���
	void test_set1()
	{
		Set<int, int> m;
		m.Insert(3);
		m.Insert(1);
		m.Insert(2);
	}
}