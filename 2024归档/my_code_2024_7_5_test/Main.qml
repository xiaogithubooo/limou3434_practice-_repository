import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: root
    visible: true
    width: 640
    height: 480

    Button {
        id: but
        width: 100
        height: 40
        // enabled: true // 设置按钮是否可以被按下, 默认为 true
        text: "a button"
        background: Rectangle { // 定义按钮的背景
            color: { // 设置背景颜色
                if(but.pressed) {
                    return "yellow"
                } else {
                    return "blue"
                }
            }
            border.color: "red" // 设置边框颜色
            border.width: 1 // 设置边框宽度
            radius: 5 // 设置圆角
        }

        autoRepeat: true // 设置按住时允许连续触发 pressed()/released()/clicked()
        autoRepeatDelay: 3000 // 设置第一次触发到下一次触发的时间间隔
        autoRepeatInterval: 1000 // 设置连续触发的时间间隔

        // 下面都是常见的事件
        onPressed: { // 按下按钮时就触发
            console.log("pressed~")
            but.checkable = true // 强制属性
        }
        onReleased: { // 松开按钮时就触发
            console.log("released~")
        }
        onClicked: { // 按下按钮并且松开按钮时就触发
            console.log("clicked~")
        }
        onDoubleClicked: { // 双击按钮时就触发
            console.log("double clicked~")
        }
        onPressAndHold: { // 长按按钮时就触发
            console.log("time out clicked~")
        }
        onDownChanged: { // 按下状态改变时就触发
            console.log("down", down, "pressed", pressed)
        }

        // flat: true // 只有在按下时才会显示按钮颜色, 一般很少使用
        // highlighted: true // 在按前提供一个类似黑遮罩把按钮颜色略微遮住, 一般很少使用
    }
}
