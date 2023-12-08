#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>&& fruits)
    {


        int left = 0, right = 0;
        unordered_map<int, int> um;
        int count = 1;

        while (right < fruits.size())
        {
            //1.进窗口
            um[fruits[right++]]++;

            //2.出窗口
            while (um.size() > 2)
            {
                um[fruits[left]]--;
                if (um[fruits[left]] == 0)
                {
                    um.erase(fruits[left]);
                }
                left++;
            }

            //3.更新
            if (um.size() == 2)
            {
                count = max(count, right - left);
            }
        }

        if (left == 0)
        {
            count = fruits.size();
        }

        return count;
    }
};
int main()
{
    Solution s;
    cout << s.totalFruit({ 3,3,3,1,2,1,1,2,3,3,4 }) << endl;
	return 0;
}