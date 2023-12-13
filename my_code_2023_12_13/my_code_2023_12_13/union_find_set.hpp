#pragma once
#include <vector>
#include <map>

namespace limou
{
	template <typename Type>
	class UnionFindSet
	{
	public:
		UnionFindSet(const Type* arr, size_t n)
		{
			for (size_t i = 0; i < n; i++)
			{
				_arr.push_back(arr[i]);
				_indexMap[arr[i]] = i;
			}
		}
	private:
		std::vector<Type> _arr;			//±‡∫≈’“»À
		std::map<Type, int> _indexMap;	//»À’“±‡∫≈
	};
}