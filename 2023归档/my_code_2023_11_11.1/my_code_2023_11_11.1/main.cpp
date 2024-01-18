#include <iostream>
#include <string>
#include <vector>
using namespace std;
void SetNext(const string& sub, vector<int>& next)
{
	next.push_back(0);
	int len = 0;//���Թ���ǰ��׺�������
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
				len = next[len - 1];//��ִ�� sub[len] �� len ָ��ԳƵ��ַ�
			}
		}
	}
}
int KmpSearch(const string& str, const string& sub)
{
	//1.����ģʽ����next����
	vector<int> next;
	SetNext(sub, next);

	//2.����next���鿪ʼƥ��
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
//void Move(char begin, int n, char end)//��һ�����Ϊ n ��Բ��Ų��������һ��Բ��
//{
//	cout << ++m << ":" << n << "��" << begin << "->" << end << endl;
//}
//void Hanoi(int n, char begin, char cache, char end)//�����Ϊ n ������Բ�̴� begin Ų�� end������ cache ��Ϊ����������Ŵ�1��ʼ��
//{
//	if (n == 1)
//	{
//		Move(begin, 1, end);
//	}
//	else
//	{
//		Hanoi(n - 1, begin, end, cache);//�� n-1 ������Բ�̴� begin Ų�� cache������ end ��Ϊ������
//		Move(begin, n, end);//��ʣ���һ�����Ϊ n ��Բ�̴� begin �ƶ��� end
//		Hanoi(n - 1, cache, begin, end);//�� n-1 ������Բ�̴� cache �ƶ��� end������ begin ��Ϊ������
//	}
//}
//int main()
//{
//	Hanoi(1, 'A', 'B', 'C');
//	int arr[1][2][3][4] = { 0 };
//	return 0;
//}