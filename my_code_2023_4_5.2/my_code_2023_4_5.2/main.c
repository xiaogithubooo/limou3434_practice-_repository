#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct grade
{
    int chinese;
    int math;
};
struct pep
{
    char name[10];//名字
    int age;//年龄
    char sex[5];//性别
    char id[100];//身份证
    struct grade a;
};
int main()
{
    struct pep p = { "limou", 13, "女", "4465667655453625", {100, 120} };
    struct pep* pp = &p;
    printf("%s\n", pp->name);
    printf("%d\n", pp->age);
    printf("%s\n", pp->sex);
    printf("%s\n", pp->id);
    printf("%d\n", pp->a.chinese);
    printf("%d\n", pp->a.math);
    return 0;
}

struct str
{
    int a;
    char b;
    double c;
};