#pragma once
#include "RBTree.hpp"
namespace limou
{
	template<class K, class V>
	class Map
	{
		//内部类（泛函数）
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V>& kv)
			{
				return kv.first;//可以取出 key 的部分
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

	//测试函数
	void test_map1()
	{
		Map<int, int> m;
		m.Insert(std::make_pair(1, 1));
		m.Insert(std::make_pair(3, 1));
		m.Insert(std::make_pair(2, 1));
	}
}