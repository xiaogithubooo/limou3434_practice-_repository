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
        vector<int> ret;

        unordered_map<char, int> sub_hash;
        for (auto it : sub)
        {
            sub_hash[it]++;
        }
        int size = sub.size();
        unordered_map<char, int> str_hash;
        for (int i = 0; i < size; i++)
        {
            str_hash[str[i]]++;
        }

        for (int i = 0; i <= str.size() - size; i++)
        {
            int be = i;
            if (sub_hash == str_hash)
            {
                ret.push_back(i);
            }
            str_hash[str[i]]--;
            if (str_hash[str[i]] == 0)
            {
                str_hash.erase(str[i]);
            }
            str_hash[str[i + size]]++;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    string str = "aa";
    string sub = "bb";
    for (auto it : s.findAnagrams(str, sub))
    {
        cout << it << " ";
    }
    return 0;
}

//class Solution
//{
//public:
//    int totalFruit(vector<int>&& fruits)
//    {
//
//
//        int left = 0, right = 0;
//        unordered_map<int, int> um;
//        int count = 1;
//
//        while (right < fruits.size())
//        {
//            //1.进窗口
//            um[fruits[right++]]++;
//
//            //2.出窗口
//            while (um.size() > 2)
//            {
//                um[fruits[left]]--;
//                if (um[fruits[left]] == 0)
//                {
//                    um.erase(fruits[left]);
//                }
//                left++;
//            }
//
//            //3.更新
//            if (um.size() == 2)
//            {
//                count = max(count, right - left);
//            }
//        }
//
//        if (left == 0)
//        {
//            count = fruits.size();
//        }
//
//        return count;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.totalFruit({ 3,3,3,1,2,1,1,2,3,3,4 }) << endl;
//	return 0;
//}