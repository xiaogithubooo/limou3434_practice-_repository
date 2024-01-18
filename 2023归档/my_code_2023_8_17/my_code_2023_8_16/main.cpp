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
		else//��
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
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 *
	 * @param pushV int����vector
	 * @param popV int����vector
	 * @return bool������
	 */
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
	{
		//0.�涨pushVΪ��ջ���У�popVΪ��ջ����
		//1.��ջ��������ջs
		//2.s��ջ�����ݺͳ�ջ���бȽ�
			//a.���ƥ�䣬��ջ����++����s��ջ��Ԫ�أ������Ƚϣ�ֱ��ջΪ�գ����߲�ƥ�䣬�ص�1����
			//b.�����ƥ�䣬�ص�����1
		//3.���һֱ�ߵ���ջ���н����ͷ���true
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
