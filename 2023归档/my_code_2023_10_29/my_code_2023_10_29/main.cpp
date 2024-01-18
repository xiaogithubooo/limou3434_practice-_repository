class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        int n = nums.n();
        for (int i = 0; i < n; )
        {
            for (int j = i + 1; j < n; )
            {
                int left = j + 1;
                int right = n - 1;
                int aim = target - nums[i] - nums[j];
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > aim)
                    {
                        right--;
                    }
                    else if (sum < aim)
                    {
                        left++;
                    }
                    else
                    {
                        ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++, right--;
                    }
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                j++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }
        return ret;
    }
};