#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
using namespace std;
int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}
/*
1. ѡ���⣺
ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
globalVar�����C
staticGlobalVar�����C
staticVar�����C
localVar�����A
num1 �����A
char2�����A
*char2�����
pChar3�����A
*pChar3�����D
ptr1�����A
*ptr1�����B

2. ����⣺
sizeof(num1) = 40
sizeof(char2) = 5
strlen(char2) = 4
sizeof(pChar3) = 4/8
strlen(pChar3) = ���
sizeof(ptr1) = 4/8
*/


//class Solution
//{
//private:
//    string addStrings(string num1, string num2)
//    {
//        int end1 = (int)num1.size() - 1;
//        int end2 = (int)num2.size() - 1;
//        int next = 0;
//        string strRet;
//        while (end1 >= 0 || end2 >= 0 || next != 0)
//        {
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0;
//            //ע��������β��
//            strRet += ('0' + (ret % 10));
//            --end1;
//            --end2;
//        }
//        reverse(strRet.begin(), strRet.end());//�����������㷨
//        return strRet;
//    }
//    string _multiply(string num, char x)
//    {
//        string ret;
//        int cur = num.size() - 1;
//        int temp = 0;
//        while (cur >= 0)
//        {
//            int mul = (num[cur] - '0') * (x - '0') + temp;
//            temp = mul / 10;//��λ
//            ret += (mul % 10 + '0');//��λ
//            cur--;
//        }
//        if (temp)
//        {
//            ret += (temp + '0');
//        }
//        std::reverse(ret.begin(), ret.end());
//        return ret;
//    }
//public:
//    string multiply(string num1, string num2)//123*32
//    {
//        if (num1 == "0" || num2 == "0")
//        {
//            return "0";
//        }
//        string ret = "0";//Ҫ���ص�����
//
//        int cur = num2.size() - 1;
//        //ret = addStrings(ret, _multiply(num1, num2[cur--]));//0+(123*2)
//        int count = 0;
//        while (cur >= 0)
//        {
//            string st = _multiply(num1, num2[cur]);
//            int co = count;
//            while (co)
//            {
//                st += "0";
//                co--;
//            } 
//            ret = addStrings(ret, st);//246+((123*3)*10)
//            cur--;
//            count++;
//        }
//
//        return ret;
//    }
//};
//int main()
//{
//    string num1 = "9133";
//    string num2 = "0";
//    Solution s;
//    cout << s.multiply(num1, num2) << endl;
//}

//class Solution
//{
//private:
//	void _reverseWords(string& s, size_t begin, size_t end)
//	{
//		if (begin >= end || (begin + 1 == end))
//		{
//			return;
//		}
//
//		char temp = 0;
//		end -= 1;
//		while (begin < end)
//		{
//			temp = s[begin];
//			s[begin] = s[end];
//			s[end] = temp;
//			begin++;
//			end--;
//		}
//	}
//public:
//	string reverseWords(string s)
//	{
//		size_t temp = 0;
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (s[i] == ' ')//���Ϊ�ո�
//			{
//				_reverseWords(s, temp, i);
//				temp = i + 1;
//			}
//		}
//		_reverseWords(s, temp, s.size());
//
//		return s;
//	}
//};
//int main()
//{
//	string str = "Let's take LeetCode contest";
//	Solution s;
//	cout << s.reverseWords(str) << endl;
//
//	return 0;
//}

