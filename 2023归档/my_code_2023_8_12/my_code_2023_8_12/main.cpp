#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test_1()
{
	//vector (const allocator_type& alloc = allocator_type());
	vector<int> v1;//(1)默认创建一个空的vector容器

	//vector (size_type n);
	vector<double> v2(10);//(2)创建一个大小位10的vector容器

	//vector(size_type n, const value_type & val, const allocator_type & alloc = allocator_type());
	vector<char> v3(10, 'c');//(2)创建一个大小位10的vector容器

	//<class InputIterator> 
	//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector<char> v4(v3.begin() + 1, v3.end() - 1);//(3)
	string str("abcdef");
	vector<char> vec(str.begin() + 1, str.end() - 1);//(3)

	//vector(const vector & x);
	vector<char> v5(v3);//(4)

	//vector (vector&& x);
	vector<char> v6(move(v3));//(5)

	//vector (initializer_list<value_type> il, const allocator_type& alloc = allocator_type());
	vector<float> v7{ 1, 3.1, 2.3, 4.5 };//(6)
}
void test_2()
{
	vector<int> v1{ 1, 2, 5, 0, 9, 4 };
	vector<int> v2;
	v2 = v1;
	vector<int>::iterator it = v2.begin();//(1)
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}

	vector<int> v3{ 1, 3, 4 };
	vector<int> v4;
	v4 = move(v3);//(2)

	vector<double> v5;
	v5 = { 3.14, 3.2, 4.5, 9.0, 2.1 };//(3)
}
void test_3()
{
	vector<int> v1 = { 1, 5, 2, 7, 9 };
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << (*(it++))++ << " ";
	}
	cout << endl;

	for (auto in : v1)
	{
		cout << in << " ";
	}
	cout << endl;

	//vector<float> v2 = { 1.2, 3.0, 4.3, 0.4 };
	//auto rit = v2.rbegin();
	//while (rit != v2.rend())
	//{
	//	cout << *rit << " ";
	//	rit++;
	//}
}
void test_4()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(1);
		cout << "size = " << v.size() << " " << "capacity = " << v.capacity() << endl;
	}
}
void test_5()
{
	vector<int> v;
	v.resize(10);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i;
		cout << v[i] << " ";
	}
}
void test_6()
{
	vector<int> v = { 1, 3, 3, 4, 5 };
	auto it = find(v.begin(), v.end(), 4);
	if (it != v.end())
		cout << "找到了！" << * it << endl;
	else
		cout << "没有找到！" << endl;
}
void test_7()
{
	class Solution
	{
	public:
		vector<vector<int>> generate(int numRows)//numRows=5
		{
			vector<vector<int>> vs(numRows);//该容器，每一个元素都是一个容器
			vs[0].resize(1);
			vs[0][0] = 1;//1
			//11
			for (int i = 0; i < numRows - 1; i++)//从vs[0]->vs[4]
			{
				for (int j = 0; j <= i; j++)
				{
					vs[i + 1].resize(i + 2);
					vs[i + 1][0] = 1;
					vs[i + 1][i + 1] = 1;
					if (j != 0 && j != i + 1)
					{
						vs[i + 1][j] = vs[i][j - 1] + vs[i][j];
					}
				}
			}
			return vs;
		}
	};
	Solution s;
	auto vs = s.generate(5);
}
int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	//test_5();
	//test_6();
	//test_7();
	return 0;
}
