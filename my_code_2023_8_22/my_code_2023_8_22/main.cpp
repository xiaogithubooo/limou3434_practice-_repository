// vector comparisons
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
void removeDuplicates(list<T>& aList)
{
	T curValue;
	list<T>::iterator cur, p;//两个迭代器
	cur = aList.begin();
	while (cur != aList.end())
	{
		curValue = *cur;
		p = cur + 1;
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				p = aList.erase(p);
			}
			else
			{
				p++;
			}
		}
	}
}
int main()
{
	list<int> li;
	removeDuplicates<int>(li);

	return 0;
}

//int main()
//{
//	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(int);//求出数组的大小
//
//	list<int> mylist(ar, ar + n);
//	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);//下标为5
//
//	reverse(mylist.begin(), pos);//{ 4, 3, 2, 1, 0, 5, 6, 7, 8, 9 }
//	reverse(pos, mylist.end());//{ 4, 3, 2, 1, 0, 9, 8, 7, 6, 5 }
//
//	list<int>::const_reverse_iterator crit = mylist.crbegin();//0的下标为9
//	while (crit != mylist.crend())
//	{
//		cout << *crit << " ";
//		++crit;
//	}
//	//{ 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 }
//	cout << endl;
//}

//int main()
//{
//	std::vector<int> foo{ 1, 100, 50 };   // three ints with a value of 100
//	std::vector<int> bar{ 2, 100, 50 };   // two ints with a value of 200
//
//	if (foo < bar) std::cout << "foo is less than bar\n";    //√
//	if (foo > bar) std::cout << "foo is greater than bar\n";
//
//	return 0;
//}