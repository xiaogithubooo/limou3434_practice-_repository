#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//最长字符串，最小N，N是指行数
//最大N，反复查询同一数据
/*
输入格式：
输入在第一行给出正整数N（≤10）；
随后N行，每行按照格式姓名 生日 性别 固话 手机给出一条记录。其中姓名是不超过10个字符、不包含空格的非空字符串；
生日按yyyy/mm/dd的格式给出年月日；性别用M表示“男”、F表示“女”；
固话和手机均为不超过15位的连续数字，前面有可能出现+。
在通讯录记录输入完成后，最后一行给出正整数K，并且随后给出K个整数，表示要查询的记录编号（从0到N−1顺序编号）。
数字间以空格分隔。

输出格式：
对每一条要查询的记录编号，在一行中按照“姓名 固话 手机 性别 生日”的格式输出该记录。
若要查询的记录不存在，则输出“Not Found”。
*/
typedef struct PeopleData
{
    char name[11];//姓名不超过10个字符、不包含空格的非空字符串
    char yearMonthDay[11];//生日按yyyy/mm/dd的格式给出年月日
    char sex;//性别用M表示“男”、F表示“女”
    char number1[16];//固话为不超过15位的连续数字，前面有可能出现+
    char number2[16];//手机为不超过15位的连续数字，前面有可能出现+
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
            arr1[z].name,
            arr1[z].yearMonthDay,
            &arr1[z].sex,
            arr1[z].number1, arr1[z].number2);
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
        if (arr2[j] < N && arr2[j] >= 0)
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