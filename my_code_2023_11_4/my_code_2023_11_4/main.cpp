#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (!numbers.size()) return -1;

        int number = numbers[0];//��ѡ��
        int count = 1;//ͶƱ��

        int i = 1;
        while (i < numbers.size())
        {
            if (number == numbers[i])
            {
                count++;//ͶƱ
            }
            else
            {
                count--;//����
            }
            i++;
            if (count == 0)
            {
                number = numbers[i];//������ѡ��
                count = 1;//����Ʊ��
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
//		x = x & (x - 1);//������ 
//	}
//	return count;
//}

//int main()
//{
//	//1.��������
//	string str;
//	getline(cin, str);
//
//	//2.��ʼ�±�
//	int cur = 0;
//
//	//3.�����ַ���
//	string str1;
//	string str2;
//
//	for (auto it : str)
//	{
//		if (isdigit(it))//�������ַ�
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
//    //1. ʹ�� new ���� B ��Ĺ��캯�� B(B* this)
//    //
//    //2. �����๹�캯�� B(B* this) ��Ĭ����������Ƭ���ø��๹�캯�� A(A* this)��
//    //   ��ʼ���������ڼ̳е� m_iVal Ϊ 0�����ڲ���ȥ���� test(A* this)��
//    //   �����޷�������̬����ʱ���� B ������ڹ���׶Σ��������ָ�����ǳ�ʼ���б����һ����ʼ���ģ�
//    //   ��˵��� func(A* this)����ʱ m_iVal Ϊ 0�����Ҵ�ӡ�� "0 "
//    //
//    //3. B(B* this)�ĳ�ʼ���б������ˣ���ʱ B ������ڲ����������ָ�롣
//    //   �����๹�캯�� B(B* this) �ڲ��� test() ���ڼ̳У�
//    //   ֱ�ӵ��ø����ڲ��� test(A* this)��������Է�����̬��
//    //   ����ڲ����� func() ���õ�������� func()��m_iVal ��Ϊ 1�����Ҵ�ӡ "1 "
//    
//    p->test();
//    //4. �������ڼ̳�ֱ�ӵ��ø���� test(A* this)���ڲ�������̬���� func(A* this)��
//    //   �� m_iVal ��Ϊ 2����ӡ"2 "
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