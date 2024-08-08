cmake_minimum_required(VERSION 3.16) # 指定 CMake 最低版本

project(my_code_2024_7_2 VERSION 0.1 LANGUAGES CXX) # 定义项目名称为 my_code_2024_7_2, 版本为 0.1, 编程语言为 C++。

set(CMAKE_AUTOMOC ON) # 自动处理 Qt 的元对象编译器（MOC）。
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制要求编译器使用所指定的 C++ 标准

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED) # 查找并加载 Qt6 的 Quick 组件，版本号至少为 6.2

qt_add_executable(appmy_code_2024_7_2 # 定义可执行文件 appmy_code_2024_7_2
    main.cpp # 指定主程序的源文件 main.cpp
)

qt_add_qml_module(appmy_code_2024_7_2 # 定义了模块文件 appmy_code_2024_7_2
    URI my_code_2024_7_2 # ?
    VERSION 1.0 # ?
    QML_FILES main.qml # 指定主 QML 文件 main.qml 和其他自定义组件
    RESOURCES qml.qrc # 指定了 QML 资源文件
    SOURCES
)

# ?
set_target_properties(appmy_code_2024_7_2 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appmy_code_2024_7_2
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appmy_code_2024_7_2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
