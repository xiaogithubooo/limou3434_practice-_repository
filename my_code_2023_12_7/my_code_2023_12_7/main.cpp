#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Student
{
	char name[20];	//����
	int age;		//����
	char id[15];	//ѧ��
	float score;	//�ɼ�
};

int main()
{
	struct Student s1 = { "����", 20, "2022010823", 88.5f };
	struct Student s2 = { "�仨", 18, "2022030405", 98.0f};
	printf("%s %d %s %f\n", s1.name, s1.age, s1.id, s1.score);

	struct Student* ps2 = &s2;
	printf("%s %d %s %f\n", (*ps2).name, (*ps2).age, (*ps2).id, (*ps2).score);
	printf("%s %d %s %f\n", ps2->name, ps2->age, ps2->id, ps2->score);
	return 0;
}