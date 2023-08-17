#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <vector>
using std::stack;
using std::queue;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void test_1()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop();
	}
	cout << endl;
}

class MinStack
{
public:
	MinStack()
	{}
	void push(int val)
	{
		s1.push(val);
		if (!s2.empty())
		{
			if (val <= s2.top())
			{
				s2.push(val);
			}
		}
		else//空
		{
			s2.push(val);
		}
	}
	void pop()
	{
		if (s1.empty())
		{
			return;
		}

		if (s1.top() == s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else
		{
			s1.pop();
		}
	}
	int top()
	{
		return s1.top();
	}
	int getMin()
	{
		return s2.top();
	}
	stack<int> s1;
	stack<int> s2;
};
void test_2()
{
	MinStack* _minStack = new MinStack();
	MinStack minStack = *_minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();
	minStack.pop();
	minStack.top();
	cout << minStack.getMin();
}

class Solution
{
public:
	/*
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param pushV int整型vector
	 * @param popV int整型vector
	 * @return bool布尔型
	 */
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
	{
		//0.规定pushV为入栈序列，popV为出栈序列
		//1.入栈序列先入栈s
		//2.s的栈顶数据和出栈序列比较
			//a.如果匹配，出栈序列++，出s的栈顶元素，继续比较，直到栈为空，或者不匹配，回到1步骤
			//b.如果不匹配，回到步骤1
		//3.如果一直走到出栈序列结束就返回true
		stack<int> s;
		int pushVIndex = 0, popVIndex = 0;
		s.push(pushV[pushVIndex++]);
		while (popVIndex < popV.size())
		{
			if (s.empty() || s.top() != popV[popVIndex])
			{
				if (pushVIndex > pushV.size())
				{
					return false;
				}
				s.push(pushV[pushVIndex]);
				pushVIndex++;
			}
			else if (s.top() == popV[popVIndex])
			{
				popVIndex++;
				s.pop();
			}
		}
		return true;
	}
};
void test_3()
{
	Solution s;
	vector<int> pushV = { 2, 1, 0 };
	vector<int> popV = { 1, 2, 0 };
	s.IsPopOrder(pushV, popV);
}

int main()
{
	//test_1();
	//test_2();
	test_3();
	return 0;
}
