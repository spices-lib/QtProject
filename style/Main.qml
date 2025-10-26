import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import ObjectList

Window {
    id: root

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    FootBallItem {
        id: teamId
        title: "Title"
        coatch: "Coatch"
        captain: Player {
            name: "Captain"
            position: "Middle"
            playing: true
        }

        players: [
            Player {
                name: "Player1"
                position: "Middle"
                playing: true
            },
            Player {
                name: "Player2"
                position: "Middle"
                playing: true
            },
            Player {
                name: "Player3"
                playing: true
                position: "Middle"
            },
            Player {
                name: "Player4"
                playing: true
                position: "Back"
            }
        ]
    }

    ListView {
        anchors.fill: parent
        model: teamId.players
        delegate: Rectangle {
            width: parent.width
            height: 50
            border.width: 1
            border.color: "yellowgreen"
            color: "beige"

            Text {
                anchors.centerIn: parent
                text: name
                font.pointSize: 20
            }
        }
    }

    Component.onCompleted: function() {
        console.log("We have " + teamId.players.length + " players in theam " + teamId.title)
    }
}