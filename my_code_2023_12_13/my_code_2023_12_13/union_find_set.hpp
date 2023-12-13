#pragma once
#include <vector>

namespace limou
{
	template <typename Type = int>
	class UnionFindSet
	{
		/*
		* 这里的并查集只使用了索引来作为集合内的元素的编号
		* 对应存储的是“根节点包含元素的个数”和“双亲结点索引”的信息
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
				_ufs[root1] += _ufs[root2];//谁合并谁都可以，没有特别强制的规定
				_ufs[root2] = root1;
				return true;
			}

			return false;
		}

		int FindRoot(int x)
		{
			/* 根据编号找编号对应元素的根：通过编号存储的父结点，不断跳转到根即可 */
			int parent = x;
			while (_ufs[x] >= 0)
			{
				parent = _ufs[x];
				x = parent;
			}

			return parent;
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
}