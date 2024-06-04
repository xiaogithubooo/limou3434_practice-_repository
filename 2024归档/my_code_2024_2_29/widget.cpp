#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

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

void Widget::on_light_clicked()
{
    this->setStyleSheet("background-color: #f0f0f0;");
    ui->light->setStyleSheet("background-color: black; color: red");
}

void Widget::on_black_clicked()
{
    this->setStyleSheet("background-color: black;");
    ui->black->setStyleSheet("background-color: white; color: blue");
}
