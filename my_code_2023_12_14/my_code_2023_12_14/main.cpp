#include "am_graph.hpp"

int main()
{
	limou::TestAMGraph();

	limou::TestAMGraphBFS();
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>

//int main()
//{
//    double input; //�洢����
//    int rounded; //ת������
//    int flag = 0; //���ű�־
//
//    while (1)
//    {
//        printf("������һ����������");
//        scanf("%lf", &input); //��ȡ����������
//
//        flag = input >= 0 ? 1 : -1;
//        rounded = (int)(fabs(input) + 0.5); //������������
//        printf("���������Ϊ��%d\n", flag * rounded); //���
//    }
//
//    return 0;
//}