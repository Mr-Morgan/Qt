import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: rootItem
    property int line_height: 25
    property int _index: index
    property bool cbVisible: (_index != 0)? rootView.delMode : false
    property string _id_text: "ID"
    property string task_name: "Название задания"
    property string task_description: "Описание задания"
    property string start_date: "Дата начала"
    property string end_date: "Дата окончания"
    property string prog: "Прогресс"
    property string back_color: "#7C9BA3"

    signal dataChanged

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
        clip: true
        color: back_color
        height: parent.height
        width: (parent.width - 470) / 2
        anchors.left: _rId.right
        border.color: black
        border.width: 1

        TextField {
            id: _tName
            text: task_name
            background: back_color
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
            verticalAlignment: TextInput.AlignVCenter
            y: (_index == 0)? -1 : parent.height/5
            x: -_hNbar.position * width
            onTextChanged: {
                task_name = text
                rootItem.dataChanged()
            }//onTextChanged
        }//_tName

        ScrollBar {
            id: _hNbar
            hoverEnabled: true
            active: hovered || pressed
            orientation: Qt.Horizontal
            size: _rDesc.width / _tDesc.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }//_hbar
    }//_rName

    Rectangle {
        id: _rDesc
        clip: true
        color: back_color
        anchors.left: _rName.right
        height: parent.height
        width: (parent.width - 470) / 2
        border.width: 1
        border.color: black

        TextField {
            id: _tDesc
            text: task_description
            background: back_color
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
            verticalAlignment: TextInput.AlignVCenter
            y: (_index == 0)? -1 : parent.height/5
            x: -_hDbar.position * width
            onTextChanged: {
                task_description = text
                rootItem.dataChanged()
            }//onTextChanged
        }//_tDesc

        ScrollBar {
            id: _hDbar
            hoverEnabled: true
            active: hovered || pressed
            orientation: Qt.Horizontal
            size: _rDesc.width / _tDesc.width
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }//_hbar
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
            onTextChanged: {
                start_date = text
                rootItem.dataChanged()
            }//onTextChanged

            MouseArea {
                id: _mStart
                anchors.fill: parent
                onClicked: {
                    _calDialog.open()
                    _calDialog.isStart = true
                }//onClicked
            }//_mStart
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
            onTextChanged: {
                end_date = text
                rootItem.dataChanged()
            }//onTextChanged

            MouseArea {
                id: _mEnd
                anchors.fill: parent
                onClicked: {
                    _calDialog.open()
                    _calDialog.isStart = false
                }//onClicked
            }//_mEnd
        }//_dEnd
    }//_rEnd

    Rectangle {
        id: _rProg
        color: back_color
        height: parent.height
        width: 140
        anchors.left: _rEnd.right
        border.color: black
        border.width: 1

        TextField {
            id: _prog
            text: prog
            background: back_color
            width: parent.width
            anchors.centerIn: parent
            font.italic: (_prog.text === "100%")
            font.strikeout: (_prog.text === "100%")
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: {
                prog = text
                rootItem.dataChanged()
            }//onTextChanged
        }//_prog

        MyCheckBox{
            id: _cB
            size: parent.height - 2
            anchors.right: parent.right
            anchors.rightMargin: 1
            anchors.top: parent.top
            anchors.topMargin: 1
            visible: cbVisible
            checked: if (!rootView.delMode) false
            onClicked: { rootView.model.setIsDel(index) }
            onVisibleChanged: { if (!visible) checked = false }
        }//_cB
    }//_rProg

    CalendarDialog {
        id: _calDialog
        visible: false
        onAccepted: {
            if (isStart) _dStart.text = (_calDialog.date !== "")? _calDialog.date : end_date
            else _dEnd.text = (_calDialog.date !== "")? _calDialog.date : end_date
        }//onAccepted
    }//_calDialog

}//rootItem
