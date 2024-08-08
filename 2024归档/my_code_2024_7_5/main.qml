import QtQuick
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 800
    height: 600
    title: "win"
    visible: true

    Image {
        id: img
        source: ":/code.jpg" // "file:///D:/GitWork/limou-c-test-code/my_code_2024_7_5/code.jpg" // 图片资源的路径
    }

    Button {
        id: but
        width: 100
        height: 100
        x: 110
        y: 0
    }
}
