#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //创建一个 Qt 应用程序
    QApplication a(argc, argv);

    //创建控件对象, 该控件是由 Qt 内的控件继承而来
    Widget w;

    //显示上述创建的控件
    w.show();

    //返回交给 Qt 内部的程序来启动事件循环
    return a.exec();
}
