#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>//ʵ��Ŀ��
 //��1���ܹ�������ʹ��C���Խ��м򵥵��������㡢��ϵ������߼����㡣
 //��2�����ղ�ͬ����������֮�丳ֵ�Ĺ��ɡ�
 //��3����һ����ϤC���Գ���ı༭����������еĹ��̡�
//����һ����������
//int main()
//{
//	int a = 2, b = 3;
//	float x = 3.9, y = 2.3;
//	float result;
//	result = (float)(a + b) / 2 + (int)x % (int)y;
//	printf("%f", result);
//	return 0;
//}
//���������������
//int main()
//{
//	int number;
//	int a1, a2, a3;
//	printf("������3λ����");
//	scanf("%d", &number);
//	a1 = number % 10;
//	a2 = number % 100, a2 = a2 / 10;
//	a3 = number / 100;
//	printf("��λ��%d�ĸ�λ��Ϊ%d��ʮλ��Ϊ%d����λ��Ϊ%d\n", number, a1, a2, a3);
//	return 0;
//}
//����������ϵ�������߼�����
//int main()
//{
//	int x;
//	printf("����x��ֵ��");
//	scanf("%d", &x);
//	printf("���ʽ��x>0����ֵ��%d\n", x > 0);	
//	printf("���ʽ��x>=-20&&x<=-10����ֵ��%d\n", x >= -20 && x <= -10);
//	printf("���ʽ��x>100||x<10����ֵ��%d\n", x > 100 || x < 10);
//	printf("���ʽ��x>20&&x%%3==0����ֵ��%d\n", x > 20 && x % 3 == 0);
//	printf("���ʽ��(x%%5==0)&&(x%%3!=0)����ֵ��%d\n", (x % 5 == 0) && (x % 3 != 0));
//	return 0;
//}
//�����ģ��ۺ�����
//int pd1(int x)
//{
//	if (x >= 0 && x <= 100)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int pd2(int x, int y)
//{
//	if (x > y)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int grad1, grad2, t1, t2,j;
//	printf("������ѧ��1�ĳɼ���");
//	scanf("%d", &grad1);
//	printf("������ѧ��2�ĳɼ���");
//	scanf("%d", &grad2);
//	t1 = pd1(grad1);
//	t2 = pd1(grad2);
//	printf("grad1��[0��100]��Χ�ڣ� %d\n", t1);
//	printf("grad2��[0��100]��Χ�ڣ� %d\n", t2);
//	j=pd2(grad1, grad2);
//	if (j == 1)
//	{
//		printf("grad1>grad2 ? %d\n",j);
//	}
//	else
//	{
//		printf("grad1<grad2 ? %d\n", j);
//	}
//	return 0;
//}
// 
// 
// 
// 
//������Ŀ��дһ�������ֵ����
//int MAX(int x, int y)
//{
//	int t;
//	if (x > y)
//	{
//		t = x;
//	}
//	else
//	{
//		t = y;
//	}
//	return t;
//}

//int main()
//{
//	int x, y, j;
//	scanf("%d,%d", &x, &y);
//	j = MAX(x, y);
//	printf("%d", j);
//	return 0;
//}
int main()
{
    int grad1, grad2;
    printf("������ѧ��1�ĳɼ�:");
    scanf("%d", &grad1);
    printf("������ѧ��2�ĳɼ�:");
    scanf("%d", &grad2);
    if (grad1 >= 0 && grad1 <= 100)
    {
        printf("grad1��[0,100]��Χ�ڣ�1\n");
    }
    else
    {
        printf("grad2��[0,100]��Χ�ڣ�0\n");
    }
    if (grad2 >= 0 && grad2 <= 100)
    {
        printf("grad2��[0,100]��Χ�ڣ�1\n");
    }
    else
    {
        printf("grad2��[0,100]��Χ�ڣ�0\n");

    }
    printf("grad1>grad2 ? %d", grad1>grad2);
    return 0;
}