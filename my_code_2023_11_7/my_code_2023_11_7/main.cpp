#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
int main()
{
	float grade1, grade2, grade3;
	float sum;
	printf("�����һ��ѧ�������ųɼ�(�ÿո�ָ�):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("��һ��ѧ�����ܳɼ�=%f\n", sum);

	printf("����ڶ���ѧ�������ųɼ�(�ö��ŷָ�):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("�ڶ���ѧ�����ܳɼ�=%f\n", sum);

	printf("���������ѧ�������ųɼ�(��ð�ŷָ�):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("������ѧ�����ܳɼ�=%f\n", sum);
	return 0;
}