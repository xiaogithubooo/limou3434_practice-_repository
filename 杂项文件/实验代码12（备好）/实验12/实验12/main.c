#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
//ʵ��Ŀ�ģ�
//��1������ö���������͵ĸ����ʹ�÷���
//��2���������սṹ���������͵ĸ����ʹ�÷���
//��3�����սṹ����ָ��Ļ��Ӧ�÷���
//��4�����սṹ����Ϊ���������ķ���

//����һ
//typedef
//enum 
//{
//	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday = 7    //ö�����ʹ�ã��α��и��ط���ӡ���ˡ������ں���ӡ�����
//}Weekday;
//
//int main(void)
//{
//	Weekday weekday;
//	printf("�����뵱ǰ�����գ�1-7����");
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
//		printf("�����뵱ǰ�����գ�1-7����");
//		scanf("%d", &weekday);
//	}
//		printf("����Ĺ�����%d������ȷ��Χ�ڣ�1-7��\n",weekday);
//	return 0;
//}
//�������
//typedef
//struct
//{
//	char Name[10];                 //�ṹ���ڲ�����������Ҫ����Ԫ�ظ���������
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
//		printf("%s��%s�����\n", per1.Name, per2.Name);      //�ַ��������Ͳ��ᱻprintf����scanf�����ո����������
//	}
//	else
//	{
//		printf("%s��%s�����\n", per2.Name, per1.Name);
//	}
//	printf("Person��%s�ĸ�����ϢΪ��\n", per1.Name);
//	printf("         Name��%s\n", per1.Name);	
//	printf("         Sex��%c\n", per1.Sex);
//	printf("         Age��%u\n", per1.Age);
//	printf("Person��%s�ĸ�����ϢΪ��\n", per2.Name);
//	printf("         Name��%s\n", per2.Name);
//	printf("         Sex��%c\n", per2.Sex);
//	printf("         Age��%u\n", per2.Age);
//
//	printf("So Easy!");
//	return 0;
//}

//��������
///////////////////////////////////////////////////////////////////////////
typedef
struct Person//�˵���Ϣ�ṹ��
{
	char name[30];
	char sex;
	int age;
}person;
void personInput(person* pPerson1)//ΪPerson��ֵ��������ָ����ʽ
{
	printf("������������");
	scanf("%s", pPerson1->name);//�α��������Ӧ����һ��������Ԫ�ص�ַ
	getchar();
	printf("�������Ա�");
	scanf("%c", &(pPerson1->sex));//ע��->ǰ��ֻ��ָ��
	printf("���������䣺");
	scanf("%u", &(pPerson1->age));//ע��->ǰ��ֻ��ָ�룬u���޷���ʮ��������
}
void personOutput(person* pPerson1)//ΪPerson�����������ָ����ʽ
{
	printf("Person��%s�ĸ�����ϢΪ��\n", pPerson1->name);
	printf("\t Name��%s\n", pPerson1->name);
	printf("\t Sex ��%c\n", pPerson1->sex);
	printf("\t Afe ��%u\n", pPerson1->age);
}
///////////////////////////////////////////////////////////////////////////
typedef
struct Grade//�ɼ��ṹ��
{
	float math;//��ѧ�ɼ�,ע�ⶼ�Ǹ�����
	float english;//Ӣ��ɼ�
	float chinese;//���ĳɼ�
	float average_score;//ƽ���ֳɼ�
}grade;
void gradeInput(grade* pGrade2)//ΪGrade��ֵ��������ָ����ʽ
{
	printf("��������ѧ�ɼ���");
	scanf("%f", &(pGrade2->math));//���Ҳ�Ǹ�����
	printf("������Ӣ��ɼ���");
	scanf("%f", &(pGrade2->english));
	printf("���������ĳɼ���");
	scanf("%f", &(pGrade2->chinese));
	(pGrade2->average_score) = ((pGrade2->math) + (pGrade2->english) + (pGrade2->chinese)) / 3;//��ƽ��ֵ
}
void gradeOutput(grade* pGrade2)//ΪGrade�����������ָ����ʽ
{
	printf("\t��ѧ��%f\n", pGrade2->math);
	printf("\tӢ�%f\n", pGrade2->english);
	printf("\t���ģ�%f\n", pGrade2->chinese);
	printf("\tƽ����%f\n", pGrade2->average_score);
}
///////////////////////////////////////////////////////////////////////////
typedef
struct Student//ѧ���ṹ�壨��������������ṹ�壩
{
	person person;//��һ���ṹ��
	long student_Num;//ѧ��
	grade grade;//�ڶ����ṹ��
}student;
void studentInput(student* pStudent3)
{
	person* x = &(pStudent3->person);
	grade* y = &(pStudent3->grade);
	personInput(x);//����Person��Grade�ĸ�ֵ
	printf("������ѧ�ţ�");
	scanf("%ld", &(pStudent3->student_Num));
	gradeInput(y);//��ֵ
}
void studentOutput(student* pStudent3)
{
	person* x = &(pStudent3->person);
	grade* y = &(pStudent3->grade);
	personOutput(x);//����Person���
	printf("\tѧ�ţ�%ld\n", pStudent3->student_Num);
	gradeOutput(y);//����Grade�����
}
///////////////////////////////////////////////////////////////////////////
int main(void)//���������в���
{
	student stu1;
	student stu2;
	//float pj1 = 0;
	//float pj2 = 0;ƽ�����Ƚϡ���δ���
	printf("������ѧ��������");
	studentInput(&stu1);
	printf("������ѧ��������");
	studentInput(&stu2);
	if (stu1.grade.average_score > stu2.grade.average_score)
	{
		printf("%s��%s��ƽ���ɼ���\n", stu1.person.name, stu2.person.name);
	}
	else
	{
		printf("%s��%s��ƽ���ɼ���\n", stu1.person.name, stu2.person.name);
	}
	studentOutput(&stu1);
	printf("\n\n");
	studentOutput(&stu2);
	printf("\n");
	printf("So Easy!");
	return 0;
}