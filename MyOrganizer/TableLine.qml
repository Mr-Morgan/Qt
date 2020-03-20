import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: rootItem
    property int line_height: 25
    property string _id_text: "ID"
    property string task_name: "Название задания"
    property string task_description: "Описание задания"
    property string start_date: "Дата начала"
    property string end_date: "Дата окончания"
    property string prog: "Прогресс"
    property string back_color: "#7C9BA3"

    width: parent.width
    height: line_height

    Rectangle {
        id: _rId
        color: back_color
        height: parent.height
        width: 50
        anchors.left: parent.left
        border.color: black
        border.width: 1

        Label {
            id: _tId
            text: _id_text
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
        }//_tId
    }//_rId

    Rectangle {
        id: _rName
        color: back_color
        height: parent.height
        width: (parent.width - 430) / 2
        anchors.left: _rId.right
        border.color: black
        border.width: 1

        TextField {
            id: _tName
            text: task_name
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
        }//_tName
    }//_rName

    Rectangle {
        id: _rDesc
        color: back_color
        height: parent.height
        width: (parent.width - 430) / 2
        anchors.left: _rName.right
        border.color: black
        border.width: 1

        clip: true

        TextField {

            id: _tDesc
            text: task_description
            background: back_color
            //                width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter

            //                x: -hbar.position * width
        }//_tDesc


        ScrollBar {
            id: hbar
            hoverEnabled: true
            active: hovered || pressed
            orientation: Qt.Horizontal
            size: _rDesc.width / _tDesc.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }

    }//_rDesc

    Rectangle {
        id: _rStart
        color: back_color
        height: parent.height
        width: 140
        anchors.left: _rDesc.right
        border.color: black
        border.width: 1

        TextField {
            id: _dStart
            text: start_date
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
        }//_dStart
    }//_rStart

    Rectangle {
        id: _rEnd
        color: back_color
        height: parent.height
        width: 140
        anchors.left: _rStart.right
        border.color: black
        border.width: 1

        TextField {
            id: _dEnd
            text: end_date
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
        }//_dEnd
    }//_rEnd

    Rectangle {
        id: _rProg
        color: back_color
        height: parent.height
        width: 100
        anchors.left: _rEnd.right
        border.color: black
        border.width: 1

        TextField {
            id: _prog
            text: progress
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
        }//_prog
    }//_rProg

}//rootItem
