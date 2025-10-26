import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Movie

Window {
    id: window

    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    Movie {
        id: movieId

        mainCharacter: "Leonardo"
        title: "Titanic"
    }
    Button {
        text: "Invoke created object"

        onClicked: {
            movieId.title = "Fast and Furious";
            movieId.mainCharacter = "Tom Cruise";

            console.log("Movie title: " + movieId.title);
        }
    }
}