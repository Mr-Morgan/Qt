import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2

Dialog {
    id: _addDialog
    visible: false

    property int _id: 0
    property string task_name: "Название задания"
    property string task_description: "Описание задания"
    property string start_date: "Дата начала"
    property string end_date: "Дата окончания"
    property string progress: "Прогресс"
    property string back_color: "#FFFFFF"

    width: 800
    height: 60

    Rectangle {
        id: _rId
        color: "#B0C3C7"
        height: parent.height
        width: 50
        anchors.left: parent.left
        border.color: black
        border.width: 1

        Text {
            id: _tId
            text: _id
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

        TextEdit {
            id: _tName
            text: task_name
            font.italic: true
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

        TextEdit {
            id: _tDesc
            text: task_description
            font.italic: true
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

        TextEdit {
            id: _dStart
            font.italic: true
            anchors.centerIn: parent

            MouseArea {
                id: _mStart
                anchors.fill: parent
                onClicked: { _calDialogStart.open() }
            }//_mStart
            text: (_calDialogStart.date !== "")? _calDialogStart.date : start_date
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

        TextEdit {
            id: _dEnd
            font.italic: true
            anchors.centerIn: parent

            MouseArea {
                id: _mEnd
                anchors.fill: parent
                onClicked: { _calDialogEnd.open() }
            }//_mStart
            text: (_calDialogEnd.date !== "")? _calDialogEnd.date : end_date
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

        TextEdit {
            id: _prog
            font.italic: true
            text: progress
            anchors.centerIn: parent
        }//_prog
    }//_rProg

    onAccepted: {
        task_name = _tName.text
        task_description = _tDesc.text
        start_date = _dStart.text
        end_date = _dEnd.text
        progress = _prog.text
    }//onAccepted

    CalendarDialog {
        id: _calDialogStart
        visible: false
    }//_calDialogEnd

    CalendarDialog {
        id: _calDialogEnd
        visible: false
    }//_calDialogEnd
}//_addDialog
