import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: rootItem
    property int _id: 0
    property int line_height: 25
    property string _id_text: "ID"
    property string task_name: "Название задания"
    property string task_description: "Описание задания"
    property string start_date: "Дата начала"
    property string end_date: "Дата окончания"
    property string progress: "Прогресс"
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
        }//_tId
    }//_rId

    Rectangle {
        id: _rName
        color: back_color
        height: parent.height
        width: (parent.width - 390) / 2
        anchors.left: _rId.right
        border.color: black
        border.width: 1

        Label {
            id: _tName
            text: task_name
            anchors.centerIn: parent
        }//_tName
    }//_rName

    Rectangle {
        id: _rDesc
        color: back_color
        height: parent.height
        width: (parent.width - 390) / 2
        anchors.left: _rName.right
        border.color: black
        border.width: 1

        Label {
            id: _tDesc
            text: task_description
            anchors.centerIn: parent
        }//_tDesc
    }//_rDesc

    Rectangle {
        id: _rStart
        color: back_color
        height: parent.height
        width: 120
        anchors.left: _rDesc.right
        border.color: black
        border.width: 1

        Label {
            id: _dStart
            text: start_date
            anchors.centerIn: parent
        }//_dStart
    }//_rStart

    Rectangle {
        id: _rEnd
        color: back_color
        height: parent.height
        width: 120
        anchors.left: _rStart.right
        border.color: black
        border.width: 1

        Label {
            id: _dEnd
            text: end_date
            anchors.centerIn: parent
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

        Label {
            id: _prog
            text: progress
            anchors.centerIn: parent
        }//_prog
    }//_rProg

}//rootItem
