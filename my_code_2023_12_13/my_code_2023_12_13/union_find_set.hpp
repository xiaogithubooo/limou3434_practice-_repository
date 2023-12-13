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
		* ����Ĳ��鼯ֻʹ������������Ϊ�����ڵ�Ԫ�صı��
		* ��Ӧ�洢���ǡ���������Ԫ�صĸ������͡�˫�׽������������Ϣ
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
				if (abs(_ufs[root1]) < abs(_ufs[root2]))//˭�ϲ�˭�����ԣ�������û���С�������ļ��Ϻϲ������������ļ��ϣ��ô����ݼ��ϵĲ�����֪����
					std::swap(root1, root2);

				_ufs[root1] += _ufs[root2];
				_ufs[root2] = root1;
				return true;
			}

			return false;
		}

		int FindRoot(int x)
		{
			/* ���ݱ���ұ�Ŷ�ӦԪ�صĸ���ͨ����Ŵ洢�ĸ���㣬������ת�������� */
			int root = x;
			while (_ufs[root] >= 0)
			{
				root = _ufs[root];
			}

			//·��ѹ�������ĸ����ӽ��������û������
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