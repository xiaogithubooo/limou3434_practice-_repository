#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include<Windows.h>
int pd1(float x) //判断函数1，判断a是否为零
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
int pd2(float y)//判断函数2，判断b是否为零
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
int pd3(float a,float b,float c ) //判断函数3，判断Dit是否合法
{
    
    float Dit;
    float e = b * b;
    float f = a * c;
    float g = 4 * f;
    Dit = e - g;

    if (Dit < 0)//Dit<0的情况
    {
        return 0;
    }
    else//Dit>=0的情况
    {
        return 1;
    }
}
int main()
{
    float a, b, c, t;
    printf("(a)x^2+(b)x+(c)=0\n请输入对应的系数");//提示用户输入数值
   
    scanf("%f %f %f", &a, &b, &c);//用户输入系数
    printf("运算中噢……");
    Sleep(1000);
    printf("\n\n您使用的是系数为\na=%f\nb=%f\nc=%f\n构成的二次函数----->", a, b, c);//提示用户使用的系数
    if (pd1(a) == 0)//判断a是否为零
    {
        if (pd2(b) == 0)//判断b是否为零
        {
            Sleep(1000);
            printf("唔姆？输入的系数对应二次方程无解或无意义！？");
        }
        else
        {
            t = -c / b;
            Sleep(1000);
            printf("函数为一元函数，结果为%f", t);
        }
    }
    else
    {
        if (pd3(a, b, c) == 0)//判断Dit不合法
        {
            Sleep(1000);
                        Sleep(1000);
printf("输入的系数构成的函数不存在实数解！");
        }
        else//判断Dit合法
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
            printf("存在实数解\n\nx1为%f\nx2为%f",J1,J2);
        }
    }
    return 0;
}
 
 


 

