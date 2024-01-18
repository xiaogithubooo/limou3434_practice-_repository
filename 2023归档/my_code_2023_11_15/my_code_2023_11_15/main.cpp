#include "hash.hpp"
#include <string>
using namespace std;
using namespace limou;
int main()
{
	HashTable<string, string> ht;

	ht.Insert(make_pair("aaa", "a"));
	ht.Insert(make_pair("bbb", "b"));
	ht.Insert(make_pair("ccc", "c"));
	ht.Insert(make_pair("", "c"));
	
	return 0;
}