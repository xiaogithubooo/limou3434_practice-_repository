#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(const string& str, const string& sub)
    {
        vector<int> ret;

        set<char> s1(sub.begin(), sub.end());
        set<char> s2;

        int len = sub.size();
        for (int i = 0; i + len -1 < str.size(); i++)
        {
            int size = sub.size();
            int j = i;
            while (size--)
            {
                s2.insert(str[j++]);
            }

            if (s1 == s2)
                ret.push_back(i);

            s2.clear();
        }
        return ret;
    }
};
int main()
{
    Solution s;
    string str = "abab";
    string sub = "ab";
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