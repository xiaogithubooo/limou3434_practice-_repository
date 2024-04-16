// main.cpp

#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // 传递命令行参数给 QApplication 类
    MyWidget w; // 创建一个控件对象, 继承自 QWidget
    w.show(); // 显示控件对象, hide() 则可以将控件隐藏
    return a.exec(); // exec() 是 QCoreApplication 类成员方法, 可启动 Qt 的事件循环, 和 Linux 中的 exec 进程替换没有关系
}
