import QtQuick
import QtQuick.Window
import QtQuick.Controls
import CppClass

Window {
    id: window

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    CppClass {
        id: cppClassId

        onSendBool: function (v) {
            console.log("Received bool: " + v + ", type is: " + typeof v);
        }
        onSendColor: function (v) {
            console.log("Received color: " + v + ", type is: " + typeof v);
        }
        onSendData: function (v) {
            console.log("Received data: " + v + ", type is: " + typeof v);
        }
        onSendTime: function (v) {
            console.log("Received time: " + v + ", type is: " + typeof v);
        }
        onSendDataTime: function (v) {
            console.log("Received data time: " + v + ", type is: " + typeof v);
        }
        onSendDouble: function (v) {
            console.log("Received double: " + v + ", type is: " + typeof v);
        }
        onSendFloat: function (v) {
            console.log("Received float: " + v + ", type is: " + typeof v);
        }
        onSendFont: function (v) {
            console.log("Received font: " + v + ", type is: " + typeof v);
        }
        onSendInt: function (v) {
            console.log("Received int: " + v + ", type is: " + typeof v);
        }
        onSendPoint: function (v) {
            console.log("Received point: " + v + ", type is: " + typeof v);
        }
        onSendReal: function (v) {
            console.log("Received real: " + v + ", type is: " + typeof v);
        }
        onSendRect: function (v) {
            console.log("Received rect: " + v + ", type is: " + typeof v);
        }
        onSendSize: function (v) {
            console.log("Received size: " + v + ", type is: " + typeof v);
        }
        onSendString: function (v) {
            console.log("Received string: " + v + ", type is: " + typeof v);
        }
        onSendUrl: function (v) {
            console.log("Received url: " + v + ", type is: " + typeof v);
        }
    }
    Button {
        text: "click here"

        onClicked: {
            const a = ['1', '2', '3']
            const b = {
                "1": "one",
                "2": "two",
                "3": "three"
            }

            cppClassId.qmlToCpp(a, b);

            const c = cppClassId.retrieveList();
            console.log("Retrieved list: " + c);

            const d = cppClassId.retrieveMap();
            console.log("Retrieved Map: " + d);
        }
    }
}