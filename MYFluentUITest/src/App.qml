// App.qml 启动器文件

import QtQuick 2.15 // 导入基础模块
import QtQuick.Window 2.15 //导入窗口模块
import QtQuick.Controls 2.15 // 导入控制模块
import QtQuick.Layouts 1.15 // 导入布局模块
import FluentUI 1.0 // 导入 FluentUI 模块

// 使用 FluentUI 中的 FluLauncher 组件作为根元素初始化应用程序的配置
FluLauncher {
    id: app
    Component.onCompleted: {
        FluApp.init(app) // 初始化应用程序
        FluApp.windowIcon = "qrc:/logo.ico" // 设置窗口图标
        FluRouter.routes = { // 定义路由规则
            "/":"qrc:/Main.qml", // 根路由
        }
        FluRouter.navigate("/") // 程序启动时就立刻跳转到根路由, 也就是主页面
    }
}