//class Solution
//{
//private:
//	//�����Ӻ���������ת�ַ���������"abcd"��k=2�����Ϊ"bacd"
//	void _reverseStr(string& s ,size_t begin, int k)
//	{
//		//1.��֤k�ĺϷ���
//		if (k == 0)
//		{
//			return;
//		}
//		assert(k > 0);
//
//		//2.�����ַ���
//		char temp;
//		size_t end = (size_t)(begin + k - 1);
//		assert(end < s.size());
//		while (begin < end)
//		{
//			temp = s[begin];
//			s[begin] = s[end];
//			s[end] = temp;
//			begin++;
//			end--;
//		}
//	}
//public:
//	string reverseStr(string s, int k)
//	{
//		//�����������
//		if (k == 0)
//		{
//			return s;
//		}
//
//		int cur = 0;
//		while (cur + (2 * k - 1) < s.size())
//		{
//			//Ҫ�������cur��cur+(2k-1)������ַ���
//			_reverseStr(s, cur, k);
//			cur += (2 * k);
//		}
//
//		//ʣ������������
//		//1.ʣ���ַ�<k��ȫ����ת
//		//2.ʣ���ַ�(>=k || <2*k)����תǰk��
//		int n = s.size() - cur;//ʣ���ַ����ĸ���
//		if (n < k)
//		{
//			//ȫ����ת
//			_reverseStr(s, cur, n);
//		}
//		else if (n >= k || n < 2 * k)
//		{
//			//תǰk��
//			_reverseStr(s, cur, k);
//		}
//		return s;
//	}
//};
//int main()
//{
//	Solution s;
//	string str = "abcd";
//	string strx = s.reverseStr(str, 2);
//	cout << strx << endl;
//	return 0;
//}

//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        vector<int>::iterator it = nums.begin();
//        vector<int>::iterator cur, p;
//        while (it != nums.end())//��ȡ�Աȵ�����
//        {
//            cur = it;
//            p = it + 1;
//            while (p != nums.end())
//            {
//                if (*cur == *p)
//                {
//                    p = nums.erase(p);
//                }
//                else
//                {
//                    p++;
//                }
//            }
//            it++;
//        }
//        return nums.size();
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
//    s.removeDuplicates(v);
//    return 0;
//}

//class Solution
//{
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        while (i < nums.size())
//        {
//            if (i + 2 >= nums.size() || nums[i] != nums[i + 2])
//            {
//                return nums[i];
//            }
//            i += 3;
//        }
//        return -1;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v = { 2,2,3,2 };
//    s.singleNumber(v);
//    return 0;
//}

//class Solution
//{
//public:
//    vector<int> singleNumber(vector<int>& nums)
//    {
//        //1.����һ��vectorȻ�������ռ�
//        vector<int> ret;
//        ret.push_back(0);
//        ret.push_back(0);
//        int all = 0;
//
//        //2.��ԭ����ȫ�����һ��
//        for (int i = 0; i < nums.size(); i++)
//        {
//            all ^= nums[i];
//        }
//
//        //3.����allѰ���������ݶ�Ӧ����λ�ò�ͬ�ĵط�
//        int k = 1;
//        int temp = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            if (((all >> i) & k) == 1)
//            {
//                temp = i;
//                break;
//            }
//        }
//
//        //4.��ʼ����Ѱ��
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (((nums[i] >> temp) & k) == 1)
//            {
//                ret[0] ^= nums[i];
//            }
//            else
//            {
//                ret[1] ^= nums[i];
//            }
//        }
//
//        //5.���ؽ��
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> v = { 1,2,1,3,2,5 };
//    vector<int> ret = s.singleNumber(v);
//    return 0;
//}

//class Solution
//{
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param numbers int����vector
//     * @return int����
//     */
//    int MoreThanHalfNum_Solution(vector<int>& numbers)
//    {
//        int size2 = (int)numbers.size() / 2;
//        int max = numbers[0];
//        int min = numbers[0];
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            if (max < numbers[i])
//            {
//                max = numbers[i];
//            }
//            if (min > numbers[i])
//            {
//                min = numbers[i];
//            }
//        }//�ҵ�max��min
//
//        int range = max - min + 1;
//
//        int* countArr = new int[range];
//        memset(countArr, 0, sizeof(int) * range);
//        for (int i = 0; i < numbers.size(); i++)
//        {
//            countArr[numbers[i] - min]++;
//        }
//
//        //�����ҵ�����Ҫ�����
//        for (int i = 0; i < range; i++)
//        {
//            if(countArr[i] > size2)
//            {
//                return i + min;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    Solution a;
//    vector<int> v = { 1,2,3,2,2,2,5,4,2 };
//    cout << a.MoreThanHalfNum_Solution(v);
//    return 0;
//}