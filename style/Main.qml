import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import RandomNumber

Window {
    id: root

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    Rectangle {
        id: rectId
        RandomNumber on width {

        }
        height: 300
        color: "red"
    }
}