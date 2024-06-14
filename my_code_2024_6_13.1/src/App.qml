import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FluentUI 1.0

FluLauncher {
    id: app

    // 黑暗模式切换
    Connections {
        target: FluTheme
        function onDarkModeChanged() {
            SettingsHelper.saveDarkMode(FluTheme.darkMode)
        }
    }

    // 系统引用程序栏切换
    Connections {
        target: FluApp
        function onUseSystemAppBarChanged() {
            SettingsHelper.saveUseSystemAppBar(FluApp.useSystemAppBar)
        }
    }

    // 语言切换
    Connections {
        target: TranslateHelper
        function onCurrentChanged() {
            SettingsHelper.saveLanguage(TranslateHelper.current)
        }
    }

    // 在子组件完成创建并初始化后执行的代码块
    Component.onCompleted: {
        FluApp.init(app, Qt.locale(TranslateHelper.current)) // 初始化 app
        FluApp.windowIcon = "qrc:/logo.ico" // 设置应用程序图标
        FluApp.useSystemAppBar = SettingsHelper.getUseSystemAppBar() // 加载系统应用栏设置
        FluTheme.darkMode = SettingsHelper.getDarkMode() // 加载黑暗模式
        FluTheme.animationEnabled = true // 启动动画
        FluRouter.routes = { // 定义路由
            "/": "qrc:/main.qml"
        }
        FluRouter.navigate("/") // 立即跳转到根路由
    }
}
