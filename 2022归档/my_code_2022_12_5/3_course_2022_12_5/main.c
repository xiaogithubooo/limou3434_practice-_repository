#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int A = 43;
//	printf("%d\n", printf("%d", printf("%d", A)));
//	//��������ʲô�أ�
//	//4321
//	printf("%d\n", printf("0,1,2,3\n"));
//	//������Ϊ
//	////0��1��2��3
//    //8
//	int a = 10, b = 3;
//	//printf("%f", a % b);//���С�����������ǲ��Ϸ���
//	int arr[3] = { 1,2,3 };
//	printf("%d\n", sizeof(arr));//���12
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));//������Ԫ�ظ���
//
//	printf("%D\t%D\n", sizeof(arr), 15);//д������
//	return 0;
//}
void f(int x, int y)
{
	if (x > y)
	{
		printf("%d\n", x);
	}
	else if (x < y)
	{
		printf("%d\n",y);
	}
	else
	{
		printf("һ����\n");
	}
}
int main()
{
	int x = 0, y = 0;
	scanf("%d%d", &x, &y);
	f(x, y);
	return 0;
}