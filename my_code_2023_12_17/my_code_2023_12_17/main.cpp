#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		//1.���ù�ϣ��
		int hash1[256] = { 0 };
		for (auto it : t)
			hash1[it]++;

		int hash2[256] = { 0 };
		int count = 0;

		for (int left = 0, right = 0; right < s.size(); right++)
		{
			//2.������
			hash2[right]++;
			if (hash2[right] >= hash1[right])
			{
				count++;
			}

			//3.�жϣ������ڣ�
			while ()
			{

			}
		}
	}
};

int main()
{
	Solution so;
	string s = "ADOBECODEBANC", t = "ABC";
	so.minWindow(s, t);
	return 0;
}