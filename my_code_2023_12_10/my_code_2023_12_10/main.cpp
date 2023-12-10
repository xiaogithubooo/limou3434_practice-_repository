#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(const string& str, vector<string>& subs)
    {
        vector<int> ret;

        //1.映射匹配字符串的 hash1
        //int hash1[26] = { 0 };
        unordered_map<string, int> hash1;

        //for (auto ch : sub) hash1[ch - 'a']++;
        for (auto string : subs) hash1[string]++;

        //2.映射主串的 hash
        //int hash2[26] = { 0 };
        unordered_map<string, int> hash2;

        //int len = sub.size();
        int len = subs.size();

        for (int left = 0, right = 0, count = 0; right < str.size(); right++)
        {
            //进窗口
            //char in = str[right];
            string in = str.substr(right, subs[0].size());

            //hash2[in - 'a']++;
            hash2[in]++;

            //if (hash2[in - 'a'] <= hash1[in - 'a']) 
            //  count++;//统计有效字符个数
            if (hash2[in] <= hash1[in])
                count++;//统计有效字符个数

            //出窗口
            //if (right - left + 1 > len)//以前我们是用循环的，由于窗口固定不变，因此可以直接用 if
            if (right - left + subs[0].size() > len * subs[0].size())//以前我们是用循环的，由于窗口固定不变，因此可以直接用 if
            {
                //char out = str[left++];
                string out = str.substr(left, subs[0].size());
                left++;

                //if (hash2[out - 'a'] <= hash1[out - 'a'])
                //  count--;
                if (hash2[out] <= hash1[out])
                  count--;
                
                //hash2[out - 'a']--;
                hash2[out]--;
            }

            //更新结果
            if (count == len) 
                ret.push_back(left);
        }

        //3.返回索引结果
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "ababababab";
    vector<string> subs = { "ababa","babab" };
    for (auto it : s.findSubstring(str, subs))
    {
        cout << it << " ";
    }
    return 0;
}

//class Solution
//{
//public:
//    vector<int> findAnagrams(const string& str, const string& sub)
//    {
//        //1.返回顺序表
//        vector<int> ret;
//
//        //2.匹配字符串的哈希表
//        unordered_map<char, int> um_sub;
//        for (auto ch : sub)
//        {
//            um_sub[ch]++;
//        }
//
//        //3.初始化对应匹配字符串长度的子串
//        unordered_map<char, int> um_str_sub;
//        for (int i = 0; i < sub.size(); i++)
//        {
//            um_str_sub[str[i]]++;
//        }
//
//        //4.判断子串和匹配字符串是否异位词
//        for (int i = 0; i + sub.size() - 1 < str.size(); i++)
//        {
//            if (um_sub == um_str_sub)
//            {
//                ret.push_back(i);
//            }
//
//            //5.更新固定窗口
//            um_str_sub[str[i]]--;
//            if (um_str_sub[str[i]] == 0)
//            {
//                um_str_sub.erase(str[i]);
//            }
//            um_str_sub[str[i + sub.size()]]++;
//        }
//
//        //6.返回索引结果
//        return ret;
//    }
//};