#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1�����������ʵ��
//void my_MAX_n(int* arr, int n)
//{
//    int d = 0;
//    int z = 0;
//    for (d = 0; d <= n; d++)
//    {
//        if (*(arr + d) < *(arr + d + 1))
//        {
//            z = *(arr + d);
//            *(arr + d) = *(arr + d + 1);
//            *(arr + d + 1) = z;
//        }
//        else
//        {
//            ;//���Ķ�����
//        }
//    }
//}
//void my_5_MAX(int* arr, int n)
//{
//    for (int i = 0; i < 51; i++)
//    {
//        my_MAX_n(arr, n);
//    }
//}
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int arr[51] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)//�洢n�����ݵ�������
//    {
//        scanf("%d", &arr[i]);
//    }
//    my_MAX_n(arr, n);//����һ������
//    my_5_MAX(arr, n);//��ε���
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}//��Ȼ���ˣ����Ǻ�����

//2������ˮ�ɻ�
//int f(int);
//int main()
//{
//    int i = 0;
//    int j = 0;
//    for (i = 10000; i < 100000; i++)
//    {
//        j = f(i);
//        if (j != 0)
//        {
//            printf("%d ", j);
//        }
//    }
//    return 0;
//}
//int f(int x)
//{
//    int a = (x / 10) * (x % 10);//ǰ4λ
//    int b = (x / 100) * (x % 100);
//    int c = (x / 1000) * (x % 1000);
//    int d = (x / 10000) * (x % 10000);
//    if (a + b + c + d == x)
//    {
//        return x;
//    }
//    else
//    {
//        return 0;
//    }
//}

//3����ѡ�糤
//int main()
//{
//    char a = 0;
//    int i = 0, j = 0;
//    while (scanf("%c", &a))
//    {
//        if (a == 'A')
//        {
//            i++;
//        }
//        else if (a == 'B')
//        {
//            j++;
//        }
//        else if (a == '0')
//        {
//            break;
//        }
//    }
//    if (i > j)
//    {
//        printf("A");
//    }
//    else if (i < j)
//    {
//        printf("B");
//    }
//    else
//    {
//        printf("E");
//    }
//    return 0;
//}

//4���ж�Ԫ������
//int main()
//{
//    char a = 0;
//    while (scanf("%c",&a)==1)
//    {
//        getchar();
//        switch (a)
//        {
//        case 'A':case 'a':
//            printf("Vowel\n");
//            break;
//
//        case 'E':case 'e':
//            printf("Vowel\n");
//            break;
//
//        case 'I':case 'i':
//            printf("Vowel\n");
//            break;
//
//        case 'O':case 'o':
//            printf("Vowel\n");
//            break;
//
//        case 'U':case 'u':
//            printf("Vowel\n");
//            break;
//
//            default:
//            printf("Consonant\n");    
//            break;
//        }
//    }
//    return 0;
//}

//5����Сдת��
//int main()
//{
//    char a = 0;
//    while (scanf("%c", &a) == 1)
//    {
//        if (a >= 'A' && a <= 'Z')
//        {
//            printf("%c\n", a + 32);
//        }
//        else if (a >= 'a' && a <= 'z')
//        {
//            printf("%c\n", a - 32);
//        }
//    }
//    return 0;
//}

//6���ж��ǲ�����ĸ
//int main()
//{
//    char a = 0;
//    while (scanf("%c", &a) == 1)
//    {
//        getchar();
//        if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
//        {
//            printf("%c is an alphabet.\n", a);
//        }
//        else
//        {
//            printf("%c is not an alphabet.\n", a);
//        }
//    }
//    return 0;
//}

//7�����㵥λ��Ծ����
//void f(float x)
//{
//    if (x > 0)
//    {
//        printf("1\n");
//    }
//    else if (x < 0)
//    {
//        printf("0\n");
//    }
//    else if (x == 0)
//    {
//        printf("%.1f\n", 1.0 / 2.0);
//    }
//}
//int main()
//{
//    float a = 0;
//    while (scanf("%f", &a) == 1)
//    {
//        f(a);
//    }
//    return 0;
//}

//8�������ε��ж�
//int main()
//{
//    int arr[3] = { 0 };
//    while (scanf("%d %d %d", arr, arr + 1, arr + 2) == 3)
//    {
//        getchar();
//        if ((arr[0] + arr[1] > arr[2]) && (arr[1] + arr[2] > arr[0]) && (arr[2] + arr[0] > arr[1]))
//        {
//            if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (((arr[0] == arr[1]) && (arr[0] != arr[2])) || ((arr[1] == arr[2]) && (arr[1] != arr[0])) || ((arr[2] == arr[0]) && (arr[0] != arr[1])))
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!");
//        }
//    }
//    return 0;
//}

//9�������������ݳ̶�
//float my_BMI(int a, float b)
//{
//    return a / (b * b);
//}
//
//int main()
//{
//    float c = 0;
//    int a;//������
//    float b;//����
//    while (scanf("%d %f", &a, &b) == 2)
//    {
//        c = my_BMI(a, b / 100);
//        if (c < 18.5)
//        {
//            printf("Underweight\n");
//        }
//        else if (c >= 18.5 && c <= 23.9)
//        {
//            printf("Normal\n");
//        }
//        else if (c >= 23.9 && c <= 27.9)
//        {
//            printf("Overweight\n");
//        }
//        else if (c > 27.9)
//        {
//            printf("Obese\n");
//        }
//    }
//    return 0;
//}