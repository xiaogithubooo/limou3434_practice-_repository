#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Set
	{
		//内部类（泛函数）
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;//可以取出 key，这是为了和 map 同步
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

	//测试函数
	void test_set1()
	{
		Set<int, int> m;
		m.Insert(3);
		m.Insert(1);
		m.Insert(2);
	}
}