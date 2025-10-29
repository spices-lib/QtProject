import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    Timer {
        interval: 1000
        running: true

        onTimeout: function () {
            console.log(1);
        }
    }
}