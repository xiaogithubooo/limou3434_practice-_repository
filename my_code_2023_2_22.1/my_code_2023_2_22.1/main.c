#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1��ʹ�ö�ά����ָ�루�����⣩
void print(int(*p)[20], int x, int y)
{
	//��ά��������־�����Ԫ�صĵ�ַ�����ַ���ǵ�һ������ĵ�ַ��Ҳ����ָ��һά�������͵�ָ��
	//����Ϊһά����������ַ&arr������Ԫ�ص�ַ&arr[0]��ʼλ����ͬ
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d", *(* (p + i) + j));//�õ�������������i�õ�ÿһ�е�������������j�õ�ĳһ�е�ÿһ�е�Ԫ�ص�ַ
		}
	}
}
int main()
{
	int arr[10][20] = { {1, 2, 3}, {2, 3, 4} };
	print(arr, 10, 20);
	return 0;
}
//2����ͬѧ�Ĵ���
int main()
{
	double a = 0, b = 0, c = 0;
	int i = scanf("%Lf! %Lf! %Lf!", &a, &b, &c);
	printf("%Lf %Lf %Lf\n%d", a, b, c, i);
	return 0;
}