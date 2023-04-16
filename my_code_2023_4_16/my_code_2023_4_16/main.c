#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//    int i = 0;
//    char ch = 0;
//    int len = 0;
//    while (scanf("%c", &ch) == 1)
//    {
//        if (i != 0 && len == 1)
//        {
//            printf(" ");
//            len = 0;
//        }
//        if (ch != ' ' && ch != '.')
//        {
//            i++;
//        }
//        else//读到空格
//        {
//            if (i == 0) continue;
//            printf("%d", i);
//            i = 0;
//            len = 1;
//        }
//    }
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
typedef struct pep
{
    char name[10];//人名
    char birthday[10];//生日
    char sex;//性别
    char number1[16];
    char number2[16];
}pep;
int main()
{
    int N = 0;
    scanf("%d", &N);
    pep* p = (pep*)malloc(sizeof(pep) * N);
    if (!p) exit(-1);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", p[i].name);
        getchar();
        scanf("%s", p[i].birthday);
        getchar();
        scanf("%c", &p[i].sex);
        getchar();
        scanf("%s", p[i].number1);
        getchar();
        scanf("%s", p[i].number2);
        getchar();
    }
    int K = 0;//次数
    int number = 0;
    scanf("%d", &K);
    while (K)
    {
        scanf("%d", &number);
        if (number < N)
        {
            printf("%s ", p[number].name);
            printf("%s ", p[number].birthday);
            printf("%c ", p[number].sex);
            printf("%s ", p[number].number1);
            printf("%s", p[number].number2);
            K--;
        }
        else
        {
            printf("Not Found\n");
        }
    }
    return 0;
}