import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: _backButton
    property int size: 75
    width: size
    height: size
    radius: 100

    signal clicked

    MouseArea {
        id: _mArea
        anchors.fill: parent
        onPressed: _imgBut.source = "qrc:/icons/left_pressed.png"
        onReleased: _imgBut.source = "qrc:/icons/left.png"
        onClicked: { parent.clicked() }
    }//_mArea

    Image {
        id: _imgBut
        source: "qrc:/icons/left.png"
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }//_imgBut
}//_backButton
