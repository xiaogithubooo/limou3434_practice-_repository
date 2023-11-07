#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
int main()
{
	float grade1, grade2, grade3;
	float sum;
	printf("输入第一个学生的三门成绩(用空格分隔):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("第一个学生的总成绩=%f\n", sum);

	printf("输入第二个学生的三门成绩(用逗号分隔):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("第二个学生的总成绩=%f\n", sum);

	printf("输入第三个学生的三门成绩(用冒号分隔):\n");
	scanf("%f %f %f", &grade1, &grade2, &grade3);
	getchar();
	sum = grade1 + grade2 + grade3;
	printf("第三个学生的总成绩=%f\n", sum);
	return 0;
}