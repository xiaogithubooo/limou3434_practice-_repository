#include <iostream>
#include <string>
#include <vector>
using namespace std;
//字符串中找出连续最长的数字串
int main()
{
	string str = "abcd12345ed125ss123456789";
	//getline(cin, str);
	int max = 0;
	int count = 0;
	vector<int> begin;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))//如果是数字就记录
		{
			if (count == 0) begin.push_back(i);
			count++;
		}
		else
		{
			max = count;
			count = 0;
		}
	}

	return 0;
}

//class Solution
//{
//public:
//    int lengthOfLongestSubstring(string str)
//    {
//        int left = 0;
//        int right = 0;
//        int maxSize = 0;
//        int hash[128] = { 0 };
//
//        while (left < str.size())
//        {
//            while (right < str.size() && hash[str[right]] == 0)//不是重复的字符就放入哈希表之中
//            {
//                hash[str[right++]]++;
//            }
//            //走到这里说明出现了重复的字符，这个重复元素就是str[right]
//            maxSize = maxSize > right - left ? maxSize : right - left;//记录最大长度
//            while (str[left] != str[right])//让left直接跳到在和str[right]重复的元素后面
//            {
//                hash[str[left]]--;
//                left++;
//            }
//            hash[str[left]]--;
//            left++;//走到这里还要在加加一次
//        }
//
//        return maxSize;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.lengthOfLongestSubstring("deabcabca");
//    return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int number, qian, bai, shi, ge;//, putout;
//	system("color 0a");
//	printf("请输入一个四位数。\n");
//	scanf("%d", &number);
//	qian = (number / 1000 + 9) % 10;
//	bai = (number / 100 % 10 + 9) % 10;
//	shi = (number / 10 % 10 + 9) % 10;
//	ge = (number % 10 + 9) % 10;
//	printf("%d	%d	%d	%d", qian, bai, shi, ge);
//	return 0;
//}