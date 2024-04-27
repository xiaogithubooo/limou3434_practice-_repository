#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void handleClick(); //信号处理回调方法

private:
    Ui::Widget *ui;
    QPushButton* _myButton; //设置一个成员变量, 否则回调函数无法使用获取到的按钮
};
#endif // WIDGET_H
