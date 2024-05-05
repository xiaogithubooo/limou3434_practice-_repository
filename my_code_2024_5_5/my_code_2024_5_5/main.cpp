#define _CRT_SECURE_NO_WARNINGS
//有清理缓冲区
#include <stdio.h>

void Empty(void)
{
    char ch = 0;
    do
    {
        ch = getchar();
    } while (ch != '\n'); //在控制台中 scanf() 输入结束后最后一次输入一定是换行符, 因此不用考虑其他空白字符, 除了 '\n' 其它滞留在缓冲区中的字符都会陷入循环而被读走, 避免以下后续输入
    //} while (ch != EOF); //但是如果是文件读取(这个就涉及到文件 IO 的知识了, 以后我再来带您重新回顾这个知识), 就需要一直读到文件结尾, 其他滞留在输入缓冲区中的字符都会陷入循环而被读走, 避免以下后续输入
}

int main()
{
    char ch = 0;
    printf("请输入一个字符: ");
    scanf("%c", &ch);

    printf("请确认输入(Y/N): ");
    Empty(); //调用函数来清理缓冲区
    char flag = getchar();

    if ('Y' == flag)
    {
        printf("确认成功\n");
    }
    else
    {
        printf("确认失败\n");
    }

    return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
////未清理缓冲区
//#include <stdio.h>
//
//int main()
//{
//    char ch = 0;
//    printf("请输入一个字符: ");
//    scanf("%c", &ch); //输入非空白字符后输入 \n 
//    printf("请确认输入(Y/N): ");
//    char flag = getchar();
//
//    if ('\n' == flag)
//    {
//        printf("意外读取到'\\n'\n");
//    }
//    else if ('\t' == flag)
//    {
//        printf("意外读取到'\\t'\n");
//    }
//    else if (' ' == flag)
//    {
//        printf("意外读取到' '\n");
//    }
//
//    if ('Y' == flag)
//    {
//        printf("确认成功\n");
//    }
//    else
//    {
//        printf("确认失败\n");
//    }
//    return 0;
//}
//
////#define _CRT_SECURE_NO_WARNINGS
////
//////求解两个数的最小公倍数和最大公因数
////#include <stdio.h>
////
//////计算最大公因数
////int FindGCD(int num1, int num2) //算法可以保证 num1 在计算过程中为较大值
////{
////    while (num2 != 0) //使用辗转相除法来计算
////    {
////        int temp    = num2;         //缓存
////        num2        = num1 % num2;  //计算边
////        num1        = temp;         //计算边
////    }
////    return num1;
////}
////
//////计算最小公倍数
////int FindLCM(int num1, int num2)
////{
////    return (num1 * num2) / FindGCD(num1, num2); //利用 LCM 和 GCD 的关系来通过最大公因数计算最小公倍数
////}
////
////int main()
////{
////    int num1 = 0, num2 = 0;
////
////    //从用户输入获取两个数
////    printf("请输入两个正整数: ");
////    scanf("%d %d", &num1, &num2);
////
////    //求出最小公倍数和最大公约数
////    printf("最小公倍数是: %d\n", FindLCM(num1, num2));
////    printf("最大公因数是: %d\n", FindGCD(num1, num2));
////    return 0;
////}
////
//////int Min(int num1, int num2)
//////{
//////    if (num1 >= num2)
//////    {
//////        return num2;
//////    }
//////    else //num1 < num2
//////    {
//////        return num1;
//////    }
//////}
//////
//////int FindGCD(int num1, int num2)
//////{
//////    int minNum = Min(num1, num2);
//////    for (int target = minNum; target >= 1; target--)
//////    {
//////        if (num1 % target == 0 && num2 % target == 0)
//////            return target;
//////    }
//////    return -1; //尽管这个 return -1 不太可能会被执行, 但是我为了编译器不进行警告, 还是加了这个返回 -1 就表示出错的返回值
//////}
//////
//////int main()
//////{
//////    int num1 = 0, num2 = 0;
//////
//////    //从用户输入获取两个数
//////    printf("请输入两个正整数: ");
//////    scanf("%d %d", &num1, &num2);
//////
//////    //调用函数找到最小公倍数并打印结果
//////    printf("最大公约数是: %d\n", FindGCD(num1, num2));
//////
//////    return 0;
//////}
////
////
