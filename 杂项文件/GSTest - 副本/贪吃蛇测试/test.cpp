//ʹ������
#include <graphics.h>
#include <windows.h>
#include <cstdio>
int main()
{

	//��ʼ����ͼ����
	initgraph(640, 480, EX_SHOWCONSOLE);

	//��ȡָ����ʾ��������ָ��
	DWORD* pMem = GetImageBuffer();//��дĬ��ΪNULL����ʾĬ�ϵĻ�ͼ���ڣ�

	//ֱ�Ӷ���ʾ��������ֵ
	for (int i = 0; i < 640 * 480; i++)
	{
		pMem[i] = BGR(RGB(0, 0, i * 256 / (640 * 480)));
		if (i % 1000 == 0)
		{
			Sleep(100);
		}
	}

	//ʹ��ʾ��������Ч��ע������ָ��IMAGE����ʾ����������Ҫ������䣩
	FlushBatchDraw();
	//�ڼ����ͼ�α���У�
	//���Ǿ�����Ҫ�����Ƶ�ͼ����ʾ����Ļ�ϡ�
	//������ͼ����һ����Ժķ���Դ�Ĳ�����
	//���ÿ�λ��ƶ�������ʾ����Ļ�ϣ�
	//�ᵼ��Ƶ����ͼ��ˢ�£�
	//���ܻ���������˸���߿��ٵ����⡣
	//Ϊ����߻��Ƶ�Ч�ʺ������ȣ�
	//���������������Ƶĸ��
	//FlushBatchDraw()�������ǽ�֮ǰ�������Ƶ�ͼ��һ���Ե�ˢ�µ���Ļ�ϡ�
	//ͨ�׵�˵���ͺñ���һ�����ύ��������
	//��֮ǰ���е����л��ƶ����ڵ���FlushBatchDraw()��һ����ʾ����Ļ��

	//��������˳�
	getchar();
	closegraph();

	return 0;
}



/*
* 	//��ͼ���ڳ�ʼ��
	int length = 1000;
	int width = 1000;
	initgraph(length, width, EX_SHOWCONSOLE);

	//��ȡͼƬ����ͼ����
	IMAGE img1;
	loadimage(
		&img1,
		_T("C:\\Users\\DELL\\Desktop\\SummerHolidaysFile\\GSnakeEasyxProject\\testPicture2.jpg")
	);
	putimage(0, 0, &img1);
	getchar();

	//�����ô�С��
	Resize(&img1, 500, 500);
	putimage(100, 100, &img1);
	getchar();
		
	closegraph();

* 	//���û�ͼĿ��Ϊimg1����
	SetWorkingImage(&img1);
	printf("img1\n");
	getchar();
* 	//���»�ͼ�������������img1��������
	line(0 + 100, 100, 200 + 100, 100);
	line(100 + 100, 0, 100 + 100, 200);
	circle(100 + 100, 100, 50);
	//���û�ͼĿ��Ϊ��ͼ����
	SetWorkingImage();
	line(0, 100, 200, 100);
	line(100, 0, 100, 200);
	circle(100, 100, 50);
	printf("��ͼ����\n");
	getchar();*/
