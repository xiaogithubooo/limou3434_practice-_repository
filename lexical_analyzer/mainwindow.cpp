#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QPushButton>
#include <QToolButton>
#include <QApplication>
#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QDebug>
#include "lexical_analyzer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口大小
    this->resize(1000, 600); // 将窗口大小调整为 1000x600

    // 创建左侧文本框控件
    _leftTextEdit = new QTextEdit("# 填入原始文件", this);
    _leftTextEdit->setGeometry(50, 50, 400, 500); // 将左侧文本框控件大小调整为 400x500

    // 创建右侧文本框控件
    _rightTextEdit = new QTextEdit(this);
    _rightTextEdit->setGeometry(550, 50, 400, 500); // 将右侧文本框控件大小调整为 400x500

    // 添加文本框控件到窗口中
    _leftTextEdit->show();
    _rightTextEdit->show();

    // 创建一个工具按钮
    QToolButton *toolButton = new QToolButton(this);
    toolButton->setText("编译工具");

    // 创建一个下拉菜单
    QMenu *menu = new QMenu(toolButton);

    // 创建动作并添加到菜单中，并关联槽函数
    QAction *action1 = new QAction("导入文件", this);
    QAction *action2 = new QAction("词法分析", this);
    QAction *action3 = new QAction("导出文件", this);

    // 将下拉菜单与工具按钮关联
    toolButton->setMenu(menu);
    toolButton->setPopupMode(QToolButton::InstantPopup); // 设置弹出模式

    // 菜单关联事件
    QObject::connect(action1, &QAction::triggered, [&]() {
        qDebug() << "导入文件";

        // 弹出资源管理器对话框，让用户选择文件
        QString fileName = QFileDialog::getOpenFileName(this, "选择文件", QDir::homePath());

        if (!fileName.isEmpty()) {
            // 读取文件内容
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                QString fileContent = in.readAll();

                // 将文件内容设置到左侧文本框中
                _leftTextEdit->setPlainText(fileContent);

                file.close();
            }
        }
    });

    QObject::connect(action2, &QAction::triggered, [&]() {
        qDebug() << "词法分析";
        // 从左侧文本框中获取文本
        QString inputText = _leftTextEdit->toPlainText();

        // 词法分析
        std::string pythonCode = inputText.toStdString();
        std::string outputText = LexicalAnalyzer::lexicalAnalyzer(pythonCode);

        // 将获取的文本设置到右侧文本框中
        _rightTextEdit->setPlainText(QString::fromStdString(outputText));
    });

    QObject::connect(action3, &QAction::triggered, [&]() {
        qDebug() << "导出文件";

        // 获取右侧文本框的内容
        QString content = _rightTextEdit->toPlainText();

        // 弹出文件保存对话框，让用户选择文件保存位置和文件名
        QString fileName = QFileDialog::getSaveFileName(this, "保存文件", QDir::homePath() + "/obj.txt", "Text Files (*.txt)");

        // 如果用户取消保存，fileName 为空
        if (!fileName.isEmpty()) {
            // 将文本框中的内容写入到用户选择的文件中
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << content;
                file.close();
                qDebug() << "文件保存成功";
            } else {
                qDebug() << "无法保存文件";
            }
        }
    });

    menu->addAction(action1);
    menu->addAction(action2);
    menu->addAction(action3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
