cmake_minimum_required(VERSION 3.16)

project(my_code_2024_7_5_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
# find_package(Qt6 COMPONENTS Multimedia REQUIRED) # 加载多媒体模块
# find_package(Qt6 COMPONENTS Quick REQUIRED) # 加载控制模块

qt_standard_project_setup()

qt_add_executable(appmy_code_2024_7_5_test
    main.cpp
)

qt_add_qml_module(appmy_code_2024_7_5_test
    URI my_code_2024_7_5_test
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES
        RESOURCES source.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appmy_code_2024_7_5_test PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appmy_code_2024_7_5_test
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appmy_code_2024_7_5_test
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appmy_code_2024_7_5_test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
