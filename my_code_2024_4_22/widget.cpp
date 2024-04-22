#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* myButton = new QPushButton(this);
    myButton->setText("button");

    connect(
        myButton, //绑定给 UI 中的 objectName=pushButton 按钮
        &QPushButton::clicked, //点击按钮时触发的信号
        this, //关联到具体的槽函数
        &Widget::handleClick //处理信号的回调函数
        );
    //注意函数和 Linux 中的 TCP 套接字编程无关, 涉及到 Qt 信号槽问题, 作用是连接信号和槽

    _myButton = myButton;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    if (_myButton->text() != "Hello World")
    {
        _myButton->setText("Hello World");
    }
    else
    {
        _myButton->setText("button");
    }
}

