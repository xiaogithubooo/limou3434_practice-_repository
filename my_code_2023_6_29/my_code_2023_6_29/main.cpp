#include <graphics.h>
#include <stdio.h>
int main()
{
	//1.��ʼ����ͼ����
	initgraph(640, 480, EX_SHOWCONSOLE);
	//2.�����ַ������������������û�����
	wchar_t s[10];
	while (1)
	{
		InputBox(s, 10, _T("������뾶"), _T("��ԲС����"), _T("100"), 50,50, true);
		//3.���û�����ת��Ϊ����
		int r = _wtoi(s);
		//4.��Բ
		circle(320, 240, r);
	}
	//5.��������˳�
	getchar();
	closegraph();
	return 0;
}
