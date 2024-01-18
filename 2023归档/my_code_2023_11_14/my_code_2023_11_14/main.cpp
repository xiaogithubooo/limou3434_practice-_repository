#include "HashTable.hpp"
int main()
{
	limou::HashTable<int, int> ht;
	int arr[] = { 3,33,2,13,5,12,1002 };
	for (auto e : arr)
	{
		ht.Insert(std::make_pair(e, e));
	}
	ht.Erase(12);
	ht.Erase(3);
	ht.Erase(3);
	return 0;
}