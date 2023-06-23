#include <graphics.h>
#include <cstdio>

int main()
{
    // 初始化图形窗口
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

    // 等待用户按键并关闭图形窗口
    closegraph();
    getchar();
    return 0;
}
