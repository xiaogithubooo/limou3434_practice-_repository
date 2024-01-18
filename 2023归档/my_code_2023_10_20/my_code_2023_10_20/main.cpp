#include <iostream>
using namespace std;
//���ṹ��
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        //1.�����һ������Ϊ�վͷ�������һ������ͬʱҲ�ܴ���ͬʱΪ�յ������
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* ret = l1;

        //2.ʹ������ָ��ֱ�ͬ�������������Ҹ��Ե�val��Ӻ󣬴洢������������
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* prev = cur1;

        int cache = 0;
        while (cur1 && cur2)
        {
            int number1 = cur1->val;
            int number2 = cur2->val;
            cur1->val = cur2->val = number1 + number2 + cache;

            if (cur1->val > 9)
            {
                cur1->val -= 10;
                cur2->val -= 10;
                cache = 1;
            }
            else
            {
                cache = 0;
            }

            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        //3.�����Ƿ���û��������������Ҵ���
        ListNode* cur = nullptr;
        if (cur1 != nullptr)
        {
            cur = cur1;
            ret = l1;
        }
        if (cur2 != nullptr)
        {
            cur = cur2;
            ret = l2;
        }

        while (cache == 1 && cur)
        {
            cur->val = cur->val + cache;
            if (cur->val > 9)
            {
                cur->val -= 10;
                cache = 1;
            }
            else
            {
                cache = 0;
            }
            prev = cur;
            cur = cur->next;
        }

        //4.�鿴cache�Ƿ�Ϊ1��������Ҫ��ӽ�㣩
        if (cache == 1)
        {
            ListNode* newNode = new ListNode(cache);
            prev->next = newNode;
        }

        //5.����������
        return ret;
    }
};
int main()
{
    return 0;
}

//#include <iostream>
//#include <cmath>
//using namespace std;
//
////�ж��Ƿ�����ȫ��
//bool IsOk(int number)
//{
//	//25 < 28 < 36
//	//5 < sqrt(28) < 6
//	//1��2��4 ---- 28��14��7
//	//Ȼ��ȥ��28����
//	//1.�ҵ�Լ��
//	int add = 0;
//	for (int i = 1; i < sqrt(number); i++)
//	{
//		if (number % i == 0)
//		{
//			add += (i + (number / i));
//		}
//	}
//
//	if (add == 2 * number)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//int main()
//{
//	//1.�������Χ
//	int k = 0;
//	cin >> k;
//
//	//2.ͳ�Ʒ��ϵ���
//	int count = 0;
//	while (k > 0)
//	{
//		if (IsOk(k))
//		{
//			count++;
//		}
//		k--;
//	}
//
//	//3.���ͳ�ƽ��
//	cout << count;
//	return 0;
//}
//
//// 64 λ������� printf("%lld")
//
////#include <iostream>
////using namespace std;
////
////class Base
////{
////public:
////	virtual void Function_1()
////	{
////		cout << "Base:Function_1()" << endl;
////	}
////	virtual void Function_2()
////	{
////		cout << "Base:Function_2()" << endl;
////	}
////private:
////	int _b_number = 1;
////};
////class Derive : public Base
////{
////private:
////	int _d_number = 2;
////};
////
////void Function(Base* x)
////{
////	x->Function_1();
////}
////
////int main()
////{
////	Base b;
////	Derive d;
////
////	Function(&b);
////	Function(&d);
////
////	Base bb;
////	return 0;
////}
