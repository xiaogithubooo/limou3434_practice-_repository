#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
int pd1(float x) //�жϺ���1���ж�a�Ƿ�Ϊ��
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int pd2(float y)//�жϺ���2���ж�b�Ƿ�Ϊ��
{
    if (y == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int pd3(float a,float b,float c ) //�жϺ���3���ж�Dit�Ƿ�Ϸ�
{
    
    float Dit;
    float e = b * b;
    float f = a * c;
    float g = 4 * f;
    Dit = e - g;

    if (Dit < 0)//Dit<0�����
    {
        return 0;
    }
    else//Dit>=0�����
    {
        return 1;
    }
}
int main()
{
    float a, b, c, t;
    printf("(a)x^2+(b)x+(c)=0\n�������Ӧ��ϵ��");//��ʾ�û�������ֵ
   
    scanf("%f %f %f", &a, &b, &c);//�û�����ϵ��
    printf("�������ޡ���");
    Sleep(1000);
    printf("\n\n��ʹ�õ���ϵ��Ϊ\na=%f\nb=%f\nc=%f\n���ɵĶ��κ���----->", a, b, c);//��ʾ�û�ʹ�õ�ϵ��
    if (pd1(a) == 0)//�ж�a�Ƿ�Ϊ��
    {
        if (pd2(b) == 0)//�ж�b�Ƿ�Ϊ��
        {
            Sleep(1000);
            printf("��ķ�������ϵ����Ӧ���η����޽�������壡��");
        }
        else
        {
            t = -c / b;
            Sleep(1000);
            printf("����ΪһԪ���������Ϊ%f", t);
        }
    }
    else
    {
        if (pd3(a, b, c) == 0)//�ж�Dit���Ϸ�
        {
            Sleep(1000);
                        Sleep(1000);
printf("�����ϵ�����ɵĺ���������ʵ���⣡");
        }
        else//�ж�Dit�Ϸ�
        {
            float Dit, t, h, i, j1, j2, J1, J2;
            float e = b * b;
            float f = a * c;
            float g = 4 * f;
            Dit = e - g;
            t = sqrt(Dit);
            h = -b + t;
            i = -b - t;
            j1 = h / 2;
            j2 = i / 2;
            J1 = j1 / a;
            J2 = j2 / a;
            Sleep(1000);
            printf("����ʵ����\n\nx1Ϊ%f\nx2Ϊ%f",J1,J2);
        }
    }
    return 0;
}
 
 


 

