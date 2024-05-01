/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *light;
    QPushButton *black;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        Widget->setFont(font);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        light = new QPushButton(Widget);
        light->setObjectName(QString::fromUtf8("light"));

        horizontalLayout->addWidget(light);

        black = new QPushButton(Widget);
        black->setObjectName(QString::fromUtf8("black"));

        horizontalLayout->addWidget(black);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        light->setText(QCoreApplication::translate("Widget", "light", nullptr));
        black->setText(QCoreApplication::translate("Widget", "black", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
