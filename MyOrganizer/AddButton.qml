import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: _addButton
    property int size: 75
    width: size
    height: size
    radius: 100

    signal clicked;

    MouseArea {
        id: _mArea
        anchors.fill: parent
        onPressed: _imgBut.source = "qrc:/icons/add_pressed.png"
        onReleased: _imgBut.source = "qrc:/icons/add.png"
        onClicked: { parent.clicked() }
    }//_mArea

    Image {
        id: _imgBut
        source: "qrc:/icons/add.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }//_imgBut
}//_addButton

