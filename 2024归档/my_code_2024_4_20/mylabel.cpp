#include <iostream>
#include "mylabel.h"

MyLabel::MyLabel(QWidget* parent)
    : QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    std::cout << "~MyLabel()" << std::endl;
}
