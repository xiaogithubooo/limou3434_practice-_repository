#define _CRT_SECURE_NO_WARNINGS 1
//1�����ֲ��ҷ��ĸ�ϰ
#include <stdio.h>
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//��������
    //�±�        0,1,2,3,[4],5,6,7,8,9
    int i = 0;
    int k = 0;
    scanf("%d", &k);
    int sz = sizeof(arr) / sizeof(arr[0]);//��������Ĵ�С
    int left = 0;//���±�
    int right = sz - 1;//���±�
    int flag = 0;
    int mid = 0;
    while (left <= right)
    {
        //mid = (left + right) / 2;//�м��±꣨�����е�С���⣬���������������
        mid = left + (right - left) / 2;//�м��±꣨������ƽ��ֵ������õģ���
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            printf("�ҵ��ˣ��±���%d", mid);
            flag = 1;
            break;
        }
    }
    if (0 == flag)
    {
        printf("û���ҵ�\n");
    }
    return 0;
}
//2����������Ϸ
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("********************************\n");
	printf("*******     1. play      *******\n");
	printf("*******     0. exit      *******\n");
	printf("********************************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("�������:>");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		else if (num > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}