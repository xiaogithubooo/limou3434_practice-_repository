//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QPushButton>
#include "lexical_analyzer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口大小
    this->resize(1000, 600); // 将窗口大小调整为 1000x600

    // 创建左侧文本框控件
    _leftTextEdit = new QTextEdit(this);
    _leftTextEdit->setGeometry(50, 50, 400, 500); // 将左侧文本框控件大小调整为 400x500

    // 创建右侧文本框控件
    _rightTextEdit = new QTextEdit(this);
    _rightTextEdit->setGeometry(550, 50, 400, 500); // 将右侧文本框控件大小调整为 400x500

    // 添加文本框控件到窗口中
    _leftTextEdit->show();
    _rightTextEdit->show();


    // 创建词法分析按钮
    QPushButton* lexButton = new QPushButton("词法分析", this);
    lexButton->setGeometry(450, 560, 100, 30); // 设置按钮位置和大小，放在两个文本框中间下方

    // 连接按钮的点击事件到槽函数
    connect(lexButton, &QPushButton::clicked, this, &MainWindow::onLexButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLexButtonClicked()
{
    // 从左侧文本框中获取文本
    QString inputText = _leftTextEdit->toPlainText();

    // 词法分析
    std::string pythonCode = inputText.toStdString();
    std::string outputText = LexicalAnalyzer::lexicalAnalyzer(pythonCode);

    // 将获取的文本设置到右侧文本框中
    _rightTextEdit->setPlainText(QString::fromStdString(outputText));
}

