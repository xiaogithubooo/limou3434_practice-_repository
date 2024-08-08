// 创建自定义的组件
import QtQuick 2.15

Rectangle {
    id: borderRect
    visible: true
    color: "red"
    property int myTopMargin: 10
    property int myBottomMargin: 10
    property int myLeftMargin: 10
    property int myRightMargin: 10

    Rectangle {
        id: innerRect
        visible: true
        color: "blue"
        anchors.fill: parent
        anchors.topMargin: borderRect.myTopMargin
        anchors.bottomMargin: borderRect.myBottomMargin
        anchors.leftMargin: borderRect.myLeftMargin
        anchors.rightMargin: borderRect.myRightMargin
    }
}
