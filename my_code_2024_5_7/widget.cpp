// widget.c
#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    ui->label_1->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 设置居中对齐(水平居中+垂直居中)
    ui->label_1->setText("垂直⽔平居中的⽂本");

    ui->label_2->setAlignment(Qt::AlignTop | Qt::AlignLeft); // 设置自动换行(顶部对齐+左部对齐)
    ui->label_2->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_2->setText("偏左上的⽂本");

    ui->label_3->setAlignment(Qt::AlignBottom | Qt::AlignRight); // 设置首行缩进（底部对齐+右部对齐）
    ui->label_3->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_3->setText("偏右下的⽂本");

    ui->label_4->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_4->setMargin(10); // 设置文本边距
    ui->label_4->setText("这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本");

    ui->label_5->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_5->setWordWrap(true); // 设置自动换行
    ui->label_5->setText("这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本");

    ui->label_6->setStyleSheet("background-color: #606060;"); // 更换标签颜色
    ui->label_6->setIndent(20); // 设置自动缩进
    ui->label_6->setText("这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本这是⼀个很⻓的⽂本");
}


Widget::~Widget()
{
    delete ui;
}
