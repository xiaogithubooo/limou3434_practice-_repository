#pragma once
#include <iostream>
#include <vector>
#include <cmath>
namespace limou
{
	template <typename Type = int>
	class UnionFindSet
	{
		/*
		* 这里的并查集只使用了索引来作为集合内的元素的编号
		* 对应存储的是“根结点包含元素的个数”和“双亲结点索引”的信息
		*/

	public:
		UnionFindSet(int n)
			: _ufs(n, -1)
		{}

		bool Union(int x1, int x2)
		{
			/* 根据编号合并两个集合：合并之前要先找根，因此可以复用 voidFindRoot() */
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);

			if (root1 != root2)
			{
				if (abs(_ufs[root1]) < abs(_ufs[root2]))//谁合并谁都可以，但是最好还是小数据量的集合合并到大数据量的集合，让大数据集合的层数不知增大
					std::swap(root1, root2);

				_ufs[root1] += _ufs[root2];
				_ufs[root2] = root1;
				return true;
			}

			return false;
		}

		int FindRoot(int x)
		{
			/* 根据编号找编号对应元素的根：通过编号存储的父结点，不断跳转到根即可 */
			int root = x;
			while (_ufs[root] >= 0)
			{
				root = _ufs[root];
			}

			//路径压缩，更改父结点从结果上来看没有区别
			while (_ufs[x] >= 0)
			{
				int parent = _ufs[x];
				_ufs[x] = root;

				x = parent;
			}

			return root;
		}

		bool InSet(int x, int y)
		{
			/* 两编号对应元素是否在同一个集合 */
			return FindRoot(x) == FindRoot(y);
		}

		size_t Count()
		{
			/* 计算并查集内集合的个数 */
			size_t count = 0;
			for (auto it : _ufs)
			{
				if (it < 0)
					++count;
			}

			return count;
		}

	private:
		std::vector<Type> _ufs;
	};

	void TestUnionFindSet()
	{
		using std::cout;

		//{0}, {1}, {2}, {3}
		UnionFindSet<> ufs(4);
		cout << ufs.Count() << '\n';
		if (ufs.InSet(1, 2))
			cout << "OK" << '\n';

		//{0, 1, 2}, {3}
		ufs.Union(0, 1);
		ufs.Union(1, 2);
		cout << ufs.Count() << '\n';
		if (ufs.InSet(1, 2))
			cout << "OK" << '\n';

		//{0, 1, 2} root->0
		//{3} root->3
		cout << ufs.FindRoot(2) << '\n';
		cout << ufs.FindRoot(3) << '\n';
	}
}