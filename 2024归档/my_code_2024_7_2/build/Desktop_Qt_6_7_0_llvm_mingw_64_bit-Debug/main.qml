import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 800
    height: 600
    visible: true
    title: "win"
    Image {
        id: img
        source: "code.jpg"
    }

    // Component {
        // id: comp

    // }

    // 加载器
    // Loader {
    //     id: loader
    //     sourceComponent: comp // 默认先加载 pageComponent 中定义的组件
    //     onStatusChanged: {
    //         console.log("status: ", status);
    //     }
    // }
}
