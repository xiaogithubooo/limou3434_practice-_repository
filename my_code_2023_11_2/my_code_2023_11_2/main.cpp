#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�ַ������ҳ�����������ִ�
int main()
{
	string str = "abcd12345ed125ss123456789";
	//getline(cin, str);
	int max = 0;
	int count = 0;
	vector<int> begin;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))//��������־ͼ�¼
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
//            while (right < str.size() && hash[str[right]] == 0)//�����ظ����ַ��ͷ����ϣ��֮��
//            {
//                hash[str[right++]]++;
//            }
//            //�ߵ�����˵���������ظ����ַ�������ظ�Ԫ�ؾ���str[right]
//            maxSize = maxSize > right - left ? maxSize : right - left;//��¼��󳤶�
//            while (str[left] != str[right])//��leftֱ�������ں�str[right]�ظ���Ԫ�غ���
//            {
//                hash[str[left]]--;
//                left++;
//            }
//            hash[str[left]]--;
//            left++;//�ߵ����ﻹҪ�ڼӼ�һ��
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
//	printf("������һ����λ����\n");
//	scanf("%d", &number);
//	qian = (number / 1000 + 9) % 10;
//	bai = (number / 100 % 10 + 9) % 10;
//	shi = (number / 10 % 10 + 9) % 10;
//	ge = (number % 10 + 9) % 10;
//	printf("%d	%d	%d	%d", qian, bai, shi, ge);
//	return 0;
//}