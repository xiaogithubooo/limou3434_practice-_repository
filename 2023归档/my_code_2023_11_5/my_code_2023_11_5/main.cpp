#include <iostream>
using namespace std;

int main()
{
	//1.输入数据
	int AsB = 0, BsC = 0, AaB = 0, BaC = 0;
	cin >> AsB >> BsC >> AaB >> BaC;

	//2.根据数据得出结果
	int A = (AsB + AaB) / 2;
	int B = (BsC + BaC) / 2;
	int C = (BaC - BsC) / 2;

	//3.判断正确性
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


////1.设置数码
//const char arr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//
//int main()
//{
//	//2.输入数据
//	int M = 0;
//	int N = 0;
//	cin >> M >> N;//输入数字和数制
//	string number;//最终结果存储的逆序字符串
//	int flag = 1;
//
//	//3.提前处理负数和零的情况
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
//	//4.进制转换
//	while (M)
//	{
//		number += arr[M % N];//映射插入字符
//		M /= N;
//	}
//
//	//5.输出数据
//	if (flag == -1) number += "-";
//	reverse(number.begin(), number.end());
//	cout << number;
//	return 0;
//}
