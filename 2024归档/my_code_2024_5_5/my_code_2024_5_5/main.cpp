#define _CRT_SECURE_NO_WARNINGS
//����������
#include <stdio.h>

void Empty(void)
{
    char ch = 0;
    do
    {
        ch = getchar();
    } while (ch != '\n'); //�ڿ���̨�� scanf() ������������һ������һ���ǻ��з�, ��˲��ÿ��������հ��ַ�, ���� '\n' ���������ڻ������е��ַ���������ѭ����������, �������º�������
    //} while (ch != EOF); //����������ļ���ȡ(������漰���ļ� IO ��֪ʶ��, �Ժ��������������»ع����֪ʶ), ����Ҫһֱ�����ļ���β, �������������뻺�����е��ַ���������ѭ����������, �������º�������
}

int main()
{
    char ch = 0;
    printf("������һ���ַ�: ");
    scanf("%c", &ch);

    printf("��ȷ������(Y/N): ");
    Empty(); //���ú�������������
    char flag = getchar();

    if ('Y' == flag)
    {
        printf("ȷ�ϳɹ�\n");
    }
    else
    {
        printf("ȷ��ʧ��\n");
    }

    return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
////δ��������
//#include <stdio.h>
//
//int main()
//{
//    char ch = 0;
//    printf("������һ���ַ�: ");
//    scanf("%c", &ch); //����ǿհ��ַ������� \n 
//    printf("��ȷ������(Y/N): ");
//    char flag = getchar();
//
//    if ('\n' == flag)
//    {
//        printf("�����ȡ��'\\n'\n");
//    }
//    else if ('\t' == flag)
//    {
//        printf("�����ȡ��'\\t'\n");
//    }
//    else if (' ' == flag)
//    {
//        printf("�����ȡ��' '\n");
//    }
//
//    if ('Y' == flag)
//    {
//        printf("ȷ�ϳɹ�\n");
//    }
//    else
//    {
//        printf("ȷ��ʧ��\n");
//    }
//    return 0;
//}
//
////#define _CRT_SECURE_NO_WARNINGS
////
//////�������������С���������������
////#include <stdio.h>
////
//////�����������
////int FindGCD(int num1, int num2) //�㷨���Ա�֤ num1 �ڼ��������Ϊ�ϴ�ֵ
////{
////    while (num2 != 0) //ʹ��շת�����������
////    {
////        int temp    = num2;         //����
////        num2        = num1 % num2;  //�����
////        num1        = temp;         //�����
////    }
////    return num1;
////}
////
//////������С������
////int FindLCM(int num1, int num2)
////{
////    return (num1 * num2) / FindGCD(num1, num2); //���� LCM �� GCD �Ĺ�ϵ��ͨ���������������С������
////}
////
////int main()
////{
////    int num1 = 0, num2 = 0;
////
////    //���û������ȡ������
////    printf("����������������: ");
////    scanf("%d %d", &num1, &num2);
////
////    //�����С�����������Լ��
////    printf("��С��������: %d\n", FindLCM(num1, num2));
////    printf("���������: %d\n", FindGCD(num1, num2));
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
//////    return -1; //������� return -1 ��̫���ܻᱻִ��, ������Ϊ�˱����������о���, ���Ǽ���������� -1 �ͱ�ʾ����ķ���ֵ
//////}
//////
//////int main()
//////{
//////    int num1 = 0, num2 = 0;
//////
//////    //���û������ȡ������
//////    printf("����������������: ");
//////    scanf("%d %d", &num1, &num2);
//////
//////    //���ú����ҵ���С����������ӡ���
//////    printf("���Լ����: %d\n", FindGCD(num1, num2));
//////
//////    return 0;
//////}
////
////
