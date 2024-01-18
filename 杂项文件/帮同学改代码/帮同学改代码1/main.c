#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//同学错误的代码
//int main()
//{
//
//    double results[10];
//    int i;
//    double max = 0, min = 100, sum = 0, average;
//    printf("成绩登记：\n");
//    for (i = 0; i < 10; i++)
//    {
//        printf("请输入第%d个学生的成绩：", i + 1);
//        scanf("%Lf,&results[i]");
//        if (max < results[i])
//            max = results[i];
//        if (min > results[i])
//            min = results[i];
//        sum += results[i];
//    }
//    average = sum / 10;
//    printf("统计如下：\n");
//    printf("所有学生中最高分为：%Lf\n", max);
//    printf("所有学生中最低分为：%Lf\n", min);
//    printf("所有学生的平均分为：%Lf\n", average);
//    return 0;
//}
//代码修改后
int main()
{

    double results[10];//1、没有写注释，例如，这里可以写“数组存放学生成绩”，注释可以帮助未来的自己看懂代码或者别人快速看懂代码，不会出现别人看不懂，甚至自己都读不懂的尴尬情况
    int i;
    double max = 0, min = 100, sum = 0, average;
    printf("成绩登记：\n");
    for (i = 0; i < 10; i++)
    {
        printf("请输入第%d个学生的成绩：", i + 1);
        scanf("%Lf",&results[i]);//2、这个双引号放错位置了！！！
        if (max < results[i])
        {
            max = results[i];//3、注意最好写上代码块，避免使用分支语句的时候出现逻辑混乱，也有利于后期代码的维护
        }
        if (min > results[i])
        {
            min = results[i];
        }
        sum += results[i];
    }
    average = sum / 10;
    printf("统计如下：\n");
    printf("所有学生中最高分为：%Lf\n", max);
    printf("所有学生中最低分为：%Lf\n", min);
    printf("所有学生的平均分为：%Lf\n", average);
    return 0;
}