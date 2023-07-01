#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct PeopleData
{
    char name[11];
    char yearMonthDay[11];
    char sex;
    char number1[16];
    char number2[16];
}PeopleData;
int main()
{
    //1.输入通讯录数据
    int N = 0;
    int scanfReturn = scanf("%d", &N);
    PeopleData* arr1 = (PeopleData*)malloc(sizeof(PeopleData) * N);
    if (!arr1) exit(-1);
    for (int z = 0; z < N; z++)
    {
        scanfReturn = scanf("%s %s %c %s %s",
            &arr1[z].name,
            &arr1[z].yearMonthDay,
            &arr1[z].sex,
            &arr1[z].number1, &arr1[z].number2);
    }
    //2.输入查看的数据
    int K;//查看K次
    scanfReturn = scanf("%d", &K);
    int* arr2 = (int*)malloc(sizeof(int) * K);
    if (!arr2) exit(-1);
    for (int i = 0; i < K; i++)
    {
        scanfReturn = scanf("%d", &arr2[i]);
    }
    //3.输出查看的数据
    for (int j = 0; j < K; j++)
    {
        if (arr2[j] <= N && arr2[j] > 0)
        {
            printf("%s %s %s %c %s\n",
                arr1[arr2[j]].name,
                arr1[arr2[j]].number1, arr1[arr2[j]].number2,
                arr1[arr2[j]].sex,
                arr1[arr2[j]].yearMonthDay);
        }
        else
        {
            printf("Not Found\n");
        }
    }
    free(arr1);
    free(arr2);
    return 0;
}