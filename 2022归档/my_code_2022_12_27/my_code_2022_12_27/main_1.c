#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("��ã�\n");
	return 0;
}
//ţ����-�߶�ͼ��
int main()
{
    int a = 0;
    while (scanf("%d", &a) == 1)
    {
        for (int i = 0; i < a; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}