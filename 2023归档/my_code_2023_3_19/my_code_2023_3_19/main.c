#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct
{
    char name[10];//����
    int age;//����
    int idnumber;//���֤
}a;
struct
{
    char name[10];//����
    int age;//����
    int idnumber;//���֤

}*p;
struct Node
{
    int data;
    struct Node next;
}a;
//����һ����
typedef struct people
{
    char name[10];//����
    int age;//����
    int idnumber;//���֤
}people;

int main()
{
    people a = { "limou3434", 30, 44443333 };
    printf("%s %d %d\n", a.name, a.age, a.idnumber);
    people b = { .age = 20, .idnumber = 1234567890, .name = "limou" };
    printf("%s %d %d\n", b.name, b.age, b.idnumber);
	return 0;
}
#include <stdio.h>
#include <stddef.h>
typedef struct people
{
    char name[10];//����
    int age;//����
    int idnumber;//���֤
}people;
int main()
{
    people s = { "limou", 12, 88888888 };
    printf("%zd %zd %zd", offsetof(people, name), offsetof(people, age), offsetof(people, idnumber));
}
struct S
{
	char c;
	int a;
};
int main()
{
	struct S s = { 0 };
	printf("%zd\n", offsetof(struct S, c));
	printf("%zd\n", offsetof(struct S, a));
	return 0;
}
enum Color//��ɫ
{
    RED,
    YELLOW,
    GREEN = 6,
    BLUE
};
int main()
{
    printf("%d %d %d %d\n", RED, YELLOW, GREEN, BLUE);
}