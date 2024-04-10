#ifndef MYLABEL_H
#define MYLABEL_H

#include<QLabel>

class MyLabel : public QLabel
{
public:
    MyLabel(QWidget* parent = nullptr); //加上 QWidget* parent 的构造方法才可以挂到对象树上
    ~MyLabel(); //[F4] 可以跳转头文件对应的源文件, [alt+enter] 就可以自动把类内定义的函数做实现模板的生成
};

#endif // MYLABEL_H
