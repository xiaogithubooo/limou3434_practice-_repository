#include <vector>
#include <iostream>

class Solution
{
public:
    int searchLeft(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left < right)
        {
            middle = left + (right - left) / 2;

            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] >= target)
            {
                right = middle;
            }
        }
        return right;
    }

    int searchRight(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left < right)
        {
            middle = left + (right - left + 1) / 2;

            if (nums[middle] <= target)
            {
                left = middle;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
        }
        return right;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        if (left < 0 || right < 0 //防止返回值为负数
            || nums[left] != target || nums[right] != target) //防止序列中都是大于或小于 target 的值
        {
            return { -1, -1 };
        }
        return { left, right };
    }
};

int main()
{
    Solution s;
    std::vector<int> v{ 5, 7, 7, 8, 8, 10 };
    std::cout << s.searchRange(v, 8)[0] << std::endl;
    std::cout << s.searchRange(v, 8)[1] << std::endl;
    return 0;
}