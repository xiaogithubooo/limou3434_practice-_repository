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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        radioButton_1 = new QRadioButton(Widget);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setGeometry(QRect(200, 150, 121, 41));
        radioButton_1->setAcceptDrops(false);
        radioButton_1->setStyleSheet(QString::fromUtf8("background-color: green;"));
        radioButton_2 = new QRadioButton(Widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(200, 190, 121, 41));
        radioButton_2->setAcceptDrops(false);
        radioButton_2->setStyleSheet(QString::fromUtf8("background-color: green;"));
        radioButton_3 = new QRadioButton(Widget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(200, 230, 121, 41));
        radioButton_3->setAcceptDrops(false);
        radioButton_3->setStyleSheet(QString::fromUtf8("background-color: green;"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        radioButton_1->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
