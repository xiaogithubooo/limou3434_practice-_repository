#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Student
{
	char name[20];	//名字
	int age;		//年龄
	char id[15];	//学号
	float score;	//成绩
};

int main()
{
	struct Student s1 = { "张三", 20, "2022010823", 88.5f };
	struct Student s2 = { "翠花", 18, "2022030405", 98.0f};
	printf("%s %d %s %f\n", s1.name, s1.age, s1.id, s1.score);

	struct Student* ps2 = &s2;
	printf("%s %d %s %f\n", (*ps2).name, (*ps2).age, (*ps2).id, (*ps2).score);
	printf("%s %d %s %f\n", ps2->name, ps2->age, ps2->id, ps2->score);
	return 0;
}