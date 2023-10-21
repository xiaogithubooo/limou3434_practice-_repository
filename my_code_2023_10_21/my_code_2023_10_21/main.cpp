//#include <iostream>
//#include <string>
//#include <stack>
//#include <cmath>
//using namespace std;
//class Solution
//{
//    bool IsNo(const char& x, const char& y)
//    {
//        if (fabs(x - y) == fabs('a' - 'A'))
//        {
//            return true;
//        }
//        return false;
//    }
//public:
//    string makeGood(string s)
//    {
//        while()
//        {
//            int index = 0;
//            while (index + 1 < s.size())
//            {
//                if (IsNo(s[index], s[index + 1]))//存在相邻的大小字母
//                {
//                    s.erase(index, 1);
//                    s.erase(index, 1);
//                }
//                else
//                {
//
//                }
//                index++;
//            }
//        }
//        return s;
//    }
//};
//int main()
//{
//    Solution s;
//    s.makeGood("leEeetcode");
//	return 0;
//}
//
////#include <iostream>
////#include <string>
////#include <stack>
////using namespace std;
////class Solution
////{
////public:
////    int maxDepth(string s)
////    {
////        stack<int> sta;
////        int count = 0;
////        int maxCount = 0;
////
////        int index = 0;
////        while (index < s.size())
////        {
////            if (s[index] == '(')
////            {
////                sta.push(s[index]);
////                count++;
////            }
////            else if (s[index] == ')')
////            {
////                sta.pop();
////                if (maxCount < count)
////                {
////                    maxCount = count;
////                }
////                count--;
////            }
////            index++;
////        }
////        return maxCount;
////    }
////};
////int main()
////{
////    Solution s;
////    s.maxDepth("(1)+((2))+(((3)))");
////    return 0;
////}