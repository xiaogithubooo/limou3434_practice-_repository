#pragma once
#include <vector>

namespace limou
{
	template <typename Type = int>
	class UnionFindSet
	{
		/*
		* ����Ĳ��鼯ֻʹ������������Ϊ�����ڵ�Ԫ�صı��
		* ��Ӧ�洢���ǡ����ڵ����Ԫ�صĸ������͡�˫�׽������������Ϣ
		*/

	public:
		UnionFindSet(int n)
			: _ufs(n, -1)
		{}

		bool Union(int x1, int x2)
		{
			/* ���ݱ�źϲ��������ϣ��ϲ�֮ǰҪ���Ҹ�����˿��Ը��� voidFindRoot() */
			int root1 = FindRoot(x1);
			int root2 = FindRoot(x2);

			if (root1 != root2)
			{
				_ufs[root1] += _ufs[root2];//˭�ϲ�˭�����ԣ�û���ر�ǿ�ƵĹ涨
				_ufs[root2] = root1;
				return true;
			}

			return false;
		}

		int FindRoot(int x)
		{
			/* ���ݱ���ұ�Ŷ�ӦԪ�صĸ���ͨ����Ŵ洢�ĸ���㣬������ת�������� */
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
			/* ����Ŷ�ӦԪ���Ƿ���ͬһ������ */
			return FindRoot(x) == FindRoot(y);
		}

		size_t Count()
		{
			/* ���㲢�鼯�ڼ��ϵĸ��� */
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