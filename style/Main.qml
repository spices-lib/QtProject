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
            spacing: 10
            anchors.right: parent.right
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
                placeholderText: qsTr("age")
                inputMethodHints: Qt.ImhDigitsOnly
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
    Other {}
}