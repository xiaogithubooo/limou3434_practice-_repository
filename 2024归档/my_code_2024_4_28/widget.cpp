#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_up_clicked()
{
    //获取 target 本身的 geometry
    QRect rect = ui->pushButton_target->geometry();
    //rect.setY(rect.y() - 5); //这里只是对矩形对象本身做了修改, 该对象只是对控件的拷贝
    //ui->pushButton_target->setGeometry(rect);

    ui->pushButton_target->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());

    qDebug() << rect;
}

void Widget::on_pushButton_left_clicked()
{
    //获取 target 本身的 geometry
    QRect rect = ui->pushButton_target->geometry();
    //rect.setX(rect.x() - 5);
    //ui->pushButton_target->setGeometry(rect);

    ui->pushButton_target->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());

    qDebug() << rect;
}

void Widget::on_pushButton_right_clicked()
{
    //获取 target 本身的 geometry
    QRect rect = ui->pushButton_target->geometry();
    //rect.setX(rect.x() + 5);
    //ui->pushButton_target->setGeometry(rect);

    ui->pushButton_target->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());

    qDebug() << rect;
}

void Widget::on_pushButton_down_clicked()
{
    //获取 target 本身的 geometry
    QRect rect = ui->pushButton_target->geometry();
    //rect.setY(rect.y() + 5);
    //ui->pushButton_target->setGeometry(rect);

    ui->pushButton_target->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());

    qDebug() << rect;
}
