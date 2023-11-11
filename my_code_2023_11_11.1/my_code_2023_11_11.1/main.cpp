#include <iostream>
using namespace std;

int m = 0;
void Move(char begin, int n, char end)//��һ�����Ϊ n ��Բ��Ų��������һ��Բ��
{
	cout << ++m << ":" << n << "��" << begin << "->" << end << endl;
}
void Hanoi(int n, char begin, char cache, char end)//�����Ϊ n ������Բ�̴� begin Ų�� end������ cache ��Ϊ����������Ŵ�1��ʼ��
{
	if (n == 1)
	{
		Move(begin, 1, end);
	}
	else
	{
		Hanoi(n - 1, begin, end, cache);//�� n-1 ������Բ�̴� begin Ų�� cache������ end ��Ϊ������
		Move(begin, n, end);//��ʣ���һ�����Ϊ n ��Բ�̴� begin �ƶ��� end
		Hanoi(n - 1, cache, begin, end);//�� n-1 ������Բ�̴� cache �ƶ��� end������ begin ��Ϊ������
	}
}
int main()
{
	Hanoi(1, 'A', 'B', 'C');
	int arr[1][2][3][4] = { 0 };
	return 0;
}