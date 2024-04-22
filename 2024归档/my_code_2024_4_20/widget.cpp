#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this); //把 from file 生成的页面和当前的 widget 关联起来
    MyLabel* label = new MyLabel(this); //创建一个标签, 并且指定控件父对象
    label->setText("hello, limou"); //设置控件的文本
}

Widget::~Widget()
{
    delete ui;
}

