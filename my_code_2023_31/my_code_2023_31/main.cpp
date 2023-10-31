#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum = 0;
        int maxLength = 0;

        int left = 0;
        int right = 0;

        while (right < nums.size())
        {
            sum += nums[right];
            if (sum >= target)
            {
                break;
            }
            right++;
        }
        maxLength = right - left + 1;
        //µÃµ½´°¿Ú[left, right]

        while(maxLength && right < nums.size())
        {
            sum -= nums[left];
            left++;
            if (sum >= target)
            {
                maxLength = right - left + 1;
            }
            else//sum < target
            {
                right++;
                if (right < nums.size())
                {
                    sum += nums[right];
                }
                else
                {
                    right = nums.size();
                }
            }
        }
        return maxLength;
    }
};
int main()
{
    int target = 7;
    vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    Solution s;
    cout << s.minSubArrayLen(target, nums);
    return 0;
}