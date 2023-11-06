#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Parenthesis
{
public:
    bool chkParenthesis(std::string A, int n)
    {
        int i = 0;
        std::stack<char> s;
        while (i < (int)A.size())
        {
            if (A[i] == '(')
            {
                s.push(A[i]);
            }
            else if (A[i] == ')')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                else//s.empty() == 0
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            i++;
        }
        return true;
    }
};
int main()
{
    return 0;
}

//int main()
//{
//    int W, H;
//    cin >> W >> H;
//
//    vector<vector<int>> arr(W);
//    int flag1 = 0;
//    int flag2 = 0;
//    int number = 1;
//
//    for (auto& e : arr)
//    {
//        e.resize(H, 1);
//    }
//
//    for (int i = 0; i < W; i++)
//    {
//        for (int j = 0; j < H; j++)
//        {
//            if (arr[i][j] == 1)
//            {
//                if (j + 2 < H)
//                    arr[i][j + 2] = 0;
//                if (j - 2 >= 0)
//                    arr[i][j - 2] = 0;
//                if (i + 2 < W)
//                    arr[i + 2][j] = 0;
//                if (i - 2 >= 0)
//                    arr[i - 2][j] = 0;
//            }
//        }
//    }
//
//    int count = 0;
//    for (auto e : arr)
//    {
//        for (auto h : e)
//        {
//            if (h == 1)
//                count++;
//        }
//    }
//
//    cout << count;
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    long long StrToInt(string str)
//    {
//        long long number = 0;   //返回的数
//        int flag = 1;           //符号标识
//        int index = 0;          //索引
//        if (str[index] == '-')
//        {
//            flag = -1;
//            index++;
//        }
//        if (str[index] == '+')
//        {
//            index++;
//        }
//        if (str[index] == '0')
//        {
//            return 0;
//        }
//
//        while (index != str.size())
//        {
//            if (str[index] <= '9' && str[index] >= '0')
//            {
//                number += (str[index] - '0');
//                index++;
//                number *= 10;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//        return flag * number / 10;
//    }
//};

//#include <cstdio>
//int main()
//{
//	char ch1 = '\200';//128的八进制数字
//	char ch2 = '\x80';//128的十六进制数字
//	printf("%o\n", ch1);
//	printf("%x\n", ch2);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	//1.输入数据
//	int size = 0;
//	cin >> size;
//	vector<int> nums(size);
//	for (auto& it : nums)
//	{
//		cin >> it;
//	}
//
//	//2.动态规划
//	int sum = nums[0];
//	int max = nums[0];
//	for (int i = 1; i < size; i++)
//	{
//		sum = std::max(sum + nums[i], nums[i]);
//		if (sum >= max)
//		{
//			max = sum;
//		}
//	}
//
//	//3.输出结果
//	cout << max;
//	return 0;
//}