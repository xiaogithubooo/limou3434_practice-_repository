#include "unordered_set.hpp"
#include "unordered_map.hpp"
#include "bit_set.hpp"
#include <vector>
#include <string>

int main()
{
	int arr[] = { 3,45,53,32,32,43,3,2,5,2,32,55,5,53,7 };
	Limou::TwoBitSet<100> tbs;
	for (auto e : arr)
	{
		tbs.Set(e);
	}

	tbs.Print();

	return 0;
}