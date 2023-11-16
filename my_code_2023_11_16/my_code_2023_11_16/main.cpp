#include "unordered_set.hpp"
#include "unordered_map.hpp"
#include <vector>
#include <string>

int main()
{
	Limou::UnorderedSet<int> us;
	int arr[] = { 3,33,2,13,5,12,1002 };
	for (auto e : arr)
	{
		us.Insert(e);
	}
	for (auto e : us)
	{
		std::cout << e << '\n';
	}

	Limou::UnorderedMap<std::string, int> um;
	std::vector<std::string> vec = { "A","B","D","C","B","A","A","C","D","C"};
	for (auto e : vec)
	{
		um[e]++;
	}
	um.Erase("A");
	for (auto e : um)
	{
		std::cout << e.first << "-" << e.second << '\n';
	}

	return 0;
}