#include <iostream>
using namespace std;
//结点结构体
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
        //1.如果有一个链表为空就返回另外一个链表（同时也能处理同时为空的情况）
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* ret = l1;

        //2.使用两个指针分别同步遍历链表，并且各自的val相加后，存储在两个链表里
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

        //3.查找是否有没有走完的链表，并且处理
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

        //4.查看cache是否还为1（是则需要多加结点）
        if (cache == 1)
        {
            ListNode* newNode = new ListNode(cache);
            prev->next = newNode;
        }

        //5.返回链表结果
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
////判断是否是完全数
//bool IsOk(int number)
//{
//	//25 < 28 < 36
//	//5 < sqrt(28) < 6
//	//1、2、4 ---- 28、14、7
//	//然后去掉28即可
//	//1.找到约数
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
//	//1.输入最大范围
//	int k = 0;
//	cin >> k;
//
//	//2.统计符合的数
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
//	//3.输出统计结果
//	cout << count;
//	return 0;
//}
//
//// 64 位输出请用 printf("%lld")
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
