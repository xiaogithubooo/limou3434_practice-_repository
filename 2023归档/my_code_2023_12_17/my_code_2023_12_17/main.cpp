#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
//class Solution
//{
//public:
//	string minWindow(string s, string t)
//	{
//		string ret = s;
//		int flag = 0;
//
//		//1.设置哈希表
//		int hash1[256] = { 0 };
//		for (auto it : t)
//			hash1[it]++;
//
//		int hash2[256] = { 0 };
//		int count = 0;
//
//		int len = t.size();
//		for (int left = 0, right = 0; right < s.size(); right++)
//		{
//			//2.进窗口
//			hash2[s[right]]++;
//			if (hash2[s[right]] <= hash1[s[right]])
//			{
//				count++;
//			}
//
//			//4.更新
//			if (count == len && ret.size() > s.substr(left, right - left + 1).size())
//				ret = s.substr(left, right - left + 1);
//
//			//3.判断（出窗口）
//			while (count == len)
//			{
//				if (count == len && ret.size() > s.substr(left, right - left + 1).size())
//					ret = s.substr(left, right - left + 1);
//
//				if (hash2[s[left]]-- <= hash1[s[left]])
//				{
//					flag = 1;
//					count--;
//				}
//
//				left++;
//			}
//
//		}
//
//		if(flag == 1)
//			return ret;
//		return "";
//	}
//};

class Solution
{
public:
	string minWindow(string s, string t)
	{
		string ret = s;
		int flag = 0;

		//1.设置哈希表
		int hash1[256] = { 0 };
		for (auto it : t)
			hash1[it]++;

		int hash2[256] = { 0 };
		int count = 0;

		int len = t.size();
		for (int left = 0, right = 0; right < s.size(); right++)
		{
			//2.进窗口
			hash2[s[right]]++;
			if (hash2[s[right]] <= hash1[s[right]])
			{
				count++;
			}

			//4.更新
			if (count == len && ret.size() > s.substr(left, right - left + 1).size())
				ret = s.substr(left, right - left + 1);

			//3.判断（出窗口）
			while (count == len)
			{
				if (count == len && ret.size() > s.substr(left, right - left + 1).size())
					ret = s.substr(left, right - left + 1);

				if (hash2[s[left]]-- <= hash1[s[left]])
				{
					flag = 1;
					count--;
				}

				left++;
			}

		}

		if (flag == 1)
			return ret;
		return "";
	}
};

int main()
{
	Solution so;
	string s = "abc", t = "ac";
	cout << so.minWindow(s, t);
	return 0;
}