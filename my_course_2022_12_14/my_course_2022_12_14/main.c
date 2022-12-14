#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define PI 3.1415926
//牛客网刷题
//1、球体提及的计算
//int amin()
//{
//	float r = 0.0f;
//	scanf("%f", &r);
//	printf("%f", (4 * PI * (r * r * r) / 3));
//	return 0;
//}

//2、转换大小写字母
//int main()
//{
//    char a = 0, b = 0;
//    scanf("%c", &a);
//    getchar();
//    scanf("%c", &b);
//    if ((a >= 65) && (a <= (65 + 26)))
//    {
//        a = a + 32;
//        printf("%c\n", a);
//    }
//    if ((b >= 65) &&( b <= (65 + 26)))
//    {
//        b = b + 32;
//        printf("%c\n", b);
//    }
//    return 0;
//}//注意A是65，a是97

//int main()
//{
//    char ch;
//    while ((ch = getchar()) != EOF) {
//        if (ch >= 'A' && ch <= 'Z') {
//            ch += 32;
//        }
//        putchar(ch);
//    }
//}