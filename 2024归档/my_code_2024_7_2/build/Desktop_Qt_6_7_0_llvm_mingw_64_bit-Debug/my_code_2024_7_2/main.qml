import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: win
    visible: true
    width: 800
    height: 480
    title: "limou"

    Column {
        id: col
        spacing: 5 // 子组件的间距

        Repeater {
            id: rep
            model: ListModel {
                // 内部一开始是空的...
            }

            delegate: Button { // 定义如何渲染每一个项
                width: 100
                height: 50
                text: model.name
            }
        }

        move: Transition {
            NumberAnimation {
                properties: "x, y"
                easing.type: Easing.OutBounce
            }
        }
        add: Transition {
            NumberAnimation {
                properties: "x, y"
                easing.type: Easing.OutBounce
            }
        }
        populate: Transition { // 会设置出一个动画效果
            NumberAnimation {
                properties: "x, y"
                from: 1000
                duration: 100 // 1ms
                easing.type: Easing.OutBounce
            }
        }
    }

    Button {
        width: 100
        height: 50
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        text: "Add Item"
        onClicked: {
            rep.model.insert(
                0, // 添加到的 index
                {"name": "Item " + rep.model.count} // ListModel
            )
        }
    }
}
