#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str2.size(); i++)
	{
		for (int j = str2.size(); j > 0; j--)
		{
			string sub = str2.substr(i, i);
		}
	}

	return 0;
}

//int main()
//{
//	string str;
//	cin >> str;
//	reverse(str.begin(), str.end());
//	cout << str;
//	return 0;
//}