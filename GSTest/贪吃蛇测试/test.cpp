//ʹ������
#include <graphics.h>
#include <cstdio>
int main()
{
	//��ͼ���ڳ�ʼ��
	int length = 1000;
	int width = 1000;
	initgraph(length, width, EX_SHOWCONSOLE);

	//����������
	setaspectratio(1, -1);
	setorigin(length / 2, width / 2);

	//��ȡͼƬ����ͼ����
	IMAGE img1;
	loadimage(
		&img1,
		_T("C:\\Users\\DELL\\Desktop\\SummerHolidaysFile\\GSnakeEasyxProject\\testPicture2.jpg")
	);
	putimage(0, 0, &img1);
	getchar();

	//��ת��
	IMAGE img2;
	rotateimage(&img2, &img1, 3.14/2);
	putimage(-500, -500, &img2);
	getchar();

	//���������ͼ�������
	IMAGE img3;
	getimage(&img3, 200, 200, 300, 300);
	putimage(0, 0, &img3);
	getchar();

	closegraph();
	return 0;
}
