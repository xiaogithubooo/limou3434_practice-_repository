#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int pd1(int x)
{
	if (x >= 0 && x <= 100)
	{
		return 1;
	}
	else
		return 0;
}
int pd2(int x, int y)
{
	if (x > y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int grad1, grad2, t1, t2, j;

	printf("������ѧ��1�ĳɼ���");
	scanf("%d", &grad1);
	printf("������ѧ��2�ĳɼ���");
	scanf("%d", &grad2);

	t1 = pd1(grad1);
	t2 = pd1(grad2);
	printf("grad1��[0��100]��Χ�ڣ� %d\n", t1);
	printf("grad2��[0��100]��Χ�ڣ� %d\n", t2);

	j=pd2(grad1, grad2);
	if (j == 1)
	{
		printf("grad1>grad2 ? %d\n",j);
	}
	else
	{
		printf("grad1<grad2 ? %d\n", j);
	}
	return 0;
}