#include <iostream>
using namespace std;

int main()
{
	//1.��������
	int AsB = 0, BsC = 0, AaB = 0, BaC = 0;
	cin >> AsB >> BsC >> AaB >> BaC;

	//2.�������ݵó����
	int A = (AsB + AaB) / 2;
	int B = (BsC + BaC) / 2;
	int C = (BaC - BsC) / 2;

	//3.�ж���ȷ��
	if (A - B == AsB && B - C == BsC && A + B == AaB && B + C == BaC)
	{
		cout << A << " " << B << " " << C;
	}
	else
	{
		cout << "No";
	}

	return 0;
}


////1.��������
//const char arr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//
//int main()
//{
//	//2.��������
//	int M = 0;
//	int N = 0;
//	cin >> M >> N;//�������ֺ�����
//	string number;//���ս���洢�������ַ���
//	int flag = 1;
//
//	//3.��ǰ��������������
//	if (M < 0)
//	{
//		flag = -1;
//		M = abs(M);
//	}
//	else if (M == 0)
//	{
//		number = "0";
//	}
//
//	//4.����ת��
//	while (M)
//	{
//		number += arr[M % N];//ӳ������ַ�
//		M /= N;
//	}
//
//	//5.�������
//	if (flag == -1) number += "-";
//	reverse(number.begin(), number.end());
//	cout << number;
//	return 0;
//}
