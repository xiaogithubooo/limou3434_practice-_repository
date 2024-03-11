#include <vector>
#include <iostream>

class Solution 
{
public:
    int search(std::vector<int>&& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
    std::vector<int> func(std::vector<int>&& nums, int i)
    {
        int begin = i;
        int end = i;
        if (i != -1)
        {
            while (begin >= 0 && nums[begin] == nums[i])
            {
                begin--;
            }
            while (end < nums.size() && nums[end] == nums[i])
            {
                end++;
            }
            return { begin + 1, end - 1 };
        }
        return { -1, -1 };
    }
};

int main()
{
    Solution s;
    std::cout << s.func({ 1, 3, 3, 3, 5 }, s.search({ 1, 3, 3, 3, 5 }, 3))[0] << std::endl;
    std::cout << s.func({ 1, 3, 3, 3, 5 }, s.search({ 1, 3, 3, 3, 5 }, 3))[1] << std::endl;
    return 0;
}