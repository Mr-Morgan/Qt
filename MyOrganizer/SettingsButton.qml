import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: _setButton
    property int size: 75
    width: size
    height: size
    radius: 100
    property bool isPressed: false

    signal clicked

    MouseArea {
        id: _mArea
        anchors.fill: parent
        onPressed: _imgBut.source = "qrc:/icons/settings_pressed.png"
        onReleased: _imgBut.source = "qrc:/icons/settings.png"
        onClicked: {
            _setButton.isPressed = !_setButton.isPressed
            _imgBut.source = (_setButton.isPressed)? "qrc:/icons/settings_pressed.png" : "qrc:/icons/settings.png"
            parent.clicked()
        }//onClicked
    }//_mArea

    Image {
        id: _imgBut
        source: "qrc:/icons/settings.png"
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }//_imgBut
}//_setButton
