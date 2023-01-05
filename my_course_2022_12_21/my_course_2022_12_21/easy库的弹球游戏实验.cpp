#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//��׼�������ͷ�ļ�
#include<easyx.h>//easyx���ⲿͷ�ļ�
#include<math.h>//��ѧͷ�ļ�
#include<windows.h>//windowsͷ�ļ�
#include<conio.h>//ˢ�������ͷ�ļ�
#include<stdlib.h>//�������ͷ�ļ�
#include<time.h>//����rand���ɽϺõ������
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*ֱ���˶�����*///<��ʵ����û���õ���������ء���>
void LinearMotion(int x1, int y1, int x2, int y2, int v)
{
	double vy, vx;
	if (y2 == y1)
	{
		vx = v;
		vy = 0;
	}
	else if (x2 == x1)
	{
		vx = 0;
		vy = v;
	}
	else
	{
		double tanTheta = (double)abs(y2 - y1) / (double)abs(x2 - x1);
		double theta = atan(tanTheta);//����Ƕ�

		vy = sin(theta) * v;
		vx = cos(theta) * v;//���x��y���ٶ�
	}



	int vxFlag = 0;
	int vyFlag = 0;
	if (x2 - x1 > 0)
	{
		vxFlag = 1;
	}
	else if (x2 - x1 < 0)
	{
		vxFlag = -1;
	}
	if (y2 - y1 > 0)
	{
		vyFlag = 1;
	}
	else if (y2 - y1 < 0)
	{
		vyFlag = -1;
	}
	if (vxFlag == 0 && vyFlag == 0)
	{
		return;
	}

	vx = vx * vxFlag;
	vy = vy * vyFlag;//�����ٶȷ���

	double x, y;
	x = x1;
	y = y1;//��ʼ������

	while (1)
	{
		cleardevice();
		solidcircle((int)x, (int)y, 25);//��Բ

		Sleep(10);
		x += vx;
		y += vy;//���ٶȸ�������꣬ʹ����״������

		if (vxFlag == 1)
		{
			if (x >= x2)
				break;
		}
		else if (vxFlag == -1)
		{
			if (x <= x2)
				break;
		}
		if (vyFlag == 1)
		{
			if (y >= y2)
				break;
		}
		else if (vyFlag == -1)
		{
			if (y <= y2)
				break;
		}//�趨�����˶�
	}
}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
/*��ʼ�������������*/
int barLeft = -150, barRight = 150, barTop = -280, barBottom = -300;
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//�������ı��ʾ���һ���ٶȷ����������˸ı䣨�෴����
int main()
{
	initgraph(800, 600, EX_SHOWCONSOLE);//��������
	setorigin(400, 300);//����߼�����ԭ�㣨400��300��
	setaspectratio(1, -1);//��תy��
	setbkcolor(RGB(164, 225, 202));//���ñ�����ɫ����
	cleardevice();//�����ñ�����ɫ��������ˢ����
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	int x = 0, y = 0, r = 40;//Բ�������е㣨0��0�����뾶40����
	int vx = 5, vy = 5;//С����趨���ٶ�
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	int i = 0;//��¼ʧ�ܴ���
	while (1)
	{
		cleardevice();//ˢ�±�ֽ
		solidcircle(x, y, r);//��Բ
		solidrectangle(barLeft, barTop, barRight, barBottom);//��һ������
		Sleep(15);//ͣ��40����
		if (y >= 300 - 40)//�Ϸ������·���������ң�
		{
			vy = -vy;
		}
		if (x >= 400 - 40 || x <= -400 + 40)//���ҷ���
		{
			vx = -vx;
		}
		if (barLeft <= x && x <= barRight && y <= barTop + r)//ײ��������ͷ���
		{
			vy = -vy;
		}
		if (y <= -300)//�ж���Ϸʧ��
		{
			i++;//�ۼ�ʧ�ܴ���
			printf("\a��Ϸʧ��%d��\n", i);
			srand((unsigned)time(NULL));//����rand�����������
			x = rand() % (400 + 1) - 200;//�����λԲ������
			y = rand() % (300 + 1) - 150;

			vx = 5;//��λ�ٶȷ�����С 
			vy = 5;

			if (rand() % 2 == 0)//����ٶȷ����ķ���
			{
				vy = -vy;
			}
			if (rand() % 2 == 0)
			{
				vx = -vx;
			}

			barLeft = -150;//��λ����
			barRight = 150;
			barTop = -280;
			barBottom = -300;
		}//<��Ȼ��δ���Ҳ�����ڵ�һ�ξͿ�ʼִ��>

		x += vx;//�����Ϸ��ƶ�
		y += vy;

		//��ȡ�������룬�Ե�������޸�
		if (_kbhit() != 0)
		{
			char c = _getch();
			if (c == 'a')//��������
			{
				if (barLeft > -400)
				{
					barLeft -= 20;
					barRight -= 20;
				}
			}
			else if(c=='d')//��������
			{
				if (barRight < 400)
				{
					barLeft += 20;
					barRight += 20;
				}
			}
			else if (c == 'q')
			{
				break;
			}
		}
	}
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	printf("���ѳɹ��˳���Ϸ\n");
	getchar();
	closegraph();//�رմ���
	return 0;
}
//<���Գ��԰����б�����װΪһ���ṹ�壬ȡ��my_GameDatd>
//<���Գ��Խ�����rand�ĳ�ʼ�����һ�������ʼ������reset>
//<��Ϸ�������ƺ�ͳ����Ϸ��������>
//<�����������ļ��������������������û���>
//<���Ӽ�ֵ����ʱʱ��>
//<��������ש��>
//<�����С��>
//<������С���Ѷ�>
//<ѡ��ؿ��Ѷ�>