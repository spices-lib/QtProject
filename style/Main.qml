import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: window

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    Column {
        anchors.right: parent.right
        spacing: 10

        Row {
            Text {
                text: "regularMethod"
            }
            Button {
                text: "Call C++ method"

                onClicked: function () {
                    BWorker.regular_method();
                }
            }
        }
    }
}
