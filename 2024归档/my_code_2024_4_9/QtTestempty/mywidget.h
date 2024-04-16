// mywidget.h

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget> // 使用 Qt 内置的类和头文件一致

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT // 这是 QT 内置的宏, 该宏展开后就会生成大量代码, 当类需要使用 Qt 的“信号”和“槽”机制的时候就要引入

public: // 下面两个类方法做了头文件、源文件分离的实现
    MyWidget(QWidget *parent = nullptr); // Qt 引入了对象树的概念, 创建 Qt 的对象, 就可以吧对象挂在对象树上(N叉树), 往上挂时需要指定父节点
    ~MyWidget();

private:
    Ui::MyWidget *ui; //和 form file 相关
};
#endif // MYWIDGET_H
