// mywidget.cpp

#include "mywidget.h"
#include "ui_mywidget.h" // from file 被 qmake 生成的头文件
#include <QLabel> //还有一个 QLabel 是较早的实现版本
#include <QString>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this); //把 from file 生成的页面和当前的 widget 关联起来
    QLabel* label = new QLabel(this); //Label 其实就是“标签”, 也就是界面上用来显示的字符串, 并且指定父对象
    label->setText(QString("Hello World!")); //C++ 早期的字符串有 C 式风格字符串和混乱的 std::string, 因此就有了自己的基础类来支持字符串(QString)、动态数组(QVector)、链表(QList)、字典(QMap)...因此就有可能有两种解决方案, 不过很多情况都使用 Qt 自己的
    label->setGeometry(QRect(230, 130, 91, 21)); //设定标签位置和标签形状
    //另外, 这里故意没有使用 delete label, 这是 Qt 的一个特点, 您在这里可以不调用 delete
    //因为前面的 QLabel* label = new QLabel(this); 把对象通过父对象挂到了对象树上, 对象树可以把界面上的各种元素组织起来
}

MyWidget::~MyWidget()
{
    delete ui; //释放资源
}
