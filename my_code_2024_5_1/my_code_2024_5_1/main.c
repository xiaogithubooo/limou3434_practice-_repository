#define _CRT_SECURE_NO_WARNINGS

//˫ѭ��
#include <stdio.h>
int main()
{
	int ret = 1;
	int sum = 0;

	//�������� n
	int maxN = 0;
	scanf("%d", &maxN);
	for (int i = 1; i <= maxN; i++) //����� 1! �� n! ��ÿһ�� i!(���� i��[1, n])
	{
		ret = 1; //ÿ�μ���ѭ���Ȱ� ret ����Ϊ 0
		for (int j = 1; j <= i; j++) //���� i! ��ֵ
		{
			ret *= j;
		}
		//i! ������ֵ��󶼴洢�� ret ��

		sum += ret; //sum
	}

	printf("%d\n", sum);
	return 0;
}