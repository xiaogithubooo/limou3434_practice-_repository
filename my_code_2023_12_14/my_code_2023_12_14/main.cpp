#include "am_graph.hpp"

int main()
{
	limou::TestAMGraph();

	limou::TestAMGraphBFS();
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>

//int main()
//{
//    double input; //存储数据
//    int rounded; //转化后结果
//    int flag = 0; //符号标志
//
//    while (1)
//    {
//        printf("请输入一个浮点数：");
//        scanf("%lf", &input); //读取浮点数输入
//
//        flag = input >= 0 ? 1 : -1;
//        rounded = (int)(fabs(input) + 0.5); //进行四舍五入
//        printf("四舍五入后为：%d\n", flag * rounded); //输出
//    }
//
//    return 0;
//}