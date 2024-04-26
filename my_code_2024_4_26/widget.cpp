#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //建立信号槽关联, 但是不代表控件已经发送信号
    connect(this, &Widget::MySignal, this, &Widget::MyHandleSignal);
}

Widget::~Widget()
{
    delete ui;
}

//3.自定义槽函数定义
void Widget::MyHandleSignal(const QString& str) //带上参数
{
    this->setWindowTitle(str);
}

//4.由于是自定义信号, 因此就需要我们自己编写触发代码
void Widget::on_pushButton_1_clicked() //注意这个槽函数是通过界面拖拽直接生成的槽函数
{
    //触发信号
    emit MySignal("标题1");
}

void Widget::on_pushButton_2_clicked() //注意这个槽函数是通过界面拖拽直接生成的槽函数
{
    //触发信号
    emit MySignal("标题2");
}
