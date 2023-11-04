#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (!numbers.size()) return -1;

        int number = numbers[0];//侯选数
        int count = 1;//投票数

        int i = 1;
        while (i < numbers.size())
        {
            if (number == numbers[i])
            {
                count++;//投票
            }
            else
            {
                count--;//抵消
            }
            i++;
            if (count == 0)
            {
                number = numbers[i];//更换候选人
                count = 1;//重置票数
                i++;
            }
        }
        return number;
    }
};
int main()
{
    Solution s;
    cout << s.MoreThanHalfNum_Solution({ 1,2,3,2,4,2,8,9,2 });
}

//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//与运算 
//	}
//	return count;
//}

//int main()
//{
//	//1.输入数据
//	string str;
//	getline(cin, str);
//
//	//2.起始下标
//	int cur = 0;
//
//	//3.竞争字符串
//	string str1;
//	string str2;
//
//	for (auto it : str)
//	{
//		if (isdigit(it))//是数字字符
//		{
//			str1.push_back(it);
//		}
//		else
//		{
//			if (str1.size() > str2.size())
//			{
//				str2 = str1;
//			}
//			str1.resize(0);
//		}
//	}
//	if (str1.size() > str2.size())
//	{
//		str2 = str1;
//	}
//
//	cout << str2;
//	return 0;
//}

//class A
//{
//public:
//    A() : m_iVal(0)
//    {
//        test();
//    }
//
//    virtual void func()
//    {
//        std::cout << m_iVal << ' ';
//    }
//
//    void test()
//    {
//        func();
//    }
//
//public:
//    int m_iVal;
//};
//
//class B : public A
//{
//public:
//    B() 
//    {
//        test();
//    }
//
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << ' ';
//    }
//};
//
//int main(int argc, char* argv[])
//{
//    A* p = new B;
//    //1. 使用 new 调用 B 类的构造函数 B(B* this)
//    //
//    //2. 在子类构造函数 B(B* this) 中默认先利用切片调用父类构造函数 A(A* this)，
//    //   初始化了子类内继承的 m_iVal 为 0，而内部又去调用 test(A* this)，
//    //   这里无法发生多态（此时还在 B 类对象还在构造阶段，而其虚表指针又是初始化列表最后一个初始化的）
//    //   因此调用 func(A* this)，此时 m_iVal 为 0，并且打印出 "0 "
//    //
//    //3. B(B* this)的初始化列表走完了，此时 B 类对象内部就有了虚表指针。
//    //   而子类构造函数 B(B* this) 内部的 test() 由于继承，
//    //   直接调用父类内部的 test(A* this)，这里可以发生多态，
//    //   因此内部调用 func() 调用的是子类的 func()，m_iVal 变为 1，并且打印 "1 "
//    
//    p->test();
//    //4. 这里由于继承直接调用父类的 test(A* this)，内部发生多态调用 func(A* this)，
//    //   则 m_iVal 变为 2，打印"2 "
//
//    return 0;
//}

//class Solution
//{
//public:
//    int longestOnes(vector<int> nums, int K)
//    {
//        int left = 0, right = 0;
//        int zero = 0;
//        int maxSize = 0;
//        int n = nums.size();
//        
//        while (right < n)
//        {
//            if (nums[right] == 0)
//                zero++;
//
//            while (zero > K)
//            {
//                if (nums[left] == 0)
//                    zero--;
//
//                left++;
//            }
//
//            right++;
//            maxSize = max(maxSize, right - left);
//        }
//        return maxSize;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.longestOnes({ 1,1,1,0,0,0,1,1,1,1,0 }, 2);
//	return 0;
//}