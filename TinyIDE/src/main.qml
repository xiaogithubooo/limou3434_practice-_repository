// main.qml 启动主页
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15
import Qt.labs.platform 1.1
import FluentUI 1.0

// 设置主页面
FluWindow {
    id:window
    title: "Tiny C IDE" // 这个标题是程序栏的标题
    width: 1000
    height: 668
    minimumWidth: 668
    minimumHeight: 320
    launchMode: FluWindowType.SingleTask // 设置窗口启动模式为单任务模式运行, 防止启动多个应用程序窗口
    fitsAppBarWindows: true // 窗口内容会自动调整以避免与应用栏重叠

    // 定义程序应用栏
    appBar: FluAppBar {
        width: window.width
        height: 30
        showDark: true // 是否显示按钮切换
        darkClickListener:(button)=>handleDarkChanged(button) // 切换黑暗模式按钮对应点击事件
        closeClickListener: ()=>{dialog_close.open()} // 关闭按钮对应点击事件(会打开另外一个窗口用于确认提示)
        title:"Tiny C IDE"
        icon: "qrc:/logo.ico"
    }

    // 定义退出弹窗
    FluContentDialog{
        id: dialog_close
        title: qsTr("Quit")
        message: qsTr("Are you sure you want to exit the program?")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        positiveText: qsTr("Quit")
        neutralText: qsTr("Cancel")
        onPositiveClicked:{
            FluRouter.exit(0)
        }
    }


    /* 填入导航栏代码 */
    FluObject {
        id: navigationBar
        //填入导航栏代码
        //可以使用之前提供的单例对象来构建导航菜单
        //例如：
        FluPaneItem {
            title: "Page 1"
            onTap: {
                navigationView.push("Page1.qml")
            }
        }
        FluPaneItem {
            title: "Page 2"
            onTap: {
                navigationView.push("Page2.qml")
            }
        }
    }


    /* 切换黑暗主题 */
    function handleDarkChanged(button) {
        if (FluTheme.dark) {
            FluTheme.darkMode = FluThemeType.Light
        } else {
            FluTheme.darkMode = FluThemeType.Dark
        }
    }

    /* 计算两点距离 */
    function distance(x1,y1,x2,y2){
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
    }
}
