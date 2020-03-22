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
    property string progress: "0%"
    property string back_color: "#FFFFFF"

    width: 840
    height: 100

    TableLine {
        id: _tLine
        _index: _id
        back_color: if (_id != 0) "#FFFFFF"
        _id_text: if (_id != 0) _id
        task_name: parent.task_name
        task_description: parent.task_description
        start_date: parent.start_date
        end_date: parent.end_date
        prog: progress
        line_height: line_height + line_height
        anchors.left: parent.left
    }//_tLine

    onAccepted: {
        task_name = _tLine.task_name
        task_description = _tLine.task_description
        start_date = _tLine.start_date
        end_date = _tLine.end_date
        progress = _tLine.prog
    }//onAccepted
}//_addDialog
