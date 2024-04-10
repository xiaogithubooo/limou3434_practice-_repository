# QtTestempty.pro 是 qmake 进行元编程时的重要依据, “qmake+QtTestempty.pro”类似 makefile 的使用(但是这个工具古老且经典)
# 经过一次运行后, 在和本项目同级目录下的 build-QtTestempty-Desktop_Qt_5_14_0_MinGW_64_bit-Debug 中, 实际上也可以看到 Makefile 的身影
# 而且还有一些相关的配置文件, 还有一个依据 mywidget.ui 生成的 ui_mywidget.h 头文件, 您可以打开一览简单看一看
QT       += core gui # 表示引入的 Qt 模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 # 编译选项(使用的 C++ 标志)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 当前项目参与构建的文件, 不需要手动修改, Qt 会自动维护好
SOURCES += \
    main.cpp \
    mylabel.cpp \
    mywidget.cpp

HEADERS += \
    mylabel.h \
    mywidget.h

FORMS += \
    mywidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
