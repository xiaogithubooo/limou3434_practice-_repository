#define _CRT_SECURE_NO_WARNINGS 1
//��־���޸���ҵ
//1������һ�������1�ĸ���
//2��sizeof�����δ���

//1������һ�������1�ĸ���
#include<stdio.h>
int count_one_bit(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
 //int main()
{
	printf("%d", count_one_bit(999));
	return 0;
}
//2��sizeof�����δ���
#include <stdio.h>
int i;
int main()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}