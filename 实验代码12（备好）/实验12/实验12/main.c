#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//实验目的：
//（1）掌握枚举数据类型的概念和使用方法
//（2）熟练掌握结构体数据类型的概念和使用方法
//（3）掌握结构体与指针的混合应用方法
//（4）掌握结构体作为函数参数的方法

//任务一
//typedef
//enum 
//{
//	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday = 7    //枚举体的使用，课本有个地方打印做了…不能在后面加“；”
//}Weekday;
//
//int main(void)
//{
//	Weekday weekday;
//	printf("请输入当前工作日（1-7）：");
//	scanf("%d", &weekday);
//	while (weekday >= 1 && weekday <= 7)
//	{
//		switch (weekday)
//		{
//		case 1:
//			printf("Monday\n");
//			break;
//		case 2:
//			printf("Tuesday\n");
//			break;
//		case 3:
//			printf("Wednesday\n");
//			break;
//		case 4:
//			printf("Thursday\n");
//			break;
//		case 5:
//			printf("Friday\n");
//			break;
//		case 6:
//			printf("Saturday\n");
//			break;
//		case 7:
//			printf("Sunday\n");
//			break;
//		}
//		printf("请输入当前工作日（1-7）：");
//		scanf("%d", &weekday);
//	}
//		printf("输入的工作日%d不在正确范围内（1-7）\n",weekday);
//	return 0;
//}
//任务二：
//typedef
//struct
//{
//	char Name[10];                 //结构体内部数组好像必须要输入元素个数？？？
//	char Sex;
//	unsigned int Age;
//}Person;
//
//int main(void)
//{
//	Person per1 = { "Person 1",'F',30 };
//	Person per2 = { "Person 2",'M',20 };
//
//	if (per1.Age < per2.Age)
//	{
//		printf("%s比%s年龄大\n", per1.Name, per2.Name);      //字符用数组存就不会被printf或则scanf遇到空格结束？？？
//	}
//	else
//	{
//		printf("%s比%s年龄大\n", per2.Name, per1.Name);
//	}
//	printf("Person：%s的个人信息为：\n", per1.Name);
//	printf("         Name：%s\n", per1.Name);	
//	printf("         Sex：%c\n", per1.Sex);
//	printf("         Age：%u\n", per1.Age);
//	printf("Person：%s的个人信息为：\n", per2.Name);
//	printf("         Name：%s\n", per2.Name);
//	printf("         Sex：%c\n", per2.Sex);
//	printf("         Age：%u\n", per2.Age);
//
//	printf("So Easy!");
//	return 0;
//}

//任务三：
///////////////////////////////////////////////////////////////////////////
typedef
struct Person//人的信息结构体
{
	char name[30];
	char sex;
	int age;
}person;
void personInput(person* pPerson1)//为Person赋值函数，以指针形式
{
	printf("请输入姓名：");
	scanf("%s", pPerson1->name);//课本这里给的应该是一个数组首元素地址
	getchar();
	printf("请输入性别：");
	scanf("%c", &(pPerson1->sex));//注意->前面只能指针
	printf("请输入年龄：");
	scanf("%u", &(pPerson1->age));//注意->前面只能指针，u是无符号十进制输入
}
void personOutput(person* pPerson1)//为Person输出函数，以指针形式
{
	printf("Person：%s的个人信息为：\n", pPerson1->name);
	printf("\t Name：%s\n", pPerson1->name);
	printf("\t Sex ：%c\n", pPerson1->sex);
	printf("\t Afe ：%u\n", pPerson1->age);
}
///////////////////////////////////////////////////////////////////////////
typedef
struct Grade//成绩结构体
{
	float math;//数学成绩,注意都是浮点型
	float english;//英语成绩
	float chinese;//语文成绩
	float average_score;//平均分成绩
}grade;
void gradeInput(grade* pGrade2)//为Grade赋值函数，以指针形式
{
	printf("请输入数学成绩：");
	scanf("%f", &(pGrade2->math));//输出也是浮点型
	printf("请输入英语成绩：");
	scanf("%f", &(pGrade2->english));
	printf("请输入语文成绩：");
	scanf("%f", &(pGrade2->chinese));
	(pGrade2->average_score) = ((pGrade2->math) + (pGrade2->english) + (pGrade2->chinese)) / 3;//求平均值
}
void gradeOutput(grade* pGrade2)//为Grade输出函数，以指针形式
{
	printf("\t数学：%f\n", pGrade2->math);
	printf("\t英语：%f\n", pGrade2->english);
	printf("\t语文：%f\n", pGrade2->chinese);
	printf("\t平均：%f\n", pGrade2->average_score);
}
///////////////////////////////////////////////////////////////////////////
typedef
struct Student//学生结构体（包含上面的两个结构体）
{
	person person;//第一个结构体
	long student_Num;//学号
	grade grade;//第二个结构体
}student;
void studentInput(student* pStudent3)
{
	person* x = &(pStudent3->person);
	grade* y = &(pStudent3->grade);
	personInput(x);//调用Person、Grade的赋值
	printf("请输入学号：");
	scanf("%ld", &(pStudent3->student_Num));
	gradeInput(y);//赋值
}
void studentOutput(student* pStudent3)
{
	person* x = &(pStudent3->person);
	grade* y = &(pStudent3->grade);
	personOutput(x);//调用Person输出
	printf("\t学号：%ld\n", pStudent3->student_Num);
	gradeOutput(y);//调用Grade的输出
}
///////////////////////////////////////////////////////////////////////////
int main(void)//主函数运行部分
{
	student stu1;
	student stu2;
	//float pj1 = 0;
	//float pj2 = 0;平均数比较……未完成
	printf("请输入学生姓名：");
	studentInput(&stu1);
	printf("请输入学生姓名：");
	studentInput(&stu2);
	if (stu1.grade.average_score > stu2.grade.average_score)
	{
		printf("%s比%s的平均成绩高\n", stu1.person.name, stu2.person.name);
	}
	else
	{
		printf("%s比%s的平均成绩低\n", stu1.person.name, stu2.person.name);
	}
	studentOutput(&stu1);
	printf("\n\n");
	studentOutput(&stu2);
	printf("\n");
	printf("So Easy!");
	return 0;
}