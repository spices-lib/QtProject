import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: window

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    /*Column {
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
        Row {
            anchors.right: parent.right
            spacing: 10

            Text {
                text: qsTr("regularMethod()")
            }
            Button {
                text: "Call C++ slot"

                onClicked: {
                    BWorker.cppSlot();
                }
            }
        }
        Row {
            anchors.right: parent.right
            spacing: 10

            Text {
                id: returnTextId

                text: qsTr("return")
            }
            Text {
                text: "regularMethodWithReturn("
            }
            TextField {
                id: nameFieldId

                placeholderText: qsTr("name")
                text: qsTr("John")
            }
            Text {
                text: qsTr(",")
            }
            TextField {
                id: ageFieldId

                inputMethodHints: Qt.ImhDigitsOnly
                placeholderText: qsTr("age")
                text: qsTr("25")
            }
            Text {
                text: qsTr(")")
            }
            Button {
                text: qsTr("Call C++ method")

                onClicked: {
                    if (nameFieldId.text !== null && ageFieldId.text !== null) {
                        var response = BWorker.regular_method_with_return(nameFieldId.text, parseInt(ageFieldId.text));
                        returnTextId.text = response;
                    } else {
                        console.log("One of the two required fields is empty");
                    }
                }
            }
        }
    }
    Other {
    }
    Row {
        Rectangle {
            id: redRectId

            color: "red"
            height: 100
            width: 100

            MouseArea {
                id: redRectMouseAreaId

                anchors.fill: parent
            }
        }
        Rectangle {
            id: greenRectId

            color: "green"
            height: 100
            width: 100

            Connections {
                function onClicked() {
                    BWorker.cppPrint(qsTr("This is green rectangle responding"))
                }

                target: redRectMouseAreaId
            }
        }
        Rectangle {
            id: blueRectId

            color: "blue"
            height: 100
            width: 100

            Connections {
                function onClicked() {
                    BWorker.cppPrint(qsTr("This is blue rectangle responding"))
                }

                target: redRectMouseAreaId
            }
        }
    }

    Connections {
        target: CppSignalSender

        function onCallQml(parm) {
            BWorker.cppPrint(parm)
        }

        function onCppTimer(v) {
            mRectText.text = v
        }
    }*/

    /*Column {
        Rectangle {
            width: 200
            height: 200
            color: "yellow"
            radius: 10

            Text {
                id: mRectText
                text: "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 30
            }
        }
        Button {
            text: "Call C++ Method"
            onClicked: {
                CppSignalSender.cppSlot()
            }
        }
        Text {
            id: mText
            text: qsTr("Default")
        }
    }*/

    /*Column {
        spacing: 20

        Text {
            id: titleId
            width: 500
            text: Movie === null ? "" : Movie.title
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: mainCharId
            width: 500
            text: Movie === null ? "" : Movie.mainCharacter
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: titleTextFiledId
                width: 300
            }
            Button {
                width: 200
                id: button1
                text: "Change Title"
                onClicked: {
                    Movie.title = titleTextFiledId.text
                }
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: mainCharTextFiledId
                width: 300
            }
            Button {
                id: button2

                text: "Change main character"
                width: 200

                onClicked: {
                    Movie.mainCharacter = mainCharTextFiledId.text;
                }
            }
        }
    }*/

    /*Rectangle {
        id: mRect1
        width: mText1.implicitWidth + 20
        height: mText1.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: mText1
            anchors.centerIn: parent
            text: lastname
            font.pointSize: 20
        }
    }

    Rectangle {
        id: mRect2
        anchors.left: mRect1.right
        anchors.leftMargin: 5
        width: mText2.implicitWidth + 20
        height: mText2.implicitHeight + 20
        border.color: "yellowgreen"
        color: "beige"

        Text {
            id: mText2

            anchors.centerIn: parent
            font.pointSize: 20
            text: firstname
        }
    }*/

    function qmlJSFunction(param) {
        console.log("qmlJSFunction called with param: " + param);
        return "qmlJSFunction returned " + param;
    }

    Button {
        id: mButton
        text: "Call QML function from C++"
        onClicked: {
            QmlJSCaller.cppMethod("QML Calling...")
        }
    }
}