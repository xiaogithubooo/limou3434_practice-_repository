#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_STR 11

int main() {
    char strings[MAX_NUM_STR][MAX_STR_LEN];
    int i = 0;

    while (i < MAX_NUM_STR) 
    {
        char* str = gets(strings[i]);//如果超出缓存区就返回NULL
        if (str == NULL || strlen(str) == 0) 
        {
            break;
        }
        i++;
    }
    for (int j = 0; j < i; j++) 
    {
        printf("%s\n", strings[j]);
    }

    return 0;
}

//int main()
//{
//    char* chs = (char*)malloc(sizeof(char) * 500001);
//    if (!chs) exit(-1);
//
//    char ch = 0;
//    int i = 0;
//    int flag = 0;
//    for (i = 0; i < 5000001; i++)
//    {
//        ch = getchar();
//        if (ch != ' ')//没遇到空格
//        {
//            chs[i] = ch;//存入数据
//            flag = 0;
//        }
//
//        if (ch == ' ' && flag != 1)//遇到空格
//        {
//            chs[i] = ch;
//            flag = 1;
//        }
//        else if (flag == 1)
//        {
//            i--;
//        }
//        if (ch == '\n')
//        {
//            break;
//        }
//    }
//    chs[i] = '\0';
//    puts(chs);
//    return 0;
//}

//int main()
//{
//    //1.输入N、U、D
//    int N = 0;//井的长度
//    int U = 0;//每分钟上爬的长度
//    int D = 0;//每次休息的下滑长度
//    scanf("%d %d %d", &N, &U, &D);
//
//    int min = 0;//
//    int i = 0;
//    while (1)
//    {
//        i += U;
//        min++;
//        if (i >= N)
//        {
//            break;
//        }
//        i -= D;
//        min++;
//    }
//    printf("%d", min);
//    return 0;
//}