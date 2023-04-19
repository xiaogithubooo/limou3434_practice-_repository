#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	unsigned char ch = -259;
	//-259 = 1000 0000|0000 0000|0000 0001|0000 0011
	//		 1111 1111|1111 1111|1111 1110|1111 1100
	//		 1111 1111|1111 1111|1111 1110|1111 1101
	//ch是unsigned char类型，开辟一个字节空间，存入截断后的数据“1111 1101”
	printf("%u\n", ch);//将数据作为无符号字符型理解：“1111 1101”变成“0000 0000|0000 0000|0000 0000|1111 1101”，转为原码，得到253
	printf("%d\n", ch);//将数据作为有符号字符型理解：“1111 1101”变成“0000 0000|0000 0000|0000 0000|1111 1101”，转为原码，得到253

	unsigned int in = -2;
	//-2  = 1000 0000|0000 0000|0000 0000|0000 0010
	//	    1111 1111|1111 1111|1111 1111|1111 1101
	//	    1111 1111|1111 1111|1111 1111|1111 1110
	//in是unsigned int类型，开辟四个字节空间，存入数据“1111 1111|1111 1111|1111 1111|1111 1110”
	printf("%u\n", in);//将数据作为无符号整型理解：“1111 1111|1111 1111|1111 1111|1111 1110”，转为原码，得到4294967294
	printf("%d\n", in);//将数据作为有符号整型理解：“1111 1111|1111 1111|1111 1111|1111 1110”，转为原码，得到-2
	return 0;
}

//int main()
//{
//    int a, b, c;
//    while (1)
//    {
//        printf("Please input two integers: ");
//        c = scanf("%d%d", &a, &b);
//        if (c != 2)
//        {
//            printf("Input format error, please input two integers.\n");
//            while ((c = getchar()) != '\n' && c != EOF); // 循环读取并忽略非数字字符
//            continue; // 继续等待用户输入
//        }
//        printf("You have input two integers: %d and %d.\n", a, b);
//        break; // 跳出循环
//    }
//    return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	while (1)
//	{
//		int c = scanf("%d %d", &a, &b);//读取失败，返回成读取的值，若是没有读取并且失败返回0，并且未读取的值放在缓冲区
//		if (c == 0) getchar();
//		printf("%d\n", c);
//		Sleep(1000);
//	}
//	return 0;
//}