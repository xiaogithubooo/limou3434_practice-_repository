#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
//��ɫѡ����
void color(short num)
{
	if (num >= 0 && num <= 15)//SetConsoleTextAttribute������windows�п������ÿ���̨����������ɫ�ͱ���ɫ�ĺ���
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);//��ȡ���ڵľ��
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//7����ΪĬ����ɫ
	}
}
void progress_bar()//����������
{
	int x = 0;
	for (x = 0; x < 51; x++)
	{
		if (x == 25)
		{
			printf("��");
		}
		else if (x == 26)
		{
			printf("��");
		}
		else if (x == 27)
		{
			printf("��");
		}
		printf("-");
	}
	printf("\n");
	SetConsoleOutputCP(437);//��ʱ���ַ���Ϊ��MS-DOS����/Ӣ�
	for (x = 0; x < 57; x++)
	{
		if (x >= 0 && x <= 2)
		{
			Sleep(2000);
			printf("%c", 219);
		}
		else if (x > 2 && x <= 10)
		{
			Sleep(500);
			printf("%c", 219);
		}
		else if (x > 10 && x <= 30)
		{
			Sleep(10);
			printf("%c", 219);
		}
		else if (x > 30 && x <= 40)
		{
			Sleep(500);
			printf("%c", 219);
		}
		else if (x > 40 && x <= 50)
		{
			Sleep(3000);
			printf("%c", 219);
		}
		else if (x > 50 && x <= 55)
		{
			Sleep(10);
			printf("%c", 219);
		}
		else
		{
			Sleep(5000);
			printf("%c", 219);
		}
	}
	SetConsoleOutputCP(936);//�Ļ��ַ���
	printf("\n");
	for (x = 0; x < 51; x++)
	{
		if (x == 25)
		{
			printf("��");
		}
		else if (x == 26)
		{
			printf("��");
		}
		else if (x == 27)
		{
			printf("��");
		}
		printf("-");
	}
	printf("\n");
}

int main()//������
{
	int i = 0;
	printf("��������Ҫ�Ľ�������ɫ��");
	scanf("%d", &i);
	color(i);

	progress_bar();
	color(7);
	return 0;
}//�����ˣ�֮�������ưɡ���