#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////1�����龲̬�����ӱ���
//void trystat(void)
//{
//    int fade = 1;
//    static int stay = 1;
//
//    printf("fade = %d and stay = %d\n", fade++, stay++);
//}
//int main()
//{
//    int count;
//    for (count = 1; count <= 3; count++)
//    {
//        printf("Here comes iteration %d:\n", count);
//        trystat();
//    }
//    return 0;
//}
////2����ʼ����̬�����ӱ���
//int main()
//{
//	int c = 200;
//	int d = 300;
//	static int a = 100;
//	static int b;
//	printf("%d %d", a, b);
//	return 0;
//}
////3����̬�ⲿ�������
//int main()
//{
//	extern int a;
//	printf("%d", a);
//
//	{
//		extern int a;
//		printf("%d\n", a);
//	}
//		return 0;
//}
//int x = 10;
//int y = 10 * x;
//
//int Errupt = 200;//�ڱ��ļ����ⲿ����
//double Up[100] = { 1.2, 2,0, 3.7};//�ڱ��ļ����ⲿ��������
//
//extern char Coal;//�������ļ����ⲿ����
//extern char arr[];//�������ļ����ⲿ��������
//
//void next(void)
//{
//	//����
//}
//int main()
//{
//	extern int Errupt;//��д�ɲ�д
//	printf("%d", Errupt);
//	extern double Up[];//��д�ɲ�д
//
//	//ʹ��Errupt��Up�Ĵ���
//
//	//ʹ��Coal��arr�Ĵ���
//
//	return 0;
//}
//int main()
//{
//	extern int a = 200;
//	a = 200;
//}
//int a = 1;
//static int b = 2;
//int main()
//{
//	printf("%d %d\n", a, b);
//	{
//		extern int a;
//		extern int b;
//		printf("%d %d", a, b);
//	}
//	return 0;
//}