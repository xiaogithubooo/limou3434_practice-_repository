#include <stdio.h>

int main() {
    int num1 = 2;
    int num2 = 7;
    double num3 = 7.0;
    double num4 = 2.; // ���� C ��������ʹ�� "2." �ķ�ʽ��ʾ "2.0"
    double result1, result2, result3, result4; // ������Բ���ʼ��, �����ⲻ�Ǻܺõ�ϰ��, ��ֻ����ʾ���������������ڴ󲿷��������û�������

    // ��������������ʱ������, �������Ϊ������������
    result1 = num1 / num2;
    printf("result1 = num1 / num2 ���: %d\n", result1); // ���Ϊ 0

    // ����һ���������Ǹ�����ʱ������, ���� num3 �Ǹ�������, num1 ��ת��Ϊ�������͵� 2.0, ���Ϊ������������
    result2 = num1 / num3;
    printf("result2 = num1 / num3 ���: %f\n", result2); // ���Ϊ 0.285714

    // ��ϳ�������һ�����������������ڶ����Ǹ�����
    result4 = num3 / num4;
    printf("result3 = num3 / num4 ���: %f\n", result4); // ���Ϊ 3.500000

    return 0;
}