#include <iostream>
using namespace std;

int pathnum(int n, int m)
{
	if (n == 0 || m == 0)
	{
		return 1;
	}
	return pathnum(n - 1, m) + pathnum(n, m - 1);
}
int main()
{
	pathnum(8, 6);
	return 0;
}

//#include <iostream>
//class Sum
//{
//public:
//    Sum()
//    {
//        _ret += _i;
//        _i++;
//    }
//    static int GetRet()
//    {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        Sum* arr = new Sum[n];
//        return Sum::GetRet();
//    }
//};
//int main()
//{
//    Solution s;
//    std:: cout << s.Sum_Solution(7);
//    return 0;
//}

//class A
//{
//public:
//    A(int number = 1)
//        : a(number)//ʧ��
//    {}
//private:
//    const static int a;
//};
//int main()
//{
//    return 0;
//}

////����С������
//#include <iostream>
//using namespace std;
//int main()
//{
//    int X = 0;
//    int Y = 0;
//    cin >> X >> Y;
//    int product = X * Y;
//
//    int Z = 0;
//    while (Z = X % Y)
//    {
//        X = Y;
//        Y = Z;
//    }
//    cout << product / Y;
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <cstdio>
//int main()
//{
//	float grade1, grade2, grade3;
//	float sum;
//	printf("�����һ��ѧ�������ųɼ�(�ÿո�ָ�):\n");
//	scanf("%f %f %f", &grade1, &grade2, &grade3);
//	getchar();
//	sum = grade1 + grade2 + grade3;
//	printf("��һ��ѧ�����ܳɼ�=%f\n", sum);
//
//	printf("����ڶ���ѧ�������ųɼ�(�ö��ŷָ�):\n");
//	scanf("%f %f %f", &grade1, &grade2, &grade3);
//	getchar();
//	sum = grade1 + grade2 + grade3;
//	printf("�ڶ���ѧ�����ܳɼ�=%f\n", sum);
//
//	printf("���������ѧ�������ųɼ�(��ð�ŷָ�):\n");
//	scanf("%f %f %f", &grade1, &grade2, &grade3);
//	getchar();
//	sum = grade1 + grade2 + grade3;
//	printf("������ѧ�����ܳɼ�=%f\n", sum);
//	return 0;
//}