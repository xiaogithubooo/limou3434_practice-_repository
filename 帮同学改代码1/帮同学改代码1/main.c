#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ͬѧ����Ĵ���
//int main()
//{
//
//    double results[10];
//    int i;
//    double max = 0, min = 100, sum = 0, average;
//    printf("�ɼ��Ǽǣ�\n");
//    for (i = 0; i < 10; i++)
//    {
//        printf("�������%d��ѧ���ĳɼ���", i + 1);
//        scanf("%Lf,&results[i]");
//        if (max < results[i])
//            max = results[i];
//        if (min > results[i])
//            min = results[i];
//        sum += results[i];
//    }
//    average = sum / 10;
//    printf("ͳ�����£�\n");
//    printf("����ѧ������߷�Ϊ��%Lf\n", max);
//    printf("����ѧ������ͷ�Ϊ��%Lf\n", min);
//    printf("����ѧ����ƽ����Ϊ��%Lf\n", average);
//    return 0;
//}
//�����޸ĺ�
int main()
{

    double results[10];//1��û��дע�ͣ����磬�������д��������ѧ���ɼ�����ע�Ϳ��԰���δ�����Լ�����������߱��˿��ٿ������룬������ֱ��˿������������Լ������������������
    int i;
    double max = 0, min = 100, sum = 0, average;
    printf("�ɼ��Ǽǣ�\n");
    for (i = 0; i < 10; i++)
    {
        printf("�������%d��ѧ���ĳɼ���", i + 1);
        scanf("%Lf",&results[i]);//2�����˫���ŷŴ�λ���ˣ�����
        if (max < results[i])
        {
            max = results[i];//3��ע�����д�ϴ���飬����ʹ�÷�֧����ʱ������߼����ң�Ҳ�����ں��ڴ����ά��
        }
        if (min > results[i])
        {
            min = results[i];
        }
        sum += results[i];
    }
    average = sum / 10;
    printf("ͳ�����£�\n");
    printf("����ѧ������߷�Ϊ��%Lf\n", max);
    printf("����ѧ������ͷ�Ϊ��%Lf\n", min);
    printf("����ѧ����ƽ����Ϊ��%Lf\n", average);
    return 0;
}