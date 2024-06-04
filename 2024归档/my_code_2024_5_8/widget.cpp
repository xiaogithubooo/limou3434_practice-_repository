// widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设定计数器初始值为 10
    ui->lcdNumber->display(10);

    // 创建 QTimer 实例
    timer = new QTimer(this);

    // 连接信号槽, timer 会每隔一定的时间触发 timeout() 信号, 把 timeout() 信号和 UpdateTime() 连接起来意味着每次触发 timeout() 信号都会伴随 UpdateTime() 槽函数的执行
    connect(timer, &QTimer::timeout, this, &Widget::UpdateTime);

    // 启动 QTimer, 并且规定每隔 1000ms 触发一次次 timeout 信号.
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::UpdateTime()
{
    qDebug() << "updateTime";
    int value = ui->lcdNumber->intValue();
    if (value <= 0) {
        // 如果时间到, 就停止定时器.
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);
}

