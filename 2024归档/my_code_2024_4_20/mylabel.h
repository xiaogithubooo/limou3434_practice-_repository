#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

//继承 QLabel 的类
class MyLabel : public QLabel
{
public:
    MyLabel(QWidget* parent = nullptr);
    ~MyLabel();
};

#endif //MYLABEL_H
