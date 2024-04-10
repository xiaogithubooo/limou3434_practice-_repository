#include "mylabel.h"

MyLabel::MyLabel(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{

}

MyLabel::~MyLabel()
{
    delete ui;
}
