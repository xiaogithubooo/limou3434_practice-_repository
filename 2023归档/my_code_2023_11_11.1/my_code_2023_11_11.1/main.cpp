#include <iostream>
#include <string>
#include <vector>
using namespace std;
void SetNext(const string& sub, vector<int>& next)
{
	next.push_back(0);
	int len = 0;//可以构成前后缀的最长长度
	int i = 1;
	while (i < sub.size())
	{
		if (sub[len] == sub[i])
		{
			len += 1;
			next.push_back(len);
			i += 1;
		}
		else
		{
			if (len == 0)
			{
				next.push_back(0);
				i += 1;
			}
			else
			{
				len = next[len - 1];//将执行 sub[len] 的 len 指向对称的字符
			}
		}
	}
}
int KmpSearch(const string& str, const string& sub)
{
	//1.设置模式串的next数组
	vector<int> next;
	SetNext(sub, next);

	//2.根据next数组开始匹配
	int cur = 0;
	int i = 0;
	while(cur < str.size())
	{
		if (str[cur] == sub[i])
		{
			cur++;
			i++;
		}
		else if (i > 0)
		{
			i = next[i - 1];
		}
		else
		{
			cur += 1;
		}
		if (i == sub.size())
		{
			return cur - i;
		}
	}
	return -1;
}
int main()
{
	string str = "ABABACABAB";
	string sub = "ABACABAB";
	cout << KmpSearch(str, sub);
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int m = 0;
//void Move(char begin, int n, char end)//将一个编号为 n 的圆盘挪动到另外一个圆盘
//{
//	cout << ++m << ":" << n << "号" << begin << "->" << end << endl;
//}
//void Hanoi(int n, char begin, char cache, char end)//将编号为 n 及以上圆盘从 begin 挪到 end，其中 cache 作为辅助塔（编号从1开始）
//{
//	if (n == 1)
//	{
//		Move(begin, 1, end);
//	}
//	else
//	{
//		Hanoi(n - 1, begin, end, cache);//将 n-1 及以上圆盘从 begin 挪到 cache，其中 end 作为辅助塔
//		Move(begin, n, end);//将剩余的一个编号为 n 的圆盘从 begin 移动到 end
//		Hanoi(n - 1, cache, begin, end);//将 n-1 及以上圆盘从 cache 移动到 end，其中 begin 作为辅助塔
//	}
//}
//int main()
//{
//	Hanoi(1, 'A', 'B', 'C');
//	int arr[1][2][3][4] = { 0 };
//	return 0;
//}