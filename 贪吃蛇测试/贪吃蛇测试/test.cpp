#include <graphics.h>
#include <cstdio>

int main()
{
    // ��ʼ��ͼ�δ���
    initgraph(640, 480, EX_SHOWCONSOLE);
    getchar();

    settextcolor(RED);

    TCHAR str[] = _T("Hello, I am limou!\nThis a C++ code.");
    outtextxy(100, 100, str);
    getchar();

    int pxSize1 = textheight(str);
    printf("%d\n", pxSize1);
    getchar();

    int pxSize2 = textwidth(str);
    printf("%d\n", pxSize2);
    getchar();

    rectangle(200, 200, 200 + pxSize2, 200 + pxSize1);
    getchar();

    // �ȴ��û��������ر�ͼ�δ���
    closegraph();
    getchar();
    return 0;
}
