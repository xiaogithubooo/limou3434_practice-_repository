#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//1.输入数据
	int size = 0;
	cin >> size;
	vector<int> nums(size);
	for (auto& it : nums)
	{
		cin >> it;
	}

	//2.动态规划
	int sum = nums[0];
	int max = nums[0];
	for (int i = 1; i < size; i++)
	{
		sum = std::max(sum + nums[i], nums[i]);
		if (sum >= max)
		{
			max = sum;
		}
	}

	//3.输出结果
	cout << max;
	return 0;
}