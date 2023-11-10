#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int grad1 = 0;//声明第1个学生的成绩grad1
	int grad2 = 0;//声明第2个学生的成绩grad2
	
	printf("输入第1个学生的成绩：");//提示输入第1个学生的成绩
	scanf("%d", &grad1);//从键盘输入第1个学生成绩
	
	printf("输入第2个学生的成绩：");//提示输入第2个学生的成绩
	scanf("%d", &grad2);//从键盘输入第2个学生成绩

	if(grad1 >= 0 && grad1 <= 100)//判断grad1是否在[0,100]范围内
	{
		printf("grad1在[0,100]范围内\n");
	}
	else
	{
		printf("grad1不在[0,100]范围内\n");
	}

	if (grad2 >= 0 && grad2 <= 100)//判断grad2是否在[0,100]范围内
	{
		printf("grad2在[0,100]范围内\n");
	}
	else
	{
		printf("grad2不在[0,100]范围内\n");
	}

	//判断grad1和grad2的关系
	if (grad1 == grad2)
	{
		printf("两学生成绩相等\n");
	}
	else if (grad1 > grad2)
	{
		printf("学生1成绩大于学生2成绩\n");
	}
	else //grad1 < grad2
	{
		printf("学生1成绩小于学生2成绩\n");
	}
	return 0;
}