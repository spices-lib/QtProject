import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import AppWrapper

Window {
    id: root

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    AppWrapper {
        id: appWrapper
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: mListView
            model: appWrapper.posts

            delegate: Rectangle {
                width: root.width
                height: textId.implicitHeight+30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    width: parent.width
                    height: parent.height
                    id: textId
                    anchors.centerIn: parent
                    text: modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button1Id
            text: "Fetch"
            Layout.fillWidth: true

            onClicked: {
                appWrapper.fetchPosts();
            }
        }
        Button {
            id: button2Id
            text: "Remove"
            Layout.fillWidth: true

            onClicked: {
                appWrapper.removeLast();
            }
        }
    }
}