#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> arr1, vector<int> arr2)
    {
        //cout存储数据的重复次数
        vector<int> count;
        count.resize(1001, -1);//可以存储1001个数据，下标从0到1000，初始化为-1

        //映射数据，并且搜集未在arr2中的数据
        vector<int> v;
        for (auto it : arr2)
        {
            count[it]++;
        }
        for (auto it : arr1)
        {
            if (count[it] == -1)
            {
                v.push_back(it);
            }
            else
            {
                count[it]++;
            }
        }
        sort(v.begin(), v.end());

        //处理返回数组
        vector<int> ret;
        for (auto it : arr2)
        {
            int n = count[it];
            while (n--)
            {
                ret.push_back(it);
            }
        }

        for (auto it : v)
        {
            ret.push_back(it);
        }

        return ret;
    }
};
int main()
{
    Solution s;
    s.relativeSortArray({ 2,3,1,3,2,4,6,7,9,2,19 }, { 2,1,4,3,9,6 });
    return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//void _function(string& str, int x, int y)//abcd, x->a, y->'\0'
//{
//    y--;
//    while (x < y)
//    {
//        swap(str[x++], str[y--]);
//    }
//}
//int main()
//{
//    //1.获取句子
//    string str;
//    getline(cin, str);//有可能有输入" "、""、"."、"apple."
//
//    //2.整个句子都逆置
//    int begin = 0;
//    int end = str.size() - 1;//例如"abcd ef ghi jklmn."的size=8，因此这里end为7
//    while (begin < end)
//    {
//        swap(str[begin++], str[end--]);
//    }
//
//    //3.寻找空格，定位好每个单词，将每个单词都逆转
//    int index = 0;
//    int begin_i = 0;
//    while (index < str.size())//0 < 8，不会越界
//    {
//        if (str[index] == ' ')
//        {
//            _function(str, begin_i, index);//传过去(0, 4)，注意这里是“框起一个单词”
//            begin_i = index + 1;//5->e
//        }
//        index++;
//    }
//    _function(str, begin_i, index);
//    cout << str;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	//1.输入数据
//	int n = 0;
//	cin >> n;
//	vector<int> arr;
//	while (n--)
//	{
//		int number = 0;
//		cin >> number;
//		arr.push_back(number);
//	}
//	arr.push_back(0);//这个0是避免越界使用，不影响结果
//
//	//2.处理子序列
//	int count = 0;
//	int i = 0;
//	while (i < arr.size())
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			while (i < arr.size() && (arr[i] <= arr[i + 1]))
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//		else if (arr[i] > arr[i + 1])
//		{
//			while (i < arr.size() && (arr[i] >= arr[i + 1]))
//			{
//				i++;
//			}
//			count++;
//			i++;
//		}
//		else
//		{
//			i++;
//		}
//	}
//
//	//3.输出数据
//	cout << count << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    //1.字符串数组
//    string str;
//    getline(cin, str);
//    string deleteStr;
//    getline(cin, deleteStr);
//
//    //2.哈希表
//    vector<int> arr(256);
//    arr.resize(0);
//
//    //3.映射deleteStr
//    for(auto ch : deleteStr)
//    {
//        arr[ch]++;
//    }
//
//    //4.输出不被输出的字符
//    for (auto ch : str)
//    {
//        if (arr[ch] == 0)
//        {
//            cout << ch;
//        }
//    }
//  
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    //1.输入数据
//    int n;
//    cin >> n;
//    vector<int> nums;
//    for (int i = 0; i < 3 * n; i++)
//    {
//        int number = 0;
//        cin >> number;
//        nums.push_back(number);
//    }
//
//    //2.排序数据
//    sort(nums.begin(), nums.end());
//
//    //3.开始组队
//    long long sum = 0;
//    int begin = 0;
//    int end = nums.size() - 1;
//    int mid = end - 1;
//    while (begin < mid)
//    {
//        sum += nums[mid];
//        begin++;
//        end -= 2;
//        mid = end - 1;
//    }
//
//    //4.输出数据
//    cout << sum;
//    return 0;
//}