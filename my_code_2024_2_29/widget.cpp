#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* label = new QLabel(this);
    label->setText("This is a text.");

    //构造字体对象
    QFont font;
    font.setFamily("Consolas");
    font.setPixelSize(40);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);

    //设置字体
    label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}
