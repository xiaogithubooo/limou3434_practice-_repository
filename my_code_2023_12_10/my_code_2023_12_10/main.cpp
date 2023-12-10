#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(const string& str, const string& sub)
    {
        //1.返回顺序表
        vector<int> ret;

        //2.匹配字符串的哈希表
        unordered_map<char, int> um_sub;
        for (auto ch : sub)
        {
            um_sub[ch]++;
        }

        //3.初始化对应匹配字符串长度的子串
        unordered_map<char, int> um_str_sub;
        for (int i = 0; i < sub.size(); i++)
        {
            um_str_sub[str[i]]++;
        }

        //4.判断子串和匹配字符串是否异位词
        for (int i = 0; i + sub.size() - 1 < str.size(); i++)
        {
            if (um_sub == um_str_sub)
            {
                ret.push_back(i);
            }

            //5.更新固定窗口
            um_str_sub[str[i]]--;
            if (um_str_sub[str[i]] == 0)
            {
                um_str_sub.erase(str[i]);
            }
            um_str_sub[str[i + sub.size()]]++;
        }

        //6.返回索引结果
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "cbaebabacd";
    string sub = "abc";
    for (auto it : s.findAnagrams(str, sub))
    {
        cout << it << " ";
    }
    return 0;
}