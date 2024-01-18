#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //1.存储字符串
    int N;
    int K;
    int scanfReturn = scanf("%d %d", &N, &K);
    char** str_arr = (char**)malloc(N * sizeof(char*));
    if (str_arr == NULL) 
    {
        printf("内存分配失败！");
        exit(-1);
    }
    for (int i = 0; i < N; i++) 
    {
        char buffer[10];
        scanfReturn = scanf("%s", buffer);
        str_arr[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (str_arr[i] == NULL) 
        {
            printf("内存分配失败！");
            exit(-1);
        }
        strcpy(str_arr[i], buffer);
    }
    //2.排序现有字符串
    for (int j = 0; j < K; j++)
    {
        for (int i = 1; i < N - j; i++)
        {
            if (*str_arr[i - 1] > *str_arr[i])
            {
                char str_x[10];
                strcpy(str_x, str_arr[i - 1]);
                strcpy(str_arr[i - 1], str_arr[i]);
                strcpy(str_arr[i], str_x);
            }
        }
    }

    //3.打印检验结果
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", str_arr[i]);
    }

    ////4.释放内存
    //for (int i = 0; i < N; i++)
    //{
    //    free(str_arr[i]);
    //}
    //free(str_arr);

    return 0;
}
