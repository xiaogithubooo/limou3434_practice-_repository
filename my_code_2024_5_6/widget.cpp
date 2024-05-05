//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QSize>
#include <QKeySequence>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置窗口的标题
    this->setWindowTitle("标题一");

    //2.禁用第一个按钮
    //ui->radioButton_1->setCheckable(false);

    //5.取消按钮 3 的排他设置, 但是其他按钮都保持排他, 哪怕有按钮被禁用也要算进去...
    ui->radioButton_3->setAutoExclusive(false);
}

Widget::~Widget()
{
    delete ui;
}

//3.设置按钮 1 的点击事件, 这里可以发现哪怕禁选了按钮 1, 对应的点击事件也会被触发
void Widget::on_radioButton_1_clicked()
{
    //如果按钮被选中, 就把标题进行修改
    if(this->windowTitle() == "标题一")
        this->setWindowTitle("标题二");
    else
        this->setWindowTitle("标题一");
}

//4.设置按钮 2 的点击事件
void Widget::on_radioButton_2_clicked()
{
    //如果按钮被选中, 就把标题进行修改
    if(ui->radioButton_2->isChecked() == true)
    {
        this->setWindowTitle("新标题");
    }
    ui->radioButton_2->setChecked(false); // 取消按钮选中状态
}
