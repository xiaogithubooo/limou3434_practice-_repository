#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
//1、scanf的输入符号问题研究
//int main()
//{
//	float x = 0.0;
//	scanf("%.2f", &x);//这种代码是错误的，不会舍位输入
//	printf("%f", x);
//	return 0;
//}

//2、牛客网一道简单的题目“KIKI算期末成绩”
//int main()
//{
//    float a, b, c, d;
//    scanf("%f %f %f %f", &a, &b, &c, &d);
//    printf("%.1f", (a * 0.2) + (b * 0.1) + (c * 0.2) + (d * 0.5));
//
//    return 0;
//}

//3、牛客网题目“KIKI的最高分”
//int a, b, c;
//int t = 0;
//int main()
//{
//    scanf("%d %d %d", &a, &b, &c);
//    if (a > b)
//    {
//        t = a;
//        if (t > c)
//        {
//            printf("%d", t);
//        }
//        else
//        {
//            printf("%d", c);
//        }
//    }
//    else
//    {
//        t = b;
//        if (t > c)
//        {
//            printf("%d", t);
//        }
//        else
//        {
//            printf("%d", c);
//        }
//    }
//    return 0;
//}

//4、牛客网题目“井字棋”判断函数
//int my_judge(char t, char(*arr)[3])//注意这里的二维数组传参，不可以写成char* a，这样写是错误的，应该复习二维数组的传参
//{
//
//	//判断输赢***************************************************************
//	int i = 0;//循环数
//	for (i = 0; i < 3; i++)//赢在横线上
//	{
//		if (  (arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2]) && (arr[i][0]==t)  )
//		{
//			return 1;
//		}
//	}
//	for (i = 0; i < 3; i++)//赢在竖线上
//	{
//		if (  (arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i]) && (arr[0][i] == t)  )
//		{
//			return 1;
//		}
//	}
//	if (  (arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && (arr[0][0] == t)  )//赢在左斜线上
//	{
//		return 1;
//	}
//	else if (   (arr[0][2] == arr[1][1]) && (arr[0][2] ==arr[2][0]) && (arr[0][2] == t)  )//赢在右斜线上
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}//赢了返回1，输了返回0
//
//
//int main()
//{
//	int x = 0;//数组遍历的行数
//	int y = 0;//数组遍历的列数
//	char arr[3][3] = { '0' };//创建一个数组
//	for (x = 0; x < 3; x++)//输入数据过程
//	{
//		for (y = 0; y < 3; y++)
//		{
//			scanf("%c", &(arr[x][y]));
//			getchar();//输入这里也要注意一下
//		}
//	}
//
//	int K = my_judge('K',arr);//存储结果
//	int B = my_judge('B',arr);//存储结果
//
//	if (K == B)//都赢（1）或者都输（0）
//	{
//		printf("No winner!\n");
//	}
//	else if (K > B)
//	{
//		printf("KiKi wins!\n");
//	}
//	else if (K < B)
//	{
//		printf("BoBo wins!\n");
//	}
//
//	return 0;
//}

//5、一个错误纠正，误认为scanf会跳过空格
//int main()
//{
//	char a = 0;
//	scanf("%c", &a);
//	printf("%d", a);
//	//可以看到正好输出32，就是空格的ASCII码值
//	//至少说明在字符类型中空格是可以被保存的
//}

//6、KiKi定义电子日历类
//typedef struct TDate
//{
//    int Month;
//    int Day;
//    int Year;
//}TDate;
//
//
//int main()
//{
//    TDate x;
//    x.Month = 0;
//    x.Day = 0;
//    x.Year = 0;
//    scanf("%d %d %d", &x.Year, &x.Month, &x.Day);
//    printf("%d/%d/%d", x.Day, x.Month, x.Year);
//    return 0;
//}

//7、序列重组矩阵
//int main()
//{
//    int n = 0, m = 0;
//    int t = 0;
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d ", &t);
//            printf("%d ", t);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//8、统计成绩
//int main()
//{
//    int n = 0;
//    double t = 0;
//    double max = 0;
//    double min = 100.0;
//    double add = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%lf", &t);
//        max = max > t ? max : t;
//        min = min < t ? min : t;
//        add += t;
//    }
//    printf("%.2lf %.2lf %.2lf", max, min, add / n);
//}