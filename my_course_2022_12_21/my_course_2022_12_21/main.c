#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<windows.h>
//һ�����Դ����������
//int main()
//{
//	double x = 1.00, y = 0;
//	for (x = 1.0; x != 0; x /= 2)
//	{
//		y = sin(x);
//		printf("%lf\n", x / y);
//		Sleep(500);
//	}
//	return 0;
//}
//����ʹ��һ��easy��ĺ���
// 1����ʼ�����ں���
//��HWND initgraoh(int width, int height, int flag = NULL)�������flag���Բ���
//2���رջ�ͼ���庯��
//��void closeraph()��
//3������������߼����꣨���꣩��غ���
//��1���޸�����ԭ��
//void setorigin(int x, int y);//����x��y��������õ������������ʾ��
//��2���޸������᷽���޸����������ű�����
//void setaspectratio(
//	float xasp,
//	float yasp
//);
////����100*30�ľ��Σ���*��
////����ִ��Setaspectratio(1��-1)������y������
//4�����豸������ָ��ͼ����
//�� EasyX �У��豸�����֣�һ����Ĭ�ϵĻ�ͼ���ڣ���һ���� IMAGE ����ͨ��SetWorkinglmage�����������õ�ǰ���ڻ�ͼ���豸��
//void SetWorkingImage(IMAGE * pImg = NULL);//����plmg�滭�豸ָ�롣���ΪNULL����ʾ��ͼ�豸ΪĬ�ϻ�ͼ���ڡ�
//// ���� 200x200 �� img ����IMAGE img(200, 200);
//SetWorkingImage(&img);
//���еĻ�ͼ��������������豸img�ϡ�
//5����ͼ�豸��غ���
//��1����������
//void cleardevice();
//��2������ʼ����ͼ���ڡ��롰�رմ��ڡ�
//HWND initgraph(
//	int width,
//	int height,
//	int flag = NULL);
////�����½���ͼ���ڵľ��
////��ͼ���ڵ���ʽ��Ĭ��Ϊ NULL����Ϊ����ֵ��
//EX_DBLCLKS
//�ڻ�ͼ������֧�����˫���¼���
//EX_NOCLOSE
//���û�ͼ���ڵĹرհ�ť��
//EX_NOMINIMIZE
//���û�ͼ���ڵ���С����ť��
//EX_SHOWCONSOLE
//��ʾ����̨���ڡ�
//
//��3������ȡ��ǰ�������ӡ��롰�����������ӡ�
//void getaspectratio(
//	float* pxasp,
//	float* pyasp
//);
//void setaspectratio(
//	float xasp,
//	float yasp
//);
//��4���ָ��滭����ΪĬ��ֵ�� �����������������ͼ����ǰ�㡢��ͼɫ������ɫ�����Ρ������ʽ������ΪĬ��ֵ����
//void graphdefaults();
//��5����������ԭ��
//void setorigin(int x, int y);
//��6�����õ�ǰ��ͼ�豸�Ĳü���
//void setcliprgn(HRGN hrgn);
//int main()
//{
//	// ��ʼ����ͼ����
//	initgraph(640, 480);
//
//	// ����һ����������
//	HRGN rgn = CreateRectRgn(100, 100, 200, 200);
//	// ���þ�����������Ϊ�ü���
//	setcliprgn(rgn);
//	// ����ʹ�� rgn������ rgn ռ�õ�ϵͳ��Դ
//	DeleteObject(rgn);
//
//	// ��Բ���ܲü���Ӱ�죬ֻ��ʾ���Ķ�Բ��
//	circle(150, 150, 55);
//
//	// ȡ��֮ǰ���õĲü���
//	setcliprgn(NULL);
//
//	// ��Բ�������ܲü���Ӱ�죬��ʾ��һ��������Բ
//	circle(150, 150, 60);
//
//	// ��������˳�
//	_getch();
//	closegraph();
//}
//��7������ü�������Ļ����
//void clearcliprgn();
//����ѧϰʹ��Linux����ϵͳ���˽��ļ���Ŀ¼��Ȩ��֪ʶ